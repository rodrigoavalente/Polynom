//! Classe Polin�mio.

/*! 
    Classe criado com a finalidade de tratar express�es num�ricas de uma �nica var�avel.
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
    //! Construtor padr�o da classe.
    /*! 
        Inicia a vari�vel com 's'.
    */
    Polynom();

    //! Construtor que inicia o numerador e o denominador do Polin�mio.
    /*! 
       Inicia o polin�mio de acordo com a quantidade de termos no numerador e denominador.
       \param Num um argumento inteiro que representa a quantidade de termos no numerador.
       \param Den um argumento inteiro que representa a quantidade de termos no denominador.
    */
    Polynom(int Num, int Den);

    //! Construdor para um polin�mio que s� tenha um numerador.
    /*!
       Inicia o polin�mio com a quantidade de termos no numerador, sempre considera o denominador como 1.
       \param Num um argumento inteiro que representa a quantidade de termos no numerador.
    */
    Polynom(int Num);
    
    //! Construdor de c�pia.
    /*!
       Construtor respons�vel para se realizar c�pias dos endere�os de mem�rias enquanto se opera com polin�mios.
       \param CopyPolynom uma constante do tipo de Polynom que refer�ncia o polin�io a ser copiado.
    */
    Polynom(const Polynom<TypeOfClass> &CopyPolynom);
    
    //! Construtor que inicia um polin�mio com uma entrada do tipo string, sempre considera o denominador como 1.
    /*!
       \param Num um argumento do tipo string que inicializa o numerador polin�mio de acordo com o texto de entrada.
    */
    Polynom(std::string Num);
    
    //! Construtor que inicia um polin�mio com uma entrada do tipo string.
    /*!
       \param Num um argumento do tipo string que incializa o numerador do polin�mio de acordo com o texto de entrada.
       \param Den um argumento do tipo string que incializa o denominador do polin�mio de acordo com o texto de entrada.
    */
    Polynom(std::string Num, std::string Den);
    
    //! Destrutor padr�o da classe.
    /*!
       Libera toda a mem�ria aloca utilzada por objetos da classe.
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
