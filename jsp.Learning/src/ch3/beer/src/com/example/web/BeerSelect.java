/*
 * javac -classpath "c:/apache-tomcat/lib/servlet-api.jar;classes;." -d classes src/com/example/web/BeerSelect.java
 */
package com.example.web;

import com.example.model.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.util.*;

public class BeerSelect extends HttpServlet {

	public void doPost(HttpServletRequest request,
			HttpServletResponse response)
			throws IOException, ServletException {

		String c = request.getParameter("color");
		BeerExpert be = new BeerExpert();
		List result = be.getBrands(c);

		// V3版删除
//		response.setContentType("text/html");
//		PrintWriter out = response.getWriter();
//		out.println("Beer Selection Advice<br>");

		request.setAttribute("styles", result);
		
		RequestDispatcher view = 
				request.getRequestDispatcher("result.jsp");
		
		view.forward(request, response);

		// V3版删除
//		Iterator it = result.iterator();
//		while(it.hasNext()) {
//			out.print("<br>try: " + it.next());
//		}
	}
}