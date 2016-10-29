import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class Report10 extends HttpServlet{
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
	    String[] numbers = req.getParameterValues("del");
	    PrintWriter out = res.getWriter();
	    
	    // データベースにデータ問い合わせ
	     String sql="";
	      if(numbers!=null){
	    	 for(int i=0;numbers.length>i;i++){
	    	     sql="DELETE FROM 注文情報 WHERE 注文番号="+numbers[i]+";";
	    	     int rs = stmt.executeUpdate(sql);
	    	 }
	     }
	    
	    


		
	    res.setContentType("text/html; charset=utf-8");
	    
	    out.println("<html>");
	    out.println("<head>");
	    out.println("<title>配送完了</title>");
	    out.println("<meta http-equiv=\"Content-Type\" content=\"text/html;charset=UTF-8\">");
	    out.println("</head>");
	    out.println("<body>");

	    out.println("<h1>配送完了しました</h1>");
	    out.println("<p>3秒後自動で戻ります</P>");
	    out.println("<meta http-equiv=\"refresh\" content=\"3;URL=order_list.html\">");
	    out.println("</body>");
	    out.println("</html>");
	    out.close();
	    
	    // ResultSetオブジェクトのclose
	    //   rs.close();
	      
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
