/*
    Elisha Dollinger
    Practice10
    CPSC2376
    Spring 2025
 */

#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

//Makes the initial shape to be overridden
class Shape
{
    public:
        virtual double getArea() const = 0;
    //Virtual destructor to destroy the virtual shapes
    virtual ~Shape(){}
};

/*
    Derived class for the rectangle
    Here, we have the width and height of the rectangle
    Then, we have a rectangle constructor and override the getArea() function to
    print the correct area using the rectangle formula for area
*/
class Rectangle : public Shape
{
    private:
        double width;
        double height;
    public:
        Rectangle(double width, double height) : width(width), height(height) {}
        double getArea() const override
        {
            return width*height;
        }
};

/*
    Derived class for the circle
    Here, we have the radius of the circle
    Then, we have a circle constructor and override the getArea() function to
    print the correct area using the circle formula for area and use M_PI for pi
*/
class Circle : public Shape
{
    private:
        double radius;
    public:
        Circle(double radius) : radius(radius) {}
        double getArea() const override
        {
            return M_PI*radius*radius;
        }
};

/*
    Prints the area of each shape, both rectangle and circle, to four decimals
*/
void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes)
{
    for(int i = 0; i < shapes.size(); i++)
    {
        std::cout << std::fixed << std::setprecision(4) << "Area: " << shapes[i]->getArea() << std::endl;
    }
}

int main()
{
    /*
        Vector of unique pointers
        The unique_ptr gives a specific pointer to each item in the vector, in
        this case the items being of the type "Shape"
    */
    std::vector<std::unique_ptr<Shape>> shapes;
    std::ifstream fileOfShapes("shapes.txt");
    
    /*
        If the file is not open, give an error and end the code
        Otherwise, determine the specific shape based on the type of shape
        listed in "shapes.txt"
        If the type of shape is a rectangle, read in the width and the height
        from the text file and create a new rectangle using the width and height
        If the type of shape is a circle, read in the radius from the text file
        and create a new circle using the radius
    */
    if(!fileOfShapes.is_open())
    {
        std::cout << "Error: File does not exist." << std::endl;
        return 0;
    }
    else
    {
        std::string typeOfShape;
        
        /*
            I used std::move() in this case to demonstrate how it works
            Here, we make a unique pointer of type "auto" to store the shape
            based on the type in the text file
            Then, the code transfers ownership of the pointer to the vector
            using "shapes.push_back(std::move(insert specific pointer here))"
        */
        while(fileOfShapes >> typeOfShape)
        {
            if(typeOfShape == "rectangle")
            {
                double width;
                double height;
                fileOfShapes >> width >> height;
                auto recPtr = std::make_unique<Rectangle>(width, height);
                shapes.push_back(std::move(recPtr));
            }
            else if(typeOfShape == "circle")
            {
                double radius;
                fileOfShapes >> radius;
                auto cirPtr = std::make_unique<Circle>(radius);
                shapes.push_back(std::move(cirPtr));
            }
        }
        
        //This prints the area of all the shapes
        printAllAreas(shapes);
    }
    return 0;
}
