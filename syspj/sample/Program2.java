import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class Program2 extends HttpServlet{
    public void doPost(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException {

	req.setCharacterEncoding("utf-8");

	String id = req.getParameter("id");
	String color = req.getParameter("color");
	String[] fruits = req.getParameterValues("fruit");
	String place = req.getParameter("place");
	String sports = req.getParameter("sports");

	res.setContentType("text/html; charset=utf-8");
        PrintWriter out = res.getWriter();

	out.println("<html>");
	out.println("<head>");
	out.println("<title>サンプルプログラム</title>");
	out.println("</head>");
	out.println("<body>");

	out.println("<h3>送信されたフォームのID(hiddenタグの値)は "+id+" です。</h3>");

	out.println("<h3>テキストボックスに入力されたのは "+color+" です。</h3>");

	out.println("<h3>チェックボックスで選択されたのは ");
	if (fruits != null){
	    for (int i = 0; i < fruits.length; i++){
		out.println(fruits[i]+" ");
	    }
	}
	out.println("です。</h3>");

	out.println("<h3>ラジオボックスで選択されたのは "+place+" です。</h3>");

	out.println("<h3>メニューで選択されたのは "+sports+" です。</h3>");

	out.println("</body>");
	out.println("</html>");
	out.close();
    }
}

