/*
DM - 17Apr2022
following code used to show use of linked list C++ using classes
*/

#include <iostream>


// -------------------    Element Class    --------------------- //
class list_element{
public:
    list_element(int v = 0, list_element* ptr = nullptr): val(v), next(ptr){}
    int get_value() { return val; }
    list_element *next_item() { return next; };
    void print_elem() { std::cout << this << " holds value: " << static_cast<char>(val) << std::endl; };
    void set_next(list_element *n) { next = n; }

private:
    int val;
    list_element *next;
};



// ---------------------    List Class    ----------------------- //
class list{
public:
    //Constructors
    list(): head(nullptr), cursor(nullptr){}
    list(const list &list);         //Copy Constructor

    void prepend(int n);            //insert value at start of list
    int get_element() { return cursor->get_value(); };
    void advance() { cursor = cursor->next_item(); };
    void print_list();
    ~list();

private:
    list_element *head;
    list_element *cursor;
    void rec_delete(list_element *elem);
    
};

void list::prepend(int n){
    if(head == nullptr)   //empty list
        cursor = head = new list_element(n, head); //create a new object which is an element of list
    
    else                  //add to the front of list
        head = new list_element(n, head);

}

void list::print_list(){
    cursor = head;
    while (cursor != nullptr)
    {
        cursor->print_elem();
        advance();
    }
    cursor = head;
}


//copy constructor
list::list(const list &cp_list): head(nullptr), cursor(nullptr){    
    if(cp_list.head == nullptr){    //if copy list is empty then we leave head and cursor as null
        return;
    }

    //We copy values to the new list starting at the head
    //rather than prepending we are appending here
    list_element *cp_item = cp_list.head;
    head = new list_element(cp_item->get_value(), nullptr);
    list_element *prev = head, *temp;
    cp_item = cp_item->next_item();

    //copy until we reach end of list
    while (cp_item != nullptr)
    {
        temp = new list_element(cp_item->get_value(), nullptr);
        prev->set_next(temp);
        prev = temp;
        cp_item = cp_item->next_item();
    }
    return;
    //Note we could easily use recursive format for this - can be easier becuase we can use prepending
}




void list::rec_delete(list_element *elem)
{
    if (elem == nullptr)
        return;

    rec_delete(elem->next_item());
    std::cout << "Deleting " << static_cast<char>(elem->get_value()) << std::endl;
    delete elem;
    return;
}

list::~list(){
    std::cout << "Destructor called\n";
    rec_delete(head);
}



// ---------------------    Main Function    ----------------------- //

int main(void)
{
    
    
    list list1;
    list1.prepend('D');
    list1.prepend('I');
    list1.prepend('V');
    list1.prepend('A');
    list1.prepend('D');

    //list1.print_list();

    list list2(list1);
    list2.prepend('M');
    list2.print_list();

}