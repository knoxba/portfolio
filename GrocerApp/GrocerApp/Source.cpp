#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

// Class blueprint
class ItemTracker {

public:
    void readDataFile();
    void displayMenu();

private:
    map<string, int> itemFrequency;
    void searchItem();
    void printFrequencyList();
    void printHistogram();
    string inputFileName = "CS210_Project_Three_Input_File.txt";
    string outputFileName = "frequency.dat";
};

// Reads item data from the CS210_Project_Three_Input_File.txt file.
void ItemTracker::readDataFile() {
    ifstream inputFile(inputFileName);
    string item;
    while (inputFile >> item) {
        itemFrequency[item]++;
    }
    inputFile.close();
}

// Displays main menu options using switch/case construction for input validation.
void ItemTracker::displayMenu() {
    int choice;
    do {
        cout << "\n Menu\n";
        cout << "  1. Search for an item\n";
        cout << "  2. Print the frequency list\n";
        cout << "  3. Print a histogram\n";
        cout << "  4. Exit\n";
        cout << " \n\tEnter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            searchItem();
            break;
        case 2:
            printFrequencyList();
            break;
        case 3:
            printHistogram();
            break;
        case 4:
            cout << "\t> Exiting program...\n";
            break;
        default:
            cout << "\t> Invalid choice. Try again.\n";
            continue;
        }
    } while (choice != 4);
}

// Searches CS210_Project_Three_Input_File.txt for a particular item on the list.
// If the value is not found, an error message is displayed. Otherwise, the frequency is returned.
void ItemTracker::searchItem() {
    string item;
    cout << "\t> Enter the item to search for: ";
    cin >> item;
    if (itemFrequency.find(item) == itemFrequency.end()) {
        cout << "\t> " << item << " not found.\n";
    }
    else {
        cout << "\t> Frequency of " << item << " = " << itemFrequency[item] << endl;
    }
}

// Prints de-duped list of grocery items with total frequency adjacent.
// This method prints to both terminal and frequency.dat file.
void ItemTracker::printFrequencyList() {
    cout << "\n\n  Frequency:\n";
    ofstream outputFile(outputFileName);
    for (auto const& item : itemFrequency) {
        cout << "      " << item.first << " " << item.second << endl;
        outputFile << item.first << " " << item.second << endl;
    }
    outputFile.close();
}

// Prints the frequency histogram of each duplicated items in the CS210_Project_Three_Input_File.txt file denoted by "*"
// This method prints to both terminal and frequency.dat file.
void ItemTracker::printHistogram() {
    cout << "\n\n  Histogram:\n";
    ofstream outputFile(outputFileName);
    for (auto const& item : itemFrequency) {
        cout << "      " << item.first << " ";
        outputFile << item.first << " ";
        for (int i = 0; i < item.second; i++) {
            cout << "*";
            outputFile << "*";
        }
        cout << endl;
        outputFile << endl;
        //outputFile << item.first << " " << item.second << endl;
       
    }
    outputFile.close();
}

// Main method driver
int main() {
    ItemTracker itemTracker;
    itemTracker.readDataFile();
    itemTracker.displayMenu();
    return 0;
}