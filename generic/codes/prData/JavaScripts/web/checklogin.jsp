
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">
 <%@ page language="java" import="java.sql.*"%>
 <%@ page language="java" import="java.lang.*"%>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Checking Login</title>
    </head>
    <body>
        <%
        try
                     {
                       Class.forName("org.postgresql.Driver");
                       Connection conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/login", "postgres1", "training10");

                       Statement stmt = conn.createStatement();
                       ResultSet rs;
                       String u1=new String();
                       String u2=new String();
                         boolean ck=false;
       			
                       rs = stmt.executeQuery("SELECT * FROM logintable");  
                       u1=request.getParameter("user");
          
                     while ( rs.next())
                     {  
                       
                             {      u2=rs.getString("loginid");
                                    if(u2.equalsIgnoreCase(u1))
                                    {
                                          ck=true;
                                         
                                        
                                                                             }
                             }
                     }  
                            
                             
                                
                     }
              catch(Exception e) 
                 {}
                 
        %>
  <a href="admin-select.jsp">Next</a>
    </body>
</html>
