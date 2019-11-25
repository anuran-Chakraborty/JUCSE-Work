package com.mailapp;

import java.util.Properties;

import javax.mail.Folder;
import javax.mail.Message;
import javax.mail.PasswordAuthentication;
import javax.mail.Session;
import javax.mail.Store;

public class FetchMail 
{
	private String host, storeType, user, password, from;
	
	public FetchMail(String host, String storeType, String user, String password)
	{
		this.host=host;
		this.storeType=storeType;
		this.user=user;
		this.password=password;
		this.from=from;
	}
	
	//Function to fetch the mail
	public Session getSession() 
	{
		//create properties field
	      Properties properties = new Properties();
	
	      properties.put("mail.pop3.host", host);
	      properties.put("mail.pop3.port", "995");
	      properties.put("mail.pop3.starttls.enable", "true");
	      
	    //get Session   
	     Session session = Session.getDefaultInstance(properties); 
	      return session;
	}
	
	public Message[] fetchMails()
	{
		Session emailSession=getSession();
		Message[] messages = null;
		try
		{
			//create the POP3 store object and connect with the pop server
			Store store = emailSession.getStore("pop3s");

			store.connect(host, user, password);
			
			//create the folder object and open it
		    Folder emailFolder = store.getFolder("INBOX");
		    emailFolder.open(Folder.READ_ONLY);

		    // retrieve the messages from the folder in an array and print it
		    messages = emailFolder.getMessages();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		return messages;
	}
	
}
