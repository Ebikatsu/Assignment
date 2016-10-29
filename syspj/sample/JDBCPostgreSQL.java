import java.sql.*;

public class JDBCPostgreSQL{
  public static void main(String[] args) {
    try {
      // ドライバをロード
      Class.forName("org.postgresql.Driver");//
      
      // データベースのURL (XXXをデータベース名に変える)
      String url = "jdbc:postgresql://10.210.128.120:5432/syspj9_test";
      // ユーザ (XXXをグループ名に変える)
      String usr = "syspj9";
      // パスワード (空でよい)
      String pwd = "";
      
      // データベースサーバへの接続
      Connection con = DriverManager.getConnection(url, usr, pwd);

      // Statementオブジェクトを生成
      Statement stmt = con.createStatement();

      // データベースにデータ問い合わせ
      String sql = "SELECT * FROM 学生;";

      // ResultSetオブジェクトの生成
      // SELECT文の処理
      ResultSet rs = stmt.executeQuery(sql);

      // 問い合わせ結果を出力
      while(rs.next()){
	  // 検索された行の各列のデータを取得
	  String id = rs.getString("学籍番号");
	  String name = rs.getString("氏名");
	  String aff = rs.getString("所属");
	  int age = rs.getInt("年齢");
	  
	  // 表示
	  System.out.println(id + " " + name + " " + age + " " + aff);
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
