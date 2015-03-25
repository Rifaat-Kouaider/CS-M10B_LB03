//
//  main.cpp
//  PolynomialClass
//
//  Created by Christopher Hunter on 3/16/15.
//

#include <iostream>
#include "Polynomial.h"
void PrintMainMenu();
void PrintMathMenu();
using namespace std;

int main()
{
    bool LOOPMAINMENU = true;
    bool LOOPMATHMENU = false;
    char input;
    
    while (LOOPMAINMENU)
    {
        PrintMainMenu();
        cin >> input;
        
        if (input == '1' || input == 'M' || input == 'm')
        {
            LOOPMATHMENU = true;
        }
        else if (input == '2' || input == 'D' || input == 'd')
        {
            
            
        }
        else if (input == '3' || input == 'R' || input == 'r')
        {
            
            
        }
        else if (input == '4' || input == 'L' || input == 'l')
        {
            
            
        }
        else if (input == '5' || input == 'S' || input == 's')
        {
            
            
        }
        else if (input == '0' || input == 'Q' || input == 'q')
        {
            LOOPMAINMENU = false;
        }
        else
        {
            cout << "Please enter a valid character" << endl;
        }
        
        while (LOOPMATHMENU)
        {
            PrintMathMenu();
            cin >> input;
            if (input == '1' || input == 'A' || input == 'm')
            {
                
            }
            else if (input == '2' || input == 'S' || input == 's')
            {
                
                
            }
            else if (input == '3' || input == 'M' || input == 'm')
            {
                
                
            }
            else if (input == '4' || input == 'N' || input == 'n')
            {
                
                
            }
            else if (input == '5' || input == 'E' || input == 'e')
            {
                
                
            }
            else if (input == '6' || input == 'D' || input == 'd')
            {
                
                
            }
            else if (input == '0' || input == 'Q' || input == 'q')
            {
                LOOPMATHMENU = false;
            }
            else
            {
                cout << "Please enter a valid character" << endl;
            }
        }
    }
    return 0;
}

void PrintMainMenu()
{
    cout << " [1]: Polynomial [M]ath\n [2]: [D]efine a New polynomial\n [3]: [R]emove a polynomial from the list\n [4]: [L]oad a file\n [5]: [S]ave to a file\n [0]: [Q]uit the program" << endl;
}
void PrintMathMenu()
{
    cout << " [1]: Add two polynomials\n [2]: Subtract two polynomials\n [3]: Multiply two polynomials\n [4]: Negate a polynomial\n [5]: Evaluate a polynomial at a real number x0\n [6]: Differentiate a polynomial\n [0]: Quit the processing of polynomials and return to the main menu." << endl;
}
