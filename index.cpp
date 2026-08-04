#include <iostream>

typedef int pin_t;
using operation_t = int;
using balance_t = double;
typedef double do_t;
using text_t = std::string;
using dollar_t = double;

namespace firstAccount {
    std::string accountName = "Zachary";
    int pin = 5132;
}

namespace secondAccount {
    std::string accountName = "Therese";
    int pin = 1234;
    balance_t balance = 900;
}

int main () {

    using namespace secondAccount;

    do {

        pin_t pin1, session, logged ={};
        operation_t operation;
        do_t withdraw, transact, exchange, cashin = {};
        text_t accountHolder, receiver;
        text_t currency = "Pesos";
        const dollar_t dollar = 0.0164;

        std::cout << "Please enter your name: \n";
        std::cin >> accountHolder;
        std::cout << "\n";

        std::cout << "Welcome, " << accountHolder << "! \nPlease enter your PIN: \n";
        std::cin >> pin1;
        std::cout << "\n";

            if (accountHolder == accountName && pin1 == pin) {
            std::cout << "Welcome to your dashboard, " << accountName << "\n";
            ++logged;
            }
            else if (accountHolder != accountName && pin1 != pin) {
                std::cout << "Invalid account holder and PIN!\n";
                continue;
            }
            else if (accountHolder != accountName) {
                std::cout << "Invalid Account Holder!\n";
                continue;
            }
            else {
                std::cout << "Invalid PIN!\n";
                continue;
            }
        
       

        while(true) {

        
        
        std::cout << "What operation do you want to do?\n";
        std::cout << "1. Withdraw\n";
        std::cout << "2. Transact\n";
        std::cout << "3. Exchange\n";
        std::cout << "4. Cash In\n";
        std::cout << "5. Logout\n";
        std::cout << "6. Check Balance\n";
        std::cout << "7. Session Info\n";
        std::cin >> operation;


        
        switch (operation) {

            case 1:
                std::cout << "How much do you want to Withdraw?\n";
                std::cin >> withdraw;

                    if (balance >= withdraw) {
                        balance = balance - withdraw;
                        std::cout << "Successfully Withdrawed " << withdraw << " Pesos!\n";
                        std::cout << "Your remaining balance is " << balance << " Pesos.\n";
                        std::cout << "Going back...\n";
                    } else {
                        std::cout << "Insufficient Balance, please try again.\n";
                    }

                break;
            case 2:
                std::cout << "How much do you want to Send?\n";
                std::cin >> transact;

                std::cout << "Whom do you wanna send it to\n";
                std::cin >> receiver;

                    if (balance >= transact && receiver == firstAccount::accountName && receiver != secondAccount::accountName) {
                        balance -= transact;
                        std::cout << "Transaction successful!\n";
                        std::cout << "Your remaining balance is: " << balance << "\n";
                    } else if (transact < balance) {
                        std::cout << "Insufficient balance.\n";
                    } else if (receiver == firstAccount::accountName && receiver != secondAccount::accountName) {
                        std::cout << "User does not exist.\n";
                    }

                break;
            case 3:
                std::cout << "How much do you want to Exchange?\n";
                std::cout << "(Exchanges all money to USD)\n";
                std::cin >> exchange;

                balance = balance * dollar;

                std::cout << "Successfully exchanged " << exchange << " to " << balance << " Dollars!\n";
                
                currency = "Dollar";

                break;
            case 4:
                std::cout << "How much do you want to Cash In?\n";
                std::cin >> cashin;

                balance = balance + cashin;

                std::cout << "Successfully cashed " << cashin << " to your account.";
                break;
            case 5:
                std::cout << "Session ended.\n";
                break;
            case 6:
                if (currency == "Pesos") {
                    std::cout << "You have " << balance << " Pesos\n";
                } else if (currency == "Dollar") {
                    std::cout << "You have " << balance << " Dollars\n";
                }   
                
                break;
            case 7:
                std::cout << "You have " << session << " Active Session.\n";
                std::cout << "You have logged in " << logged << " times.\n";
                break;
            default:
                std::cout << "Invalid operation, please try again.\n";
                break;
        }
        if (operation == 5) {
        break;
        }

    }

    
    }while(true);
}