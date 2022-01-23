package mvc_arch.controllers;
import mvc_arch.models.User;

public class UserController {
	User user;

	public void createUser(User user) {
		this.user = user;
		// update db
	}

	public User getUser() {
		return user;
	}
}
