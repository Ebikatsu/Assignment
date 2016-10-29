import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class Program1 extends HttpServlet {
  public void doGet (HttpServletRequest req, 
                      HttpServletResponse res) 
                          throws ServletException, IOException {

    // ContentTypeを設定
    res.setContentType("text/html; charset=utf-8");

    // 出力用PrintWriterを取得
    PrintWriter out = res.getWriter();

    // HTML出力
    out.println("<html>");
    out.println("<head>");
    out.println("<title>Hello World Servlet</title>");
    out.println("</head>"); 
    out.println("<body>");
    out.println("<h1>Hello World Servlet</h1>"); 
    out.println("</body>");
    out.println("</html>");

    try {
      // ドライバをロード
      Class.forName("org.postgresql.Driver");//
      
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
      String sql = "SELECT * FROM 顧客;";

      // ResultSetオブジェクトの生成
      // SELECT文の処理
      ResultSet rs = stmt.executeQuery(sql);

      // 問い合わせ結果を出力
      while(rs.next()){
	  // 検索された行の各列のデータを取得
	  String id = rs.getString("クレジットカード番号");
	  String name = rs.getString("住所");
	  
	  // 表示

    out.println("<html>");
    out.println("<head>");
    out.println("<title>Hello World Servlet</title>");
    out.println("</head>"); 
    out.println("<body>");
    out.println("<h1>Hello World Servlet</h1>"); 
    out.println("<h1>"+id+"</h1><br>");
    out.println("<h1>"+name+"</h1><br>");
    out.println("</body>");
    out.println("</html>");

      }

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

