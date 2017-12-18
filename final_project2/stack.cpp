/*********************************************************************
** Program Filename: stack.cpp
** Author: brian palmer
** Date: 11.5.16
** Description: stack implementation
** Input: none
** Output: none
*********************************************************************/

#include "stack.hpp"

/*********************************************************************
** Function: find
** Description: searches for node in linked list that has an item pointer with
the same name as the argument
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: Node pointer
*********************************************************************/

Node * Stack::find(Item * obj)
{
        Node * iter = top;
        while (iter != NULL && iter->item->get_type() != obj->get_type())
        {
                iter = iter->next;
        }

        return iter;
}

/*********************************************************************
** Function: find
** Description: takes string argument and compares with items in linked list.
Returns true if a match was found in the list.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

bool Stack::find(string name)
{
        Node * iter = top;
        while (iter != NULL && cmpString(iter->item->get_type(), name) == false)
        {
                iter = iter->next;
        }
        if (iter != NULL)
                return true;
        else
                return false;
}

/*********************************************************************
** Function: get node
** Description: takes integer position (0 == front of the list) argument
and iterates through list until that position is found or the end of the list
is reached. Returns a pointer to that node.
** Parameters: integer
** Pre-Conditions: none
** Post-Conditions: none
** Return: Pointer to node
*********************************************************************/

Node * Stack::get_node(int pos)
{
        Node * iter = top;
        int i = 0;
        while (iter != NULL && i != pos)
        {
                iter = iter->next;
                i++;
        }
        return iter;
}

//// Used for debugging
// void Stack::debug()
// {
//         cout << endl;
//         Node * iter = top;
//         if (iter != NULL)
//         {
//                 while (iter->next != NULL)
//                 {
//                         cout << "iter = " << iter << endl;
//                         cout << "iter->item = " << iter->item->get_type() << endl;
//                         cout << "iter->prev = " << iter->prev << endl;
//                         cout << "iter->branch = " << iter->branch << endl;
//                         if (iter->branch != NULL)
//                         {
//                                 cout << "Heading down branch:\n";
//                                 Node * iter2 = iter->branch;
//                                 while (iter2->next != NULL)
//                                 {
//                                         cout << "iter = " << iter2 << endl;
//                                         cout << "iter->item = " << iter2->item->get_type() << endl;
//                                         cout << "iter->prev = " << iter2->prev << endl;
//                                         cout << "iter->branch = " << iter2->branch << endl;
//
//                                         iter2 = iter2->next;
//                                 }
//                                 cout << "iter = " << iter2 << endl;
//                                 cout << "iter->item = " << iter2->item->get_type() << endl;
//                                 cout << "iter->prev = " << iter2->prev << endl;
//                                 cout << "iter->branch = " << iter2->branch << endl;
//
//                                 iter2 = NULL;
//
//                         }
//                         cout << "iter->next = " << iter->next << endl;
//                         cout << endl;
//
//                         iter = iter->next;
//                 }
//                 cout << "iter = " << iter << endl;
//                 cout << "iter->item = " << iter->item->get_type() << endl;
//                 cout << "iter->prev = " << iter->prev << endl;
//                 cout << "iter->branch = " << iter->branch << endl;
//                 if (iter->branch != NULL)
//                 {
//                         cout << "\nHeading down branch:\n";
//                         Node * iter2 = iter->branch;
//                         while (iter2->next != NULL)
//                         {
//                                 cout << "iter = " << iter2 << endl;
//                                 cout << "iter->item = " << iter2->item->get_type() << endl;
//                                 cout << "iter->prev = " << iter2->prev << endl;
//                                 cout << "iter->branch = " << iter2->branch << endl;
//
//                                 iter2 = iter2->next;
//                         }
//                         cout << "iter = " << iter2 << endl;
//                         cout << "iter->item = " << iter2->item->get_type() << endl;
//                         cout << "iter->prev = " << iter2->prev << endl;
//                         cout << "iter->branch = " << iter2->branch << endl;
//
//                         iter2 = NULL;
//                         cout << "\nBack to trunk:\n";
//
//                 }
//                 cout << "iter->next = " << iter->next << endl;
//
//                 cout << "\nDone!\n";
//         }
//         else
//         {
//                 cout << "Top is NULL. Done!" <<endl;
//         }
// }


