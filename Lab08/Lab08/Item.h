#pragma once
/*
Task 2:  Create a class to be used as the item stored in the list.  This class will be a part.  
		 It should have the following members at a minimum.
1.   Private:
	a.   SKU – stock keeping number
	b.   Description
	c.   Price
	d.   UOM - Unit of measure (is it sold by the foot, pound, each, etc...)
	e.   QuantityOnHand
	f.   LeadTime (number of days it takes to order if there aren’t any on hand to sell)
2.   Public:
	a.   Constructor – This accepts parameters for SKU, Description, Price, and UOM.  
		 It has an optional parameter for QuantityOnHand which if missing is set to 0.
	b.   GetPartInfo – this returns a string containing both SKU concatenated with Description
	c.   GetPrice
	d.   InStock – returns a bool indicating if the QuantityOnHand is > 0.  
	e.   Available – accepts a date.  This returns true if QuantityOnHand is > 0. If it isn’t, 
		 it calculates if the desired date is > LeadTime (added to current date) and returns the results of that comparison
	f.   Overloads of the >, < and == operators that compare the SKU member of two-Part instances.
Complete this before moving on to task 3.
*/

class Item
{
};

