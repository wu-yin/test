
#
# 本程序是Python 3的语法
#

d = {}
f = open('test.txt')

while True :
    line = f.readline().strip('\n')
    if len(line) == 0 :
        break

    if line in d.keys() :
        d[line] += 1
    else :
        d[line] = 1
 
li = sorted(d.items(), key = lambda d : d[0])

for e in li :
    print('%-10s   %d' % e)
