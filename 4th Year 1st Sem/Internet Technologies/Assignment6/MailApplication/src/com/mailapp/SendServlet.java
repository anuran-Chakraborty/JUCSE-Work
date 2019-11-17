package com.mailapp;

import java.io.IOException;
import java.util.Properties;

import javax.mail.*;
import javax.mail.internet.*;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class SendServlet
 */
@WebServlet(name = "send", urlPatterns = { "/send" })
public class SendServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

    /**
     * Default constructor. 
     */
    public SendServlet() {
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.getWriter().append("Served at: ").append(request.getContextPath());
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
		
		String sendTo=(String)request.getParameter("recipient");
		String sub=(String)request.getParameter("subject");
		String mess=(String)request.getParameter("message");
		String from=(String)request.getServletContext().getInitParameter("fromMail");
		String password=(String)request.getServletContext().getInitParameter("password");
		
		System.out.println(sendTo);
		//Send the mail
		sendMail(from, password, sendTo, sub, mess);
		
	}

	private void sendMail(String from, String password, String sendTo, String sub, String mess) {
		// TODO Auto-generated method stub
		//Get properties object    
        Properties props = new Properties();    
        props.put("mail.smtp.host", "smtp.gmail.com");    
        props.put("mail.smtp.socketFactory.port", "465");    
        props.put("mail.smtp.socketFactory.class","javax.net.ssl.SSLSocketFactory");    
        props.put("mail.smtp.auth", "true");    
        props.put("mail.smtp.port", "465");    
        //get Session   
        Session session = Session.getDefaultInstance(props,
        		new javax.mail.Authenticator() {    
		         protected PasswordAuthentication getPasswordAuthentication() {    
		         return new PasswordAuthentication(from,password);  
         }    
        });    
		
        try 
        {    
            MimeMessage message = new MimeMessage(session);    
            message.addRecipient(Message.RecipientType.TO,new InternetAddress(sendTo));    
            message.setSubject(sub);    
            message.setText(mess);    
            //send message  
            Transport.send(message);    
            System.out.println("message sent successfully");    
        } 
        catch (MessagingException e) 
        {
        	throw new RuntimeException(e);
        } 
	}

}
