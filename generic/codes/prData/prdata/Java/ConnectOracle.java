import java.sql.*;
import java.io.*;

class ConnectOracle
{
    public static void main(String [] args) throws Exception
    {
        Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
        Connection con = DriverManager.getConnection("jdbc:odbc:Oracle","scott","tiger");
        Statement Stmt = con.createStatement();
        ResultSet rs = Stmt.executeQuery("Select * from Emp");
        while(rs.next())
        {
            System.out.println(rs.getInt(1) + "\t" + rs.getString(2));
        }
    }
}