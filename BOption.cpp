#include "DLL.cpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    DLL_list<string> string_list;


    string_list.insertRear("Ford with 4 doors");
    string_list.insertFront("Ford with 2 doors");
    string_list.printList();

}