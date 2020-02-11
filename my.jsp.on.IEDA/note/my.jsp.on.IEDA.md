## 开发环境

- 安装：jdk-8u31-windows-x64.exe
- 安装：apache-tomcat-8.5.45-windows-x64.zip
- 安装：ideaIU-2019.3.2

## 新建第一个IEDA程序

启动IntelliJ IDEA，选择“Create New Project”
![](images\01.png)
.
![](images\02.png)
.
![](images\03.png)
给新项目起名：firstProject
![](images\04.png)

右键新建一个“Module”。在IEDA中`Project`相当于是VS中的`Solution`，而`Module`相当于是VS中的`Project`
![](images\05.png)
.
![](images\06.png)
给新建的Module起名为：dateModule
![](images\07.png)
现在工程的目录是这样的。
![](images\08.png)

从资源管理器中，在web/WEB-INF下创建两个文件夹：classes和lib。
- classes用来存放编译后输出的class文件
- lib用于存放第三方jar包。
![](images\09.png)
.打开“Project Structure”菜单，设置如下路径
![](images\10.png)
在“Dependencies”选项卡继续设置如下路径：
![](images\11.png)
.
![](images\12.png)
.
![](images\13.png)

配置Tomcat容器
![](images\14.png)
.
![](images\15.png)
.
![](images\16.png)
.
编辑index.jsp文件
![](images\17.png)

```jsp
<%--
  Created by IntelliJ IDEA.
  User: Administrator
  Date: 2020/2/11
  Time: 13:50
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
  <head>
    <title>$Title$</title>
  </head>
  <body>
  Hello world!
  你好！
  </body>
</html>
```
点击运行，在浏览器中就可以看到运行结果了。
![](images\18.png)
.
![](images\19.png)
