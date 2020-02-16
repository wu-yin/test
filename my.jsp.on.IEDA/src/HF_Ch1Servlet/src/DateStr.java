import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;

public class DateStr extends HttpServlet {

	public void doGet(HttpServletRequest reque, HttpServletResponse response)
			throws IOException {

		PrintWriter out = response.getWriter();
		java.util.Date today = new java.util.Date();

		out.println("<html>" + "<body>"
				+ "<h1 align=center>HF's Chapter1 Servlet</h1>"
				+ "<br>" + today + "</body>" + "</html>");
	}

}
