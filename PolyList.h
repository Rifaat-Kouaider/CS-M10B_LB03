//
//  PolyList.h
//  CS-M10B_LB03
//
//  Created by Christopher Hunter on 3/24/15.
//  Copyright (c) 2015 hunter-christopher. All rights reserved.
//

#ifndef __CS_M10B_LB03__PolyList__
#define __CS_M10B_LB03__PolyList__

#include <istream>
#include "Polynomial.h"

class PolyList
{
public:
    PolyList();
    ~PolyList() { }
    // Menu Option Functions
    void NewPolynomial();
    void RemoveAPolynomial();
    void LoadPolynomialFile();
    void SavePolynomialFile();
    
    void AddPolynomials();
    void SubtractPolynomial();
    void MultiplyPolynomials();
    void NegatePolynomial();
    void EvaluatePolynomial();
    void DifferentiatePolynomial();
    
    friend std::ostream& operator<< (std::ostream& out, const PolyList& PList);
public:
    Polynomial list[12];                          // fixed-size list of polynomials
    int listCount;                               // number of polynomials in the list
    PolyList(const PolyList & PL);              // copy-constructor – no copies (i.e. body << 0)
    PolyList operator<< (const PolyList & PL); // assignment operator – no assignments
};

#endif /* defined(__CS_M10B_LB03__PolyList__) */