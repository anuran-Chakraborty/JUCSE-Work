<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<%@ page import="java.sql.*" %>
<%@ page import="com.flight.*" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">

<!-- Latest compiled and minified CSS -->
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/css/bootstrap.min.css">

<!-- jQuery library -->
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>

<!-- Latest compiled JavaScript -->
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/js/bootstrap.min.js"></script>


<style>

	.flight{
		width: 100%;
		text-align: center;
		margin: 20px;
		padding: 5px;

		border: solid;
	}

	table{
		width: 100%;
	}
	
	th {
  		background-color: #4CAF50;
  		color: white;
  		font-size: 15px;
	}
	th, td {
	  padding: 15px;
	  text-align: center;
	  border-bottom: 1px solid #ddd;
	}
	tr:nth-child(even) {background-color: #f2f2f2;}

	.company{
		font-size: 20px;
		font-family: serif;
	}

	.stops{
		font-size: 20px;
		font-family: serif;
	}

	.time{
		font-size: 25px;
		font-family: sans-serif;
		font-weight: 100;
	}
	.city{
		font-size: 20px;
		font-family: serif;
	}

	.actual-price{
		font-size: 27px;
		font-family: sans-serif;
	}

	.actual-price-discount{
		font-size: 23px;
		font-family: sans-serif;
		text-decoration: line-through;
		color: grey;
	}

	.price-discount{
		color: green;
		font-size: 25px;
	}

	.num-stops{
		color:blue;
	}

	.error{
		text-align: center;
		font-size: 30px;
		font-family: serif;
	}

	.duration{
		font-size: 27px;
		font-family: sans-serif;
	}

	.stop-list{
		color: grey;
	}

	.travel-form{
		margin: auto;
		align-content: center;
		display: block;
		text-align: center;
		background-color: #DBDADA;
		padding: 20px;
	}

	.travel-form form{
		display: inline-block;
	}

	.travel-form select, input{
		height: 60px;
		width: 300px;
	}
	

</style>



<title>Flights</title>
</head>
<body>

<%
		response.setHeader("Cache-Control","no-cache, no-store, must-revalidate");
		System.out.println((User)session.getAttribute("user"));
		//Session check
		if(((User)session.getAttribute("user")).getUname()==null)
		{
			System.out.println("Hi");
			response.sendRedirect("index.jsp");
			return;
		}
%>

<%
String url,user,pass;
url="jdbc:mysql://localhost:3306/travel";
System.out.println(url);
user="root";
pass="";

DAO dao=new DAO(url,user,pass);

ResultSet rs;
rs=dao.getCompanies();

String day=(String)request.getAttribute("day");
String src=(String)request.getAttribute("src");
String dest=(String)request.getAttribute("dest");
ResultSet rs2;
%>

<ul>
	<li class="logout"><a href="index.jsp">Home</a></li>
	<li class="logout"><a href="<%=request.getContextPath()%>/logout">Logout</a></li>
	<li class="logout">Hi, <%=((User)(session.getAttribute("user"))).getName()%></li>
</ul>
<!-- Form for filtering -->

<div class="travel-form">
	<form action="filter" id="filter-form" method="post">
		<input type="hidden" name="day" value="<%=day%>">
		<input type="hidden" name="src" value="<%=src%>">
		<input type="hidden" name="dest" value="<%=dest%>">

		<select class="company" id="company" name="company">
			<option value="all">All</option>
			<%
				do
				{%>
					<option value="<%=rs.getString("company")%>"><%=rs.getString("company")%> </option>
				<%}
				while(rs.next());
			%>
		</select>

		<select class="stops" id="stops" name="stops">
			<option value="all">All</option>
			<option value="0">Non-Stop</option>
		</select>

		<input class="search" type="button" value="SEARCH" onclick="validate_and_submit()">
		
	</form>
</div>




<div class="list">


<%
rs=null;
rs=(ResultSet)request.getAttribute("flights");	
if(rs==null)
{%>
	<div class="error">Sorry!!! No flights found</div>
<% }

else
{%>

	<table>
		<tr>
			<th>Flight</th>
			<th>Departure</th>
			<th>Duration</th>
			<th>Arrival</th>
			<th>Price</th>
		</tr>
	<%
	do
	{

		String disc= rs.getString("discount");
		String act_price= rs.getString("price");

		int discount=0;
		int a_price=Integer.parseInt(act_price);
		int d_price=0;
		if(disc!=null)
		{
			discount=Integer.parseInt(disc);
			d_price=(int)((double)a_price*(100.0-(double)discount)/100.0);
		}
		String disc_price=Integer.toString(d_price);

		%>
		<tr>
			<td>
				<div class="company">
					<strong><%=rs.getString("company")%></strong><br>
				</div>
			 	<%=rs.getString("flight_num")%>
			</td>


			<td>
				<div class="time">
					<%
					String dept_time=rs.getString("dept_time");
					dept_time=dept_time.substring(0,dept_time.lastIndexOf(':'));
					%>
					<strong><%=dept_time%></strong><br>
				</div>

				<div class="city">
					<%=rs.getString("src_city")%>
				</div>
								
			</td>







			<td>
				<div class="duration">
					<%
					if(rs.getString("dur_hrs").compareTo("0")!=0)
					{%>
						<strong><%=rs.getString("dur_hrs")%>h </strong>
					<%}
					if(rs.getString("dur_min").compareTo("0")!=0)
					{%>
						<strong><%=rs.getString("dur_min")%>m </strong>
					<%}%>
				</div>

				<div class="num-stops">
					<%
					if(rs.getString("num_stops").compareTo("0")==0)
					{%>
						Non stop
					<%}	
					else
					{%>
						<%=rs.getString("num_stops")%> stop(s)
						<div class="stop-list">
							
							<%
							rs2=dao.getStops(rs.getString("id"));
							do{
								if(Integer.parseInt(rs2.getString("stop_no"))<Integer.parseInt(rs.getString("num_stops"))){%>
									<%=rs2.getString("dest_city")%><span style='font-size:15px;'>&#8594;</span>
								<%}else
								{%>
									<%=rs2.getString("dest_city")%>
							<%}}
							while(rs2.next());
							%>


						</div>
					<%}%>
				</div>
			</td>


			<td>
				<div class="time">
					<%
					String arr_time=rs.getString("arr_time");
					arr_time=arr_time.substring(0,arr_time.lastIndexOf(':'));
					%>
					<strong><%=arr_time%></strong><br>
				</div>

				<div class="city">
					<%=rs.getString("dest_city")%>
				</div>
								
			</td>

			<%
				if(disc==null)
				{
			%>
			<td>
				<div class="actual-price">
					<strong>&#x20b9;<%=rs.getString("price")%></strong>
				</div>
			</td>	
			<% } else {	%>
				<td>
					<div class="actual-price-discount">
						&#x20b9;<%=rs.getString("price")%>
					</div>
					<div class="actual-price price-discount">
						<strong>&#x20b9;<%=disc_price%></strong>
					</div>
				</td>

			<%}%>

		</tr>
	<%}
	while(rs.next());
	}%>

</table>
</div>
</body>


<script type="text/javascript">
	function validate_and_submit(){
		// var src=document.getElementById("src").value;
		// var dest=document.getElementById("dest").value;
		// if(src===dest)
		// {
		// 	//Error
		// 	alert("Source and destination city cannot be same");
		// }
		// else
			document.getElementById("filter-form").submit();
	}
</script>


</html>