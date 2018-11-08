
import re

s2 = 'hello world[my2]'
reg = r'\[(.+)\]'
arr = re.findall(reg, s2)
print(arr)

s3 = 'hello world2[my3]'
reg = r'\s(.+)\[.+\]'
arr = re.findall(reg, s3)
print(arr)
