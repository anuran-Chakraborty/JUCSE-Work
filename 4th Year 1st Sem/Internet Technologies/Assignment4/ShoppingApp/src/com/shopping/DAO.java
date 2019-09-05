package com.shopping;

import java.sql.*;

public class DAO {
	
	private Connection con;
	private Statement stmt;
	private String url,uname,password;
	
	public DAO(String url, String uname, String password)
	{
		this.url=url;
		this.uname=uname;
		this.password=password;
	}
	
	//Function to establish the connection
	private void setConnection() throws ClassNotFoundException, SQLException
	{
		Class.forName("com.mysql.jdbc.Driver");
		con=DriverManager.getConnection(url,uname,password);
	}
	
	//Function to close the connection
	private void closeConn() throws SQLException
	{
		con.close();
	}
	
	//Function for login
	public ResultSet loginCheck(String username, String password) throws ClassNotFoundException, SQLException
	{
		setConnection();
		String query="select * from loginInfo where uname=\'"+username+"' and password=\'"+password+'"';
		ResultSet rs=stmt.executeQuery(query);
		
		if(rs.next())
		{
			return rs; //Means username password exists
		}
		closeConn();
		return null;
	}
	
	//Function for checking duplicate username 
	public boolean checkUname(String username) throws ClassNotFoundException, SQLException
	{
		setConnection();
		String query="select * from loginInfo where uname=\'"+username+"'";
		ResultSet rs=stmt.executeQuery(query);
		
		if(rs.next())
		{
			return true; //Means username password exists
		}
		closeConn();
		return false;
	}
	
	//Function for registering
	public void register(User u) throws ClassNotFoundException, SQLException
	{
		setConnection();
		
		String query="insert into loginInfo values('"+u.getName()+"','"+u.getGender()+"','"+u.getUname()+"','"+u.getPassword()+"','"+u.getChoice()+"'";
		ResultSet rs=stmt.executeQuery(query);
		closeConn();
		
	}
	
	//Function for fetching data from items table
	public ResultSet getItems(User u) throws ClassNotFoundException, SQLException
	{
		setConnection();
		String query="select * from items where itemType=\'"+u.getChoice()+"' and gender='"+u.getGender()+"'";
		ResultSet rs=stmt.executeQuery(query);
		
		if(rs.next())
		{
			return rs;
		}
		closeConn();
		return null;
	}
	
}
