#include "interface.h"
#include "Parallelogram.h"
#include <iostream>

using namespace std;

Parallelogram::Parallelogram() : top1{}, top2{}, top3{}, top4{}, m_mass{}, m_classname("Parallelogram") {}

double Parallelogram::square() const 
{
    CVector2D a, b;
    a.x = top2.x - top1.x, a.y = top2.y - top1.y;
    b.x = top3.x - top1.x, b.y = top3.y - top1.y;

    return abs(a.x * b.y - a.y * b.x);
}

double Parallelogram::perimeter() const 
{
    CVector2D a, b;
    a.x = top2.x - top1.x, a.y = top2.y - top1.y;
    b.x = top3.x - top1.x, b.y = top3.y - top1.y;

    return 2 * (sqrt(pow(a.x, 2) + pow(a.y, 2)) + sqrt(pow(b.x, 2) + pow(b.y, 2)));
}

double Parallelogram::mass() const 
{
    return m_mass;
}

CVector2D Parallelogram::position() const 
{
    CVector2D pos;
    pos = { (top4.x - top1.x) / 2, (top4.y - top1.y) / 2 };
    return pos;
}

bool Parallelogram::operator==(const IPhysObject& in) const 
{
    return this->mass() == in.mass();
}

bool Parallelogram::operator<(const IPhysObject& in) const 
{
    return this->mass() < in.mass();
}

void Parallelogram::draw() const 
{
    cout << "=============DRAW-PARALLELOGRAM================" << endl;
    //cout << "Parallelogram:\n";
    cout << "Classname is " << m_classname << endl;
    cout << "First top is (" << top1.x << ", " << top1.y << ")" << endl;
    cout << "Second top is (" << top2.x << ", " << top2.y << ")" << endl;
    cout << "Third top is (" << top3.x << ", " << top3.y << ")" << endl;
    cout << "Fourth top is ( " << top4.x << ", " << top4.y << ")" << endl;
    cout << "Weight is " << mass() << endl;
    cout << "Size in bytes is " << size() << endl;
    cout << "==========================================";
}

void Parallelogram::initFromDialog() 
{
    cout << "=======Initialization_PARALLELOGRAM=============" << endl;
    cout << "Enter Parallelogram's first top coordinates (x, y):" << endl;
    cin >> top1.x >> top1.y;
    cout << "Enter Parallelogram's second top coordinates (x, y):" << endl;
    cin >> top2.x >> top2.y;
    cout << "Enter Parallelogram's third top coordinates (x, y):" << endl;
    cin >> top3.x >> top3.y;
    top4 = { top1.x + top2.x + top3.x, top1.y + top2.y + top3.y };
    cout << "Enter Parallelogram's weight:" << endl;
    cin >> m_mass;
    cout << "================================================" << endl;
}

const char* Parallelogram::classname() const 
{
    return m_classname;
}

unsigned int Parallelogram::size() const 
{
    return sizeof(top1) * 4 + sizeof(m_mass) + sizeof(m_classname);
}