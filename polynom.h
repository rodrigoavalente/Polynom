#ifndef POLYNOM_H
#define POLYNOM_H
#include <cstdlib>
#include <iostream>
#include <string>
#include "matrix.h"


template <class TypeOfClass>
class Polynom
{
private:
    int sizeNum, sizeDen;
    TypeOfClass *num, *den;
    char x;

    void init(int NumSize);
    void init(int NumSize, int DenSize);
    void init(std::string Num);
    void init(std::string Num, string Den);
    TypeOfClass *initPointer(int Size);
    TypeOfClass *SumPoly(TypeOfClass *value1, TypeOfClass *value2, int SizeValue1, int SizeValue2);
    TypeOfClass *SubPoly(TypeOfClass *value1, TypeOfClass *value2, int SizeValue1, int SizeValue2);
    TypeOfClass *MultPoly(TypeOfClass *value1, TypeOfClass *value2, int SizeValue1, int SizeValue2);
    bool VefDen(TypeOfClass *den1, TypeOfClass *den2, int sizeden1, int sizeden2);



public:
    Polynom();
    Polynom(int Num, int Den);
    Polynom(int Num);
    Polynom(const Polynom<TypeOfClass> &CopyPolynom);
    Polynom(std::string Num);
    Polynom(std::string Num, std::string Den);
    ~Polynom();

    Polynom<TypeOfClass> operator+(Polynom<TypeOfClass> P);
    Polynom<TypeOfClass> operator+(TypeOfClass scalar);
    friend Polynom<TypeOfClass> operator+(TypeOfClass scalar, Polynom<TypeOfClass> P){return P+scalar;}

    Polynom<TypeOfClass> operator-(Polynom<TypeOfClass> P);
    Polynom<TypeOfClass> operator-(TypeOfClass scalar);
    friend Polynom<TypeOfClass> operator-(TypeOfClass scalar, Polynom<TypeOfClass> P){return (-1)*P+scalar;}

    Polynom<TypeOfClass> operator*(TypeOfClass scalar);
    Polynom<TypeOfClass> operator*(Polynom<TypeOfClass> P);
    friend Polynom<TypeOfClass> operator*(TypeOfClass scalar, Polynom<TypeOfClass> P){return P*scalar;}

    Polynom<TypeOfClass> operator/(Polynom<TypeOfClass> P);
    Polynom<TypeOfClass> operator/(TypeOfClass scalar);
    friend Polynom<TypeOfClass> operator/(TypeOfClass scalar, Polynom<TypeOfClass> P){return (P^-1)*scalar;}
    void operator=(Polynom<TypeOfClass> P);


    Polynom<TypeOfClass> operator^(int scalar);

    void setNum(TypeOfClass *Num, int sizenum);
    void setDen(TypeOfClass *Den, int sizeden);

    void print();
};


#endif // POLYNOM_H
