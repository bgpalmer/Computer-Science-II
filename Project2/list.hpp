/*********************************************************************
** Program Filename: list.hpp
** Author: brian palmer
** Date: 10.22.16
** Description: list class template and prototype declarations
** Input: "item.hpp", "helper_functions.hpp","validation.hpp"
** Output: none
*********************************************************************/

#ifndef _LIST_
#define _LIST_

#include "item.hpp"
#include "helper_functions.hpp"
#include "validation.hpp"

class List
{
private:
	Item ** list;
	int num_items;
	int size;
	double total_cost;

public:
	List();
	~List();

	void setSize(int);
	int getSize() const;

	Item ** getList() const;
	void setList(Item ** );
	int getNumItems() const;
	void setNumItems(int);
	void addItem();
	void maybeExtendList();
	void extendList();
	void shortenList();
	void maybeShortenList();
	Item * findMatch(Item *) const;
	void subtractFromQuantity(Item *, int);
	void addToQuantity(Item *, int);
	void addToEnd(Item *);

	void sort();
	string itemName();
	void removeItem();
	void shift();
	void swapItems(Item * &, Item * &);
	void print();
	void deleteItem(Item *);
	void deletion(Item *);
	void calcTotalCost();

	void setTotalCost(double);
	double getTotalCost();

};

#endif
