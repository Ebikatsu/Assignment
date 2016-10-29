import java.io.*;
import java.sql.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class Report5 extends HttpServlet
{
	public void doPost(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException
	{
		Connection con;
		PrintWriter out;
		ResultSet rs;
		Statement stmt;
		String pwd = "",
		url        = "jdbc:postgresql://10.210.128.120:5432/syspj9",
		usr        = "syspj9";
		try
		{
			req.setCharacterEncoding("utf-8");
			res.setContentType("text/html; charset=utf-8");
			out = res.getWriter();
			Class.forName("org.postgresql.Driver");
			con = DriverManager.getConnection(url, usr, pwd);
			stmt = con.createStatement();
			out.print(" <!DOCTYPE html> <html> <head> <title>システム創成プロジェクトグループ09顧客用ウェブページ</title> <meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\"> </head> <body> <table border=\"1\" width=\"100%\" height=\"100\"> <tr> <td> <center> <font size=\"7\">商品一覧</font> </center> </td> </tr> </table> <table height=\"50\"> </table> <table border=\"1\" width=\"100%\" height=\"100%\"> <tr height=\"50\"> <td width=\"20%\"> <center>商品コード</center> </td> <td width=\"20%\"> <center>商品名 </center> </td> <td width=\"20%\"> <center>価格 </center> </td> <td width=\"20%\"> <center>在庫数 </center> </td> <td width=\"20%\"> <center>購入する </center> </td> </tr>");
			rs = stmt.executeQuery("SELECT * FROM 商品 WHERE カテゴリー='"+req.getParameter("カテゴリー")+"';");
			while(rs.next())out.print(" <tr height=\"50\"> <td> <center>"+rs.getInt("商品コード")+" </center> </td> <td> <center>"+rs.getString("商品名")+" </center> </td> <td> <center>"+rs.getInt("価格")+" </center> </td> <td> <center>"+rs.getInt("在庫数")+" </center> </td> <td> <center> <form method=\"post\" action=\"http://10.210.128.120:8080/~syspj9/Report6\"> <input name=\"商品コード\" type=\"hidden\" value=\""+rs.getInt("商品コード")+"\"> <input type=\"submit\" value=\"購入する\"> </form> </center> </td>");
			out.print("</table></body></html>");
			rs.close();
			stmt.close();
			con.close();
		}
		catch (Exception e)
		{
			res.sendRedirect("forguest_error.html?exception="+e.toString());
		}
		return;
	}
}
