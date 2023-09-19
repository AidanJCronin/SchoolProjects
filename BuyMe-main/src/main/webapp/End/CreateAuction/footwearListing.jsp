<!DOCTYPE html>
<html>
	<head>
		<link rel='stylesheet' href='../../CSS/navbar.css'>
		<link rel='stylesheet' href='../../CSS/params.css'>
		<title>BuyMe Create Footwear Auction Page</title>
	</head>
	<body>
		<div class = 'navbar'>
			<a href='../endMain.jsp'>Home</a>
			<div class = 'dropdown active'>
				<button class='dropbtn'>Create a new listing</button>
					<div class='dropdown-content'>
						<a href='footwearListing.jsp'>Footwear</a>
						<a href='pantsListing.jsp'>Pants</a>
						<a href='shirtListing.jsp'>Shirts</a>
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
			<div class='dropdown'>
				<button class='dropbtn'>Browse Items</button>
				<div class='dropdown-content'>
					<a href='../BrowseItems/endFootwearParameters.jsp'>Footwear</a>
					<a href='../BrowseItems/endPantsParameters.jsp'>Pants</a>
					<a href='../BrowseItems/endShirtParameters.jsp'>Shirts</a>
				</div>
			</div>
			<a href='../BidHistory/searchAuctionHistory.jsp'>Browse Auction Bid Histories</a>
			<a href='../UserHistory/searchUserHistory.jsp'>Browse User Histories</a>
			<a href='../CustService/endCustomerService.jsp'>Customer Service</a>
			<a href='../Profile/endProfile.jsp'>Profile</a>
			<a href='../../logout.jsp' style='float:right'>Log out</a>
		</div>
		<div class='back'>
			<h1>Create a new footwear listing</h1>
			<form action="addFootwear.jsp" method="POST">
				<div class='lcolumn'>
					<label>Name:</label>
					<input type="text" name="name"/>
					<label>Condition:</label>
					<select name="condition" id="condition">
						<option value="brandnew">Brand New</option>
						<option value="good">Used: Good</option>
						<option value="fair">Used: Fair</option>
					</select>
					<label>Manufacturing location (Country):</label>
					<input type="text" name="loc"/>
					<label>Brand:</label>
					<input type="text" name="brand"/>
					<label>Color:</label>
					<input type="text" name="color"/>
					<label>Design:</label>
					<input type="text" name="design"/>
					<label>Material:</label>
					<input type="text" name="material"/>
					<label>Auction end date and time:</label>
					<input type="datetime-local" name="endDate"/>
					<input type="submit" value="List Item">
				</div>
				<div class='rcolumn'>
					<label>Child size?</label>
					<select name="child" id="child">
						<option value=false>No</option>
						<option value=true>Yes</option>
					</select>
					<label>Shoe Size:</label>
					<input type="number" step="0.5" name="shoeSize">
					<label>Shoe Width:</label>
					<select name="width" id="width">
						<option value="Narrow">Narrow</option>
						<option value="Normal">Normal</option>
						<option value="Wide">Wide</option>
					</select>
					<label>Has an insole?</label>
					<select name="insole" id="insole">
						<option value="false">No</option>
						<option value="true">Yes</option>
					</select>
					<label>Securing method (laces, velcro, etc.):</label>
					<input type="text" name="method">
						<label>Purpose (running, casual, hiking, etc):</label>
					<input type="text" name="purpose">
					<label>Gender:</label>
					<select name="gender" id="gender">
						<option value="Male">Male</option>
						<option value="Female">Female</option>
					</select>
					<label>Minimum price (reserve):</label>
					<input type="number" step="0.01" name="reservePrice"/>
				</div>
			</form>
		</div>
	</body>
</html>