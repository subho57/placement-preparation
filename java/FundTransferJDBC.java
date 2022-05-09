import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class FundTransferJDBC {
    public static void main(String[] args) throws SQLException, ClassNotFoundException {
        Class.forName("com.mysql.cj.jdbc.Driver");
        String url = "jdbc:mysql://localhost:3306/test";
        Connection conn = DriverManager.getConnection(url, "root", "");
        conn.setAutoCommit(false);
        PreparedStatement ps = conn.prepareStatement("UPDATE orders SET ORD_AMOUNT = ORD_AMOUNT + 500 WHERE ORD_NUM = 200100");
        try {
            ps.executeUpdate();
            conn.commit();
        } catch (SQLException e) {
            System.err.println(e);
            conn.rollback();
        }
        ps.close();
        conn.close();
    }
}
