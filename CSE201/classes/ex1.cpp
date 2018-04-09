#include <iostream>

using namespace std;

class Rectangle
{
    //Declare the public variables and the constructor
    //The constructor will just store variables
    public: 
        Rectangle(int x, int y);
        int area(void);
    
    //Declare private variables that will contain the width and height
    private:
        int width, height; 
};

//This will set the private variables = to the user inputs
Rectangle:: Rectangle( int x, int y)
{
    width = x;
    height = y;
}

//This will return the area of the rectangle
int Rectangle::area(void)
{
    return width * height;
}
int main()
{
    //Creates the rectangles and gives them their values
    Rectangle foo(3,4);
    Rectangle bar(5,5);
    //Displays the area of the rectangles
    cout << "The area of rectangle foo is: " << foo.area() << endl;
    cout << "The area of rectangle bar is: " << bar.area() << endl;
    
    //Declares the variables for the custom rectangle
    int input1, input2;
    cout << "Input the width and height and I will tell you the area" << endl;
    
    //stores the dimensions of the custom rectangle
    cout << "Width: ";
    cin >> input1;
    
    cout << "Length: ";
    cin >> input2;
    
    //Creates the rectangle and displays the area
    Rectangle custom(input1,input2);
    cout << endl << "The area of the custom rectangle is: " << custom.area() << endl;
}