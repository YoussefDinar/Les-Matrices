#pragma once

#include <iostream>

class Matrice
{
private:
   
    int ln;
    int cln;
    typedef double* ligne;
    ligne* lignes;
    

public:

    Matrice();
    Matrice(int nl, int nc);
    Matrice(int nl, int nc, double x);
    Matrice(const Matrice& matrc);
    ~Matrice(void);

    Matrice operator+(const Matrice& mat) const;
    Matrice operator-(const Matrice& mat) const;
    Matrice operator*(const Matrice& mat) const;
    Matrice& operator=(const Matrice& mat);
    void affMat()const;
};
