#include"matrice.h"
#include<iostream>

Matrice::Matrice()
{
    ln = 0;
    cln = 0;
    lignes = NULL;
}
Matrice::Matrice(int nl, int nc)
{
    ln = nl;
    cln = nc;
    lignes = new ligne[ln];  
    for (int i = 0; i < ln; i++)
    {
        lignes[i] = new double[cln];
        for (int j = 0; j < cln; j++)
            lignes[i][j] = 0;  
    }
}

Matrice::Matrice(const Matrice& matrc)
{
    ln = matrc.ln;
    cln = matrc.cln;

    lignes = new ligne[ln];
    for (int i = 0; i < ln; i++)
    {
        lignes[i] = new double[cln];
        for (int j = 0; j < cln; j++)
         lignes[i][j] = matrc.lignes[i][j]; 
    }

}

Matrice::Matrice(int nl, int nc, double x)
{
    ln = nl;
    cln = nc;
    lignes = new ligne[ln];
    for (int i = 0; i < ln; i++)
    {
        lignes[i] = new double[cln];
        for (int j = 0; j < cln; j++)
          lignes[i][j] = x;
    }
}

Matrice::~Matrice()
{
    for (int i = 0; i < ln; i++) 
     delete[] lignes[i];
    delete[] lignes;
}

Matrice& Matrice::operator=(const Matrice& mat)
{
    if (this != &mat) 
    {
        if (mat.ln != ln || mat.ln != cln) 
        {
            for (int i = 0; i < ln; i++)
                delete[] lignes[i];
            delete[] lignes;

            ln = mat.ln;
            cln = mat.cln,

                lignes = new ligne[ln];  
            for (int i = 0; i < ln; i++)
                lignes[i] = new double[cln];
        }

        for (int i = 0; i < ln; i++)
           for (int j = 0; j < cln; j++)
          lignes[i][j] = mat.lignes[i][j];
    }
    return *this;
}

Matrice Matrice::operator+(const Matrice& mat) const
{
    Matrice tmp(ln, cln);
    for (int i = 0; i < ln; i++) 
        for (int j = 0; j < cln; j++)
            tmp.lignes[i][j] = lignes[i][j] + mat.lignes[i][j]; 
    return tmp;
}

Matrice Matrice::operator-(const Matrice& mat) const
{
    Matrice tmp(ln, cln);
    for (int i = 0; i < ln; i++) 
        for (int j = 0; j < cln; j++)
            tmp.lignes[i][j] = lignes[i][j] - mat.lignes[i][j]; 
    return tmp;
}

Matrice Matrice::operator*(const Matrice& mat) const
{
    Matrice tmp(ln, cln);
    for (int i = 0; i < ln; i++) 
      for (int j = 0; j < cln; j++)
       tmp.lignes[i][j] = lignes[i][j] * mat.lignes[i][j]; 
    return tmp;
}

void Matrice::affMat()const {

    for (int i = 0; i < this->ln; i++) {
        for (int j = 0; j < this->cln; j++) {
            cout << this->lignes[i][j]<< " ";
        }
        cout << endl;
    }

    cout << endl;

}
