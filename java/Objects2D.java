public class Objects2D extends Rectangle {
	int x, y;
	public static void main(String[] args) {
		// Rectangle r = new Rectangle(10, 20);
		// System.out.println("Area: " + r.area());
		// System.out.println("Perimeter: " + r.perimeter());
		
		Objects2D o = new Objects2D(10, 20, 5, 6);
		System.out.println("Area: " + o.area());
		System.out.println("Perimeter: " + o.perimeter());
		System.out.println("Add: " + o.add());
	}
	Objects2D(int length, int breadth, int x, int y) {
		super(length, breadth);
		this.x = x;
		this.y = y;
	}
	public int add() {
		return x + y;
	}
}
