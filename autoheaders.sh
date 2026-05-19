#/bin/sh

H_PATH=$1
SRCS_PATH=$2
echo "$(cat $H_PATH | sed -z 's#//[ \t]*start-headers.*#// start-headers\n#')
$(./makeheaders.out -local -h $(find $SRCS_PATH -name '*.c') | grep -v '#define')
$(cat $H_PATH | sed -z 's#.*//[ \t]*end-headers#\n// end-headers#')" > $H_PATH
pip3 install c_formatter_42
echo "$(c_formatter_42 < $H_PATH)" > $H_PATH


