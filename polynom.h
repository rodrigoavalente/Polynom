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
    TypeOfClass *MultPoly(TypeOfClass *value1, TypeOfClass *value2, int SizeValue1, int SizeValue2);


public:
    Polynom();
    Polynom(int Num, int Den);
    Polynom(int Num);
    //Polynom(const Polynom<TypeOfClass> &CopyPolynom);
    Polynom(std::string Num);
    Polynom(std::string Num, std::string Den);
    ~Polynom();

    Polynom<TypeOfClass> operator +(Polynom<TypeOfClass> P);
    void operator*(TypeOfClass scalar);
    void operator=(Polynom<TypeOfClass> P);


//    void insert(int index, float value);

//    void operator=(Polynom poly);
//    void operator=(std::string value);

//    Polynom operator+(Polynom poly);
//    Polynom operator+(float value);

//    Polynom operator-(Polynom poly);
//    Polynom operator-(float value);

//    Polynom operator*(Polynom poly);


//    friend Polynom resize(int newsize, Polynom poly);

    void print();
};


#endif // POLYNOM_H
