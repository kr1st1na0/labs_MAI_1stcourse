#!/bin/bash

echo "Enter the suffix of files or press "?" if you don't want to enter the value:"
read suffix
suffix=$suffix

echo "Enter the size in bytes or press "?" if you don't want to enter the value:"
read size
size=$size

if [ "$suffix" == "?" ]; then
  suffix="txt"
fi

if [ "$size" == "?" ]; then
  size=100
fi

echo -n > /home/kristina/lab21/answer

for i in $(find ./ -name \*."$suffix" -type f -print)
do
  file_size=$(stat -c %s "$i")
  if [ "$file_size" -le "$size" ]; then
    cat "$i"  >> /home/kristina/lab21/answer
  fi
done

cat /home/kristina/lab21/answer

rm /home/kristina/lab21/answer
