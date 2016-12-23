#########################################################################
# File Name     : mv.sh
# Author        : enjoy5512
# mail          : enjoy5512@163.com
# Created Time  : 2016年12月16日 星期五 18时53分28秒
#########################################################################

#!/bin/bash

read -p "input the dif : " num

file=$(ls | grep acm*.c)
mkdir ./$num/${file:0:7}
mv ${file:0:7}* ./$num/${file:0:7}
