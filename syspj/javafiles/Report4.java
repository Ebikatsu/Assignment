import java.io.*;
import java.sql.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class Report4 extends HttpServlet
{
	public void doPost(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException
	{
		Connection con;
		PrintWriter out;
		Statement stmt;
		String pwd        = "",
		url        = "jdbc:postgresql://10.210.128.120:5432/syspj9",
		usr        = "syspj9";
		try{
			res.setContentType("text/html; charset=utf-8");
			out = res.getWriter();
			Class.forName("org.postgresql.Driver");
			con  = DriverManager.getConnection(url, usr, pwd);
			stmt = con.createStatement();
			stmt.executeUpdate("UPDATE 顧客 SET ipアドレス='' WHERE ipアドレス='"+req.getRemoteAddr()+"';");
			stmt.close();
			con.close();
			res.sendRedirect("forguest_home.html");
			return;
		}
		catch (Exception e)
		{
			res.sendRedirect("forguest_error.html?exception="+e.toString());
		}
		return;
	}
}
