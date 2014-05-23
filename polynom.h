#ifndef POLYNOM_H
#define POLYNOM_H
#include <cstdlib>
#include <iostream>
#include <string>


class Polynom
{
private:
    int degree;
    float *poly;

public:
    Polynom();
    Polynom(int length);
    Polynom(std::string value);
    ~Polynom();

    void init(int length);
    void init(std::string value);
    void insert(int index, float value);

    void operator=(Polynom poly);
    void operator=(std::string value);
    Polynom operator+(Polynom poly);

    void print();
};

#endif // POLYNOM_H
