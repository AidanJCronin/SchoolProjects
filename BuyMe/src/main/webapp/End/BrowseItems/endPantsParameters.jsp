<!DOCTYPE html>
<html>
	<head>
		<link rel='stylesheet' href='../../CSS/navbar.css'>
		<link rel='stylesheet' href='../../CSS/params.css'>
		<title>Set Search Parameters</title>
	</head>
	<body class='body'>
<div class = 'navbar'>
			<a href='../endMain.jsp'>Home</a>
			<div class = 'dropdown'>
				<button class='dropbtn'>Create a new listing</button>
					<div class='dropdown-content'>
						<a href='../CreateAuction/footwearListing.jsp'>Footwear</a>
						<a href='../CreateAuction/pantsListing.jsp'>Pants</a>
						<a href='../CreateAuction/shirtListing.jsp'>Shirts</a>
					</div>
			</div>
			<div class='dropdown'>
				<button class='dropbtn'>Browse active listings</button>
				<div class='dropdown-content'>
					<a href='../BrowseAuctions/endFootwearParameters.jsp'>Footwear</a>
					<a href='../BrowseAuctions/endPantsParameters.jsp'>Pants</a>
					<a href='../BrowseAuctions/endShirtParameters.jsp'>Shirts</a>
				</div>
			</div>
			<div class='dropdown active'>
				<button class='dropbtn'>Browse Items</button>
				<div class='dropdown-content'>
					<a href='endFootwearParameters.jsp'>Footwear</a>
					<a href='endPantsParameters.jsp'>Pants</a>
					<a href='endShirtParameters.jsp'>Shirts</a>
				</div>
			</div>
			<a href='../BidHistory/searchAuctionHistory.jsp'>Browse Auction Bid Histories</a>
			<a href='../UserHistory/searchUserHistory.jsp'>Browse User Histories</a>
			<a href='../CustService/endCustomerService.jsp'>Customer Service</a>
			<a href='../Profile/endProfile.jsp'>Profile</a>
			<a href='../../logout.jsp' style='float:right'>Log out</a>
		</div>
		<div class='back'>
			<h1>Set your search parameters</h1>
			<p>Leave text box entries blank for no restrictions.</p>
			<form action="endBrowsePants.jsp" method="POST">
			<div class='lcolumn'>
				<label>Condition:</label>
				<select name="condition" id="condition">
					<option value="brandnew">Brand New</option>
					<option value="good">Used: Good</option>
					<option value="fair">Used: Fair</option>
				</select><br>
				<label>Manufacturing location (Country):</label>
				<input type="text" name="loc"/><br>
				<label>Brand:</label>
				<input type="text" name="brand"/><br>
				<label>Color:</label>
				<input type="text" name="color"/><br>
				<label>Design:</label>
				<input type="text" name="design"/><br>
				<label>Material:</label>
				<input type="text" name="material"/><br>
				<input type="submit" name="Search">
			</div>
			<div class='rcolumn'>
				<label>Child size?</label>
				<select name="child" id="child">
					<option value=false>No</option>
					<option value=true>Yes</option>
				</select><br>
				<label>Size:</label>
				<select name="size" id="size">
					<option value="any">Any</option>
					<option value="XS">XS</option>
					<option value="S">S</option>
					<option value="M">M</option>
					<option value="L">L</option>
					<option value="XL">XL</option>
					<option value="XXL">XXL</option>
				</select><br>
				<label>Pants type (jeans, khakis, etc.):</label>
				<input type="text" name="type"><br>
				<label>Pants style:</label>
				<input type="text" name="style"><br>
				<label>Gender:</label>
				<select name="gender" id="gender">
					<option value="Male">Male</option>
					<option value="Female">Female</option>
				</select><br>
			</div>
			</form>
		</div>
	</body>
</html>