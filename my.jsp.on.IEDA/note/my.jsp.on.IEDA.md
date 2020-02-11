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
.
![](images\04.png)

右键新建一个“Module”，在IEDA中`Project`相当于是VS中的`Solution`，而`Module`相当于是VS中的`Project`
![](images\05.png)
.
![](images\06.png)
.
![](images\07.png)
.
![](images\08.png)



从资源管理器中，在web/WEB-INF下创建两个文件夹：classes和lib。

- classes用来存放编译后输出的class文件

- lib用于存放第三方jar包。
![](images\09.png)
.
![](images\10.png)
.
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

