#ifndef __LIST_B
#define __LIST_B

#include <cstddef>

//creating the node
template<class Generic>
struct DLL_item
{
    Generic value;
    DLL_item<Generic>* next; //pointer to the next node
    DLL_item<Generic>* previous; //pointer to the previous node

    DLL_item(Generic a_value)
    {
        this ->value = a_value;
        this -> next = NULL;
        this -> previous = NULL;
    }
};


//Generic class for the list
template<class Generic>
class DLL_list
{
DLL_item<Generic>* head;
DLL_item<Generic>* tail;
public:
    //the constructor
    DLL_list(/* args */);

    //the deconstructor
    ~DLL_list();

    //inserting functions
    void insertFront(Generic item); //insert in the front of the List
    void insertRear(Generic item); //insert at the back of the list

    //deleting functions
    void deleteBoV(); //will more than likely need to pass thru the item I am searching for but lets see how it works as of now
    void deleteHead();

    //print function
    void printList();
};
#endif
