/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;

class GFG {
	public static void main (String[] args) {
		HashMap<Character, Integer> map = new HashMap<>();
		String str = "aaabbddccaa";
		for (int i = 0; i <= str.length(); i++) {

		    if (map.containsKey(str.charAt(i))) {
				map.put(str.charAt(i), map.get(str.charAt(i)) + 1);
		    } else {
				map.put(str.charAt(i), 1);
		    }
		}
		for (char ch: map.keySet()) {
		    System.out.println(ch + ": " + map.get(ch));
		}
		
	}
}