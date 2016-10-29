import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;


public class Program7 extends HttpServlet {
 public void doPost (HttpServletRequest req,
                      HttpServletResponse res)
                          throws ServletException, IOException {

    // ContentTypeを設定
    res.setContentType("text/html; charset=utf-8");
    req.setCharacterEncoding("utf-8");
    // 出力用PrintWriterを取得
    PrintWriter out = res.getWriter();

    // HTML出力
    String aff=null;


String id = req.getParameter("id");        	
String name = req.getParameter("name");
String price = req.getParameter("price");
String zaiko = req.getParameter("zaiko");
String kate = req.getParameter("kate");

 try {
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
String sql="INSERT INTO 商品 VALUES(\'"+id+"\',\'"+name+"\',\'"+price+"\',\'"+zaiko+"\',\'"+kate+"\')";
      //String sql = "SELECT * FROM 学生";

      // ResultSetオブジェクトの生成
      // SELECT文の処理
int result = stmt.executeUpdate(sql);

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
out.println("<html>");
out.println("<head>");
out.println("<meta http-equiv=\"content-type\" content=\"text/html; charset=utf-8\">");
out.println("<title>管理者ページ</title>");
out.println("</head>");
out.println("<body>");
out.println("<h2>登録完了画面</h2>");
out.println("<h2>"+id+","+name+","+price+","+zaiko+","+kate+"</h2>");
out.println("<h3>商品のデータを登録しました。</h3>");
out.println("<a href=\"http://10.210.128.120:8080/~syspj9/Program1\">商品一覧に戻る。</a><br>");
out.println("</body>");
out.println("</html>");

}
}
