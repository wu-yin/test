# -*- coding: utf-8 -*-

x = []
usedMem = []
usedCpu_Usr = []
i = 0

logFile = open('AppSpy.log', 'r')
for lineInLog in logFile:
    lineInLog = logFile.readline()
    if "SpyInfo_top: Mem" in lineInLog:
        words = lineInLog.split()
        i += 1
        x.append(i)
        # 输出字符串words[2]中除了倒数第一个字符外的所有字符
        usedMem.append(words[2][:-1])

    if "SpyInfo_top: CPU" in lineInLog:
        words = lineInLog.split()
        print(words)
        usedCpu_Usr = words[2][:-1])
#        print(words[4])
#        print(words[6])
#        print(words[10])
#        print(words[12])
#        print(words[14])
        

#print(usedMem)
logFile.close()

