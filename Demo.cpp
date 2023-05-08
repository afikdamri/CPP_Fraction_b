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

#include <iostream>
#include <vector>
#include <utility>

using namespace ariel;

int main()
{
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
  cout << c.getNumerator() << " / " << c.getDenominator() << endl;

  Fraction d(4, 5);
  float e = 0.4;
  Fraction f = d / e; // 4/5 / 2/5 = 4/5 * 5/2 = 20 / 10 = 2/1
  cout << f.getNumerator() << " / " << f.getDenominator() << endl;

  Fraction fraction1(-1,2);
  Fraction fraction2(-1,3);
  cout << fraction1.getNumerator() << " / " << fraction1.getDenominator() << endl;
  cout << fraction2.getNumerator() << " / " << fraction2.getDenominator() << endl;


  if (fraction1 < fraction2)
  {
    cout << "yes" << endl;
  }else
  {
    cout << "no" << endl;
  }

  /*   std::vector<std::pair<Fraction, Fraction>> fracs = {
       {Fraction{2, 6}, Fraction{1, 2}},
       {Fraction{1000, 3000}, Fraction{1, 2}},
       {Fraction{1, 4}, Fraction{1, 3}},
       {Fraction{1, 3}, Fraction{2, 3}},
       {Fraction{1000, 3000}, Fraction{2, 3}},
       {Fraction{-1, 2}, Fraction{-1, 3}},
       {Fraction{1, -2}, Fraction{-1, 3}},
       {Fraction{3, -5}, Fraction{-2, 5}},
       {Fraction{-500, 1000}, Fraction{1000, -3000}},
       {Fraction{4, 3}, Fraction{7, 5}},
       {Fraction{7, 5}, Fraction{4, 2}},
       {Fraction{7, 5}, Fraction{9, 4}},
       {Fraction{120, 3}, Fraction{250, 3}}
   };

   for (size_t i = 0; i < fracs.size(); i++) {
       if (fracs[i].first < fracs[i].second) {
           std::cout << fracs[i].first.getNumerator() << "/" << fracs[i].first.getDenominator()
                     << " is less than " << fracs[i].second.getNumerator() << "/" << fracs[i].second.getDenominator() << std::endl;
       }
       else {
           std::cout << fracs[i].first.getNumerator() << "/" << fracs[i].first.getDenominator()
                     << " is not less than " << fracs[i].second.getNumerator() << "/" << fracs[i].second.getDenominator() << std::endl;
       }

       if (fracs[i].second < fracs[i].first) {
           std::cout << fracs[i].second.getNumerator() << "/" << fracs[i].second.getDenominator()
                     << " is less than " << fracs[i].first.getNumerator() << "/" << fracs[i].first.getDenominator() << std::endl;
       }
       else {
           std::cout << fracs[i].second.getNumerator() << "/" << fracs[i].second.getDenominator()
                     << " is not less than " << fracs[i].first.getNumerator() << "/" << fracs[i].first.getDenominator() << std::endl;
       }
   }

   return 0;*/
}
