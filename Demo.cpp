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
  /*  Fraction a(5,3), b(14,21);
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
*/
    Fraction a(1, 2), b(1, 4);
    Fraction c = a / b; // 1/2 / 1/4 = 1/2 * 4/1 = 4/2 = 2/1
    cout << c.getNumerator() << " / " << c.getDenominator()  << endl;
    
    Fraction d(4, 5);
    float e = 0.4;
    Fraction f = d / e; // 4/5 / 2/5 = 4/5 * 5/2 = 20 / 10 = 2/1
    cout << f.getNumerator() << " / " << f.getDenominator() << endl;
    


}
