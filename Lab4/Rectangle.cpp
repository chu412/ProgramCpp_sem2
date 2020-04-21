#include "interface.h"
#include "Rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle() : _position{}, _a{}, _b{}, _mass{}, _classname("Rectangle"){}

double Rectangle::square() const
{
    return _a * _b;
}

double Rectangle::perimeter() const
{
    return 2 * (_a + _b);
}

double Rectangle::mass() const
{
    return _mass;
}

CVector2D Rectangle::position() const
{
    CVector2D pos{ _position.x, _position.y };
    return pos;
}

bool Rectangle::operator==(const IPhysObject& in) const
{
    return this->mass() == in.mass();
}

bool Rectangle::operator<(const IPhysObject& in) const
{
    return this->mass() < in.mass();
}

void Rectangle::draw() const
{
    cout << "=============DRAW-RECTANGLE=============" << endl;
    cout << "Classname is " << _classname << endl;
    cout << "a = " << _a << endl;
    cout << "b = " << _b << endl;
    cout << "Position: x = " << _position.x << ", y = " << _position.y << endl;
    cout << "Weight is " << mass() << endl;
    cout << "Size in bytes is " << size() << endl;
    cout << "========================================" << endl;
}

void Rectangle::initFromDialog()
{
    cout << "=========Initialization_RECTANGLE==========" << endl;
    double n_a, n_b;
    cout << "Enter Rectangles sides a and b:" << endl;
    cin >> n_a >> n_b;
    CVector2D n_position;
    cout << "Enter Position (x and y):" << endl;
    cin >> n_position.x >> n_position.y;
    double n_mass;
    cout << "Enter weight:" << endl;
    cin >> n_mass;
    _mass = n_mass;
    _a = n_a;
    _b = n_b;
    _position = n_position;
    cout << "=========================================" << endl;
}

const char* Rectangle::classname() const
{
    return _classname;
}

unsigned int Rectangle::size() const
{
    return sizeof(_a) + sizeof(_b) + sizeof(_mass) + sizeof(_classname) + sizeof(_position);
}
