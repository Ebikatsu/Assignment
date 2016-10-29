import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class Report8 extends HttpServlet{
    public void doPost(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException {

	
	try{     
	    // ドライバをロード
	    Class.forName("org.postgresql.Driver");
	    
	    // データベースのURL (XXXをデータベース名に変える)
	    String url = "jdbc:postgresql://10.210.128.120:5432/syspj9";
	    // ユーザ (XXXをグループ名に変える)
	    String usr = "syspj9";
	    // パスワード (空でよい)
	    String pwd = "";
	    
	    // データベースサーバへの接続
	    Connection con = DriverManager.getConnection(url, usr, pwd);
	    
	    // Statementオブジェクトを生成
	    Statement stmt = con.createStatement();
	    
	    // データベースにデータ問い合わせ
	    String sql = "SELECT * FROM 注文情報;";
	    
	    // ResultSetオブジェクトの生成
	    // SELECT文の処理
	    ResultSet rs = stmt.executeQuery(sql);
	    
	    
	    
	     req.setCharacterEncoding("utf-8");


	    res.setContentType("text/html; charset=utf-8");
	    PrintWriter out = res.getWriter();

	    out.println("<html>");
	    out.println("<head>");
	    out.println("<title>注文情報一覧</title>");
	    out.println("<meta http-equiv=\"Content-Type\" content=\"text/html;charset=UTF-8\">");
	    out.println("</head>");
	    out.println("<body>");
	    out.println("<h1>注文情報一覧</h1>");

	    out.println("<form method=\"post\" action=\"http://10.210.128.120:8080/~syspj9/Report9\">");

	    out.println("<table border=\"1\" cellpadding=\"5\" cellspacing=\"0\">");
	    out.println("<th>配送</th>");
	    out.println("<th>注文番号</th>");
	    out.println("<th>id</th>");
	    out.println("<th>商品コード</th>");
	    out.println("<th>個数</th>");
	    
	    // 問い合わせ結果を出力
	    while(rs.next()){
		out.println("<tr>");
		// 検索された行の各列のデータを取得
		int number = rs.getInt("注文番号");
		int id = rs.getInt("顧客のid");
		int cord = rs.getInt("商品コード");
		int count = rs.getInt("個数");
		out.println("<td><input type=\"checkbox\" name=\"getnumber\" value=\""+number+"\"></td>");
		out.println("<td>"+number+"</td>");
		out.println("<td>"+id+"</td>");
		out.println("<td>"+cord+"</td>");
		out.println("<td>"+count+"</td>");	
		out.println("</tr>");
	    }
	    out.println("</table>");

	    out.println("<br>");
	    out.println("<input type=\"submit\" value=\"注文情報へ\">");
	    out.println("<input type=\"reset\" value=\"リセット\">");
	    out.println("</from>");
	    out.println("</body>");
	    out.println("</html>");
	    out.close();
	    
	    // ResultSetオブジェクトのclose
	    rs.close();

	    // Statementオブジェクトのclose
	    stmt.close();

	    // データベースから切断
	    con.close();
	}
	// エラー処理
	catch (SQLException e){
	    System.out.println(e);
	}
	catch (Exception e) {
	    System.out.println(e);
	}

    }
}
