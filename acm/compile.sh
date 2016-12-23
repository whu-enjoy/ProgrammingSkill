#########################################################################
# File Name     : compile.sh
# Author        : enjoy5512
# mail          : enjoy5512@163.com
# Created Time  : 2016年12月20日 星期二 18时29分41秒
#########################################################################

#!/bin/sh

file=$(ls | grep acm*.c)
if [ -z "$file" ]
then
	echo -e "no input file"
else
	gcc -g -o ${file:0:7} $file
	touch ${file:0:7}_question
	echo  "compile success!!"
	cat input | ./${file:0:7}>log
fi
