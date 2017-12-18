/*********************************************************************
** Program Filename: list.cpp
** Author: brian palmer
** Date: 10.22.16
** Description: list class implementation file
** Input: list.hpp
** Output: none
*********************************************************************/

#include "list.hpp"

/************
* getSize
* preReq: none
* parameters: none
* post: none
* descrition: returns size
*************/

int List::getSize() const
{
	return size;
}

/************
* setSize
* preReq: none
* parameter: none
* post: none
* description: sets size
*************/

void List::setSize(int s)
{
	size = s;
}

/***************
* getlist
* preReq: member should be set
* parameters: none
* post: none
* description: returns pointer to item pointers
**************/

Item ** List::getList() const
{
	return list;
}

/**************
* setLIst
* preReq: none
* parameters: none
* post: none
* description: sets list member
****************/

void List::setList(Item ** l)
{
	list = l;
}

/*************
* getNumItems
* preReq: none
* parameters: none
* post: none
* description: get num items
*************/

int List::getNumItems() const
{
	return num_items;
}

/**************
* setNumItems
* preReq: none
* parameters: int
* post: none
* description: returns num items
***************/

void List::setNumItems(int i)
{
	num_items = i;
}

/*********************************************************************
* constructor
* preReq: none
* parameters: none
* post: none
* description: constructor for list object
*********************************************************************/

List::List()
{
	Item ** temp = new Item * [4];
	setSize(4);
	setNumItems(0);
	for (int i = 0; i < 4; i++)
		temp[i] = NULL;

	setList(temp);
}
/*********************************************************************
* Function: calcTotalCost
* Description: multiplies item quantity with price to get total cost
* Parameters: none
* pre conditions: item should be removed or added
* post conditions: display should continue to show correct total cost
* return: void
*********************************************************************/
void List::calcTotalCost()
{
	double cost = 0;
	for (int i = 0; i < getNumItems(); i++)
	{
		cost += list[i]->getExtPrice();
	}
	setTotalCost(cost);
}

void List::setTotalCost(double d)
{
	total_cost = d;
}

double List::getTotalCost()
{
	return total_cost;
}

/*********************************************************************
* destructor
* prereq: none
* parameters: none
* post: none
* description: destorys list object
*********************************************************************/

List::~List()
{
	Item ** temp = getList();
	int num = getNumItems();
	if (num > 0)
	{
		for (int i = 0; i < num; i++)
			delete temp[i];
		delete [] temp;
	}
}

/*********************************************************************
* addItem
* preReq: none
* parameters: none
* post: none
* description: faciliates user entering item contents
*********************************************************************/

void List::addItem()
{
	string input = itemName();
	cout << "\nHow many items are you adding? (1 - 25)" << endl;
	int num = facilitateIntInput(1,26);

	string unit = facilitateValidUnitInput();

	cout << "\nWhat is the price of the item? (NNN.NN)" << endl;
	double price = facilitateMoneyInput(0.00,1000.00);

	Item * ptr = NULL;
	ptr = new Item(input, num, price, unit);
	maybeExtendList();
	Item * match = findMatch(ptr);
	if (match != NULL)
	{
		addToQuantity(match, num);
	}
	else
	{
		addToEnd(ptr);
	}
	calcTotalCost();

}

/*********************************************************************
* maybeExtendList()
* preReq: none
* parameters: none
* post: none
* description: maybe doubles size of list
*********************************************************************/

void List::maybeExtendList()
{
	if (getNumItems() >= getSize())
		extendList();
}


/************
* ExtendList()
* preReq: none
* parameters: none
* post: none
* description: doubles list size
***************/

void List::extendList()
{
	Item ** temp = new Item * [size * 2];
	for (int i = 0; i < (size * 2); i++)
		temp[i] = NULL;
	for (int i = 0; i < num_items; i++)
		temp[i] = list[i];
	delete [] list;
	list = temp;
	setSize(size * 2);
}

/*************
* Shorten List
* preReq: Quotient of size of list and number of items should equal 2.
* parameters: none
* post: none
* description: this function shortens the list by half
*********************/

void List::shortenList()
{
	int size = getSize();
	int num = getNumItems();
	Item ** temp = new Item * [size/2];
	int i = 0;
	while ( i < num )
	{
		temp[i] = list[i];
		i++;
	}
	delete [] list;
	list = temp;

	setSize(size/2);
}

/************
* findMatch
* preReq: none
* parameters: Item pointer
* post: returns item if there is a matching item
* description: returns item if there is a matching item
***************/

Item * List::findMatch(Item * user) const
{
	Item * match = NULL;
	int counter = 0;
	if (num_items == 0)
	{
		return match;
	}
	else
	{
		while (counter < num_items)
		{
			if ( *list[counter] == *user)
			{
				match = list[counter];
				counter++;
			}
			else
				counter++;
		}
	}
	return match;
}

