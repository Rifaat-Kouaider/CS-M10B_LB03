//
//  Polynomial.h
//  CS-M10B_HW04
//
//  Created by Christopher Hunter on 3/16/15.
//  GitHub: hunter-christopher/PolynomialClass
//

#ifndef __CS_M10B_HW04__Polynomial__
#define __CS_M10B_HW04__Polynomial__

#include <istream>
using namespace std;

class Polynomial
{
public:
    // -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
    // Constructors / Destructor
    
    Polynomial();
    Polynomial( int theDegree, int theCoeff = 1);
    Polynomial( int theDegree, int *coeffArray);
    Polynomial( const Polynomial &other);
    
    ~Polynomial();
    
    
    // -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
    // Arithmatic Operator Overloaders
    Polynomial& operator= (const Polynomial& other);
    Polynomial operator+ (const Polynomial& other) const;
    Polynomial operator- (const Polynomial& other) const;
    Polynomial operator* (const Polynomial& other) const;
    
    Polynomial operator-() const;
    double evaluate(double X) const;
    Polynomial differentiate() const;
    // -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
    //Input output
    friend ostream& operator<< (ostream& out, const Polynomial& P);
    
private:
    
    int degree; // the degree of this polynomial
    int* coeff; // the list of coefficients for this polynomial
    void printTerm(ostream &out, int i) const;
    double exp(double x,int toThePowerOf) const;
};

#endif /* defined(__CS_M10B_HW04__Polynomial__) */
