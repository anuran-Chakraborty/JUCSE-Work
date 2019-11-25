package com.flight;

public class User {
	private String name,uname,password;
	
	public User(String name,String uname, String password)
	{
		this.name=name;
		this.uname=uname;
		this.password=password;
	}

	public String getName() {
		return name;
	}

	public String getUname() {
		return uname;
	}

	public String getPassword() {
		return password;
	}
}
