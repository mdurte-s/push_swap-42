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

# Clean up and reset terminal state
cleanup() {
    printf "\033[0m" # Reset terminal colors
    tput cnorm       # Show cursor
    tput rmcup       # Restore terminal screen
    exit 0
}

# Redraw screen immediately on terminal resize
handle_resize() {
    draw_screen
}

# Bind signals to handler functions
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

STACK_A=($RANKS_SEQUENCE)
STACK_B=()

if [ ${#STACK_A[@]} -eq 0 ]; then
    printf "Error: Failed to initialize STACK_A.\n"
    cleanup
fi

# ==========================================
# SPEED & FPS CONFIGURATION
# ==========================================
FPS=30
FRAME_DELAY="0.033" # Roughly 1/30th of a second
SPEEDS=(1 5 10 30 60 150 300 600 1200 3000 6000 12000)
SPEED_IDX=5 # Starts at 60 ops/s
ACCUMULATOR=0

# ==========================================
# TUI DRAWING ENGINE (DOWN-SAMPLING + DEFAULT THEME)
# ==========================================
draw_screen() {
    local cols
    local lines
    cols=$(tput cols)
    lines=$(tput lines)
    
    awk -v cols="$cols" -v lines="$lines" \
        -v max_n="$N_ELEMS" \
        -v op_idx="$OP_IDX" -v total_ops="$TOTAL_OPS" \
        -v auto_play="$AUTO_PLAY" -v speed_val="${SPEEDS[$SPEED_IDX]}" \
        -v stack_a="${STACK_A[*]}" -v stack_b="${STACK_B[*]}" '
    BEGIN {
        sa_len = split(stack_a, sa, " ");
        sb_len = split(stack_b, sb, " ");
        
        # Clear screen and apply default terminal colors
        printf "\033[0m\033[2J\033[H"
        
        half_cols = int((cols - 5) / 2);
        max_lines = lines - 8;
        if (max_lines < 1) max_lines = 1;
        max_slots = max_lines * 2;
        
        # Downsample Stack A logic to fit in screen
        display_sa_len = (sa_len > max_slots) ? max_slots : sa_len;
        for (k = 0; k < display_sa_len; k++) {
            idx = (sa_len > max_slots && max_slots > 1) ? int(k * (sa_len - 1) / (max_slots - 1)) + 1 : k + 1;
            disp_sa[k] = sa[idx];
        }
        
        # Downsample Stack B logic to fit in screen
        display_sb_len = (sb_len > max_slots) ? max_slots : sb_len;
        for (k = 0; k < display_sb_len; k++) {
            idx = (sb_len > max_slots && max_slots > 1) ? int(k * (sb_len - 1) / (max_slots - 1)) + 1 : k + 1;
            disp_sb[k] = sb[idx];
        }
        
        # Draw btop-like Header Box
        printf "╭"; for(i=0;i<cols-2;i++) printf "─"; printf "╮\n";
        
        title = sprintf(" Push_swap TUI Visualizer | Op: %d / %d | Auto: %s | Speed: %d ops/s ", op_idx, total_ops, auto_play, speed_val);
        pad = cols - 2 - length(title);
        pad_l = int(pad / 2); pad_r = pad - pad_l;
        printf "│"; for(i=0;i<pad_l;i++) printf " "; printf "%s", title; for(i=0;i<pad_r;i++) printf " "; printf "│\n";
        
        ctrl = " Controls: [P] Play/Pause | [F] Fast | [S] Slow | [N] Next Step | [B] Back Step | [Q] Quit ";
        pad2 = cols - 2 - length(ctrl);
        pad2_l = int(pad2 / 2); pad2_r = pad2 - pad2_l;
        printf "│"; for(i=0;i<pad2_l;i++) printf " "; printf "%s", ctrl; for(i=0;i<pad2_r;i++) printf " "; printf "│\n";
        
        printf "╰"; for(i=0;i<cols-2;i++) printf "─"; printf "╯\n";
        
        fmt_header = sprintf(" %%-%ds │ %%s\n", half_cols);
        printf fmt_header, "STACK A", "STACK B";
        
        for (i = 0; i < max_lines; i++) {
            idx1 = i * 2;
            idx2 = i * 2 + 1;
            
            a1 = (idx1 < display_sa_len) ? disp_sa[idx1] : -1;
            a2 = (idx2 < display_sa_len) ? disp_sa[idx2] : -1;
            b1 = (idx1 < display_sb_len) ? disp_sb[idx1] : -1;
            b2 = (idx2 < display_sb_len) ? disp_sb[idx2] : -1;
            
            if (a1 == -1 && a2 == -1 && b1 == -1 && b2 == -1) break;
            
            str_a = build_bar(a1, a2, half_cols, max_n);
            str_b = build_bar(b1, b2, half_cols, max_n);
            
            printf " %s \033[0m│ %s \033[0m\n", str_a, str_b;
        }
        
        printf "\033[0m";
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

    function build_bar(val1, val2, max_w, max_n,    l1, l2, min_l, max_l, out, spaces, j, rgb1, rgb2, bg_reset) {
        bg_reset = "\033[0m";
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
            out = out sprintf("\033[38;2;%sm\033[48;2;%sm", rgb1, rgb2);
            for(j=0; j<min_l; j++) out = out "▀";
            out = out bg_reset;
        }
        
        if (l1 > l2) {
            out = out sprintf("\033[38;2;%sm\033[49m", rgb1);
            for(j=0; j<(l1 - min_l); j++) out = out "▀";
            out = out bg_reset;
        } else if (l2 > l1) {
            out = out sprintf("\033[38;2;%sm\033[49m", rgb2);
            for(j=0; j<(l2 - min_l); j++) out = out "▄";
            out = out bg_reset;
        }
        
        spaces = max_w - max_l;
        for(j=0; j<spaces; j++) out = out " ";
        
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
            if [ ${#STACK_A[@]} -ge 2 ]; then
                local t=${STACK_A[0]}; STACK_A[0]=${STACK_A[1]}; STACK_A[1]=$t
            fi ;;
        sb)
            if [ ${#STACK_B[@]} -ge 2 ]; then
                local t=${STACK_B[0]}; STACK_B[0]=${STACK_B[1]}; STACK_B[1]=$t
            fi ;;
        ss) execute_op sa; execute_op sb ;;
        pa)
            if [ ${#STACK_B[@]} -ge 1 ]; then
                STACK_A=("${STACK_B[0]}" "${STACK_A[@]}")
                STACK_B=("${STACK_B[@]:1}")
            fi ;;
        pb)
            if [ ${#STACK_A[@]} -ge 1 ]; then
                STACK_B=("${STACK_A[0]}" "${STACK_B[@]}")
                STACK_A=("${STACK_A[@]:1}")
            fi ;;
        ra)
            if [ ${#STACK_A[@]} -ge 2 ]; then
                local t=${STACK_A[0]}; STACK_A=("${STACK_A[@]:1}" "$t")
            fi ;;
        rb)
            if [ ${#STACK_B[@]} -ge 2 ]; then
                local t=${STACK_B[0]}; STACK_B=("${STACK_B[@]:1}" "$t")
            fi ;;
        rr) execute_op ra; execute_op rb ;;
        rra)
            if [ ${#STACK_A[@]} -ge 2 ]; then
                local last=$(( ${#STACK_A[@]} - 1 ))
                local t=${STACK_A[$last]}; unset 'STACK_A[$last]'
                STACK_A=("$t" "${STACK_A[@]}")
            fi ;;
        rrb)
            if [ ${#STACK_B[@]} -ge 2 ]; then
                local last=$(( ${#STACK_B[@]} - 1 ))
                local t=${STACK_B[$last]}; unset 'STACK_B[$last]'
                STACK_B=("$t" "${STACK_B[@]}")
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

while true; do
    
    if [ "$AUTO_PLAY" == "ON" ]; then
        TARGET_OPS_SEC=${SPEEDS[$SPEED_IDX]}
        ACCUMULATOR=$((ACCUMULATOR + TARGET_OPS_SEC))
        OPS_THIS_FRAME=$((ACCUMULATOR / FPS))
        ACCUMULATOR=$((ACCUMULATOR % FPS))

        for ((i=0; i<OPS_THIS_FRAME; i++)); do
            if [ "$OP_IDX" -lt "$TOTAL_OPS" ]; then
                execute_op "${OPS[$OP_IDX]}"
                OP_IDX=$((OP_IDX + 1))
            else
                AUTO_PLAY="OFF"
                ACCUMULATOR=0
                break
            fi
        done
    fi

    draw_screen

    # Use '|| true' to gracefully handle read interrupts from SIGWINCH
    if [ "$AUTO_PLAY" == "ON" ]; then
        read -rsn1 -t "$FRAME_DELAY" key || true
    else
        read -rsn1 key || true
    fi

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
        "f"|"F") 
            if [ "$SPEED_IDX" -lt $(( ${#SPEEDS[@]} - 1 )) ]; then
                SPEED_IDX=$((SPEED_IDX + 1))
            fi
            ;;
        "s"|"S") 
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