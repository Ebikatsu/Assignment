import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class Report9 extends HttpServlet{
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
	    
	    res.setContentType("text/html; charset=utf-8");
	    String[] numbers = req.getParameterValues("getnumber");
	    PrintWriter out = res.getWriter();
	    
	    
	    // データベースにデータ問い合わせ
	    String sql="SELECT * FROM 注文情報;";
	    if(numbers!=null){
		 sql = "SELECT 注文情報.*,顧客.氏名,顧客.住所 FROM 注文情報,顧客 WHERE 顧客のid=id AND (注文番号="+numbers[0];
		 for(int i=1;numbers.length>i;i++){
			 sql=sql+" OR 注文情報.注文番号="+numbers[i];
		     }
		 sql=sql+");";
	     }
	     
	     // ResultSetオブジェクトの生成
	    // SELECT文の処理
	    
	     ResultSet rs = stmt.executeQuery(sql);
	    
	    res.setContentType("text/html; charset=utf-8");
	    
	    out.println("<html>");
	    out.println("<head>");
	    out.println("<title>注文情報</title>");
	    out.println("<meta http-equiv=\"Content-Type\" content=\"text/html;charset=UTF-8\">");
	    out.println("</head>");
	    out.println("<body>");
	    if(numbers==null)
		out.println("<meta http-equiv=\"refresh\" content=\"0;URL=order_list.html\">");
	    out.println("<h1>注文情報</h1>");
	    
	    out.println("<table border=\"1\" cellpadding=\"5\" cellspacing=\"0\">");
	    out.println("<th>注文番号</th>");
	    out.println("<th>id</th>");
	    out.println("<th>商品コード</th>");
	    out.println("<th>個数</th>");
	    out.println("<th>氏名</th>");
	    out.println("<th>住所</th>");
	    
	    // 問い合わせ結果を出力
	    while(rs.next()){
		out.println("<tr>");
		// 検索された行の各列のデータを取得
		int number = rs.getInt("注文番号");
		int id = rs.getInt("顧客のid");
		int cord = rs.getInt("商品コード");
		int count = rs.getInt("個数");
		String name = rs.getString("氏名");
	        String adr = rs.getString("住所");

		out.println("<td>"+number+"</td>");
		out.println("<td>"+id+"</td>");
		out.println("<td>"+cord+"</td>");
		out.println("<td>"+count+"</td>");
		out.println("<td>"+name+"</td>");
		out.println("<td>"+adr+"</td>");		
		out.println("</tr>");
	    }
	    out.println("</table>");
	    
	    out.println("<br>");
	    
	    out.println("<input type=\"button\" onclick=\"location.href='http://10.210.128.120:8080/~syspj9/order_list.html'\"value=\"戻る\">");
	    out.println("<form method=\"post\" action=\"http://10.210.128.120:8080/~syspj9/Report10\">");
	    for(int i=0;i<numbers.length;i++)
		out.println("<input type=\"hidden\" name=\"del\" value=\""+numbers[i]+"\">");
	    out.println("<input type=\"submit\" \"value=\"配送完了\">");
	    out.println("</form>");
	    
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
