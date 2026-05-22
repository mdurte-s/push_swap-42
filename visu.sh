#!/bin/bash

# ==========================================
# CONFIGURATION & INITIALIZATION
# ==========================================
TARGET_EXECUTABLE="$1"
N_ELEMS="$2"

if [ -z "$TARGET_EXECUTABLE" ] || [ ! -x "$TARGET_EXECUTABLE" ] || [ -z "$N_ELEMS" ]; then
    printf "Usage: %s <path_to_push_swap> <number_of_elements>\n" "$0"
    exit 1
fi

if ! [[ "$N_ELEMS" =~ ^[0-9]+$ ]] || [ "$N_ELEMS" -le 0 ]; then
    printf "Error: number_of_elements must be a positive integer.\n"
    exit 1
fi

exec 3<&0
exec 0</dev/tty

tput smcup
tput civis
clear

# ==========================================
# STATE & SIGNAL HANDLING
# ==========================================
FORCE_REDRAW=1

cleanup() {
    printf "\033[0m\033[?25h"
    tput rmcup
    exit 0
}

handle_resize() {
    FORCE_REDRAW=1
    draw_screen
}

trap cleanup INT TERM
trap handle_resize WINCH

# ==========================================
# DATA GENERATION
# ==========================================
printf "Generating %d unique random numbers...\n" "$N_ELEMS"

RAW_SEQUENCE=$(awk -v n="$N_ELEMS" 'BEGIN {
    srand();
    for(i=1; i<=n; i++) {
        do { r = int(rand() * 2000000) - 1000000 } while (r in seen)
        seen[r] = 1
        print r
    }
}')

SEQ_ARRAY=($RAW_SEQUENCE)
printf "Running %s...\n" "$TARGET_EXECUTABLE"

