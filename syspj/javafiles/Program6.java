import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;


public class Program6 extends HttpServlet {
  public void doGet (HttpServletRequest req,
                      HttpServletResponse res)
                          throws ServletException, IOException {

String a = req.getParameter("i");
int id = Integer.parseInt(a);      	


    // ContentTypeを設定
    res.setContentType("text/html; charset=utf-8");
    req.setCharacterEncoding("utf-8");

    // 出力用PrintWriterを取得
    PrintWriter out = res.getWriter();

    // HTML出力
    String aff=null;

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

out.println("<html>");
out.println("<head>");
out.println("<meta http-equiv=\"content-type\" content=\"text/html; charset=utf-8\">");
out.println("<title>管理者ページ</title>");
out.println("</head>");
out.println("<body>");
out.println("<form action = \"http://10.210.128.120:8080/~syspj9/Program7\" method=\"post\">");
out.println("<h2>商品情報</h2>");
out.println("<table border=\"1\">");
out.println("<td>商品コード</td>");
out.println("<td>商品名</td>");
out.println("<td>価格</td>");
out.println("<td>在庫数</td>");
out.println("<td>カテゴリー</td>");
out.println("<tr>");
out.println("<td><input type=\"hidden\" name=\"id\" value="+id+"></td>");
out.println("<td><input type=\"text\" name=\"name\"></td>");
out.println("<td><input type=\"text\" name=\"price\"></td>");
out.println("<td><input type=\"text\" name=\"zaiko\"></td>");
out.println("<td><input type=\"checkbox\" name=\"kate\" value=\"本\">本");
out.println("<input type=\"checkbox\" name=\"kate\" value=\"食品\">食品");
out.println("<input type=\"checkbox\" name=\"kate\" value=\"家具家電\">家具家電");
out.println("<input type=\"checkbox\" name=\"kate\" value=\"文房具\">文房具</td>");
out.println("</tr>");
out.println("</table>");
out.println("<input type=\"submit\" value=\"登録\">");
out.println("</form>");
out.println("</body>");
out.println("</html>");

      // Statementオブジェクトのclose
      stmt.close();

      // データベースから切断
      con.close();

 }
    // エラー処理
    catch (SQLException e){
	System.out.println(e);
    }
    // エラー処理
    catch (Exception e) {
	System.out.println(e);
    }
}
}
