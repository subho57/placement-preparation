import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.HashMap;

public class JDBCTemplate {

    enum Driver {
        mysql,
        mariadb,
        oracle
    }

    protected Connection conn;
    protected HashMap<Driver, String> DriverClass = new HashMap<>();

    JDBCTemplate() {
        DriverClass.put(Driver.mysql, "com.mysql.cj.jdbc.Driver");
        DriverClass.put(Driver.mariadb, "org.mariadb.jdbc.Driver");
        DriverClass.put(Driver.oracle, "oracle.jdbc.driver.OracleDriver");
        this.conn = null;
    }

    public Connection connect(Driver driver, String server, String database, String username, String password, int port)
            throws SQLException, ClassNotFoundException {
        Class.forName(DriverClass.get(driver));
        String connectionUrl = "jdbc:" + driver.toString();
        switch (driver) {
            case oracle:
                connectionUrl += ":thin:@" + server + ":" + port + ":" + database;
                break;
            default:
                connectionUrl += "://" + server + ":" + port + "/" + database;
        }
        this.conn = DriverManager.getConnection(connectionUrl, username, password);
        conn.setAutoCommit(false);
        return conn;
    }

    public static void main(String[] args) {
        JDBCTemplate jdbc = new JDBCTemplate();
        try {
            Connection connection = jdbc.connect(Driver.mysql, "localhost", "test", "root", "", 3306);
            PreparedStatement ps = connection.prepareStatement("SELECT * FROM customer");
            ResultSet rs = ps.executeQuery();
            while(rs.next()) {
                System.out.println(rs.getString("CUST_CODE"));
            }
            rs.close();
            ps.close();
            connection.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}