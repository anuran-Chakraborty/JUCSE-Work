<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<%@ page import="com.mailapp.FetchMail" %>
<%@ page import="javax.mail.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Inbox</title>
</head>
<body>

	<%
		ServletContext context = pageContext.getServletContext();
		String from=(String)request.getServletContext().getInitParameter("fromMail");
		String password=(String)request.getServletContext().getInitParameter("password");
		FetchMail fm=new FetchMail("pop.gmail.com","pop3",from,password);
		Message messages[]=fm.fetchMails();
	%>

	<a href="SendMail.html">Compose Mail</a>
	<h1>INBOX</h1>
	<div class="table-mess">
		<table>
			<tr>
				<th>From</th>
				<th>Subject</th>
				<th>Message</th>
			</tr>

			<%
				for (int i = 0; i < messages.length; i++) 
				{
			         Message message = messages[i];
			%>
			<tr>
				<td><%=message.getFrom()[0]%></td>
				<td><%=message.getSubject()%></td>
				<td><%=message.getContent().toString()%></td>
			</tr>
			<%   }

			%>


		</table>
	</div>
</body>
</html>