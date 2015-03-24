//
//  Polynomial.cpp
//  CS-M10B_HW04
//
//  Created by Christopher Hunter on 3/16/15.
//  GitHub: hunter-christopher/PolynomialClass
//
#include "Polynomial.h"
#include <iostream>
#include <math.h>
using namespace std;
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
// Constructors / Destructor
Polynomial::Polynomial()
{
    coeff = new int[1];
    *coeff = 0;
    degree = 0;
}
Polynomial::Polynomial( int theDegree, int theCoeff)
{
    coeff = new int[theDegree + 1];
    degree = theDegree;
    coeff[degree] = theCoeff;
    for (int i = degree-1; i >= 0; i--)
    {
        coeff[i] = 0;
    }
}
Polynomial::Polynomial(int theDegree, int *coeffArray)
{
    coeff = new int[theDegree + 1];
    degree = theDegree;
    for (int i = degree; i >= 0; i--)
    {
        coeff[i] = coeffArray[i];
    }
}
Polynomial::Polynomial(const Polynomial &other)
{
    coeff = new int[other.degree+1];
    for (int i = 0; i <= degree; i++)
    {
        coeff[i] = other.coeff[i];
    }
    degree = other.degree;
}
Polynomial::~Polynomial()
{
    delete [] coeff;
}
Polynomial& Polynomial::operator=(const Polynomial &other)
{
    if (this != &other)
    {
        degree = other.degree;
        delete coeff;
        coeff = new int[other.degree + 1];
        for (int i = degree; i >= 0; i--)
        {
            coeff[i] = other.coeff[i];
        }
    }
    return *this;
}
Polynomial Polynomial::operator+ (const Polynomial& other) const
{
    int great = (degree >= other.degree) ? (degree): (other.degree);
    
    int * addCoeffArr = new int[great + 1];
    for (int i = great; i >= 0; i--)
    {
        addCoeffArr[i] = coeff[i] + other.coeff[i];
    }
    return Polynomial(great, addCoeffArr);
}
Polynomial Polynomial::operator- (const Polynomial& other) const
{
    int great = (degree >= other.degree) ? (degree): (other.degree);
    
    int * addCoeffArr = new int[great];
    for (int i = great; i >= 0; i--)
    {
        addCoeffArr[i] = coeff[i] - other.coeff[i];
    }
    return Polynomial(great, addCoeffArr);
}
Polynomial Polynomial::operator* (const Polynomial& other) const
{
    int newDegree = degree + other.degree;
    int * prod = new int[newDegree + 1];
    
    for (int i = 0; i <= newDegree; i++)
    {
        prod[i] = 0;
    }
    for (int i = degree; i >= 0; i--) {
        for (int j = other.degree; j >=0; j--) {
            prod[i+j] += coeff[i]*other.coeff[j];
        }
    }
    return Polynomial(newDegree, prod);
}
Polynomial Polynomial::operator-() const
{
    int * newCoeff = new int[degree+1];
    for (int i = degree; i >= 0; i--)
    {
        newCoeff[i] = coeff[i] * -1;
    }
    return Polynomial(degree, newCoeff);
}
double Polynomial::evaluate(double x)const
{
    double result = pow(x, degree) * coeff[degree];
    for(int i = degree - 1; i >= 0; i--)
    {
        result += pow(x,i) * coeff[i];
    }
    return result;
}
Polynomial Polynomial::differentiate() const
{
    int * dxCoeff = new int [degree];
    for (int i = degree; i >= 0; i--)
    {
        dxCoeff[i - 1] = coeff[i] * i;
    }
    return Polynomial(degree - 1, dxCoeff);
}
ostream& operator<< (ostream& out, const Polynomial& P)
{
    for (int i = P.degree; i >= 0; i--)
    {
        P.printTerm(out, i);
    }
    return  out;
}
void Polynomial::printTerm(ostream &out, int i) const// int index,
{
    if (coeff[i] == 0)
    {
        out << "";
    }
    else if (degree == 0)
    {
        out << coeff[i];
    }
    else if (coeff[i] > 0 && i == degree)
    {
        out << coeff[i] << "x^" << i;
    }
    else if (coeff[i] > 0 && i == 0)
    {
        out << " + " << coeff[i];
    }
    else if (coeff[i] < 0 && i == 0)
    {
        out << " - " << coeff[i] * -1;
    }
    else if(coeff[i] > 0)
    {
        out << " + " << coeff[i] << "x^" << i;
    }
    else if(coeff[i] < 0)
    {
        out << " - " << (coeff[i] * -1) << "x^" << i;
    }
}