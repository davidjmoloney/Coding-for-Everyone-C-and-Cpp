#include <iostream>


//We can now use classes instead of structs to create objects (instances)
//similar form but now we can declare functions within classes 

class rect {
public:             //Visibility is an important idea in classes - if something is 'public' it can be accessed at the object
                    //if something is 'private' it is only used with the classes and can not be accessed outside of it
    double h, w;
    
    //function created within the class
    double area_calc(void) {
        return (h * w);
    }

};


int main(void) {
    rect rect1;

    std::cout << "please enter height and width" << std::endl;
    std::cin >> rect1.h;
    std::cin >> rect1.w;
    
    double area = rect1.area_calc();    //call functions like variables using '.' notation

    std::cout << "The area of this rectangle is: " << area << std::endl;

}