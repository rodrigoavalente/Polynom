#include "polynom.h"

Polynom::Polynom()
{
    this->degree = 0;
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
    free(this->poly);
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

void Polynom::print()
{
    for(int i = 0; i < this->degree; i++)
        std::cout<<this->poly[i]<<" ";
    std::cout<<"\n";
}
