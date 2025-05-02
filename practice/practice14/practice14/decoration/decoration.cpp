/*
    Elisha Dollinger
    Practice14
    CPSC2376
    Spring 2025
 */

#include <iostream>
#include <memory>
#include <string>
#include <iomanip>
#include <limits>

//Class with generic info for the purchase
class Purchase
{
    public:
        virtual double getCost() const = 0;
        virtual ~Purchase() = default;
};

//Class that returns the base cost
class SimplePurchase : public Purchase
{
    double baseCost;
    public:
        explicit SimplePurchase(double cost) : baseCost(cost) {}
        double getCost() const override
        {
            return baseCost;
        }
};

//Constructor to allow for purchase decorations to be applied
class PurchaseDecorator : public Purchase
{
    protected:
        std::shared_ptr<Purchase> purchase;
    public:
        explicit PurchaseDecorator(std::shared_ptr<Purchase> p) : purchase(std::move(p)) {}
};

//Applies the tax to the purchase, which is 10%
class TaxDecorator : public PurchaseDecorator
{
    public:
        TaxDecorator(std::shared_ptr<Purchase> p) : PurchaseDecorator(std::move(p)) {}
        double getCost() const override
        {
            return purchase->getCost() * 1.1;
        }
};

//Applies the shipping fee to the purchase, which is $9.00
class ShippingFeeDecorator : public PurchaseDecorator
{
    public:
        ShippingFeeDecorator(std::shared_ptr<Purchase> p) : PurchaseDecorator(std::move(p)) {}
        double getCost() const override
        {
            return purchase->getCost() + 9;
        }
};

//Applies the discount to the decorator, which is 2.5%
class DiscountDecorator : public PurchaseDecorator
{
    public:
        DiscountDecorator(std::shared_ptr<Purchase> p) : PurchaseDecorator(std::move(p)) {}
    
        double getCost() const override
        {
            return purchase->getCost() * 0.975;
        }
};

//Simple user interface
int userInterface()
{
    int choice;
    std::cout << "Menu:" << std::endl;
    std::cout << "\t1: Get the base price of the product." << std::endl;
    std::cout << "\t2: Get the current price of the product." << std::endl;
    std::cout << "\t3: Check the price of the product with tax." << std::endl;
    std::cout << "\t4: Check the price of the product with the shipping fee." << std::endl;
    std::cout << "\t5: Check the discounted price of the product (2.5% discount)." << std::endl;
    std::cout << "\t6: Get the final price of the product and exit." << std::endl;
    std::cout << "Your choice: ";
    std::cin >> choice;
    while(choice < 1 || choice > 6 || std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: Invalid choice.\nYour choice: ";
        std::cin >> choice;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
}

/*
    We have limits so that the user will not go overboard or below
 */
int main()
{
    std::shared_ptr<Purchase> p = std::make_shared<SimplePurchase>(100.0);
    double basePrice = p->getCost();
    int userChoice = userInterface();
    bool stillGoing = true;
    while(stillGoing)
    {
        if(userChoice == 1)
        {
            std::cout << "Base price: $" << basePrice << std::endl;
        }
        else if(userChoice == 2)
        {
            std::cout << "Current price: $" << p->getCost() << std::endl;
        }
        else if(userChoice == 3)
        {
            if(p->getCost() > 175)
            {
                std::cout << "Error: Price is too high. Please lower." << std::endl;
            }
            else
            {
                p = std::make_shared<TaxDecorator>(p);
                std::cout << "Tax(10%) included: $" << std::fixed << std::setprecision(2) << p->getCost() << std::endl;
            }
        }
        else if(userChoice == 4)
        {
            if(p->getCost() > 175)
            {
                std::cout << "Error: Price is too high. Please lower." << std::endl;
            }
            else
            {
                p = std::make_shared<ShippingFeeDecorator>(p);
                std::cout << "Shipping fee($9) included: $" << std::fixed << std::setprecision(2) << p->getCost() << std::endl;
            }
        }
        else if(userChoice == 5)
        {
            if(p->getCost() < 85)
            {
                std::cout << "Error: Cost is too low.\nIncrease the cost to apply a discount." << std::endl;
            }
            else
            {
                p = std::make_shared<DiscountDecorator>(p);
                std::cout << "Discount(2.5%) included: $" << std::fixed << std::setprecision(2) << p->getCost() << std::endl;
            }
        }
        else if(userChoice == 6)
        {
            std::cout << "Final price: $" << p->getCost() << std::endl;
            stillGoing = false;
            break;
        }
        userChoice = userInterface();
    }

    std::cout << "Exiting program..." << std::endl;
    return 0;
}
