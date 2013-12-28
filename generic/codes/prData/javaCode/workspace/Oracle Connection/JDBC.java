/*
 * Created on Jun 7, 2006
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */

/**
 * @author Nitin
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */

import java.sql.*;

public class JDBC
{
	public static void main(String[] args)  throws Exception
	{
		Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
		Connection Con = DriverManager.getConnection("jdbc:odbc:oracle","scott","tiger");
		Statement Stmt = Con.createStatement();
		ResultSet Rs = Stmt.executeQuery("select ename from emp");
		int i = 0;
		while(Rs.next())
		{
			++i;
			System.out.println(Rs.getString(1));
		}
		System.out.println(i + " Rows Selected");
	}
}
