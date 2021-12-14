#include <iostream>
#include "matrice.h"


int main()
{
    Matrice m1, m2, mp, mm, madd;
    m1 = Matrice(2, 3, 1);
    m2 = Matrice(2, 3, 1);
    cout << "matrice 1" << endl;
    m1.affMat();
    cout << "matrice 2" << endl;
    m2.affMat();
    cout << "Produit des matrices" << endl;
    mp = m1 * m2;

    mp.affMat();
    madd = m1 + mp;
    cout << "Addition des matrices" << endl;
    madd.affMat();
    mm = m1 - mp;

    cout << "soustraction des matrices" << endl;
    mm.affMat();
  
  return 0;
}
