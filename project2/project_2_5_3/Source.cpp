#include <iostream>
#include <iomanip>

using namespace std;
class BankingApp {


public:
    // Declare the variables to store input
    float initialInv;
    float annualInt;
    float monthlyDep;
    float months;
    float years;
    float totalAmt;
    float interestAmt;
    float yearTotalInt;

    // Display the form to user
    void print_form() {

        cout << "*\n";
        cout << "* Data Input *\n";
        cout << "Initial Investment Amount: \n";
        cout << "Monthly Deposit: \n";
        cout << "Annual Interest: \n";
        cout << "Number of years: \n";

    }

    // Gets data from user
    void get_data_from_user() {
        while (true) {
            cout << "\n";
            cout << "Data Input \n";
            cout << "Initial Investment Amount: $";
            cin >> initialInv;
            cout << "Monthly Deposit: $";
            cin >> monthlyDep;
            cout << "Annual Interest: %";
            cin >> annualInt;
            cout << "Number of years: ";
            cin >> years;
            months = years * 12;

            if ((initialInv > 0) && (monthlyDep > 0) && (annualInt > 0) && (years > 0)) {
                break;
            }
            else {
                cout << "Entered value less than zero. Negative numbers not allowed.\n\n";
                continue;
            }

        }
        
    }

    // Display YTD data for user without monthly deposit
    void display_ytd_null_deposit() {
        cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
        cout << "=====================================================================\n";
        cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
        cout << "---------------------------------------------------------------------\n";
        for (int i = 0; i < years; i++) {

            // Calculates yearly interest
            interestAmt = (totalAmt) * ((annualInt / 100));

            // Calculates year end total
            totalAmt = totalAmt + interestAmt;

            // Print result to table showcasing only two decimal point
            cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << setw(7) << totalAmt << "\t\t$" << fixed << setprecision(2) << setw(7) << interestAmt << "\n";
        }
    }

    // Display YTD data for user with monthly deposit
    void display_ytd_deposit() {
        cout << "\n\nBalance and Interest With Additional Monthly Deposits\n";
        cout << "=====================================================================\n";
        cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
        cout << "---------------------------------------------------------------------\n";
        for (int i = 0; i < years; i++) {
            //Set yearly interest to zero at the start of the year
            yearTotalInt = 0;
            for (int j = 0; j < 12; j++) {

                //Calculate monthly interest
                interestAmt = (totalAmt + monthlyDep) * ((annualInt / 100) / 12);

                //Calculate month end interest
                yearTotalInt = yearTotalInt + interestAmt;

                //Calculate month end total
                totalAmt = totalAmt + monthlyDep + interestAmt;

            }

            //Print results to table showcasing only two decimal points
            cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << setw(7) << totalAmt << "\t\t$" << fixed << setprecision(2) << setw(7) << yearTotalInt << "\n";

        }
    }
};

int main() {

    // Opens/launches a banking application object called 'session'
    BankingApp session;

    // Prints the session form for user reference
    session.print_form();

    // Wait for the input from user
    system("PAUSE");

    // Get data from the user
    session.get_data_from_user();

    // Wait for input from the user
    system("PAUSE");

    // Set of total amount to initial investments to be updated
    session.totalAmt = session.initialInv;

    // Display year-to-date data without monthly deposit
    session.display_ytd_null_deposit();

    // Set of total amount to the initial investment to be updat
    session.totalAmt = session.initialInv;

    // Display year-to-date data with monthly deposit
    session.display_ytd_deposit();

    return 0;
}