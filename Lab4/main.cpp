#include "interface.h"
#include "Rectangle.h"
#include "Parallelogram.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;
int Command()
{
    int number = 0;
    cout << "=================MENU==================" << endl;
    cout << "Choose the command from the command list:" << endl;
    cout << "1. Add figure." << endl;
    cout << "2. Show all figure." << endl;
    cout << "3. Sum all figure's square." << endl;
    cout << "4. Sum all figure's perimeters." << endl;
    cout << "5. Show figure's mass center." << endl;
    cout << "6. Show count memory from all classes." << endl;
    cout << "7. Sort all figures by mass." << endl;
    cout << "8. Exit..." << endl;
    cout << "=======================================" << endl;
    cin >> number;
    return number;
}

int selectFigure()
{
    int type;
    cout << "==================FIGURE================" << endl;
    cout << "Choose type of figure:" << endl;
    cout << "1. Rectangle." << endl;
    cout << "2. Parallelogram." << endl;
    cout << "========================================" << endl;
    cin >> type;
    return type;
}

int main()
{
    vector <Figure*> figures;
    int count = 0;
    while (true)
    {
        int number = Command();
        switch (number)
        {
        case 1:
        {
            int type = selectFigure();
            if (type == 1)
            {
                figures.push_back(new Rectangle);
                figures[count]->initFromDialog();
                count++;
                break;
            }
            else
            {

                figures.push_back(new Parallelogram);
                figures[count]->initFromDialog();
                count++;
                break;
            }
        }

        case 2:
        {
            for (int i = 0; i < figures.size(); i++) 
            {
                figures[i]->draw();
            }
            break;
        }

        case 3:
        {
            double sum = 0;
            for (int i = 0; i < figures.size(); i++)
                sum += figures[i]->square();
            cout << "Sum all figure's squares is " << sum << endl;
            break;
        }

        case 4:
        {
            double sum = 0;
            for (int i = 0; i < figures.size(); i++)
                sum += figures[i]->perimeter();
            cout << "Sum all figure's perimeters is " << sum << endl;
            break;

        }

        case 5:
        {
            double m_x = 0, m_y = 0, m = 0;
            for (int i = 0; i < figures.size(); i++) 
            {
                m_x += figures[i]->position().x * figures[i]->mass();
                m_y += figures[i]->position().y * figures[i]->mass();
                m += figures[i]->mass();
            }
            cout << "Mass center is = (" << m_x / m << ", " << m_y / m << " )" << endl;
            break;
        }

        case 6:
        {
            int countMemory = 0;
            for (int i = 0; i < figures.size(); i++)
                countMemory += figures[i]->size();
            cout << "Count of memory for this system is " << countMemory << endl;
            break;
        }

        case 7:
        {
            std::sort(figures.begin(), figures.end(),
                [](Figure* a, Figure* b)
                {
                    return (a->mass() < b->mass());
                });

            cout << "All figures was successfully sorted" << endl;
            break;
        }
        }
    }
}