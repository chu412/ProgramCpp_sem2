#pragma once
#include "interface.h"
#include <iostream>

using namespace std;

class Figure :
    public IGeoFig,
    public CVector2D, public IPhysObject,
    public IPrintable, public IgIDialogInitial, public BaseCObject {
};


class Rectangle : public Figure
{
private:
    CVector2D _position;
    double  _a;
    double _b;
    double _mass;
    const char* _classname;
public:
    Rectangle();
    double square() const override;
    double perimeter() const override;
    double mass() const override;
    CVector2D position() const override;
    bool operator== (const IPhysObject&) const override;
    bool operator< (const IPhysObject&) const override;
    void draw() const override;
    void initFromDialog() override;
    const char* classname() const override;
    unsigned int size() const override;

};