OPERATIONS_TEXT=$("$TARGET_EXECUTABLE" "${SEQ_ARRAY[@]}")
OPS=($OPERATIONS_TEXT)
TOTAL_OPS=${#OPS[@]}

TMP_RAW=$(mktemp)
TMP_SORTED=$(mktemp)
printf "%s\n" "${SEQ_ARRAY[@]}" > "$TMP_RAW"
sort -n "$TMP_RAW" > "$TMP_SORTED"

RANKS_SEQUENCE=$(awk '
    NR==FNR { rank[$1] = NR; next }
    { printf "%d ", rank[$1] }
' "$TMP_SORTED" "$TMP_RAW")

rm -f "$TMP_RAW" "$TMP_SORTED"

INITIAL_RANKS=($RANKS_SEQUENCE)

if [ ${#INITIAL_RANKS[@]} -eq 0 ]; then
    printf "Error: Failed to initialize initial sequence.\n"
    cleanup
fi

OFFSET=1000000
A_HEAD=$OFFSET
A_TAIL=$OFFSET
B_HEAD=$OFFSET
B_TAIL=$OFFSET

for val in "${INITIAL_RANKS[@]}"; do
    A[$A_TAIL]=$val
    A_TAIL=$((A_TAIL + 1))
done

# ==========================================
# SPEED & FPS CONFIGURATION
# ==========================================
FPS=30
FRAME_DELAY="0.033"
SPEEDS=(1 5 10 30 60 150 300 600 1200 3000 6000 12000 50000 100000)
SPEED_IDX=5
ACCUMULATOR=0

# ==========================================
# TUI DRAWING ENGINE 
# ==========================================
draw_screen() {
    local cols=$(tput cols)
    local lines=$(tput lines)
    
    local clear_cmd="\033[H"
    if [ "$FORCE_REDRAW" -eq 1 ]; then
        clear_cmd="\033[2J\033[H"
        FORCE_REDRAW=0
    fi
    
    awk -v cols="$cols" -v lines="$lines" \
        -v clear_cmd="$clear_cmd" \
        -v max_n="$N_ELEMS" \
        -v op_idx="$OP_IDX" -v total_ops="$TOTAL_OPS" \
        -v auto_play="$AUTO_PLAY" -v speed_val="${SPEEDS[$SPEED_IDX]}" \
        -v play_dir="$PLAY_DIR" \
        -v stack_a="${A[*]}" -v stack_b="${B[*]}" '
    BEGIN {
        sa_len = split(stack_a, sa, " ");
        sb_len = split(stack_b, sb, " ");
        
        # Apply clear command (H for redraw, 2J H for full wipe on resize)
        printf "%s\033[0m", clear_cmd;
        
        half_cols = int((cols - 5) / 2);
        max_lines = lines - 8;
        if (max_lines < 1) max_lines = 1;
        max_slots = max_lines * 2;
        
        display_sa_len = (sa_len > max_slots) ? max_slots : sa_len;
        for (k = 0; k < display_sa_len; k++) {
            idx = (sa_len > max_slots && max_slots > 1) ? int(k * (sa_len - 1) / (max_slots - 1)) + 1 : k + 1;
            disp_sa[k] = sa[idx];
        }
        
        display_sb_len = (sb_len > max_slots) ? max_slots : sb_len;
        for (k = 0; k < display_sb_len; k++) {
            idx = (sb_len > max_slots && max_slots > 1) ? int(k * (sb_len - 1) / (max_slots - 1)) + 1 : k + 1;
            disp_sb[k] = sb[idx];
        }
        
        # ---------------------------------------------------------
        # COLOR DEFINITIONS
        # ---------------------------------------------------------
        c_rst = "\033[0m"; c_dim = "\033[2m"; c_bold = "\033[1m";
        c_cyan = "\033[1;36m"; c_yellow = "\033[1;33m"; c_green = "\033[1;32m";
        c_red = "\033[1;31m"; c_magenta = "\033[1;35m"; c_frame = "\033[38;5;60m";

        # ---------------------------------------------------------
        # HEADER DRAWING
        # ---------------------------------------------------------
        printf "%s╭%s╮%s\033[K\n", c_frame, repeat_str("─", cols-2), c_rst;
        
        # --- TITLE LINE ---
        plain_title = sprintf(" push_swap visualizer | Op: %d / %d | Auto: %s (%s) | Speed: %d ops/s ", op_idx, total_ops, auto_play, play_dir, speed_val);
        pad = cols - 2 - length(plain_title);
        pad_l = int(pad / 2); pad_r = pad - pad_l;
        
        auto_col = (auto_play == "ON") ? c_green : c_red;
        dir_col = (play_dir == "FWD") ? c_cyan : c_magenta;
        
        colored_title = sprintf(" %spush_swap visualizer%s %s|%s %sOp: %d / %d%s %s|%s Auto: %s%s%s (%s%s%s) %s|%s %sSpeed: %d ops/s%s ",
            c_cyan, c_rst,  c_dim, c_rst,
            c_yellow, op_idx, total_ops, c_rst,  c_dim, c_rst,
            auto_col, auto_play, c_rst,
            dir_col, play_dir, c_rst,  c_dim, c_rst,
            c_bold, speed_val, c_rst);
            
        printf "%s│%s%s%s%s%s│%s\033[K\n", c_frame, c_rst, repeat_str(" ", pad_l), colored_title, repeat_str(" ", pad_r), c_frame, c_rst;
        
        # --- CONTROLS LINE ---
        plain_ctrl = " [P] Play/Pause | [O] Fwd/Rev |  [N] Next | [B] Back | [Z] Speed - | [X] Speed + | [Q] Quit ";
        pad2 = cols - 2 - length(plain_ctrl);
        pad2_l = int(pad2 / 2); pad2_r = pad2 - pad2_l;
        
        colored_ctrl = " [" c_dim "P" c_rst "] Play/Pause " c_dim "|" c_rst " [" c_dim "O" c_rst "] Fwd/Rev " c_dim "|" c_rst " [" c_dim "N" c_rst "] Next " c_dim "|" c_rst " [" c_dim "B" c_rst "] Back " c_dim "|" c_rst " [" c_dim "Z" c_rst "] Speed - " c_dim "|" c_rst " [" c_dim "X" c_rst "] Speed + " c_dim "|" c_rst " [" c_red "Q" c_rst "] Quit ";
        
        printf "%s│%s%s%s%s%s│%s\033[K\n", c_frame, c_rst, repeat_str(" ", pad2_l), colored_ctrl, repeat_str(" ", pad2_r), c_frame, c_rst;
        
        printf "%s╰%s╯%s\033[K\n", c_frame, repeat_str("─", cols-2), c_rst;
        
        # --- COLUMNS HEADER ---
        hdr_a = sprintf("%sSTACK A%s", c_rst, c_rst);
        hdr_b = sprintf("%sSTACK B%s", c_rst, c_rst);
        
        # Calculate padding without ANSI escape characters (7 is the length of "STACK X")
        pad_a_len = half_cols - 7;
        if (pad_a_len < 0) pad_a_len = 0;
        
        printf " %s%s %s│%s %s\033[K\n", hdr_a, repeat_str(" ", pad_a_len), c_dim, c_rst, hdr_b;
        
        # ---------------------------------------------------------
        # STACKS DRAWING
        # ---------------------------------------------------------
        for (i = 0; i < max_lines; i++) {
            idx1 = i * 2;
            idx2 = i * 2 + 1;
            
            a1 = (idx1 < display_sa_len) ? disp_sa[idx1] : -1;
            a2 = (idx2 < display_sa_len) ? disp_sa[idx2] : -1;
            b1 = (idx1 < display_sb_len) ? disp_sb[idx1] : -1;
            b2 = (idx2 < display_sb_len) ? disp_sb[idx2] : -1;
            
            str_a = build_bar(a1, a2, half_cols, max_n);
            str_b = build_bar(b1, b2, half_cols, max_n);
            
            printf " %s \033[0m%s│\033[0m %s \033[0m\033[K\n", str_a, c_dim, str_b;
        }
        printf "\033[0m";
    }
    
    function repeat_str(char, count,    res, i) {
        res = ""; for(i=0;i<count;i++) res = res char; return res;
    }

    function get_rgb(val, max_val,    ratio, r, g, b) {
        if (val <= 0) return "0;0;0";
        ratio = val / max_val;
        if (ratio < 0.25) { r = 0; g = int((ratio/0.25)*255); b = 255; }
        else if (ratio < 0.5) { r = 0; g = 255; b = int((1 - (ratio-0.25)/0.25)*255); }
        else if (ratio < 0.75) { r = int(((ratio-0.5)/0.25)*255); g = 255; b = 0; }
        else { r = 255; g = int((1 - (ratio-0.75)/0.25)*255); b = 0; }
        return sprintf("%d;%d;%d", r, g, b);
    }

    function build_bar(val1, val2, max_w, max_n,    l1, l2, min_l, max_l, out, spaces, rgb1, rgb2) {
        if (val1 == -1 && val2 == -1) return repeat_str(" ", max_w);

        l1 = (val1 != -1 && val1 != "") ? int((val1 * max_w) / max_n) : 0;
        l2 = (val2 != -1 && val2 != "") ? int((val2 * max_w) / max_n) : 0;
        
        if (val1 > 0 && l1 == 0) l1 = 1;
        if (val2 > 0 && l2 == 0) l2 = 1;

        rgb1 = get_rgb(val1, max_n);
        rgb2 = get_rgb(val2, max_n);

        min_l = (l1 < l2) ? l1 : l2;
        max_l = (l1 > l2) ? l1 : l2;
        
        out = "";
        if (min_l > 0) {
            out = out sprintf("\033[38;2;%sm\033[48;2;%sm%s\033[0m", rgb1, rgb2, repeat_str("▀", min_l));
        }
        
        if (l1 > l2) {
            out = out sprintf("\033[38;2;%sm\033[49m%s\033[0m", rgb1, repeat_str("▀", l1 - min_l));
        } else if (l2 > l1) {
            out = out sprintf("\033[38;2;%sm\033[49m%s\033[0m", rgb2, repeat_str("▄", l2 - min_l));
        }
        
        spaces = max_w - max_l;
        if (spaces > 0) out = out sprintf("%*s", spaces, "");
        
        return out;
    }
    '
}

# ==========================================
# STACK OPERATIONS
# ==========================================
execute_op() {
    case "$1" in
        sa)
            if (( A_TAIL - A_HEAD >= 2 )); then
                local t=${A[$A_HEAD]}
                A[$A_HEAD]=${A[$((A_HEAD + 1))]}
                A[$((A_HEAD + 1))]=$t
            fi ;;
        sb)
            if (( B_TAIL - B_HEAD >= 2 )); then
                local t=${B[$B_HEAD]}
                B[$B_HEAD]=${B[$((B_HEAD + 1))]}
                B[$((B_HEAD + 1))]=$t
            fi ;;
        ss) execute_op sa; execute_op sb ;;
        pa)
            if (( B_TAIL - B_HEAD >= 1 )); then
                A_HEAD=$((A_HEAD - 1))
                A[$A_HEAD]=${B[$B_HEAD]}
                unset 'B[$B_HEAD]'
                B_HEAD=$((B_HEAD + 1))
            fi ;;
        pb)
            if (( A_TAIL - A_HEAD >= 1 )); then
                B_HEAD=$((B_HEAD - 1))
                B[$B_HEAD]=${A[$A_HEAD]}
                unset 'A[$A_HEAD]'
                A_HEAD=$((A_HEAD + 1))
            fi ;;
        ra)
            if (( A_TAIL - A_HEAD >= 2 )); then
                A[$A_TAIL]=${A[$A_HEAD]}
                unset 'A[$A_HEAD]'
                A_HEAD=$((A_HEAD + 1))
                A_TAIL=$((A_TAIL + 1))
            fi ;;
        rb)
            if (( B_TAIL - B_HEAD >= 2 )); then
                B[$B_TAIL]=${B[$B_HEAD]}
                unset 'B[$B_HEAD]'
                B_HEAD=$((B_HEAD + 1))
                B_TAIL=$((B_TAIL + 1))
            fi ;;
        rr) execute_op ra; execute_op rb ;;
        rra)
            if (( A_TAIL - A_HEAD >= 2 )); then
                A_HEAD=$((A_HEAD - 1))
                A_TAIL=$((A_TAIL - 1))
                A[$A_HEAD]=${A[$A_TAIL]}
                unset 'A[$A_TAIL]'
            fi ;;
        rrb)
            if (( B_TAIL - B_HEAD >= 2 )); then
                B_HEAD=$((B_HEAD - 1))
                B_TAIL=$((B_TAIL - 1))
                B[$B_HEAD]=${B[$B_TAIL]}
                unset 'B[$B_TAIL]'
            fi ;;
        rrr) execute_op rra; execute_op rrb ;;
    esac
}

