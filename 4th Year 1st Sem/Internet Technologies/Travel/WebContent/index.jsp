<!DOCTYPE html>
<html>
<head>
<title>Home</title>



</head>
<body>

<!-- Title bar -->
<div class="title-bar">
<h1> TravelThruAir </h1>
</div>


<%
		
	DAO dao=(DAO)session.getAttribute("dao");
	ResultSet rs;
	rs=dao.getCitites();
%>


<!-- Form -->
<div class="travel-form">
	<form action="/search" method="post">
		<select class="src" name="src">
			<%
				do
				{%>
					<option value="<%=rs.getString("code")%>"> <%=rs.getString("city")%> </option>
				<%}
				while(rs.next());
				rs=dao.getCitites();
			%>
		</select>

		<select class="dest" name="dest">
			<%
				do
				{%>
					<option value="<%=rs.getString("code")%>"> <%=rs.getString("city")%> </option>
				<%}
				while(rs.next());
			%>
		</select>

		<input type="date" name="date">
		<input type="submit" value="submit">
		
	</form>
</div>

<!-- Offers -->
<div class="offers">
	
</div>

</body>
</html>