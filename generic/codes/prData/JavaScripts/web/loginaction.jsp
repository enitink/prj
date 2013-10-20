<%-- 
    Document   : loginaction
    Created on : Feb 15, 2010, 7:42:56 AM
    Author     : swati
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">
   <%@ page language="java" import="java.sql.*"%>

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
      <%
      try {
 	    Class.forName("org.postgresql.Driver");
 	    	    Connection conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/login", "postgres1", "swati");

            Statement stmt = conn.createStatement();
            ResultSet rs;
			
            rs = stmt.executeQuery("SELECT * FROM logintable");



            while(rs.next())
            {
                out.println("Welcome");
            }
            }catch(Exception e)
                    {}
            %>
    </body>
</html>
