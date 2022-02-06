class Base {
  private int fun() {
    return 0;
  }

  public int run() {
    return 3;
  }
}

class Derived extends Base {
  private int fun() {
    return 1;
  }

  public int run() {
    return fun();
  }
}

class Derived1 extends Derived {
  public int fun() {
    return 2;
  }
}

public class Main {
  public static void main(String[] args) {
    /* code */
    Base baseRef = new Derived1();
    System.out.print(baseRef.run());
  }
}