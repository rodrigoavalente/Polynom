#include "polynom.h"
template <class TypeOfClass>
Polynom<TypeOfClass>::Polynom()
{

}

template <class TypeOfClass>
Polynom<TypeOfClass>::Polynom(int Num, int Den)
{
    init(Num, Den);
}

template <class TypeOfClass>
Polynom<TypeOfClass>::Polynom(std::string Num, std::string Den)
{
    this->init(Num, Den);
}

template <class TypeOfClass>
Polynom<TypeOfClass>::Polynom(const Polynom<TypeOfClass> &CopyPolynom)
{
    this->num = initPointer(CopyPolynom.sizeNum);
    this->den = initPointer(CopyPolynom.sizeDen);

    for(int i = 0; i < this->sizeNum; i++)
        this->num[i] = CopyPolynom.num[i];

    for(int i = 0; i < this->sizeDen; i++)
        this->den[i] = CopyPolynom.den[i];
}

template <class TypeOfClass>
Polynom<TypeOfClass>::~Polynom()
{
    free(this->num);
    free(this->den);
}

template <class TypeOfClass>
TypeOfClass *Polynom<TypeOfClass>::initPointer(int Size)
{
    TypeOfClass *ret;
    ret = (TypeOfClass*)calloc((Size+1),(Size+1)*sizeof(TypeOfClass*));


    return ret;
}

template <class TypeOfClass>
void Polynom<TypeOfClass>::init(int NumSize)
{
    this->num = initPointer(NumSize);
    this->den = initPointer(0);
    this->sizeNum = NumSize;
    this->sizeDen = 1;
    this->den[0] = 1;
    this->x = 's';
}

template <class TypeOfClass>
void Polynom<TypeOfClass>::init(int NumSize, int DenSize)
{
    this->num = initPointer(NumSize);
    this->den = initPointer(DenSize);
    this->sizeNum = NumSize;
    this->sizeDen = DenSize;
    this->x = 's';
}

template <class TypeOfClass>
void Polynom<TypeOfClass>::init(string Num)
{
    using namespace std;

    Matrix tempNum;

    tempNum = Num;
    this->sizeNum = tempNum.getCols();
    this->num = initPointer(tempNum.getCols());
    for (int i = 0; i < tempNum.getCols(); i++)
        this->num[i] = (TypeOfClass) tempNum.getMat(1, i+1);

    this->sizeDen = 1;
    this->den[0] = 1;

}

template <class TypeOfClass>
void Polynom<TypeOfClass>::init(std::string Num, std::string Den)
{
    using namespace std;

    Matrix tempNum, tempDen;

    tempNum = Num;
    this->sizeNum = tempNum.getCols();
    this->num = initPointer(tempNum.getCols());
    for (int i = 0; i < tempNum.getCols(); i++)
        this->num[i] = (TypeOfClass) tempNum.getMat(1, i+1);

    tempDen = Den;
    this->sizeDen = tempDen.getCols();
    this->den = initPointer(tempDen.getCols());
    for (int i = 0; i < tempDen.getCols(); i++)
        this->den[i] = (TypeOfClass) tempDen.getMat(1 , i+1);
    this->x = 's';
}

template <class TypeOfClass>
TypeOfClass *Polynom::SumPoly(TypeOfClass *value1, TypeOfClass *value2, int SizeValue1, int SizeValue2)
{
   TypeOfClass *ret;
   int min = SizeValue1, max = SizeValue2;

   if(min < SizeValue2)
   {
       min = SizeValue2;
       max = SizeValue1;
   }

   ret = initPointer(max);
   for (int i = 0; i < min; i++)
            ret[max - i] =  value1[SizeValue1 - i] + value2[SizeValue2 - i];

   return ret;
}

template <class TypeOfClass>
void Polynom<TypeOfClass>::operator +(Polynom<TypeofClass> P)
{

    this->num = SumPoly(this->num, P, this->sizeNum, P.sizeNum);
}

template <class TypeOfClass>
void Polynom<TypeOfClass>::operator *(TypeOfClass scalar)
{
    for (int i = 0; i < this->sizeNum; i++)
        this->num[i] = scalar*this->num[i];
}

template <class TypeOfClass>
Polynom<TypeOfClass> operator*(TypeOfClass scalar)
{
    return *this*scalar;
}

template <class TypeOfClass>
TypeOfClass *Polynom<TypeOfClass>::MultPoly(TypeOfClass *value1, TypeOfClass *value2, int SizeValue1, int SizeValue2)
{
    TypeOfClass *ret;

    ret = initPointer(SizeValue1+SizeValue2);
    for(int i = 0; i <= SizeValue1; i++)
        for(int j = 0; j <= SizeValue2; j++)
            ret[i+j] = ret[i+j] +  value1[i]*value2[j];

    return ret;
}


//void Polynom::insert(int index, float value)
//{
//    this->poly[index] = value;
//}

//void Polynom::operator =(Polynom poly)
//{
//    this->init(poly.degree+1);

//    for(int i = 0; i <= this->degree; i++)
//        this->poly[i] = poly.poly[i];
//}

//void Polynom::operator =(std::string value)
//{
//    this->init(value);
//}


//Polynom Polynom::operator +(Polynom poly)
//{

//    Polynom ret;

