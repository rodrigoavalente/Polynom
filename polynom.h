//! Classe Polinômio.

/*! 
    Classe criado com a finalidade de tratar expressões numéricas de uma única varíavel.
*/

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
    //! Construtor padrão da classe.
    /*! 
        Inicia a variável com 's'.
    */
    Polynom();

    //! Construtor que inicia o numerador e o denominador do Polinômio.
    /*! 
       Inicia o polinômio de acordo com a quantidade de termos no numerador e denominador.
       \param Num um argumento inteiro que representa a quantidade de termos no numerador.
       \param Den um argumento inteiro que representa a quantidade de termos no denominador.
    */
    Polynom(int Num, int Den);

    //! Construdor para um polinômio que só tenha um numerador.
    /*!
       Inicia o polinômio com a quantidade de termos no numerador, sempre considera o denominador como 1.
       \param Num um argumento inteiro que representa a quantidade de termos no numerador.
    */
    Polynom(int Num);
    
    //! Construdor de cópia.
    /*!
       Construtor responsável para se realizar cópias dos endereços de memórias enquanto se opera com polinômios.
       \param CopyPolynom uma constante do tipo de Polynom que referência o polinôio a ser copiado.
    */
    Polynom(const Polynom<TypeOfClass> &CopyPolynom);
    
    //! Construtor que inicia um polinômio com uma entrada do tipo string, sempre considera o denominador como 1.
    /*!
       \param Num um argumento do tipo string que inicializa o numerador polinômio de acordo com o texto de entrada.
    */
    Polynom(std::string Num);
    
    //! Construtor que inicia um polinômio com uma entrada do tipo string.
    /*!
       \param Num um argumento do tipo string que incializa o numerador do polinômio de acordo com o texto de entrada.
       \param Den um argumento do tipo string que incializa o denominador do polinômio de acordo com o texto de entrada.
    */
    Polynom(std::string Num, std::string Den);
    
    //! Destrutor padrão da classe.
    /*!
       Libera toda a memória aloca utilzada por objetos da classe.
    */
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
