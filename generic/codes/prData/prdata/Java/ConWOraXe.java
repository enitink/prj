import java.sql.*;
import java.io.*;

public class ConWOraXe 
{
    public static void main(String [] args) throws Exception
    {
        Class.forName("Sun.jdbc.odbc.jdbcodbcdriver");
        Connection con = DriverManager.getConnection("jdbc:odbc:XE", "hr", "hr");
        Statement stmt = con.createStatement();
        ResultSet rs = stmt.executeQuery("Select FIRST_NAME from employees where MANAGER_ID > 150");
        
        while(rs.next())
        {
            System.out.println(rs.getInt(1));
        }
    }
}