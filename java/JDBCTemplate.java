import java.math.BigInteger;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class JDBCTemplate {
    public static void main(String[] args) throws SQLException, ClassNotFoundException {
        Class.forName("com.mysql.cj.jdbc.Driver");
        String url="jdbc:mysql://localhost:3306/test";

        // Database Connectivity established
        Connection conn = DriverManager.getConnection(url, "root", "");
        conn.setAutoCommit(false);

        // Statement(Normal)(slower)
        Statement st = conn.createStatement();
        // DQL -> Always returns a dataset/resultset -> result might be empty, then empty linked list
        ResultSet rs = st.executeQuery("select * from customer"); // Runtime
        while(rs.next()) {
            System.out.println("Customer Code: " + rs.getString(1));
        }
        // DML or DDL -> boolean
        System.out.println(st.execute("DELETE FROM customer WHERE CUST_CODE = 'C00020'"));
        // Faster
        PreparedStatement ps = conn.prepareStatement("select * from customer"); // Compile Time
        rs = ps.executeQuery();
        // conn.commit();
        while(rs.next()) {
            System.out.println("Customer Code: " + rs.getString(1));
        }
        rs.close();
        st.close();
        conn.close();
    }
}