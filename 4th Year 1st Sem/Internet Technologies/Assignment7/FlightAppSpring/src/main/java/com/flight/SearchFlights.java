package com.flight;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.ModelAndView;

import java.sql.*;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.text.DateFormat;

@Controller
public class SearchFlights 
{
	@Value("jdbc:mysql://localhost:3306/travel")
	String dburl;
	
	@Value("root")
	String dbuname;
	
	@Value("")
	String dbpass;
	
	@RequestMapping(value="/search", method = RequestMethod.POST)
	public ModelAndView getFlights(@RequestParam("src") String src, @RequestParam("dest") String dest, @RequestParam("date") String date)
	{
		System.out.println(dburl);
		DAO dao=new DAO(dburl,dbuname,dbpass);

		ResultSet rs=null;
		
		// get day of week from date string
		String day;
		SimpleDateFormat format1=new SimpleDateFormat("yyyy-MM-dd");
		Date dt1=null;
		try 
		{
			dt1 = (Date) format1.parse(date);
		} 
		catch (Exception e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		DateFormat format2=new SimpleDateFormat("EEEE"); 
		day=format2.format(dt1);
		
		System.out.println(day);
		try 
		{
			rs=dao.getFlights(src,dest,day);
		} 
		catch (Exception e) 
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		ModelAndView mv=new ModelAndView();
		mv.setViewName("flights.jsp");
		mv.addObject("flights",rs);
		mv.addObject("day",day);
		mv.addObject("src",src);
		mv.addObject("dest",dest);
		
		return mv;
		
	}
	
	@RequestMapping(value="/filter", method = RequestMethod.POST)
	public ModelAndView filter(@RequestParam("src") String src, @RequestParam("dest") String dest, @RequestParam("day") String day, @RequestParam("company") String company, @RequestParam("stops") String stops)
	{
		System.out.println(dburl);
		DAO dao=new DAO(dburl,dbuname,dbpass);
		ResultSet rs=null;
		
		System.out.println(day);

		try 
		{
			rs=dao.filterFlights(src,dest,company,stops,day);
		} 
		catch (Exception e) 
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		ModelAndView mv=new ModelAndView();
		mv.setViewName("flights.jsp");
		mv.addObject("flights",rs);
		mv.addObject("day",day);
		mv.addObject("src",src);
		mv.addObject("dest",dest);
		
		return mv;
		
	}
	
}
