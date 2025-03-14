#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>

class Employee
{
    //Here, we use "protected" instead of "private" to allow derived classes to use these variables
    protected:
        std::string employeeName;
        int id;
        Employee(std::string name, int id) : employeeName(name), id(id) {}
    public:
        //Purely virtual function
        virtual double calculateSalary() const = 0;
        //This displays the info that the user is guaranteed to have, such as their ID and name
        virtual void displayInfo() const
        {
            std::cout << "ID: " << id << ", Name: " << employeeName;
        }
        //Destructor
        virtual ~Employee() = default;
};

class SalariedEmployee : public Employee
{
    protected:
        double monthlySalary;
    public:
        //Constructor for salariedEmployee class
        SalariedEmployee(std::string name, int id, double monthlySalary) : Employee(name, id), monthlySalary(monthlySalary) {}
        /*Since the salaried employee is based off of their monthly salary, we just have to return said monthly salary
         We have to override these classes so that they are usable outside of the Emplooyee class*/
        double calculateSalary() const override
        {
            return monthlySalary;
        }
        /*Here, we print the basic info of the salaried employee(their name and ID), along with their type(salaried in this case) and their monthly salary*/
        void displayInfo() const override
        {
            Employee::displayInfo();
            std::cout << ", Type: Salaried, Monthly salary: $" << std::fixed << std::setprecision(2) << calculateSalary() << std::endl;
        }
};

class HourlyEmployee : public Employee
{
    protected:
        double hourlyRate;
        int hoursWorked;
    public:
        //Constructor for hourlyEmployee class
        HourlyEmployee(std::string name, int id, double hourlyRate, int hoursWorked) : Employee(name, id),
        hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}
        /*We have to return the hourly rate multiplied by the hours worked to correctly get the user's salary*/
        double calculateSalary() const override
        {
            return hourlyRate*hoursWorked;
        }
        /*Here, we print the basic info of the hourly employee(their name and ID), along with their type(hourly in this case), the hours they worked, their hourly rate and their accumulative salary*/
        void displayInfo() const override
        {
            Employee::displayInfo();
            std::cout << ", Type: Hourly, Hours worked: " << hoursWorked << ", Hourly Rate: $" << hourlyRate << ", Salary: $";
            std::cout << std::fixed << std::setprecision(2) << calculateSalary() << std::endl;
        }
};

class CommissionEmployee : public Employee
{
    protected:
        double baseSalary;
        double salesAmount;
        double commissionRate;
    public:
        //Constructor for CommissionEmployee Class
        CommissionEmployee(std::string name, int id, double baseSalary, double salesAmount, double commissionRate)
        : Employee(name, id), baseSalary(baseSalary), salesAmount(salesAmount), commissionRate(commissionRate) {}
        
        //To calculate the commissioned employee's salary, we have to multiply the sales amount and the commission rate, and add that to the base salary
        double calculateSalary() const override
        {
            return baseSalary + (salesAmount * commissionRate);
        }
        /*Here, we print the basic info of the hourly employee(their name and ID), along with their type(commissioned in this case), their base salary, their amount in sales, their commission rate and their accumulative salary*/
        void displayInfo() const override
        {
            Employee::displayInfo();
            std::cout << ", Type: Commission, Base Salary: $" << baseSalary << ", Sales: $" << salesAmount;
            std::cout << ", Commission Rate: " << std::fixed << std::setprecision(0) << commissionRate * 100 << std::fixed << std::setprecision(2) << "%, Salary: $" << calculateSalary() << std::endl;
        }
};

int main()
{
    //Vector using derived classes
    std::vector<Employee*> employees;
    
    std::ifstream fin("employees.txt");
    
    //If the code cannot open the file, print an error
    if(!fin)
    {
        std::cout << "Error opening file." << std::endl;
        return 0;
    }
    
    std::string line;
    //While the next line exists, keep taking the line with info
    while(std::getline(fin, line))
    {
        //Variables that are guaranteed to exist no matter the type of employee they are
        std::string type;
        std::string name;
        int id;
        /*Takes a line and stores the type of employee they are, their id and their name
        Here, we only have three types so we will check for those three types specifically*/
        std::istringstream iss(line);
        iss >> type >> id >> name;
        
        /*If the user is a salaried employee, create a monthlySalary variable, store the employee's monthly salary according to what is in the txt file, and create a salaried employee with these variables in the vector
         If the user is an hourly employee, create hourlyRate and hoursWorked variables, store the employee's hourly rate and hours worked according to what is in the txt file, and push back an hourly employee with these variables in the vector
         If the user is a commissioned employee, create baseSalary, salesAmount and commissionRate variables, store the employee's base salary, sales amount,  and commission rate according to what is in the txt file, and push back a commissioned employee with these variables in the vector*/
        if(type=="Salaried")
        {
            double monthlySalary;
            iss >> monthlySalary;
            employees.push_back(new SalariedEmployee(name, id, monthlySalary));
        }
        else if(type=="Hourly")
        {
            double hourlyRate;
            int hoursWorked;
            iss >> hourlyRate >> hoursWorked;
            employees.push_back(new HourlyEmployee(name, id, hourlyRate, hoursWorked));
        }
        else if(type=="Commission")
        {
            double baseSalary;
            double salesAmount;
            double commissionRate;
            iss >> baseSalary >> salesAmount >> commissionRate;
            employees.push_back(new CommissionEmployee(name, id, baseSalary, salesAmount, commissionRate));
        }
    }
    
    fin.close();

    std::cout << "Employee Records" << std::endl;
    
    /*For loop to iterate through each employee
    Each line is tabbed over and the info for each employee is displayed*/
    for (auto emp : employees)
    {
        std::cout << "\t";
        emp->displayInfo();
    }

    /*I had to use ChatGPT to figure out how to clear the memory
     I initially forgot this part. However, when I went back over the rubric, I remembered the necessity of it
     This deletes each employee in the vector*/
    for (auto emp : employees)
    {
        delete emp;
    }
    return 0;
}
