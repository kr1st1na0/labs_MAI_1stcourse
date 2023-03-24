#!/usr/bin/env python

import os
from os.path import getsize
from os.path import join

print("Enter the suffix of files or press '?' if you don't want to enter the value:")
suffix = input()

print("Enter the size in bytes or press '?' if you don't want to enter the value:")
size = input()

if suffix == "?":
    suffix = "txt"

if size == "?":
    size = int(100)
else:
    size = int(size)

directory = "lab21"

for (root, dirs, files) in os.walk(directory):
    for file in files:
        in_name = join(root, file)
        cur_size = getsize(in_name)
        if file.endswith(suffix) and cur_size < size:
            with open(in_name, "r") as input:
                with open("ans", "a") as output:
                    for line in input:
                        output.write(line)

with open("ans", "r") as print_content:
    for line in print_content:
        print(line, end = '')

os.remove("ans")
