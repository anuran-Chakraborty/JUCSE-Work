<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
    
<%@page import="java.sql.*"%>
<%@page import="com.shopping.DAO"%>
<%@page import="com.shopping.User"%>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Dashboard</title>

<style type="text/css">
	ul {
		list-style-type: none;
		margin: 0;
		padding: 2px;
		overflow: hidden;
		background-color: #333;
		height: 40px;
	}

	li {
		padding:1px;
		float: left;
		color: #ffffff;
		font-size: 20px;
		text-align: center;
	}

	.cards{
		width:12%;
		display: inline-block;
		margin:40px;
		box-shadow:2px 2px 10px black;
	}

	.image img{
		width:100%;
	}

	.title{
		text-align: center;
	}

	.price{
		text-align: center;
		font-size: 20px;
		padding:4px;
	}

	.gender{
		text-align: center;
		color:#a0a0a0;
		font-size: 16px;
		padding:4px;
	}
	
	.origPrice{
		text-align: center;
		font-size: 16px;
		padding:4px;
		text-decoration: line-through;
		color: grey;
	}

	.nameDisp{
		float: right;
	}

	.logout a{
		color:white;
	}
	
	
	.ribbon {
	  position: relative;
	  left: -5px; top: -5px;
	  z-index: 1;
	  overflow: hidden;
	  width: 75px; height: 75px;
	  text-align: right;
	}
	.ribbon span {
	  font-size: 10px;
	  font-weight: bold;
	  color: #FFF;
	  text-transform: uppercase;
	  text-align: center;
	  line-height: 20px;
	  transform: rotate(-45deg);
	  -webkit-transform: rotate(-45deg);
	  width: 100px;
	  display: block;
	  background: #79A70A;
	  background: linear-gradient(#F70505 0%, #8F0808 100%);
	  box-shadow: 0 3px 10px -5px rgba(0, 0, 0, 1);
	  position: absolute;
	  top: 19px; left: -21px;
	}
	.ribbon span::before {
	  content: "";
	  position: absolute; left: 0px; top: 100%;
	  z-index: -1;
	  display: block;
	  border-left: 3px solid #8F0808;
	  border-right: 3px solid transparent;
	  border-bottom: 3px solid transparent;
	  border-top: 3px solid #8F0808;
	}
	.ribbon span::after {
	  content: "";
	  position: absolute; right: 0px; top: 100%;
	  z-index: -1;
	  display: block;
	  border-left: 3px solid transparent;
	  border-right: 3px solid #8F0808;
	  border-bottom: 3px solid transparent;
	  border-top: 3px solid #8F0808;
	}
	
	.images img{
		width:100%;
	}

	.error{
		font-size: 20px;
		text-align: center;
	}

	.search-bar{
		justify-content: center;
		align-items: center;
	}

	.search-field{
		margin: auto;
		height: 30px;
		width: 50%;
		padding: 10px;
		border-radius: 40px;
	}

	.search-btn{
		height: 40px;
		width: 10%;
		padding: 10px;
		border-radius: 40px;
		background-color: grey;
		color: white;
		text-align: center;
	}

	.search-btn:hover{
		background-color: black;
		cursor: pointer;
	}

</style>


</head>
<body>
	
	<%
		response.setHeader("Cache-Control","no-cache, no-store, must-revalidate");
		System.out.println((User)session.getAttribute("user"));
		//Session check
		if((User)session.getAttribute("user")==null)
		{
			System.out.println("Hi");
			response.sendRedirect("index.html");
			return;
		}
	%>
	
	<ul>
		<li class="logout"><a href="<%=request.getContextPath()%>/logout">Logout</a></li>
		<li class="nameDisp">Hi, <%=((User)(session.getAttribute("user"))).getName()%></li>
	</ul>
	<br><br>
	<!-- Now fetch the data -->

	<div class="main">

		<div class="search-bar">
			<form method="post">
				<input type="text" class="search-field" name="search" required="" placeholder="Search...">
				<input type="submit" class="search-btn" name="submit" value="search">
			</form>
		</div>

	<%
		
		DAO dao=(DAO)session.getAttribute("dao");
		ResultSet rs;
		if(request.getParameter("submit")!=null)
			rs=dao.getItemsByName(request.getParameter("search"));
		else
			rs=dao.getItems((User)session.getAttribute("user"));

		if(rs==null)
		{%>
			<div class="error">
				Sorry!! No Items match your search
			</div>
		<%}

		else
		do
		{
			System.out.println(rs);
			
			{%>
			<div class="cards">
				<%if(rs.getString("itemtype").equals("newarr")){ %>
				
				<div class="ribbon"><span>NEW</span></div>
				<%} %>
				
				<div class="images">
					<img src="<%="/ShoppingApp/images/"+rs.getString("name")+".png" %>"/>
				</div>

				<div class="title">
					<h3><%=rs.getString("name")%></h3>
				</div>
				<div class="gender">
					Gender: <%=rs.getString("gender")%>
				</div>
				<%if(rs.getString("itemtype").equals("discount"))
					{%>
					<div class="origPrice">
						Price: Rs. <%=rs.getString("price")%>
					</div>
				<%} %>
				
				<div class="price">
					Price: Rs. 
					<%
					int disc=Integer.parseInt(rs.getString("discount"));
					int orig=Integer.parseInt(rs.getString("price"));
					int newprice=orig-(int)(orig*disc/100.0);
					out.print(newprice);
					%>
				</div>

			</div>
				
		<%}
		}
		while(rs.next());
	%>

	</div>

</body>
</html>