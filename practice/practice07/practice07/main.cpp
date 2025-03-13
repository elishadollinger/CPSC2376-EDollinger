#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <unistd.h>

class Employee
{
    protected:
        std::string employeeName;
        int id;
        Employee(std::string name, int id) : employeeName(name), id(id) {}
    public:
        virtual double calculateSalary() const = 0;
        virtual void displayInfo() const
        {
            std::cout << "ID: " << id << ", Name: " << employeeName;
        }
        virtual ~Employee() = default;
};

class SalariedEmployee : public Employee
{
    protected:
        double monthlySalary;
    public:
        SalariedEmployee(std::string name, int id, double monthlySalary) : Employee(name, id), monthlySalary(monthlySalary) {}
        double calculateSalary() const override
        {
            return monthlySalary;
        }
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
        HourlyEmployee(std::string name, int id, double hourlyRate, int hoursWorked) : Employee(name, id),
        hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}
        double calculateSalary() const override
        {
            return hourlyRate*hoursWorked;
        }
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
        CommissionEmployee(std::string name, int id, double baseSalary, double salesAmount, double commissionRate)
        : Employee(name, id), baseSalary(baseSalary), salesAmount(salesAmount), commissionRate(commissionRate) {}
        
        double calculateSalary() const override
        {
            return baseSalary + (salesAmount * commissionRate);
        }
        void displayInfo() const override
        {
            Employee::displayInfo();
            std::cout << ", Type: Commission, Base Salary: $" << baseSalary << ", Sales: $" << salesAmount;
            std::cout << ", Commission Rate: " << commissionRate * 100 << "%, Salary: $" << calculateSalary();
        }
};

int main()
{
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    std::cout << "Current Working Directory: " << cwd << std::endl;
    std::vector<Employee*> employees;
    
    std::ifstream fin("employees.txt");
    
    if(!fin)
    {
        std::cout << "Error opening file." << std::endl;
        return 0;
    }
    
    std::string line;
    while(std::getline(fin, line))
    {
        std::string type;
        std::string name;
        int id;
        
        std::istringstream iss(line);
        iss >> type >> id >> name;
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

    std::cout << "--- Employee Records ---" << std::endl;
    for (const auto &emp : employees)
    {
        emp->displayInfo();
    }

    for (auto emp : employees)
    {
        delete emp;
    }
    std::cout << "\n";
    return 0;
}