//    if(this->degree > poly.degree)
//    {
//        poly = resize(this->degree, poly);
//        ret.init(this->degree + 1);
//        for (int i = 0; i <= this->degree; i++)
//                ret.poly[i] = this->poly[i] + poly.poly[i];
//    }
//    else if (poly.degree > this->degree)
//    {
//        poly = resize(poly.degree, poly);
//        ret.init(poly.degree + 1);
//        for (int i = 0; i <= poly.degree; i++)
//                ret.poly[i] = this->poly[i] + poly.poly[i];
//    }
//    else
//    {
//        ret.init(this->degree);
//        for(int i = 0; i < ret.degree; i++)
//            ret.poly[i] = this->poly[i] + poly.poly[i];
//    }

//    return ret;
//}

//Polynom Polynom::operator +(float value)
//{
//    Polynom ret(this->degree);

//    ret.poly = this->poly;
//    ret.poly[ret.degree - 1] =  ret.poly[ret.degree - 1] + value;

//    return ret;
//}

//Polynom Polynom::operator -(Polynom poly)
//{
//    Polynom ret;

//    if(this->degree > poly.degree)
//    {
//        poly = resize(this->degree, poly);
//        ret.init(this->degree + 1);
//        for (int i = 0; i <= this->degree; i++)
//                ret.poly[i] = this->poly[i] - poly.poly[i];
//    }
//    else if (poly.degree > this->degree)
//    {
//        poly = resize(poly.degree, poly);
//        ret.init(poly.degree + 1);
//        for (int i = 0; i <= poly.degree; i++)
//                ret.poly[i] = this->poly[i] - poly.poly[i];
//    }
//    else
//    {
//        ret.init(this->degree);
//        for(int i = 0; i < ret.degree; i++)
//            ret.poly[i] = this->poly[i] - poly.poly[i];
//    }

//    return ret;
//}

//Polynom Polynom::operator -(float value)
//{
//    Polynom ret(this->degree);

//    ret.poly = this->poly;
//    ret.poly[ret.degree - 1] =  ret.poly[ret.degree - 1] - value;

//    return ret;
//}

//Polynom Polynom::operator *(Polynom Poly)
//{
//   Polynom ret(this->degree+Poly.degree + 1);

//    for(int i = 0; i <= this->degree; i++)
//        for(int j = 0; j <= Poly.degree; j++)
//            ret.poly[i+j] = ret.poly[i+j] + this->poly[i]*Poly.poly[j];

//    return ret;
//}

//Polynom resize(int newsize, Polynom poly)
//{
//    Polynom temp;

//    temp = poly;
//    poly.init(newsize);
//    for (int i = temp.degree; i > 0; i--)
//        poly.poly[temp.degree - i + 1] = temp.poly[temp.degree - i];
//    return poly;
//}

template <class TypeOfClass>
void Polynom<TypeOfClass>::print()
{
    unsigned int maxSize;

        if(this->sizeNum > this->sizeDen)
            maxSize = this->sizeNum;
        else
            maxSize = this->sizeDen;

        if(this->sizeDen == 0) {
            if(this->sizeNum >= 2) {
                for(unsigned i = 0; i < this->sizeNum - 2; i++) {
                    if(this->num[i] != 0) {
                        if(this->num[i] != 1)
                            std::cout << this->num[i];
                        std::cout << this->x << '^' << this->sizeNum - i - 1 << ' ';
                        if(i != this->sizeNum - 3)
                            std::cout << '+' << ' ';
                    }
                }
                if(this->num[this->sizeNum - 2]  != 0) {
                    if(this->num[this->sizeNum - 2] != 1)
                            std::cout << '+' << ' ' << this->num[this->sizeNum - 2];
                    std::cout << this->x << ' ';
                }
            }
            if(this->num[this->sizeNum - 1] != 0)
                std::cout << '+' << ' ' << this->num[this->sizeNum - 1] << '\n';

        }
        else {
            if(this->sizeNum >= 2) {
                for(unsigned i = 0; i < this->sizeNum - 2; i++) {
                    if(this->num[i] != 0) {
                        if(this->num[i] != 1)
                            std::cout << this->num[i];
                        std::cout << this->x << '^' << this->sizeNum - i - 1 << ' ';
                        if( i != this->sizeNum - 3)
                           std::cout << '+' << ' ';
                    }
                }
                if(this->num[this->sizeNum - 2] != 0) {
                    if(this->num[this->sizeNum - 2] != 1)
                        std::cout << this->num[this->sizeNum - 2];
                    std::cout << this->x << ' ';
                }
            }
            if(this->num[this->sizeNum - 1] != 0)
                std::cout << '+' << ' ' << this->num[this->sizeNum - 1] << '\n';

            for(unsigned i = 0; i < maxSize; i++)
                std::cout << '-' << '-' << '-' << '-' << '-';
            std::cout << '\n';

            if(this->sizeDen >= 2) {
                for(unsigned i = 0; i < this->sizeDen - 2; i++) {
                    if(this->den[i] != 0) {
                        if(this->den[i] != 1)
                            std::cout << this->den[i];
                        std::cout << this->x << '^' << this->sizeDen - i - 1 << ' ';
                        if(i != this->sizeDen - 3)
                           std::cout << '+' << ' ';
                    }
                }
                if(this->den[this->sizeDen - 2] != 0) {
                    if(this->den[this->sizeDen - 2] != 1)
                       std::cout << '+' << ' ' << this->den[this->sizeDen - 2];
                    std::cout << this->x << ' ';
                }
            }
           if(this->den[this->sizeDen - 1] != 0)
               std::cout << '+' << ' ' << this->den[this->sizeDen - 1];
        }
        std::cout << '\n';
}

template class Polynom <int>;
template class Polynom <float>;
template class Polynom <double>;
