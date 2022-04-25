/*

DM - 11Apr2022
- Program to show the implenation of singly linked list in C++
- We see use of 'new' and 'delete' in this to show how to allocate memory to heap
- also see the use of destructors in classes to remove all heap memory allocation

*/


#include <iostream>

//struct definition of element
typedef struct slistelem{
    char data;
    slistelem *next;
} slistelem_t;

//class definition
class slist
{

public:
    slist() : head(0) { std::cout << "Constructing" << std::endl; } //Default Constructor - initialize a linked list to be empty
    void prepend(char c);
    ~slist();                   //Destructor - only one call exists - no signature - function used to delete what is required
    

private:
    slistelem_t *head;
    //Private method declarations - only the class will be able to access these 
    void release();
    void rec_delete(slistelem_t *head);


};





//Method definitions for slist class

//destructor for class - here we call release which will delete the memory allocation given to the elements of list
slist::~slist(){
    std::cout << "Destructor Called" << std::endl;
    release();
}

//method to add an element to the start of list
void slist::prepend(char c)                         //We can use the unary scope resolution operator to define methods outside of the scope of a class
{
    slistelem_t *temp = new slistelem_t;            //Allocation of memory
    temp->next = head;
    temp->data = c;
    head = temp;
}

//Method for delete memory allocation of the list
void slist::release()
{
    rec_delete(head);
}

void slist::rec_delete(slistelem_t *elem)
{
    if (elem == NULL)
        return;

    rec_delete(elem->next);
    std::cout << "Deleting " << elem->data << std::endl;
    delete elem;
    return;
}






int main (void){
    std::cout << "Press any key to start" << std::endl;
    char temp;
    std::cin >> temp;
    {
        slist list1;
        list1.prepend('D');
        list1.prepend('I');
        list1.prepend('V');
        list1.prepend('A');
        list1.prepend('D');
    }
    std::cout << "Press any key to finish" << std::endl;
    std::cin >> temp;
}