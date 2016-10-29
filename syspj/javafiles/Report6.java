import java.io.*;
import java.sql.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class Report6 extends HttpServlet
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
			con = DriverManager.getConnection(url,usr,pwd);
			stmt = con.createStatement();
			rs = stmt.executeQuery("SELECT * FROM 商品 WHERE 商品コード="+req.getParameter("商品コード")+";");
			rs.next();
			out.print(" <!DOCTYPE html> <html> <head> <title>システム創成プロジェクトグループ09顧客用ウェブページ</title> <meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\"> </head> <body> <table border=\"1\" width=\"100%\" height=\"100\"> <tr> <td> <center> <font size=\"7\">以下の商品を注文しますか？</font> </center> </td> </tr> </table> <table height=\"50\"> </table> <form method=\"post\" action=\"http://10.210.128.120:8080/~syspj9/Report7\"> <table border=\"1\" width=\"100%\" height=\"100%\"> <tr height=\"50\"> <td width=\"20%\"> <center>商品コード</center> </td> <td width=\"20%\"> <center>商品名</center> </td> <td width=\"20%\"> <center>価格</center> </td> <td width=\"20%\"> <center>在庫数</center> </td> <td width=\"20%\"> <center>注文数</center> </td> </tr> <tr height=\"50\"> <td width=\"20%\"> <center> "+rs.getInt("商品コード")+" </center> </td> <td width=\"20%\"> <center>"+rs.getString("商品名")+"</center> </td> <td width=\"20%\"> <center>"+rs.getInt("価格")+"</center> </td> <td width=\"20%\"> <center>"+rs.getInt("在庫数")+"</center> </td> <td width=\"20%\"> <center> <input name=\"注文数\" type=\"text\" size=\"5\"> </center> </td> </tr> </table> <br> <input name=\"商品コード\" value=\""+rs.getInt("商品コード")+"\" type=\"hidden\"> <input type=\"submit\" value=\"注文\"> </form> <br> <form method=\"post\" action=\"http://10.210.128.120:8080/~syspj9/Report3\"> <input type=\"submit\" value=\"キャンセル\"> </form> </body> </html>");
			rs.close();
			stmt.close();
			con.close();
		}
		catch(Exception e)
		{
			res.sendRedirect("forguest_error.html?Exception="+e.toString());
		}
		return;
	}
}
