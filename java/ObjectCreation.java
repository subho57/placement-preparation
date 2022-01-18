import java.util.Scanner;

class ClassName {
	int c, d;
	static int abc = 5; // static member variable - independent of object, retains its value
	// static memory leak
	ClassName(int c, int d) { // 
		this.c = c;
		this.d = d;
	}
	ClassName() { // 
		c = 0;
		d = 0;
	}
	ClassName(int a, int b, int c, int d) { // 
		this(a, b);
		this.c = c;
		this.d = d;
	}
	public int globalAdd() {
		return c+d;
	}
	public int add(int a, int b) {
		return a + b;
	}
	// static method allows it to be called even without an object
	public static int product(int a, int b) {
		return a * b;
	}
	public void display() {
		System.out.println("c = " + c + " d = " + d + " abc = " + abc);
	}
}

public class ObjectCreation {
	public static void main(String[] args) {
		// ClassName obj = new ClassName();
		// ClassName objName = new Constructor(); // Default
		ClassName objName = new ClassName(4, 6, 8, 7); // Parameterized
		objName.display();

		objName.c = 10;
		objName.d = 50;
		objName.abc = 100;
		objName.display();
		// Anonymous Object used for one time operations
		new ClassName(4, 5).display();



		ClassName objName1 = new ClassName(4, 6, 6, 5); // Parameterized
		objName1.display();
		// System.out.println(obj.globalAdd());
		// Scanner sc = new Scanner(System.in);
		// int c = sc.nextInt();
		// System.out.println("Enter two numbers: ");
		// int a = ClassName.product(4, 5);
		// int b = 40; // primitive data type
		// Integer b = new Integer(40); // wrapper class //Boxing
		// Integer c = 40; // Auto-boxing
		// int d = c + 10; // Auto-unboxing
		// int a = 40;
		// Primitive Data Types
		// BB SC IF LD
		// 1  2  4  8 bytes
		// Non Primitive Types
		//  Array, String, Object, Class, Interface
		// String str = new String("Hello");
	}
}
