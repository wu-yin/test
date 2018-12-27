运行cmd命令，在当前目录下打开控制台
$ javac -classpath "c:\Program Files\Apache Software Foundation\Tomcat 9.0\lib\servlet-api.jar" Ch1Servlet.java

顺利的话，在该目录下会生成一个新文件`Ch1Servlet.class`
将文件`Ch1Servlet.class`拷贝到下面的文件夹中：
> C:\Program Files\Apache Software Foundation\Tomcat 9.0\webapps\ch1\WEB-INF\classes\

然后把文件web.xml拷贝到如下路径：
> C:\Program Files\Apache Software Foundation\Tomcat 9.0\webapps\ROOT\WEB-INF\web.xml

在浏览器中输入地址：
> http://localhost:8080/ch1/Serv1