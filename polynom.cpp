#include "polynom.h"

Polynom::Polynom()
{

}

Polynom::Polynom(int length)
{
    init(length);
}

Polynom::Polynom(std::string value)
{
    this->init(value);
}

Polynom::~Polynom()
{
//    free(this->poly);
}

void Polynom::init(int length)
{
    this->degree = length;
    this->poly = (float*)calloc(length,(length)*sizeof(float*));
}

void Polynom::init(std::string value)
{
    int positioncoma, pos = 0;
    std::string index = value, temp = "";

    while(!index.empty())
    {
        positioncoma = index.find(",");
        if (positioncoma == -1)
            positioncoma = 1;
        temp = temp + index.substr(0, positioncoma);
        index.erase(0, positioncoma + 1);
    }

    this->degree = (temp.length());
    this->init(this->degree);

    while(!value.empty())
    {
        positioncoma = value.find(",");
        if (positioncoma == -1)
            positioncoma = 1;
        temp = value.substr(0, positioncoma);
        this->insert(pos, atof(temp.c_str()));
        pos++;
        value.erase(0, positioncoma + 1);
    }
}

void Polynom::insert(int index, float value)
{
    this->poly[index] = value;
}

void Polynom::operator =(Polynom poly)
{
    this->init(poly.degree);

    for(int i = 0; i < this->degree; i++)
        this->poly[i] = poly.poly[i];
}

void Polynom::operator =(std::string value)
{
    this->init(value);
}

Polynom Polynom::operator +(Polynom poly)
{

    Polynom ret;

    if(this->degree > poly.degree)
    {
        poly = resize(this->degree, poly);
        ret.init(this->degree);
        for (int i = 0; i < this->degree; i++)
                ret.poly[i] = this->poly[i] + poly.poly[i];
    }
    else if (poly.degree > this->degree)
    {
        poly = resize(poly.degree, poly);
        ret.init(poly.degree);
        for (int i = 0; i < poly.degree; i++)
                ret.poly[i] = this->poly[i] + poly.poly[i];
    }
    else
    {
        ret.init(this->degree);
        for(int i = 0; i < ret.degree; i++)
            ret.poly[i] = this->poly[i] + poly.poly[i];
    }

    return ret;
}

Polynom Polynom::operator +(float value)
{
    Polynom ret(this->degree);

    ret.poly = this->poly;
    ret.poly[ret.degree - 1] =  ret.poly[ret.degree - 1] + value;

    return ret;
}

Polynom Polynom::operator -(Polynom poly)
{
    Polynom ret;

    if(this->degree > poly.degree)
    {
        poly = resize(this->degree, poly);
        ret.init(this->degree);
        for (int i = 0; i < this->degree; i++)
                ret.poly[i] = this->poly[i] - poly.poly[i];
    }
    else if (poly.degree > this->degree)
    {
        poly = resize(poly.degree, poly);
        ret.init(poly.degree);
        for (int i = 0; i < poly.degree; i++)
                ret.poly[i] = this->poly[i] - poly.poly[i];
    }
    else
    {
        ret.init(this->degree);
        for(int i = 0; i < ret.degree; i++)
            ret.poly[i] = this->poly[i] - poly.poly[i];
    }

    return ret;
}

Polynom Polynom::operator -(float value)
{
    Polynom ret(this->degree);

    ret.poly = this->poly;
    ret.poly[ret.degree - 1] =  ret.poly[ret.degree - 1] - value;

    return ret;
}

Polynom resize(int newsize, Polynom poly)
{
    Polynom temp;

    temp = poly;
    poly.init(newsize);
    for (int i = temp.degree; i > 0; i--)
        poly.poly[temp.degree - i + 1] = temp.poly[temp.degree - i];
    return poly;
}

void Polynom::print()
{
    for(int i = this->degree; i > 0; i--)
        if (this->poly[i] > 0)
            std::cout<<"+"<<this->poly[i-1]<<"x^"<<(this->degree - i)<<" ";
        else
            std::cout<<this->poly[i-1]<<"x^"<<(this->degree - i)<<" ";
    std::cout<<"\n";
}