/*********************************************************************
** Function: open
** Description: provides user with operations to take on bag. Includes displaying contents
and throwing out items
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Stack::open()
{
        bool done = false;
        do
        {
                cout << "\t:::Bag:::\n\n";
                cout << "1) Display Contents\n";
                cout << "2) Throw Away Item\n";
                cout << "3) Exit\n";

                int choice = facilitateIntInput(1,4);
                Item * item = NULL;
                int c;
                switch(choice)
                {
                        case 1:
                                display();
                                break;

                        case 2:
                                cout << "What item do you want to throw away?" << endl;
                                cout << "[note]: press number in brackets to left of item" << endl;
                                display();
                                if (num_types != 0)
                                {
                                        c = facilitateIntInput(1, num_types+1);
                                        item = remove(c-1);
                                        if (item != NULL)
                                        {
                                                cout << "Threw away one " << item->get_type() << " away!" << endl;
                                                delete item;
                                        }
                                }
                                break;

                        case 3:
                                done = true;
                                break;
                }
        }
        while (done == false);
}

/*********************************************************************
** Function: maybe add
** Description: facilitates users action with found item. If the user wants
to add the item, the weight is checked to see if adding item will make bag too
heavy. If so, the item is returned back to it's hiding place. Otherwise it is added.
** Parameters: pointer to item
** Pre-Conditions: User should have found an item, and not NULL.
** Post-Conditions: Item is not added at this point. Add function should be used to add
the item. Read pre-conditions of add function.
** Return: returns true if item was added, false if not
*********************************************************************/

bool Stack::maybe_add(Item * obj)
{
        bool add = false;
        cout  << "Do you want to add the item to your bag?" << endl;
        char c = facilitateYNresponse();
        switch (c)
        {
                case 'Y':
                        if (check_weight(obj) == false)
                        {
                                cout << "\n** Adding the object will make your bag too heavy!\n";
                                cout << "Remove or use some objects to make bag lighter. ** \n\n";
                                cout << "The " << obj->get_type() << " was put back\n";
                        }
                        else
                                add = true;
                        break;

                case 'N':
                        cout << "The " << obj->get_type() << " was put back\n";
                        break;
        }
        return add;
}

/*********************************************************************
** Function: remove
** Description: Removes one item from the users backpack. First, a node pointer
traverses the list until it reaches the user-desired position. Once found, if a node
is assigned to the branch member (i.e. there is more than one of these items), that
node is removed and the next node is assigned to the branch. Otherwise, the first node
is removed from the main list (i.e. there are no more items of that type in the bag).
** Parameters: integer
** Pre-Conditions: user chooses item to remove with an integer, that is also +1
the nodes position. Argument should be users choice - 1.
** Post-Conditions: returns pointer to Item
** Return: returns pointer to Item
*********************************************************************/

Item * Stack::remove(int pos)
{
        Node * iter = top;
        int i = 0;
        while (iter != NULL && i != pos)
        {
                iter = iter->next;
                i++;
        }
        if (iter == NULL)
        {
                return NULL;
        }
        else if (iter->item->is_special() == true)
        {
                cout << "Can't throw away this item, you'll need it!" << endl;
                return NULL;
        }
        else
        {
                // remove items weight from backpack total weight
                weight-= iter->item->get_weight();

                // remove one from quantity for that item type
                iter->quantity--;

                // remove weight for that items type
                iter->type_weight -= iter->item->get_weight();
                if (iter->prev == NULL)
                {
                        if (iter->branch != NULL)
                        {
                                Node * iter2 = iter->branch;
                                iter->branch = iter2->next;
                                Item * item = iter2->item;
                                iter2->item = NULL;
                                iter2->next = NULL;
                                iter2->prev = NULL;
                                delete iter2;

                                iter = NULL;
                                return item;
                        }
                        else
                        {
                                num_types--;
                                top = iter->next;
                                Item * item = iter->item;
                                if (iter->next != NULL)
                                        iter->next->prev = NULL;
                                iter->item = NULL;
                                iter->prev = NULL;
                                iter->next = NULL;
                                iter->branch = NULL;

                                delete iter;

                                return item;
                        }
                }
                else if (iter->branch == NULL)
                {
                        iter->prev->next = iter->next;
                        if (iter->prev != NULL)
                                iter->prev = NULL;
                        if (iter->next != NULL)
                                iter->next = NULL;
                        Item * item = iter->item;
                        //iter->tot_weight -= item->get_weight();
                        iter->item = NULL;
                        num_types--;
                        delete iter;
                        return item;
                }
                else
                {
                        Node * iter2 = iter->branch;
                        Item * item = iter2->item;
                        //iter->tot_weight -= item->get_weight();
                        iter->branch = iter2->next;
                        iter2->next = NULL;
                        iter2->prev = NULL;
                        iter2->branch = NULL;
                        iter2->item = NULL;
                        delete iter2;
                        return item;
                }
        }
}

