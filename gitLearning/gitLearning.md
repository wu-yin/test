# git笔记

## 使用GitHub

参考了[廖雪峰的Git教程](https://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000)

* 第1步：在本机创建SSH Key。
~~~ bash
$ ssh-keygen -t rsa -C "youremail@example.com"
~~~
你需要把邮件地址换成你自己的邮件地址，然后一路回车，使用默认值即可。
如果一切顺利的话，可以在用户主目录（`C:\Users\Wu Yin`）里找到.ssh目录，里面有`id_rsa`和`id_rsa.pub`两个文件，这两个就是SSH Key的秘钥对，`id_rsa`是私钥，不能泄露出去，`id_rsa.pub`是公钥，可以放心地告诉任何人。
* 第2步：
登陆GitHub，打开“Account settings”，“SSH Keys”页面：
然后，点“Add SSH Key”，填上任意Title，在Key文本框里粘贴id_rsa.pub文件的内容：
![](image\0.png)
点`Add Key`，你就应该看到已经添加的Key：
![](image\1.png)
为什么GitHub需要SSH Key呢？因为GitHub需要识别出你推送的提交确实是你推送的，而不是别人冒充的，而Git支持SSH协议，所以，GitHub只要知道了你的公钥，就可以确认只有你自己才能推送。
当然，GitHub允许你添加多个Key。假定你有若干电脑，你一会儿在公司提交，一会儿在家里提交，只要把每台电脑的Key都添加到GitHub，就可以在每台电脑上往GitHub推送了。

## 常用命令

* 从GitHub远程库克隆到本地
  从任何电脑都可以克隆，GitHub的免费账号不提供私有库功能。
~~~ bash
$ git clone https://github.com/wu-yin/test.git
~~~

* 在本地库查看远程路径
~~~ bash
$ git remote -v
~~~

* 增加文件，并推送到远程
~~~ bash
$ git add file.txt
$ git commit -m "add file.txt"
$ git push origin master
~~~

* 修改文件后提交，并推送到远程
~~~ bash
$ git add file.txt
$ git commit -m "modify file.txt"
$ git push
~~~

* 删除文件、文件夹
~~~ bash
$ git rm test.txt
$ git commit -m "remove test.txt"
~~~

* 放弃某个文件的本地修改，恢复成库里的版本
~~~ bash
$ git checkout -- file.txt
~~~

* 文件更名
~~~ bash
$ git mv filename.txt newFileName.txt
$ git commit -m "renamed filename.txt"
$ git push origin master
~~~