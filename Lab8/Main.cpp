#include "Cube.h"

using namespace std;

int menu() 
{
    system("cls");
    cout << "========================RUBIK's CUBE===========================\n";
    cout << "1. Saving and reading the state of a Rubik's cube from a file." << endl;
    cout << "2. Check rubik." << endl;
    cout << "3. Show the current state of rubik." << endl;
    cout << "4. Rotating the faces of the Rubik's cube." << endl;
    cout << "5. Setting random Rubik's Cube state." << endl;
    cout << "6. Find result." << endl;
    cout << "7. Exit..." << endl;
    cout << "================================================================\n";
    int action;
    cin >> action;
    return action;
}

int secmenu() 
{
    cout << "1. Save." << endl;
    cout << "2. Read." << endl;
    int number;
    cin >> number;
    return number;
}

int main() 
{
    int i;
    Cube cube;
    int action;
    bool flag = true;
    do {
        action = menu();
        if (action == 1) 
        {
            int number;
            number = secmenu();
            if (number == 1) 
            {
                cube.save();
            }
            else if (number == 2) 
            {
                cube.read();
            }
        }
        else if (action == 2) 
        {
            flag = cube.check();
            if (flag == false) 
            {
                cout << "Bad Kub." << endl;
            }
            else 
            {
                flag = cube.find(0, 0);
                if (flag == true) 
                {
                    cout << "OK" << endl;
                }
                else {
                    cout << "Bad Kub." << endl;
                }
            }
        }
        else if (action == 3) 
        {
            cube.show();
        }
        else if (action == 4) 
        {
            cube.myspin();
        }
        else if (action == 5) 
        {
            cube.scrol();
        }
        else if (action == 6) 
        {
            cube.setString();
            flag = cube.check();
            if (flag == true) 
            {
                flag = cube.find(0, 0);
                if (flag == true) 
                {
                    cube.getString();
                    cout << endl;
                }
                else 
                {
                    cout << "Bad angle or edge." << endl;
                }
            }
            else 
            {
                cout << "Take new kub." << endl;
            }
        }
        if (action != 7) 
        {
            system("pause");
        }
    } while (action != 7);
    return 0;
}