/**************
* addToQuantity
* preReq: The user is entering an item that already exists in the list
* parameters: Item *, int
* post: quantity of item in list should be updated
* description: updates the quantity member of an item
*******************/

void List::addToQuantity(Item * match, int numItems)
{
	match->setQuantity(match->getQuantity() + match->getQuantity());
	match->calcExtPrice();
}

/***************
* subtractFromQuantity
* preReq: the users is removing an item that already exists in the list, and doesnt want to remove it completely
* parameters: Item *, int
* post: quantity of item should be updated
* description: updates the quantity of an item
*****************/

void List::subtractFromQuantity(Item * match, int numItems)
{
	match->setQuantity(match->getQuantity() - numItems);
	match->calcExtPrice();
}

/****************
* addToEnd
* preReq: item should not already exist in the list
* parameters: Item *
* post: item will be added the first NULL Item * in the list
* description: item will be added to the last available NULL position
*****************/
void List::addToEnd(Item * user)
{
	int i = 0;
	while(list[i] != NULL) { i++; };
	list[i] = user;
	num_items++;

}

/*****************
* itemName()
* preReq: none
* parameters: none
* post: none
* description: outputs valid name
******************/

string List::itemName()
{
	string input;
        cout << "What is the name of the item?" << endl;
        input = facilitateNameInput();
	return input;
}

/***************
* deletion
* preReq: user is removing an item from the List
* paramters: Item *
* post: triggers deleteItem(), sort(), and maybeShortenList() subfunctions
* description: removes an object from the list
******************/

void List::deletion(Item * match)
{
	deleteItem(match);
	setNumItems(num_items - 1);
	sort();
	maybeShortenList();
}

/****************
* removeItem
* preReq: none
* parameters: none
* post: either removes an item, mutates item quantity, or does nothing via subfunctions
* description: facilitates the removal of an item
***************/

void List::removeItem()
{
	string input = itemName();
	Item * user = new Item(input);
	Item * match = findMatch(user);
	if (match == NULL)
	{
		cout << "Couldn't find a match!" << endl;
	}
	else
	{
		int quantity = match->getQuantity();
		cout << "How many items would you like to remove? (0 - " << quantity << ")" << endl;
		int num = facilitateIntInput(0, quantity + 1);
		if (quantity == num)
		{
			deletion(match);
		}
		else
		{
			subtractFromQuantity(match, num);
		}
	}
	delete user;
	calcTotalCost();
}

/***************
* maybeShortenList
* preReq: item should be deleted from list and num items member updated
* parameters: none
* post: either does nothing or triggers shortenList function
* description: Shortens the list by half if quotient between size and num of items is 2
******************/

void List::maybeShortenList()
{
	if (getNumItems() > 3 && (getSize() / getNumItems() == 2))
	{
		shortenList();
	}
}

/***************
* sort
* preReq: item was just deleted and item pointer set to NULL
* parameter: none
* post: all the items will be grouped together
* description: groups all items together so there are no randomly dispersed NULL ptrs
************************/

void List::sort()
{
	int num = getNumItems();
	int i = 0;
	while (i < num)
	{
		if (list[i] == NULL && list[i + 1] != NULL)
		{
			swapItems(list[i], list[i+1]);
		}
		i++;
	}
}

/*************
* swapItems
* preReq: just deleted an item from the list
* parameters: Item * & a, Item * & b
* post: items positions will be swaped
* description: swaps positions of items
**************/

void List::swapItems(Item * & a, Item * & b)
{
	Item * temp = b;
	b = a;
	a = temp;
}

/************
* print()
* preReq: none
* parameters: none
* post: none
* description: displays all members of each items in list, number of items in list,
size of list, and total cost
***************/

void List::print()
{

	cout << endl;
	cout << setw(25) << "::Items::" << endl;

	cout << setw(10) << "Name" << setw(10) << "Quantity" << setw(10)<< "UnitPrice" << setw(10) << "Units" << setw(10) << "TotPrice" << endl;
	int counter = 0;
	while (counter < num_items)
	{
		cout << setw(10) << list[counter]->getName() << setw(10) << list[counter]->getQuantity() << setw(10) << list[counter]->getUnitPrice() << setw(10) << list[counter]->getUnit() << setw(10) << list[counter]->getExtPrice() << endl;
		counter++;
	}
	cout << " --> Size of Grocery List: " << size << endl;
	cout << " --> Number of items: " << num_items << endl;
	cout << " --> Total Cost: " << getTotalCost() << endl;
}

/***************
* deleteItem
* preReq: none
* Parameters: Item *
* post: deletes item
* description: deletes item
*************/

void List::deleteItem(Item * obj)
{
	int i = 0;
	while (i < num_items)
	{
		if (list[i] == obj)
		{
			delete list[i];
			list[i] = NULL;
		}
		else
			i++;
	}
}
