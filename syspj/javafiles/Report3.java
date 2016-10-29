import java.io.*;
import java.sql.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class Report3 extends HttpServlet
{
	public void doPost(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException
	{
		Connection con;
		PrintWriter out;
		ResultSet rs;
		Statement stmt;
		String pwd        = "",
		url               = "jdbc:postgresql://10.210.128.120:5432/syspj9",
		usr               = "syspj9";
		try
		{
			res.setContentType("text/html; charset=utf-8");
			out = res.getWriter();
			Class.forName("org.postgresql.Driver");
			con  = DriverManager.getConnection(url, usr, pwd);
			stmt = con.createStatement();
			out.print("<!DOCTYPE html> <html> <head> <title>システム創成プロジェクトグループ09顧客用ウェブページ</title> <meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\"> </head> <body> <table border=\"1\" width=\"100%\" height=\"100\"> <tr> <td> <center> <font size=\"7\">カテゴリー一覧</font> </center> </td> </tr> </table> <table width=\"100%\" height=\"100%\"> <tr> <td> <form method=\"post\" action=\"http://10.210.128.120:8080/~syspj9/Report5\">");
			rs = stmt.executeQuery("SELECT DISTINCT カテゴリー FROM 商品;");
			while(rs.next())out.print("<input name=\"カテゴリー\" type=\"submit\" value=\""+rs.getString("カテゴリー")+"\"><br>");
			out.print("</form> </td> <td> <div align=\"right\"> <form method=\"post\" action=\"http://10.210.128.120:8080/~syspj9/Report4\"> <input type=\"submit\" value=\"ログアウト\"> </form> </div> </td> </tr> </table> </body> </html>");
			rs.close();
			stmt.close();
			con.close();
			return;
		}
		catch (Exception e)
		{
			res.sendRedirect("forguest_error.html");
		}
		return;
	}
}
