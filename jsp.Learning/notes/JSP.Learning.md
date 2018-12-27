Servlet & JSP学习笔记
Windows 7
Java 11
Tomcat 9

## 安装开发环境
1. 安装JDK
[下载JDK](https://www.oracle.com/technetwork/java/javase/downloads/index.html)
jdk-11.0.1_windows-x64_bin.exe
新增环境变量`JAVA_HOME`，变量值`C:\Program Files\Java\jdk-11.0.1;`
编辑环境变量`PATH`，添加变量值：`%JAVA_HOME%\bin;%JAVA_HOME%\jre\bin;`
新建`CLASSPATH`变量，变量值：`.;%JAVA_HOME%\lib;%JAVA_HOME%\lib\tools.jar;`，（注意最前面有一点）

2. 安装Tomcat
[下载Tomcat](https://tomcat.apache.org/download-90.cgi)
双击`apache-tomcat-9.0.14.exe`安装
新建`TOMCAT_HOME`变量，变量值：`C:\Program Files\Apache Software Foundation\Tomcat 9.0`

http://localhost:8080/
http://127.0.0.1:8080/
![](images/01.png)

## 第一个Servlet程序
新建一个Java源文件：Ch1Servlet.java，文件内容：
~~~ java
import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;

public class Ch1Servlet extends HttpServlet {
	public void doGet(HttpServletRequest reque,
			HttpServletResponse response)
			throws IOException {
		PrintWriter out = response.getWriter();
		java.util.Date today = new java.util.Date();
		out.println("<html>" + 
			"<body>" +
			"<h1 align=center>HF\'s Chapter1 Servlet</h1>"
			+ "<br>" + today + "</body>" + "</html>");
	}
}
~~~

运行cmd命令，在当前目录下打开控制台
~~~ bash
$ javac -classpath "c:\Program Files\Apache Software Foundation\Tomcat 9.0\lib\servlet-api.jar" Ch1Servlet.java
~~~
顺利的话，在该目录下会生成一个新文件`Ch1Servlet.class`
将文件`Ch1Servlet.class`拷贝到下面的文件夹中：
> C:\Program Files\Apache Software Foundation\Tomcat 9.0\webapps\ch1\WEB-INF\classes\

然后新建文件`web.xml`：
> C:\Program Files\Apache Software Foundation\Tomcat 9.0\webapps\ch1\WEB-INF\web.xml

文件`web.xml`的代码：
~~~ xml
<?xml version="1.0" encoding="UTF-8"?>

<web-app xmlns="http://java.sun.com/xml/ns/j2ee"
    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    xsi:schemaLocation="http://java.sun.com/xml/ns/j2ee/web-app_2_4.xsd"
    version="2.4">

	<servlet>
		<servlet-name>Chapter1 Servlet</servlet-name>
		<servlet-class>Ch1Servlet</servlet-class>
	</servlet>
	
	<servlet-mapping>
		<servlet-name>Chapter1 Servlet</servlet-name>
		<url-pattern>/Serv1</url-pattern>
	</servlet-mapping>

</web-app>
~~~
整个目录结构如图：
![](images/06.png)

此时保证Tomcat服务器是在运行中的，如果已经启动，不用重新启动。
![](images/03.png)
在浏览器中输入地址：
> http://localhost:8080/ch1/Serv1

此时应看到程序运行结果
![](images/04.png)

## 备忘
* 目录`Apach_home/htdocs`是服务器上所有web应用的根目录。

* JSP中的MVC分工
![](images/05.png)
