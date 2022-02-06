public class variable_scope {
  public static void main(String args[]) {
    int x;
    x = 22;
    {
      int y = 16;
      System.out.print(x + " " + y);
    }
    System.out.println(x + " " + y);
  }
}