/*********************************************************************
** Function: add
** Description: first, the function checks whether there is at least one item
of the same type already in the list. If so, the item is assigned to the branch member.
If a list already exists, the list is assigned to the node next member (the series of operations
replicates adding to a stack). If no category exists for that item, the item is added to the front of
the main list (like a stack).
** Parameters: Pointer to item
** Pre-Conditions: Any passed Item pointer argument should be from get_accessor members and not
check_accessor members. Get Accessors remove the item completely from their hiding place,
whereas check_accessors provide a pointer to the item.
** Post-Conditions: Only Node item members should be pointing to added items
** Return: none
*********************************************************************/

void Stack::add(Item * obj)
{
        Node * iter = find(obj);
        //num_items++;
        weight += obj->get_weight();
        if (iter == NULL)
        {
                top = new Node(obj, top);
                top->quantity++;
                top->type_weight+=obj->get_weight();
                obj = NULL;
                iter = NULL;
                num_types++;
        }
        else
        {
                iter->branch = new Node(obj, iter->branch);
                iter->quantity++;
                iter->type_weight += obj->get_weight();
                obj = NULL;
                iter = NULL;
        }
}

/*********************************************************************
** Function: check_weight
** Description: determines if adding item to bag will make bag too heavy
** Parameters: Item pointer
** Pre-Conditions: none
** Post-Conditions: none
** Return: bool
*********************************************************************/

bool Stack::check_weight(Item * obj)
{
        float tot = obj->get_weight() + weight;
        if (tot > 7.00)
                return false;
        else
                return true;
}

/*********************************************************************
** Function: display
** Description: lists contents of bag by item type, including the number
of items of that type and weight makeup
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Stack::display()
{
        int count = 1;
        cout << "\t:::Bag Contents:::\n\n";
        cout << "[#]" << setw(10) << "Item" << setw(10) << "Qty" << setw(10) << "Wt";
        cout << "\n==================================\n";
        Node * temp = top;
        if (temp == NULL)
        {
                cout << setw(10) << "  *** EMPTY ***" << setw(10) << "*** EMPTY ***" << setw(10) << "*** EMPTY ***" << "\n";
        }
        else
        {
                while (temp->next != NULL)
                {
                        cout << "[" << count << "]";
                        cout << setw(10) << temp->item->get_type() << setw(10) << temp->quantity;
                        cout << setw(10) << temp->type_weight << "\n";
                        temp = temp->next;
                        count++;
                }
                cout << "[" << count << "]";
                cout << setw(10) << temp->item->get_type() << setw(10) << temp->quantity;
                cout << setw(10) << temp->type_weight << "\n";
                cout << "Bag Weight: " << weight << " lbs\n\n";
                //cout << "==========================================\n";
                //cout << setw(10) << num_types << setw(10) << num_items << setw(10) << weight << "\n";
        }

}

// Creature * Stack::peek()
// {
//         if (top == NULL)
//                 return NULL;
//         else
//                 return top->creature;
// }

bool Stack::is_empty()
{
        if (top == NULL)
                return true;
        else
                return false;
}

// /*********************************************************************
// ** Function: pop
// ** Description: removes the top node in the stack and returns the value
// ** Parameters:  none
// ** Pre-Conditions: none
// ** Post-Conditions: none
// ** Return: integer
// *********************************************************************/
//
// Creature * Stack::pop()
// {
//         if (is_empty() == true)
//         {
//                 Creature * temp = NULL;
//                 return temp;
//         }
//         else
//         {
//                 Creature * output = top->creature;
//                 Node * temp = top;
//                 top = top->next;
//                 delete temp;
//
//                 return output;
//         }
// }

// /*********************************************************************
// ** Function: push(int)
// ** Description: adds an integer to the front of the list
// ** Parameters: int
// ** Pre-Conditions: none
// ** Post-Conditions: should return user to stack menu
// ** Return: none
// *********************************************************************/
//
// void Stack::push(Node * v)
// {
//         top = new Node(v, top);
// }

/*********************************************************************
** Function: Stack constructor
** Description: creates stack
** Parameters:  none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Stack::Stack()
{
        top = NULL;
        weight = 0.00;
        num_types = 0;
        //num_items = 0;
}


/*********************************************************************
** Function: Stack destructor
** Description: destroys stack
** Parameters:  none
** Pre-Conditions: none
** Post-Conditions: no dangling pointers
** Return: none
*********************************************************************/

Stack::~Stack()
{
        while (top != NULL)
        {
                Node * temp = top;
                top = top->next;
                delete temp;
        }
}
