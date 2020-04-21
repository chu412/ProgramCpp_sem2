#pragma once

#include "interface.h"
#include "Rectangle.h"
#include <iostream>

class Parallelogram : public Figure 
{

private:
    CVector2D top1;
    CVector2D top2;
    CVector2D top3;
    CVector2D top4;
    double m_mass;
    const char* m_classname;
public:
    Parallelogram();

    double square() const override;
    double perimeter() const override;
    double mass() const override;
    CVector2D position() const override;
    bool operator== (const IPhysObject& ob) const override;
    bool operator< (const IPhysObject& ob) const override;
    void draw() const override;
    void initFromDialog() override;
    const char* classname() const override;
    unsigned int size() const override;

};