execute_inverse_op() {
    case "$1" in
        sa)  execute_op "sa" ;;
        sb)  execute_op "sb" ;;
        ss)  execute_op "ss" ;;
        pa)  execute_op "pb" ;;
        pb)  execute_op "pa" ;;
        ra)  execute_op "rra" ;;
        rb)  execute_op "rrb" ;;
        rr)  execute_op "rrr" ;;
        rra) execute_op "ra" ;;
        rrb) execute_op "rb" ;;
        rrr) execute_op "rr" ;;
    esac
}

# ==========================================
# MAIN LOOP
# ==========================================
OP_IDX=0
AUTO_PLAY="OFF"
PLAY_DIR="FWD"

while true; do
    if [ "$AUTO_PLAY" == "ON" ]; then
        TARGET_OPS_SEC=${SPEEDS[$SPEED_IDX]}
        ACCUMULATOR=$((ACCUMULATOR + TARGET_OPS_SEC))
        OPS_THIS_FRAME=$((ACCUMULATOR / FPS))
        ACCUMULATOR=$((ACCUMULATOR % FPS))

        for ((i=0; i<OPS_THIS_FRAME; i++)); do
            if [ "$PLAY_DIR" == "FWD" ]; then
                if [ "$OP_IDX" -lt "$TOTAL_OPS" ]; then
                    execute_op "${OPS[$OP_IDX]}"
                    OP_IDX=$((OP_IDX + 1))
                else
                    AUTO_PLAY="OFF"
                    ACCUMULATOR=0
                    break
                fi
            else
                if [ "$OP_IDX" -gt 0 ]; then
                    OP_IDX=$((OP_IDX - 1))
                    execute_inverse_op "${OPS[$OP_IDX]}"
                else
                    AUTO_PLAY="OFF"
                    ACCUMULATOR=0
                    break
                fi
            fi
        done
    fi

    draw_screen
    
    # Use '|| true' to gracefully handle read interrupts from SIGWINCH
    read -rsn1 -t "$FRAME_DELAY" key || true

    # Ignore escape sequences completely (like arrows)
    if [[ "$key" == $'\x1b' ]]; then
        read -rsn2 -t 0.01 key2 || true
        key="" 
    fi

    case "$key" in
        "p"|"P")
            if [ "$AUTO_PLAY" == "ON" ]; then 
                AUTO_PLAY="OFF"
                ACCUMULATOR=0
            else 
                AUTO_PLAY="ON"
            fi
            ;;
        "o"|"O")
            if [ "$PLAY_DIR" == "FWD" ]; then
                PLAY_DIR="REV"
            else
                PLAY_DIR="FWD"
            fi
            ;;
        "x"|"X")
            if [ "$SPEED_IDX" -lt $(( ${#SPEEDS[@]} - 1 )) ]; then
                SPEED_IDX=$((SPEED_IDX + 1))
            fi
            ;;
        "z"|"Z")
            if [ "$SPEED_IDX" -gt 0 ]; then
                SPEED_IDX=$((SPEED_IDX - 1))
            fi
            ;;
        "n"|"N")
            AUTO_PLAY="OFF"
            ACCUMULATOR=0
            if [ "$OP_IDX" -lt "$TOTAL_OPS" ]; then
                execute_op "${OPS[$OP_IDX]}"
                OP_IDX=$((OP_IDX + 1))
            fi
            ;;
        "b"|"B")
            AUTO_PLAY="OFF"
            ACCUMULATOR=0
            if [ "$OP_IDX" -gt 0 ]; then
                OP_IDX=$((OP_IDX - 1))
                execute_inverse_op "${OPS[$OP_IDX]}"
            fi
            ;;
        "q"|"Q")
            break
            ;;
    esac
done

cleanup