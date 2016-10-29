import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;


public class Program5 extends HttpServlet {
  public void doPost (HttpServletRequest req,
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
String b = req.getParameter("name");
String c = req.getParameter("price");
String f = req.getParameter("zaiko");
String h = req.getParameter("kate");

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
out.println(b+","+c+","+f+","+h+","+id1);

String sql1="null";
String sql2="null";
String sql3="null";
String sql4="null";
      // データベースにデータ問い合わせ
if(b!=null){
sql1 = "UPDATE 商品 SET 商品名= \'"+b+"\' WHERE 商品コード = \'"+id1+"\'";
}
if(c!=null){
sql2 = "UPDATE 商品 SET 価格=\'"+c+"\' WHERE 商品コード = \'"+id1+"\'";
}
if(f!=null){
sql3 = "UPDATE 商品 SET 在庫数=\'"+f+"\' WHERE 商品コード = \'"+id1+"\'";
}
if(h!=null){
sql4 = "UPDATE 商品 SET カテゴリー=\'"+h+"\' WHERE 商品コード = \'"+id1+"\'";
}



if(sql1 != null){
stmt.executeUpdate(sql1);
}
if(sql2 !=null){
stmt.executeUpdate(sql2);
}
if(sql3 !=null){
stmt.executeUpdate(sql3);
}
if(sql4 !=null){
stmt.executeUpdate(sql4);
}
      //String sql = "SELECT * FROM 学生";


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
}
out.println("<html>");
out.println("<head>");
out.println("<meta http-equiv=\"content-type\" content=\"text/html; charset=utf-8\">");
out.println("<title>管理者ページ</title>");
out.println("</head>");
out.println("<h1>商品情報変更完了ページ</h1>");
out.println("<h1>変更が完了しました。</h1>");
out.println("<a href=\"http://10.210.128.120:8080/~syspj9/Program1\">商品一覧に戻る。</a><br>");
out.println("<body>");
out.println("</body>");
out.println("</html>");
}}
