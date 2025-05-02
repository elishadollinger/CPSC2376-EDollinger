#include <iostream>
#include <memory>
#include <string>
#include <algorithm>
#include <cctype>
#include <functional>
#include <vector>

//Starting code to allow for the text to be filtered
class TextFilter
{
public:
    virtual std::string apply(const std::string& text) = 0;
    virtual ~TextFilter() = default;
};

//Sets the text to uppercase and returns said uppercased result
class UppercaseFilter : public TextFilter
{
    public:
        std::string apply(const std::string& text) override
        {
            std::string result = text;
            std::transform(result.begin(), result.end(), result.begin(), ::toupper);
            return result;
        }
};

//Sets the text to lowercase and returns said lowercased result
class LowercaseFilter : public TextFilter
{
    public:
        std::string apply(const std::string& text) override
        {
            std::string result = text;
            std::transform(result.begin(), result.end(), result.begin(), ::tolower);
            return result;
        }
};

//Transforms the string to a vector that is in the reverse order of the initial string and returns the vector as a string
class Reverse : public TextFilter
{
    public:
        std::string apply(const std::string& text) override
        {
            std::vector<char> result;
            for(int i = text.size()-1; i >= 0; i--)
            {
                result.push_back(text.at(i));
            }
            return std::string(result.begin(), result.end());
        }
};

//Checks the text for vowels and removes vowels as they are found
class RemoveVowels : public TextFilter
{
public:
    std::string apply(const std::string& text) override
    {
        std::string result;
        for (int i = 0; i < text.size(); i++)
        {
            char original = text.at(i);
            char lower = std::tolower(static_cast<unsigned char>(original));

            if (lower != 'a' && lower != 'e' && lower != 'i' &&
                lower != 'o' && lower != 'u')
            {
                result += original;
            }
        }
        return result;
    }
};

//Checks the text for the words stupid, bad and dumb and censors the words as they are found
class Censor : public TextFilter
{
public:
    std::string apply(const std::string& text) override
    {
        std::vector<std::string> badWords = {"stupid", "dumb", "bad"};
        std::string word;
        std::string lowerWord;
        std::string result;

        for (int i = 0; i <= text.size(); i++)
        {
            char c;
            if (i < text.size())
            {
                c = text.at(i);
            }
            else
            {
                c = ' ';
            }

            if (c != ' ' && !std::ispunct(c))
            {
                word += c;
                lowerWord += std::tolower(static_cast<unsigned char>(c));
            }
            else
            {
                for (int j = 0; j < badWords.size(); j++)
                {
                    if (lowerWord == badWords.at(j))
                    {
                        for (int k = 0; k < word.size(); k++)
                        {
                            word.at(k) = '*';
                        }
                        break;
                    }
                }
                result += word;
                if (i < text.size())
                {
                    result += c;
                }
                word = "";
                lowerWord = "";
            }
        }

        return result;
    }
};


//Allows the text to be processed with the strategy
class TextProcessor
{
    std::unique_ptr<TextFilter> strategy;
    public:
        void setStrategy(std::unique_ptr<TextFilter> newStrategy)
        {
            strategy = std::move(newStrategy);
        }
    
        std::string process(const std::string& input)
        {
            if (strategy)
                return strategy->apply(input);
            return input;
        }
};

//User interface
void userInterface()
{
    std::cout << "Menu:" << std::endl;
    std::cout << "\t1: Make the string uppercase." << std::endl;
    std::cout << "\t2: Make the string lowercase." << std::endl;
    std::cout << "\t3: Reverse the string." << std::endl;
    std::cout << "\t4: Remove the vowels in the string." << std::endl;
    std::cout << "\t5: Censor certain words in the string (stupid, bad, dumb)." << std::endl;
    std::cout << "\t6: Exit." << std::endl;
}

//Prompts the user for their choice
int promptUserChoice()
{
    int choice;
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

//Decorates the text based on the user's choice 
int main()
{
    TextProcessor processor;
    std::string userString;

    userInterface();
    std::cout << "Enter a string: ";
    std::getline(std::cin, userString);
    
    int userChoice = promptUserChoice();

    while(userChoice != 6)
    {
        if(userChoice == 1)
        {
            processor.setStrategy(std::make_unique<UppercaseFilter>());
            std::cout << "Uppercase string: " << processor.process(userString) << std::endl;
        }
        else if(userChoice == 2)
        {
            processor.setStrategy(std::make_unique<LowercaseFilter>());
            std::cout << "Lowercase string: " << processor.process(userString) << std::endl;
        }
        else if(userChoice == 3)
        {
            processor.setStrategy(std::make_unique<Reverse>());
            std::cout << "Reverse: " << processor.process(userString) << std::endl;
        }
        else if(userChoice == 4)
        {
            processor.setStrategy(std::make_unique<RemoveVowels>());
            std::cout << "Vowels removed: " << processor.process(userString) << std::endl;
        }
        else if(userChoice == 5)
        {
            processor.setStrategy(std::make_unique<Censor>());
            std::cout << "Censored: " << processor.process(userString) << std::endl;
        }
        userChoice = promptUserChoice();
    }
    std::cout << "Exiting program..." << std::endl;
    return 0;
}
