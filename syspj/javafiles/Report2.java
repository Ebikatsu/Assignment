import java.io.*;
import java.sql.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class Report2 extends HttpServlet
{
	public void doPost(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException
	{
		int id                  = 0;
		long creditcardNumber = 0;
		Connection con;
		PrintWriter out;
		ResultSet rs;
		Statement stmt;
		String address = "", 
		name           = "",
		pwd            = "",
		url            = "jdbc:postgresql://10.210.128.120:5432/syspj9",
		usr            = "syspj9";
		try
		{
			req.setCharacterEncoding("utf-8");
			address = req.getParameter("address");
			creditcardNumber = Long.parseLong(req.getParameter("creditcardnumber"));
			name = req.getParameter("name");
			res.setContentType("text/html; charset=utf-8");
                        out = res.getWriter();
			Class.forName("org.postgresql.Driver");
			con  = DriverManager.getConnection(url, usr, pwd);
			stmt = con.createStatement();
			rs = stmt.executeQuery("SELECT * FROM 顧客");
			if(rs.next())
			{
				rs = stmt.executeQuery("SELECT MAX(id) FROM 顧客");
				rs.next();
				id = rs.getInt("max")+1;
			}
			stmt.executeUpdate("INSERT INTO 顧客 VALUES("+id+",'"+name+"','"+address+"',"+creditcardNumber+",'"+req.getRemoteAddr()+"');");
			out.println("<!DOCTYPE html> <html> <head> <title>システム創成プロジェクトグループ09顧客用ウェブページ</title> <meta http-equiv=\"Content-Type\" content=\"text/html;charset=UTF-8\"> </head> <body> <table border=\"1\" width=\"100%\" height=\"100\"> <tr> <td> <center> <font size=\"7\">登録完了しました。</font> </center> </td> </tr> </table> <center> <table width=\"200\" height=\"100\"> <tr> <td> <center> <font size=\"5\">ID:"+id+"</font> </center> </td> </tr> <tr> <td> <center> <form method=\"post\" action=\"http://10.210.128.120:8080/~syspj9/Report3\"> <input type=\"submit\" value=\"商品を探す\"> </form> </center> </td> </tr> </table> </center> </body> </html>");
			rs.close();
			stmt.close();
			con.close();
		}
		catch (Exception e)
		{
			res.sendRedirect("forguest_error.html");
		}
		return;
	}
}
