# 学习Markdown语法
●♦►■
## 行首缩进
&emsp;&emsp;全角段首两空格缩进<br>
&ensp;&ensp;半角段首两空格缩进<br>

## 字体
**这是加粗的文字**
*这是倾斜的文字*` 或  _斜体_
***这是斜体加粗的文字***
~~这是加删除线的文字~~
<u>下划线</u> （尽量不要给文本加下划线，因为这会和超链的表现形式混淆，会被误以为是个超链。）

> 这是引用的内容
> > 这是引用的内容
> >
> > >>>>>>>> 这是引用的内容

分割线示例：
---
***

Markdown中如何插入尖括号
此时我们需要使用转义字符：&lt;&gt;
比如：&lt;尖括号中的内容&gt;

## 导出PDF时的分页符

~~~html
<div STYLE="page-break-after: always;"></div>
~~~

## 插入链接
[谷歌搜索](https://www.google.com)

## 插入图片
![imag](image/dang.png)

## 图片对齐
<div align=center>
<img src="image/dang.png" />
</div>

<div align=right>
<img src="image/dang.png" />
</div>


## 图片尺寸
<div align=right>
<img src="image/dang.png" width="100" height="100" />
</div>

## 字体、字号与颜色
<font color=red>color=red</font>
<font face="黑体">我是黑体字</font>
<font face="微软雅黑">我是微软雅黑</font>
<font face="STCAIYUN">我是华文彩云</font>
<font color=#0099ff size=7 face="黑体">color=#0099ff size=72 face="黑体"</font>
<font color=#00ffff size=72>color=#00ffff</font>
<font color=gray size=72>color=gray</font>



<table><tr><td bgcolor=orange> 背景色是 1 orange</td></tr></table>

<div style="background-color:orange; color:white">我是内容</div>





## 画图
参考：

https://blog.csdn.net/whatday/article/details/88655461

https://mermaid-js.github.io/mermaid/#/

```mermaid
graph LR;
A-->B
B-->C
C-->D
D-->A
D-.-cmt1(这是一个备注)
D-.-cmt2(这是另一个备注)
D-.-cmt3(这是还一个备注)

style cmt1 fill:#bbf, stroke:#f66, stroke-width:2px, color:#fff, stroke-dasharray:5, 5
style cmt2 fill:#f9f, stroke:#333, stroke-width:4px
style cmt3 fill:#ff9
```

图方向
TB，从上到下
TD，从上到下
BT，从下到上
RL，从右到左
LR，从左到右

节点形状
默认节点 A
文本节点 B[bname]
圆角节点 C(cname)
圆形节点 D((dname))
非对称节点 E>ename]
菱形节点 F{fname}

```mermaid
graph TB
A
B[bname]
C(cname)
D((dname))
E>ename]
F{fname}
```

连线
```mermaid
graph TB
A1-->B1
A2---B2
A3--text---B3
A4--text-->B4
A5-.-B5
A6-.->B6
A7-.text.-B7
A8-.text.->B8
A9===B9
A10==>B10
A11==text===B11
A12==text==>B12
```


```mermaid
graph LR
start("input x") --> handler("x > 0?")
handler --yes--> yes("output x")
handler --no--> start
yes --> exit("exit")
```

