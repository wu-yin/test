## 脚本、命令

### bashrc

```bash
export PS1="\[\e[34m\]\u@ \T [\w] >>>> \[\e[0m\] \n\$ "
alias ll='ls -lFh --time-style=long-iso'
```

### grep
```bash
# -n：显示行号
# -r：递归查找当前目录
# -i：忽略大小写（ignore case）。
# -w：全字匹配，grep –w "abc" 或者是 grep "\<abc\>"

# 返回结果带颜色
$ grep --color "text" test.json

# 排除某个文件、某类型文件
$ grep --exclude=exclude.java "text" .
$ grep --exclude=*.{java,c} "text" .


# 指定文件类型查找
$ find -type f -name '*.java' | xargs grep "text"
```
正则表达式

|       |                                                              |
| ----- | ------------------------------------------------------------ |
| ^word | 搜寻以word开头的行。<br/>例如：搜寻以#开头的脚本注释行<br/>grep –n ‘^#’ regular.txt |
| word$ | 搜寻以word结束的行<br/>例如，搜寻以‘.’结束的行<br/>grep –n ‘.$’ regular.txt |
| .     | 匹配任意一个字符。<br/>例如：grep –n ‘e.e’ regular.txt<br/>匹配e和e之间有任意一个字符，可以匹配eee，eae，eve，但是不匹配ee。 |

### tar
```bash
$ tar -cjvf  filename.tar.bz2    folder_name  # 压缩
$ tar -xvf   filename.tar.bz2  # 解压缩
```



## Linux Toy

### Markdown编辑软件：Typora

官网：https://www.typora.io/

```bash
# or run:
# sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys BA300B7755AFCFAE
wget -qO - https://typora.io/linux/public-key.asc | sudo apt-key add -

# add Typora's repository
sudo add-apt-repository 'deb https://typora.io/linux ./'
sudo apt-get update

# install typora
sudo apt-get install typora
```

### 录屏软件：Kazam

```bash
$ sudo apt-get install kazam
```

