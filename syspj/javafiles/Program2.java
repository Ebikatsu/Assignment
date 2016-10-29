import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;


public class Program2 extends HttpServlet {
  public void doGet (HttpServletRequest req,
                      HttpServletResponse res)
                          throws ServletException, IOException {
      	req.setCharacterEncoding("utf-8");


    // ContentTypeを設定
    res.setContentType("text/html; charset=utf-8");

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
      String sql = "SELECT * FROM 商品 WHERE 商品コード = \'"+id2+"\'";
      //String sql = "SELECT * FROM 学生";

      // ResultSetオブジェクトの生成
      // SELECT文の処理
      ResultSet rs = stmt.executeQuery(sql);

out.println("<html>");
out.println("<head>");
out.println("<meta http-equiv=\"content-type\" content=\"text/html; charset=utf-8\">");
out.println("<title>管理者ページ</title>");
out.println("</head>");
out.println("<h1>商品情報詳細ページ</h1>");
    out.println("<h2>商品情報</h2>");
    out.println("<table border=\"1\">");
out.println("<table>");
    out.println("<td>商品コード</td>");
    out.println("<td>商品名</td>");
    out.println("<td>価格</td>");
    out.println("<td>在庫数</td>");
    out.println("<td>カテゴリー</td>");
     while(rs.next()){
       int id = rs.getInt("商品コード");
       String name = rs.getString("商品名");
       int price = rs.getInt("価格");
       int zaiko = rs.getInt("在庫数");
       String kate = rs.getString("カテゴリー");
       out.println("<tr>");
       out.println("<td>"+id+"</td>");
       out.println("<form action = \"http://10.210.128.120:8080/~syspj9/Program5\" method=\"post\">");
 out.println("<input type=\"hidden\" name=\"id\" value="+id+">");
       out.println("<td><input type=\"text\" name=\"name\" placeholder="+name+"></td>");
       out.println("<td><input type=\"text\" name=\"price\" placeholder="+price+"></td>");
       out.println("<td><input type=\"text\" name=\"zaiko\" placeholder="+zaiko+"></td>");
       out.println("<td>現在のカテゴリー=>["+kate+"]");
       out.println("<input type=\"checkbox\" name=\"kate\" value=\"本\">本");
       out.println("<input type=\"checkbox\" name=\"kate\" value=\"食品\">食品");
       out.println("<input type=\"checkbox\" name=\"kate\" value=\"家具家電\">家具家電");
       out.println("<input type=\"checkbox\" name=\"kate\" value=\"文房具\">文房具</td>");
       out.println("</tr>");
       out.println("</table>");
       out.println("<input type=\"submit\" value=変更>");
       out.println("</form>");
out.println("</table>");
}
   out.println("<style>");
    out.println("table {");
    out.println("border-collapse: collapse;");
    out.println("}");
    out.println("td {");
    out.println("border: solid 1px;");
    out.println("padding: 0.5em;");
    out.println("}");
    out.println("</style>");
    out.println("<table>");
    out.println("<a href=\"http://10.210.128.120:8080/~syspj9/Program3?id="+id2+"\">   削除</a>");
    out.println("</table>");
out.println("<body>");
out.println("</body>");
out.println("</html>");


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
}}}
