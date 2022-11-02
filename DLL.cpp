#ifndef __DLLIST_PP
#define __DLL_PP

#include "DLL.h"
#include<iostream>
#include<string>
using namespace std;

//setting both the head and the tail to NULL
template<class Generic>
DLL_list<Generic>::DLL_list()
{
    head = NULL;
    tail = NULL;
}


//Memory management(needed for lower end machines, theoretically I SHOULD be okay)

template<class Generic>
DLL_list<Generic>::~DLL_list()
{
    for(int i = 0; i < 500; i++)
    {
        deleteHead();
    }
}


//inserting at the front/head/left of the list
template<class Generic>
void DLL_list<Generic>::insertFront(Generic item)
{
    if(head == NULL)//this will only run if the list is EMPTY
    {
        head = new DLL_item<Generic>(item); //creates the new node at the front of the list
        tail = head; //sets the end of the list to the front of the list
        return;
    }
    DLL_item<Generic> *Node = new DLL_item<Generic>(item);
    head ->previous = Node;
    Node ->next = head;
    head = Node;
}

//inserting at the rear/tail/right of the list
template<class Generic>
void DLL_list<Generic>::insertRear(Generic item)
{
    if(tail == NULL)
    {
        tail = new DLL_item<Generic>(item);//creates the node at the back of the list
        head = tail;//sets the front of the list to the end of the list
        return;

    }
    DLL_item<Generic> *Node = new DLL_item<Generic>(item);
    tail ->next = Node;
    Node ->previous = head;
    tail = Node;
}

//this will be where I implement the deleting portion

//deleting the head
template<class Generic>
void DLL_list<Generic>::deleteHead()
{
    if(head == NULL)
    {
        return;
    }
    else if (head -> next == NULL)
    {
        delete head;
        head = NULL;
        tail = NULL;

    }
    else
    {
        DLL_item<Generic>* current = head ->next;
        delete head;
        head = current;
        head ->previous = NULL;
    }
    
}

//printing the list
template<class Generic>
void DLL_list<Generic>::printList()
{
    if (head == NULL)
    {
        cout << "The list is empty";

    }
    else
    {
        DLL_item<Generic> *current = head;
        while (current != NULL)
        {
            if(current ->next != NULL)
            {
                cout << current -> value << "<=>";
            }
            else
            {
                cout << current -> value;
            }

            current = current -> next;
        }
        
    }
    
}

#endif