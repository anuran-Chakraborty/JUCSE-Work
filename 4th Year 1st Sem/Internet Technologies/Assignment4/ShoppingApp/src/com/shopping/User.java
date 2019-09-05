package com.shopping;

public class User {
	private String name,uname,gender,choice,password;
	
	public User(String name,String uname,String gender,String choice, String password)
	{
		this.name=name;
		this.uname=uname;
		this.gender=gender;
		this.choice=choice;
		this.password=password;
	}

	public String getName() {
		return name;
	}

	public String getUname() {
		return uname;
	}

	public String getGender() {
		return gender;
	}

	public String getChoice() {
		return choice;
	}

	public String getPassword() {
		return password;
	}
}
