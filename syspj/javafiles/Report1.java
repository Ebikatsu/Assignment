import java.io.*;
import java.sql.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class Report1 extends HttpServlet
{
	public void doPost(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException
	{
		int id                  = 0;
		long creditcardNumber   = 0,
		enteredCreditcardNumber = 0;
		Connection con;
		PrintWriter out;
		ResultSet rs;
		Statement stmt;
		String pwd        = "";
		try{
			req.setCharacterEncoding("utf-8");
			res.setContentType("text/html;charset=utf-8");
			out = res.getWriter();
			Class.forName("org.postgresql.Driver");
			con = DriverManager.getConnection("jdbc:postgresql://10.210.128.120:5432/syspj9", "syspj9", "");
			stmt = con.createStatement();
			id                      = Integer.parseInt(req.getParameter("id"));
			enteredCreditcardNumber = Long.parseLong(req.getParameter("CreditCardNumber"));
			rs = stmt.executeQuery("SELECT クレジットカード番号 FROM 顧客 WHERE id="+id+";");
			rs.next();
			creditcardNumber = rs.getLong("クレジットカード番号");
			stmt.executeUpdate("UPDATE 顧客 SET ipアドレス='' WHERE ipアドレス='"+req.getRemoteAddr()+"';");
			if(enteredCreditcardNumber == creditcardNumber)
			{
				stmt.executeUpdate("UPDATE 顧客 SET ipアドレス='"+req.getRemoteAddr()+"' WHERE id="+id+";");
				out.print("<!DOCTYPE html> <html> <head> <title>システム創成プロジェクトグループ09顧客用ウェブページ</title> <meta http-equiv=\"Content-Type\" content=\"text/html;charset=UTF-8\"> </head> <body> <table border=\"1\" width=\"100%\" height=\"100\"> <tr> <td> <center> <font size=\"7\">カテゴリー一覧</font> </center> </td> </tr> </table> <table width=\"100%\" height=\"100%\"> <tr> <td> <form method=\"post\" action=\"http://10.210.128.120:8080/~syspj9/Report5\">");
				rs = stmt.executeQuery("SELECT DISTINCT カテゴリー FROM 商品;");
				while(rs.next())out.print("<input name=\"カテゴリー\" type=\"submit\" value=\""+rs.getString("カテゴリー")+"\"><br>");
				out.print("</form> </td> <td> <div align=\"right\"> <form method=\"post\" action=\"http://10.210.128.120:8080/~syspj9/Report4\"> <input type=\"submit\" value=\"ログアウト\"> </form> </div> </td> </tr> </table> </body> </html>");
				return;
			}
			else res.sendRedirect("forguest_error.html");
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
