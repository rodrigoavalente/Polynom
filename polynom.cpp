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
    init(Num, Den);
}

template <class TypeOfClass>
Polynom<TypeOfClass>::Polynom(std::string Num)
{
    init(Num);
}

template <class TypeOfClass>
Polynom<TypeOfClass>::Polynom(int Num)
{
    init(Num);
}

template <class TypeOfClass>
Polynom<TypeOfClass>::Polynom(const Polynom<TypeOfClass> &CopyPolynom)
{
    this->num = initPointer(CopyPolynom.sizeNum);
    this->den = initPointer(CopyPolynom.sizeDen);
    this->sizeNum = CopyPolynom.sizeNum;
    this->sizeDen = CopyPolynom.sizeDen;
    this->x = CopyPolynom.x;

    for(int i = 0; i < this->sizeNum; i++)
        this->num[i] = CopyPolynom.num[i];

    for(int i = 0; i < this->sizeDen; i++)
        this->den[i] = CopyPolynom.den[i];
}

template <class TypeOfClass>
Polynom<TypeOfClass>::~Polynom()
{
    if(this->sizeNum != 0 && this->sizeDen != 0)
    {
        free(this->num);
        free(this->den);
    }

    this->num = NULL;
    this->den = NULL;

    this->sizeNum = 0;
    this->sizeDen = 0;
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
void Polynom<TypeOfClass>::init(std::string Num)
{
    using namespace std;

    Matrix tempNum;

    tempNum = Num;
    this->sizeNum = tempNum.getCols();
    this->num = initPointer(tempNum.getCols());
    for (int i = 0; i < tempNum.getCols(); i++)
        this->num[i] = (TypeOfClass) tempNum.getMat(1, i+1);

    this->sizeDen = 1;
    this->den = initPointer(1);
    this->den[0] = 1;
    this->x = 's';

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
Polynom<TypeOfClass> Polynom<TypeOfClass>::operator +(Polynom<TypeOfClass> P)
{
    Polynom<TypeOfClass> ret;

    ret.num = SumPoly(MultPoly(P.den, this->num, P.sizeDen, this->sizeNum),MultPoly(P.num, this->den, P.sizeNum, this->sizeDen), (P.sizeDen + this->sizeNum - 1),(P.sizeNum + this->sizeDen - 1));
    ret.den = MultPoly(this->den, P.den, this->sizeDen, P.sizeNum);
    int max = (P.sizeDen + this->sizeNum - 1);

    if(max < (P.sizeNum + this->sizeDen - 1))
        max = (P.sizeNum + this->sizeDen - 1);

    ret.sizeNum = max;
    ret.sizeDen = this->sizeDen + P.sizeDen - 1;
    ret.x = P.x;

    return ret;
}

template <class TypeOfClass>
Polynom<TypeOfClass> Polynom<TypeOfClass>::operator -(Polynom<TypeOfClass> P)
{
    Polynom<TypeOfClass> ret;

    ret.num = SubPoly(MultPoly(P.den, this->num, P.sizeDen, this->sizeNum),MultPoly(P.num, this->den, P.sizeNum, this->sizeDen), (P.sizeDen + this->sizeNum - 1),(P.sizeNum + this->sizeDen - 1));
    ret.den = MultPoly(this->den, P.den, this->sizeDen, P.sizeNum);
    int max = (P.sizeDen + this->sizeNum - 1);

    if(max < (P.sizeNum + this->sizeDen - 1))
        max = (P.sizeNum + this->sizeDen - 1);

    ret.sizeNum = max;
    ret.sizeDen = this->sizeDen + P.sizeDen - 1;
    ret.x = P.x;

    return ret;
}

template <class TypeOfClass>
void Polynom<TypeOfClass>::operator *(TypeOfClass scalar)
{
    for (int i = 0; i < this->sizeNum; i++)
        this->num[i] = scalar*this->num[i];
}
template <class TypeOfClass>
void Polynom<TypeOfClass>::operator =(Polynom<TypeOfClass> P)
{
    this->sizeNum = P.sizeNum;
    this->sizeDen = P.sizeDen;
    this->num = initPointer(P.sizeNum);
    this->den = initPointer(P.sizeDen);

    for (int i = 0; i < P.sizeNum; i++)
        this->num[i] = P.num[i];

    for (int i = 0; i < P.sizeDen; i++)
        this->den[i] = P.den[i];

    this->x = P.x;
}

template <class TypeOfClass>
Polynom<TypeOfClass> Polynom<TypeOfClass>::operator *(Polynom<TypeOfClass> P)
{
    Polynom<TypeOfClass> ret;

    ret.num = MultPoly(this->num, P.num, this->sizeNum, P.sizeNum);
    ret.den = MultPoly(this->den, P.den, this->sizeDen, P.sizeDen);
    ret.sizeNum = (this->sizeNum + P.sizeNum - 1);
    ret.sizeDen = (this->sizeDen + P.sizeDen - 1);
    ret.x = P.x;

    return ret;

}

template <class TypeOfClass>
TypeOfClass *Polynom<TypeOfClass>::SumPoly(TypeOfClass *value1, TypeOfClass *value2, int SizeValue1, int SizeValue2)
{
   TypeOfClass *ret;

   int min = SizeValue1, max = SizeValue2;

   if(min < SizeValue2)
   {
       min = SizeValue2;
       max = SizeValue1;
   }

   ret = initPointer(max);
   for (int i = 1; i <= min; i++)
       ret[max - i] =  value1[SizeValue1 - i] + value2[SizeValue2 - i];

   return ret;
}

template <class TypeOfClass>
TypeOfClass *Polynom<TypeOfClass>::SubPoly(TypeOfClass *value1, TypeOfClass *value2, int SizeValue1, int SizeValue2)
{
    TypeOfClass *ret;

    int min = SizeValue1, max = SizeValue2;

    if(min < SizeValue2)
    {
        min = SizeValue2;
        max = SizeValue1;
    }

    ret = initPointer(max);
    for (int i = 1; i <= min; i++)
        ret[max - i] =  value1[SizeValue1 - i] - value2[SizeValue2 - i];

    return ret;
}

template <class TypeOfClass>
TypeOfClass *Polynom<TypeOfClass>::MultPoly(TypeOfClass *value1, TypeOfClass *value2, int SizeValue1, int SizeValue2)
{
    TypeOfClass *ret;

    ret = initPointer(SizeValue1+SizeValue2);
    for(int i = 0; i < SizeValue1; i++)
        for(int j = 0; j < SizeValue2; j++)
            ret[i+j] = ret[i+j] +  value1[i]*value2[j];

    return ret;
}

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
