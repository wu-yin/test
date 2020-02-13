## 开发环境

- 安装：jdk-8u31-windows-x64.exe
- 安装：apache-tomcat-8.5.45-windows-x64.zip
- 安装：ideaIU-2019.3.2

## 新建一个IEDA程序

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



## 例1：Ch1Servlet

这个是《Head First Servlets & JSP》书中第一章的实例。

接着上个例子，新建一个java源文件：DateStr.java
![](images\21.png)
.
![](images\22.png)

```java
import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;

public class DateStr extends HttpServlet {
	public void doGet(HttpServletRequest reque,
					  HttpServletResponse response)
			throws IOException {
		PrintWriter out = response.getWriter();
		java.util.Date today = new java.util.Date();
		out.println("<html>" +
				"<body>" +
				"<h1 align=center>HF's Chapter1 Servlet</h1>"
				+ "<br>" + today + "</body>" + "</html>");
	}
}
```

然后编辑web.xml文件
![](images\23.png)

```xml
<?xml version="1.0" encoding="UTF-8"?>
<web-app xmlns="http://xmlns.jcp.org/xml/ns/javaee"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://xmlns.jcp.org/xml/ns/javaee http://xmlns.jcp.org/xml/ns/javaee/web-app_4_0.xsd"
         version="4.0">

	<servlet>
		<servlet-name>Chapter1 Servlet</servlet-name>
		<servlet-class>DateStr</servlet-class>
	</servlet>

	<servlet-mapping>
		<servlet-name>Chapter1 Servlet</servlet-name>
		<url-pattern>/Serv1</url-pattern>
	</servlet-mapping>

</web-app>
```

此时再运行项目，输入不同的URL就可以访问不同的项目
![](images\24.png)
.
![](images\25.png)





## 附录：IntelliJ IDEA中的一些说明

### Project 和 Module
IntelliJ IDEA中的`Project` 和 `Module`，相当于VS中的`Solution`和`Project`，相当于Eclipse中的`Workspace`和`Project`。
在 IntelliJ IDEA 中Project是最顶级的结构单元，然后就是Module，一个Project可以有多个Module。目前，主流的大型项目结构基本都是多Module的结构，这类项目一般是按功能划分的，比如：user-core-module、user-facade-module和user-hessian-module等等，模块之间彼此可以相互依赖。

### 文件和文件夹图标的说明
**文件的颜色：**
绿色：已经加入控制暂未提交
红色：未加入版本控制
蓝色：加入，已提交，有改动
白色：加入，已提交，无改动
灰色：版本控制已忽略文件

**文件夹图标：**
![](images\20.png)
