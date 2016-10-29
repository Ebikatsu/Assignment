import java.io.*;
import java.sql.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class Report7 extends HttpServlet
{
	public void doPost(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException
	{
		Connection con;
		int customerID,
		orderNumber,
		orderQuantity,
		price,
		productCode,
		stock;
		PrintWriter out;
		ResultSet rs;
		Statement stmt;
		String category,
		productName;
		try
		{
			req.setCharacterEncoding("utf-8");
			res.setContentType("text/html; charset=utf-8");
			out = res.getWriter();
			Class.forName("org.postgresql.Driver");
			con = DriverManager.getConnection("jdbc:postgresql://10.210.128.120:5432/syspj9", "syspj9", "");
			stmt = con.createStatement();
			rs = stmt.executeQuery("SELECT id FROM 顧客 WHERE ipアドレス='"+req.getRemoteAddr()+"';");
			rs.next();
			customerID = rs.getInt("id");
			rs = stmt.executeQuery("SELECT * FROM 注文情報;");
			if(rs.next())
			{
				rs = stmt.executeQuery("SELECT MAX(注文番号) FROM 注文情報;");
				rs.next();
				orderNumber = rs.getInt("max")+1;
			}
			else orderNumber=0;
			rs = stmt.executeQuery("SELECT * FROM 商品 WHERE 商品コード="+req.getParameter("商品コード")+";");
			rs.next();
			category = rs.getString("カテゴリー");
			orderQuantity = Integer.parseInt(req.getParameter("注文数"));
			productCode = rs.getInt("商品コード");
			productName = rs.getString("商品名");
			price = rs.getInt("価格");
			stock = rs.getInt("在庫数");
			if(orderQuantity>stock)
			{
				res.sendRedirect("forguest_error.html");
				return;
			}
			stmt.executeUpdate("INSERT INTO 注文情報 VALUES("+orderNumber+","+customerID+","+productCode+","+orderQuantity+");");
			stmt.executeUpdate("UPDATE 商品 SET 在庫数="+(stock-orderQuantity)+" WHERE 商品コード="+productCode+";");
			out.print("<!DOCTYPE html> <html> <head> <title>システム創成プロジェクトグループ09顧客用ウェブページ</title> <meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\"> </head> <body> <table border=\"1\" width=\"100%\" height=\"100\"> <tr> <td> <center> <font size=\"7\">以下の商品を注文しました。</font> </center> </td> </tr> </table> <table height=\"50\"> </table> <table border=\"1\" width=\"100%\" height=\"100%\" style=\"table-layout:fixed;\"> <tr height=\"50\"> <td> <center>商品コード</center> </td> <td> <center>商品名</center> </td> <td> <center>価格</center> </td> <td> <center>在庫数</center> </td> <td> <center>カテゴリー</center> </td> <td> <center>注文数</center> </td> <td> <center>総額</center> </td> </tr> <tr height=\"50\"> <td> <center>"+productCode+"</center> </td> <td> <center>"+productName+"</center> </td> <td> <center>"+price+"<center> </td> <td> <center>"+stock+"</center> </td> <td> <center>"+category+"</center> </td> <td> <center>"+orderQuantity+"</center> </td> <td> <center>"+(orderQuantity*price)+"</center> </td> </tr> </table> <br> <form method=\"post\" action=\"http://10.210.128.120:8080/~syspj9/Report3\"> <input type=\"submit\" value=\"カテゴリー一覧に戻る\"> </form> </body> </html>");
			rs.close();
			stmt.close();
			con.close();
		}
		catch(Exception e)
		{
			res.sendRedirect("forguest_error.html?Exception="+e.toString());
		}
	}
}
