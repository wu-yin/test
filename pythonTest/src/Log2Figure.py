# -*- coding: utf-8 -*-

import matplotlib.pyplot as plt
import glob
import tarfile
import bz2
import shutil

shutil.rmtree('log', True)
archive = tarfile.open('log.tar.bz2', 'r:bz2')
for tarinfo in archive:
    archive.extract(tarinfo)
archive.close()

###########################################################
# 读文件
###########################################################
logFileList = glob.glob(r"log\archive\*.log")
logFileList.sort()

x = []
usedMem = []
usedCpu_Usr = []
usedCpu_Sys = []
usedCpu_All = []
i = 0

for logFile in logFileList:
    oneLogFile = open(logFile, 'r')
    for lineInFile in oneLogFile:
        if "SpyInfo_top: Mem" in lineInFile:
            i += 1
            x.append(i / 60)
            words = lineInFile.split()
            # 舍去最后4个字符，最后一个是字符‘K’，再舍去3个就是以M为单位
            usedMem.append(words[2][:-4])

        if "SpyInfo_top: CPU" in lineInFile:
            words = lineInFile.split()
            usedCpu_Usr.append(words[2][:-1])
            usedCpu_Sys.append(words[4][:-1])
            usedCpu_All.append(float(words[2][:-1]) + float(words[4][:-1]))

    oneLogFile.close

###########################################################
# 绘图
###########################################################

# 可以使用subplot()快速绘制包含多个子图的图表，它的调用形式如下：
# subplot(numRows, numCols, plotNum)
ax1 = plt.subplot(4, 1, 1) # 在图中创建子图1
ax2 = plt.subplot(4, 1, 2) # 在图中创建子图2
ax3 = plt.subplot(4, 1, 3) # 在图中创建子图3
ax4 = plt.subplot(4, 1, 4) # 在图中创建子图4

plt.sca(ax1)
plt.xlabel('Time(min)')
plt.ylabel('Used Memory(MB)')
plt.plot(x, usedMem)

plt.sca(ax2)
plt.xlabel('Time(min)')
plt.ylabel('Used CPU_Usr(%)')
plt.scatter(x, usedCpu_Usr, s=1)

plt.sca(ax3)
plt.xlabel('Time(min)')
plt.ylabel('Used CPU_Sys(%)')
plt.scatter(x, usedCpu_Sys, s=1)

plt.sca(ax4)
plt.xlabel('Time(min)')
plt.ylabel('Used CPU_All(%)')
plt.scatter(x, usedCpu_All, s=1)

plt.show()

