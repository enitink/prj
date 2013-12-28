

<%@ page contentType="text/html; charset=iso-8859-1" language="java" import="java.sql.*" errorPage="" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<%@page language="java" import="java.util.*" %>
<%@page language="java" import="java.lang.*" %>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<title>Untitled Document</title>
<style type="text/css">
<!--
body {
	background-color: #CCCCCC;
     }
-->
</style></head>

<body>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<p><strong>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Select the Officer by clicking the Radio Button</strong></p>
 <%! ResultSet rs=null;%>
 <%  String connectionURL = "jdbc:postgresql://localhost:5432/NIC";

    Connection connection=null;
    try {
       // Load the database driver
      Class.forName("org.postgresql.Driver");
      // Get a Conneorg.postgresql.Driverction to the database
      connection = DriverManager.getConnection(connectionURL, "postgres1", "training10");
      //Add the data into the database
      String sql = "select * from employee";
      Statement s = connection.createStatement();
      s.executeQuery (sql);
      rs = s.getResultSet();
       }
      catch(Exception e){
      System.out.println("Exception is ;"+e);
      }
    %>
        <!-- Template text -->
<table width="550" border="1" align="center">
<tr>
<td bgcolor="#006633">
<div align="center">
<font size="4" color="#FFFFFF">
<b>Select an employee</b>
</font>
</div>
</td>
</tr>
<tr>
<td>
<p>&nbsp;</p>
<p>&nbsp;</p>
<p align="center"><b>Employees for NDC </b></p>
<table width="290" border="0" align="center">
    <tr>
    <th>Employee Code</th>
    <th>Employee Name</th>
    <th>Email ID</th>
    </tr>
         <% 
    try
     {                  while(rs.next())
                            {
          %>
      
<!-- JSP Expressions used within template text -->

    
             <tr>
                    <td width="80"><%= rs.getInt("emp_code") %><input type="radio" name="e1" value="" /></td>
           
           
                   <td width="200"><%= rs.getString("emp_name") %></td>
         
            
        
                   <td width="70"><%= rs.getString("email_id") %></td>
      </tr>



<%} }catch(Exception e)
        {System.out.println(e.toString());} %>


</td>
</tr>
</table>
<table>
<tr>
<td>
<p>&nbsp;</p>
<p align="center"> <a href="admin-select.jsp">Back</a></p>
<p align="right"> <a href="give-ndc.jsp">Next</a></p>
</td>
</tr>
</table>
</body>
</html>
