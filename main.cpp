#include <chrono>
#include <cmath>
#include <ios>
#include <iostream>
#include <limits>
#include <stdlib.h>
#include <thread>
#include <vector>

// Detect OS

// All Windows OS
#ifdef _WIN32
#define OS "Windows"

// MacOS
#elif TARGET_OS_MAC
#define OS "MacOS"

// Linux
#elif __linux__
#define OS "Linux"

// Incompatible OS found
#else
cout << "\033[31mError: \033[37mCompatible OS not found, closing the program..." << flush;
this_thread::sleep_for(chrono::seconds(1));
exit(EXIT_FAILURE);

#endif

using namespace std;

void clearConsole()
{
    if (OS == "Windows")
        system("cls");

    else
        system("clear");
}

void pressAnyKeyToContinue()
{
    if (OS == "Windows")
        system("pause");

    else
    {
        cout << "Press any key to continue...\n";
        system("read");
        system("clear");
    }
}

void series(vector<float> &resistances)
{
    float tot = 0;
    char option;

    do
    {
        float resistance;
        cout << "Resistor value (Ohm): ";
        cin >> resistance;

        if (resistance >= 0)
        {
            tot += resistance;
            cout << "\033[32mResistor's value added\n\033[37m";
        }

        else
            cout << "\033[31mError: \033[37mInvalid input\n";

        cout << "\nContinue? (Y/N): ";
        cin >> option;

        clearConsole();

    } while ((option == 'Y') || (option == 'y'));

    if (tot > 0)
    {
        resistances.push_back(tot);
        cout << "\033[32mTotal series resistance added\n\033[37m";
    }

    else
        cout << "\033[31mNo total series resistance added\n\033[37m";

    pressAnyKeyToContinue();
}

void parallel(vector<float> &resistances)
{
    float tot = 0;
    char option;

    do
    {
        float resistance;
        cout << "Resistor value (Ohm): ";
        cin >> resistance;

        if (resistance >= 0)
        {
            tot += 1 / resistance;
            cout << "\033[32mResistor's value added\n\033[37m";
        }

        else
            cout << "\033[31mError: \033[37mInvalid input\n";

        cout << "\nContinue? (Y/N): ";
        cin >> option;

        clearConsole();
    } while ((option == 'Y') || (option == 'y'));

    if (tot > 0)
    {
        resistances.push_back(pow(tot, -1));
        cout << "\033[32mTotal parallel resistance added\n\033[37m";
    }

    else
        cout << "\033[31mNo total parallel resistance added\n\033[37m";

    pressAnyKeyToContinue();
}

void totalResistance(vector<float> &resistances)
{
    if (resistances.empty())
        cout << "\033[31mError: \033[37mThere are no resistances\n";

    else
    {
        float tot = 0;
        for (int i = 0; i < resistances.size(); i++)
            tot += resistances.at(i);

        cout << "Total resistance value (Ohm): " << tot << "\n";
    }

    pressAnyKeyToContinue();
}

int main(void)
{
    vector<float> resistances;
    unsigned int option;

    do
    {
        cout << "Electronics calculator\n";
        cout << "1. Series resistors\n";
        cout << "2. Parallel resistors\n";
        cout << "3. Calculate total resistance\n";
        cout << "4. Exit\n";
        cout << "Select an option: ";
        cin >> option;

        // Clear buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        clearConsole();

        switch (option)
        {
        case 1:
        {
            series(resistances);
            break;
        }

        case 2:
        {
            parallel(resistances);
            break;
        }

        case 3:
        {
            totalResistance(resistances);
            break;
        }

        case 4:
        {
            cout << "Closing the program..." << flush;
            this_thread::sleep_for(chrono::seconds(1));
            break;
        }

        default:
        {
            cout << "\033[31mError: \033[37mInvalid option\n";

            pressAnyKeyToContinue();

            break;
        }
        }
    } while (option != 4);

    return 0;
}