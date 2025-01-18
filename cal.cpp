#include <iostream>
#include <vector>
#include <unistd.h>
using namespace std;

void calander(int, int);
void showcalander(int, int, int, vector<int> &);

vector<string> month = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
vector<string> week = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

void clearOutputConsole()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main()
{
    clearOutputConsole();
    cout << "Enter Choice : \n";
    cout << "1. View Whole Year Calendar \n";
    cout << "2. View Month Calendar \n";

    int choice;
    cin >> choice;
    if (choice != 1 && choice != 2)
    {
        cout << "invalid Choice" << endl;
        return 0;
    }

    if (choice == 1)
    {
        cout << "Enter all in Number\n";
        int year;
        cout << "Enter Year : ";
        cin >> year;

        if (year < 1945)
        {
            cout << "\n\tPlease enter year above 1945\n";
        }
        else
        {
            for (int i = 0; i < 12; i++)
            {
                calander(year, i + 1);
                    #ifdef _WIN32
                        cout<<"Please wait for 3 seconds"<<endl;
                        sleep(3);
                    #else
                        cout<<"Please wait for 3 seconds"<<endl;
                        sleep(3);
                    #endif
            }
        }
    }
    else
    {
        cout << "Enter all in Number\n";
        int year, month_num;
        cout << "Enter Year : ";
        cin >> year;
        cout << "Enter Month : ";
        cin >> month_num;

        if (year < 1945)
        {
            cout << "\n\tPlease enter year above 1945\n";
        }
        else
        {
            calander(year, month_num);
        }
    }

    return 0;
}

void calander(int year, int month_num)
{
    vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total_days = 0, prev_year;
    prev_year = year - 1;

    if (year >= 1945)
    {
        for (int i = 1945; i <= prev_year; i++)
        {
            if (i % 4 == 0)
            {
                total_days += 366;
            }
            else
            {
                total_days += 365;
            }
        }
    }

    if (year % 4 == 0)
    {
        days[1] = 29;
    }
    else
    {
        days[1] = 28;
    }

    for (int i = 0; i < month_num - 1; i++)
    {
        total_days += days[i];
    }

    total_days %= 7;
    showcalander(year, month_num, total_days, days);
}

void showcalander(int year, int month_num, int total_days, vector<int> &days)
{
    clearOutputConsole();
    int pos, i, j;

    // Header
    cout << "+-----------------------------+\n";
    cout << "|       " << month[month_num - 1] << " " << year << "          |\n";
    cout << "+-----------------------------+\n";

    // Weekday Names
    cout << "| Mon Tue Wed Thu Fri Sat Sun |\n";

    // Row Separator
    cout << "|";

    // Adjust starting position for the first day
    for (pos = 0; pos < total_days; pos++)
    {
        cout << "    "; // Empty spaces for days before the first day  2222
    }

    // Print days of the month
    for (i = 1, pos = total_days; i <= days[month_num - 1]; i++, pos++)
    {
        cout << (i < 10 ? "  " : " ") << i; // Print each day with 2-character width

        if (pos == 6)
        {                    // If the current day is Sunday (end of the week)
            cout << " |\n|"; // Move to the next row
            pos = -1;        // Reset position for the new row
        }
        else
        {
            cout << " ";
        }
    }

    // Fill empty spaces at the end of the last row
    while (pos < 6)
    {
        cout << "   ";
        pos++;
    }

    cout << " |\n";
    cout << "+----------------------+\n";
}
