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
            Class.forName("org.postgresql.Driver");
                       Connection conn = DriverManager.getConnection("jdbc:postgresql://localhost/trying","nitin", "nitin");

                       Statement stmt = conn.createStatement();
                       ResultSet rs;
                       String u1=new String();
                       String u2=new String();
                         boolean ck=false;
                  
                       rs=stmt.executeQuery("select * from products"); 
                       u1=request.getParameter("user");
         		while ( rs.next())
                     { 
                       {  
                           u2=rs.getString(1);
                            if(u2.equals(u1))
                             {
                              ck=false;
                            }
				else{
					ck=true;
				}
                       }
                     }                            
        %>
	u1 = <%= u1 %>
	ck = <%= ck %>
    </body>
</html>
