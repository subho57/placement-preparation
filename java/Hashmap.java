import java.util.HashMap;

public class Hashmap implements Interface {
	public static void main(String[] args) {
		// HashMap<K, V> hm = new HashMap<K, V>();
		HashMap<Character, Integer> hm = new HashMap<>();
		hm.put('b', 1); // O(1)
		hm.put('a', 2);
		hm.put('a', 3);
		hm.putIfAbsent('e', 5);
		hm.putIfAbsent('c', 5);
		System.out.println(hm.get('a')); // O(1)
		System.out.println("a=" + hm.containsKey('a')); // true
		System.out.println("d=" + hm.containsKey('d')); // true
		
		// for-each loop
		System.out.println("JSON: {");
		for (char ch: hm.keySet()) {
			System.out.println("\t" + ch + ": " + hm.get(ch) + ",");
		}
		System.out.println("}");
		System.out.println("Values:");
		for (int ch: hm.values()) {
			System.out.println(ch);
		}
	}

	@Override
	public void method1() {
		System.out.println("method1");
	}

	@Override
	public void method2() {
		System.out.println("method2");		
	}

	// Overloading or Polymorphism
	public void pri() {
		System.out.println("pri");
	}

	public void pri(int a) {
		System.out.println("pri" + a);
	}
}