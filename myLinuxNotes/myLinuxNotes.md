## 脚本

### bashrc

```bash
export PS1="\[\e[34m\]\u@ \T [\w] >>>> \[\e[0m\] \n\$ "
alias ll='ls -lFh --time-style=long-iso'
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

