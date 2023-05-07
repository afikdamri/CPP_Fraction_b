/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;


int main() {
    Fraction a(5,3), b(14,21);
    cout << "a: " << a << "b: " << b << endl;
    cout << "a+b:   " << a+b << endl; 
    cout << "a-b:   " << a-b << endl; 
    cout << "a/b:   " << a/b << endl; 
    cout << "a*b:   " << a*b << endl; 
    cout << "2.3*b:   " << 2.3*b << endl; 
    cout << "a+2.421:   " << a+2.421 << endl; 
    Fraction c = a+b-1;
    cout << c++ << endl;
    cout << --c << endl;

    cout << "c >=b ? : " << (c >= b) << endl;
    if (a > 1.1) cout << " a is bigger than 1.1" << endl;
    else cout << " a is smaller than 1.1" << endl;

    Fraction f(2, 5);
    Fraction h(4, 5);
    cout << f.getDenominator() << endl;
    cout << f.getNumerator() << endl;
    float e = 0.4;
    Fraction z = e-h;
    cout << z.getNumerator() << endl;
    cout << z.getDenominator() << endl;

    


}
