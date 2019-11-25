package com.flight;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.SessionAttributes;
import org.springframework.web.servlet.ModelAndView;

import java.sql.*;

@Controller
@SessionAttributes("user")
public class LoginController {
	
	@Value("jdbc:mysql://localhost:3306/travel")
	String dburl;
	
	@Value("root")
	String dbuname;
	
	@Value("")
	String dbpass;
	
	@RequestMapping(value="/login", method = RequestMethod.POST)
	public ModelAndView Login(@RequestParam("username") String uname, @RequestParam("password") String password)
	{
		DAO dao=new DAO(dburl,dbuname,dbpass);
		ResultSet rs=null;
		try 
		{
			rs = dao.loginCheck(uname, password);
		} 
		catch (ClassNotFoundException | SQLException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		ModelAndView modelAndView = new ModelAndView();
		if(rs!=null)
		{
			User u=null;
			//Set the session
			try
			{
				u = new User(rs.getString("name"), rs.getString("uname"), rs.getString("password"));
			} 
			catch (SQLException e) 
			{
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			 modelAndView.addObject("user", u);
			 modelAndView.setViewName("searchFlight.jsp");
			 return modelAndView;
		}
		else
		{	
			System.out.println("Error"+rs);
			String msg=new String("sorry!! Wrong credentials");
			System.out.println(msg);
			modelAndView.addObject("msg", msg);
			modelAndView.setViewName("error.jsp");
			return modelAndView;
		}
	}
	
	
	@RequestMapping(value="/register", method = RequestMethod.POST)
	public ModelAndView Register(@RequestParam("name") String name, @RequestParam("username") String uname, @RequestParam("password") String password)
	{
		DAO dao=new DAO(dburl,dbuname,dbpass);
		
		User u=new User(name,uname,password);

		try {
			if(dao.checkUname(uname))
			{
				ModelAndView modelAndView = new ModelAndView();
				String msg="sorry!! Duplicate username";
				modelAndView.addObject("msg", msg);
				modelAndView.setViewName("error.jsp");
				return modelAndView;
			}
		} 
		catch (Exception e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		
		try{
			dao.register(u);
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		ModelAndView modelAndView = new ModelAndView();
		modelAndView.setViewName("searchFlight.jsp");
		return modelAndView;
	}
	
	@RequestMapping(value="/logout", method = RequestMethod.GET)
	public ModelAndView Logout()
	{
		User u=new User(null,null,null);
		ModelAndView modelAndView = new ModelAndView();
		modelAndView.addObject("user", u);
		modelAndView.setViewName("index.jsp");
		return modelAndView;
	}
	
	
}
