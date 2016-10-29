import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class HelloWorldServlet extends HttpServlet {
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
  } 
}
