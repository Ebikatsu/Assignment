import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;


public class Program4 extends HttpServlet {
  public void doGet (HttpServletRequest req,
                      HttpServletResponse res)
                          throws ServletException, IOException {
      	


    // ContentTypeを設定
    res.setContentType("text/html; charset=utf-8");
    req.setCharacterEncoding("utf-8");
    // 出力用PrintWriterを取得
    PrintWriter out = res.getWriter();

    // HTML出力
    String aff=null;

String id1 = req.getParameter("id");
int id2 = Integer.parseInt(id1);

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
      String sql = "DELETE FROM 商品 WHERE 商品コード=\'"+id2+"\'";
      //String sql = "SELECT * FROM 学生";

      // ResultSetオブジェクトの生成
      // SELECT文の処理
      ResultSet rs = stmt.executeQuery(sql);


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

out.println("<html>");
out.println("<head>");
out.println("<meta http-equiv=\"content-type\" content=\"text/html; charset=utf-8\">");
out.println("<title>管理者ページ</title>");
out.println("</head>");
out.println("<body>");
out.println("<h2>削除完了画面</h2>");
out.println("<h3>商品のデータを削除しました。</h3>");
out.println("<a href=\"http://10.210.128.120:8080/~syspj9/Program1\">商品一覧に戻る。</a><br>");
out.println("</body>");
out.println("</html>");

}
}
