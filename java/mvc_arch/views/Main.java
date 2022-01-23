package mvc_arch.views;
import java.util.Scanner;

import mvc_arch.controllers.UserController;
import mvc_arch.models.User;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter name: ");
		String name = sc.nextLine();
		System.out.println("Enter email: ");
		String email = sc.nextLine();
		System.out.println("Enter phone: ");
		String phone = sc.nextLine();
		sc.close();

		User pri = new User(name, email, phone);
		UserController uc = new UserController();
		uc.createUser(pri);

		System.out.println("User name: " + uc.getUser().getName());

	}
}
