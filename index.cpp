#include <ios>
#include <iostream> 
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>


typedef int pin_t;
using operation_t = int;
using balance_t = double;
typedef double do_t;
using text_t = std::string;
using dollar_t = double;

// Account info are found here
namespace firstAccount {
std::string accountName = "Zachary";
int pin = 5132;
balance_t balance = 500;
balance_t secondBalance = {};

}

namespace secondAccount {
std::string accountName = "Therese";
int pin = 1234;
balance_t balance = 900;
balance_t secondBalance = {};
}

namespace newAccount {
std::string accountName;
int pin = {};
balance_t balance = {};
balance_t secondBalance = {};
}

int main () {

// Using a namespace to refer to a certain account
using namespace secondAccount;

// Variables
char hasAccount;
char createAccount;

bool accountExists = false;

// Password Randomizer
srand(time(NULL));

// Log counter
pin_t logged = {};

// Account Creation
do {
    std::cout << "Do you have an exisiting account?\n(Y/N)\n";
    std::cin >> hasAccount;

    if (hasAccount == 'N' || hasAccount == 'n') {
        std::cout << "Do you want to create an account?\n";
        std::cin >> createAccount;

        if (createAccount == 'Y' || createAccount == 'y') {
            std::cout << "Please enter your account name: ";
            std::cin >> accountName;

            std::cout << "\nEnter your 4 digit PIN (Press 1 to create a generated PIN): ";
            std::cin >> pin;

            // Random function
            if(pin == 1) {
                pin = 
                ((rand() % 9) + 1) * 1000
                + ((rand() % 9) + 1) * 100
                + ((rand() % 9) + 1) * 10
                + ((rand() % 9) + 1); 
                
                //Random PIN display
                std::cout << "This is your system generated 4 digit PIN: " << pin;

                
            } else if (pin >= 1000 && pin <= 9999) {
                // Do nothing
            } else {
                std::cout << "Your PIN should be 4 digits!\n";
                continue;
            }
            std::cout << "\nEnter your balance: ";
            std::cin >> balance;

            std::cout << "Account successfully created, please log in.\n";
            accountExists = true;
        }
    } else if (hasAccount == 'Y' || hasAccount == 'y') {
        accountExists = true;
    } else {
        std::cout << "Please enter a valid input (Y/N)!\n";
        std::cout << '\n';
        continue;
    }

} while (accountExists == false);


// Start of the first loop
do {

    // Initialized variables
    pin_t pin1 = {};
    pin_t session = {};

    do_t withdraw = {};
    do_t transact = {};
    do_t exchange = {};
    do_t cashin = {};

    text_t accountHolder;
    text_t receiver;
    text_t currency = "Pesos";
    text_t secondCurrency;

    operation_t operation = {};
    
    const dollar_t dollar = 0.0164;


    // Prompt
    std::cout << "Please enter your name: \n";
    std::cin >> accountHolder;
    std::cout << '\n';
    if (accountHolder != accountName) {
        std::cout << "Invalid Account Holder!\n";
        continue;
    }

    std::cout << "Welcome, " << accountHolder << "! \nPlease enter your PIN: \n";
    std::cin >> pin1;
    std::cout << '\n';
    if (pin1 != pin){
        std::cout << "Invalid PIN!\n";
        continue;
    }

    // User authentication
    if (accountHolder == accountName && pin1 == pin) {
        std::cout << "Welcome to your dashboard, " << accountName << '\n';
        ++logged;
    }
    else {
        std::cout << "Invalid account holder and PIN!\n";
        continue;
    }
         
    // Start of second loop
    while(true){

    // Prompt
    std::cout << "What operation do you want to do?\n";
    std::cout << "1. Withdraw\n";
    std::cout << "2. Transact\n";
    std::cout << "3. Exchange\n";
    std::cout << "4. Cash In\n";
    std::cout << "5. Logout\n";
    std::cout << "6. Check Balance\n";
    std::cout << "7. Session Info\n";
    std::cin >> operation;
        
    // L82-L90 Main function
    switch (operation) {

        case 1:
            std::cout << "How much do you want to Withdraw?\n";
            std::cin >> withdraw;
                
                if (withdraw <= 0 || std::cin.fail()) {
                    std::cout << withdraw << " is an invalid amount!\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } else if (balance >= withdraw) {
                    balance -= withdraw;

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

            // Transaction validation
            if (std::cin.fail()) {
                std::cout << "Invalid input!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }else if (transact <= 0) {
                std::cout << "Invalid input!\n";
                break;
            }

            std::cout << "Whom do you wanna send it to\n";
            std::cin >> receiver;

            // Receiver validation
            if (receiver == firstAccount::accountName) {
                std::cout << "Sending...\n";
            }
            else if (receiver == accountName) {
                std::cout << "You cannot send money to yourself.\n";
                break;
            } else {
                std::cout << "This user does not exist!\n";
                break;
            }

            // Checks if balance is enough & if receiver exists
            if (balance >= transact && receiver == firstAccount::accountName) {
                balance -= transact;
                std::cout << "Transaction successful!\n";
                std::cout << transact << " sent to " << receiver << '\n';
                std::cout << "Your remaining balance is: " << balance << '\n';
            } else if (balance < transact) {
                std::cout << "Insufficient balance.\n";
                break;
            }  
            break;
        case 3:
            std::cout << "How much do you want to Exchange?\n";
            std::cin >> exchange;

            // Verifies if balance is enough for exchange
            if (std::cin.fail()) {
                std::cout << "Invalid input!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else if (exchange <= 0) {
                std::cout << exchange << " is an invalid amount!\n";
            } else if (exchange <= balance) {

                // Does balance operation and sets secondBalance
                balance -= exchange;
                secondBalance = exchange * dollar;

                // Success message
                std::cout << "Successfully exchanged " << exchange << " to " << secondBalance << " Dollars!\n";
                std::cout << "Your remaining balance is " << balance << " Pesos.\n";

                secondCurrency = "Dollar";
            } else {
                std::cout << "You do not have enough balance.\n";
            }
            break;
        case 4:
            std::cout << "How much do you want to Cash In?\n";
            std::cin >> cashin;

            if (std::cin.fail()) {
                std::cout << "Please enter a valid number\n";
                std::cin.clear(); // Clear the error flags
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input   
            } else if (cashin < 1) {
                std::cout << "You cannot add " << cashin << " to your account!\n";
            } else {
                balance += cashin;

                std::cout << "Successfully cashed " << cashin << " to your account.";
            }
            break;
        case 5:
            std::cout << "Session ended.\n";
            break;
        case 6:
            if (secondCurrency == "Dollar" && currency == "Pesos") {
                std::cout << "You have " << balance << " Pesos, and " << secondBalance << " Dollars.\n";
            } 
            else if (currency == "Pesos") {
                std::cout << "You have " << balance << " Pesos\n";
            } 
            else if (secondCurrency == "Dollar") {
                std::cout << "You have " << secondBalance << " Dollars\n";
            }
            break;
        case 7:
            std::cout << "Hello, " << accountName << '\n';
            std::cout << "You have logged in " << logged << " times.\n";
            break;
        default:
            std::cout << "Invalid operation, please try again.\n";
            break;
    }

    // Exits the operation and goes back to Auth
    if (operation == 5) {
        break;
    }

    }

} while(true);

}
