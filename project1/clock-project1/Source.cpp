#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
#include<iomanip>

using namespace std;

class TimeSim {
public:
    int hour;
    int minute;
    int seconds;
};

// instantiate class object for 12-hour clock format inheriting/extending class TimeSim
class hour_12_format :public TimeSim {
public:
    string meridiem;
    hour_12_format() {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        hour = ltm->tm_hour;
        minute = ltm->tm_min;
        seconds = ltm->tm_sec;

        if (hour >= 12) {
            meridiem = "P.M.";
            hour -= 12;
        }
        else
            meridiem = "A.M.";

    }

    // adds an hour to the 24-hour clock system. If more than 24 hours, return to hour 0.
    void add_hour(int h) {
        hour += h;
        if (hour > 12) {
            hour -= 12;
        }

        // establishes meridiem threshold, set to change if the hour passes over 12 (noon/midnight)
        else if (hour >= 12) {
            if (meridiem == "A.M.") {
                meridiem = "P.M.";
            }

            else if (meridiem == "P.M.") {
                meridiem = "A.M.";
            }
        }
    }

    /*  adds a minute, If more than 60 minutes in a given hour,
     *  convert and add to hours value and reset minutes value to 0.
     */
    void add_minute(int min) {
        minute += min;
        if (minute >= 60) {
            int h = minute / 60;
            minute -= 60 * h;
            add_hour(h);
        }
    }

    /*  adds a second, If more than 60 seconds in a given minute,
     *  convert and add to minutes value and reset seconds value to 0.
     */
    void add_seconds(int sec) {
        seconds += sec;
        if (seconds >= 60) {
            int m = seconds / 60;
            seconds -= 60 * m;
            add_minute(m);
        }
    }
};  // end 12-hour class

// instantiate class object for 24-hour clock format inheriting/extending class TimeSim
class hour_24_format :public TimeSim {
public:
    int hour;
    int minute;
    int seconds;
    hour_24_format() {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        hour = ltm->tm_hour;
        minute = ltm->tm_min;
        seconds = ltm->tm_sec;
    }

    // adds an hour to the 24-hour clock system. If more than 24 hours, return to hour 0.
    void add_hour(int h) {
        hour += h;
        if (hour >= 24) {
            hour -= 24;
        }
    }

    /*  adds a minute, If more than 60 minutes in a given hour,
     *  convert and add to hours value and reset minutes value to 0.
     */
    void add_minute(int min) {
        minute += min;
        if (minute >= 60) {
            int h = minute / 60;
            minute -= 60 * h;
            add_hour(h);
        }
    }

    /*  adds a second, If more than 60 seconds in a given minute,
     *  convert and add to minutes value and reset seconds value to 0.
     */
    void add_seconds(int sec) {
        seconds += sec;
        if (seconds >= 60) {
            int m = seconds / 60;
            seconds -= 60 * m;
            add_minute(m);
        }
    }
}; // end 24-hour class

// displays 12-hour and 24-hour clock
void display(hour_12_format c1, hour_24_format c2) {
    cout << "\t\t*************************\t\t";
    cout << "*************************\n";
    cout << "\t\t*\t12-Hour Clock\t*\t\t";
    cout << "*\t24-Hour Clock\t*\n";
    cout << "\t\t*\t" << setw(2) << setfill('0') << c1.hour << ":" << setw(2) << setfill('0') << c1.minute << ":" << setw(2) << setfill('0') << c1.seconds << " " << c1.meridiem << "\t*\t\t";
    cout << "*\t" << setw(2) << setfill('0') << c2.hour << ":" << setw(2) << setfill('0') << c2.minute << ":" << setw(2) << setfill('0') << c2.seconds << "\t*\n";
    cout << "\t\t*************************\t\t";
    cout << "*************************\n";
}

// main method driving user input to change clock values
int main() {
    hour_12_format c1;
    hour_24_format c2;
    display(c1, c2);
    int choice = 0;

    while (choice != 4) {
        cout << setw(4) << "\n\n\t\t\t\t*******************************\n";
        cout << setw(4) << "\t\t\t\t* 1 - Add One Hour\t      *\n";
        cout << setw(4) << "\t\t\t\t* 2 - Add One Minute\t      *\n";
        cout << setw(4) << "\t\t\t\t* 3 - Add One Second\t      *\n";
        cout << setw(4) << "\t\t\t\t* 4 - Exit Program\t      *\n";
        cout << setw(4) << "\t\t\t\t*******************************\n";
        cin >> choice;

        /* switch employed to simultaneously add time to both 12-hour and 24-hour clocks
         * based on user input.
         */
        switch (choice) {
        case 1: c1.add_hour(1);
            c2.add_hour(1);
            break;

        case 2: c1.add_minute(1);
            c2.add_minute(1);
            break;

        case 3: c1.add_seconds(1);
            c2.add_seconds(1);
            break;

        case 4:
            exit(0);
            break;

        default:
            cout << "Enter Correct Choice!!\n";
        }
        system("cls");
        display(c1, c2);
    }
}