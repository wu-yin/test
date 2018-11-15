# git笔记

## 使用GitHub

## 常用命令

- 增加文件，并推送到远程
~~~ bash
$ git add file.txt
$ git commit -m "add file.txt"
$ git push origin master
~~~

- 删除文件、文件夹
~~~ bash
$ git rm test.txt
$ git commit -m "remove test.txt"
~~~

- 放弃某个文件的本地修改，恢复成库里的版本
~~~ bash
$ git checkout -- file.txt
~~~
