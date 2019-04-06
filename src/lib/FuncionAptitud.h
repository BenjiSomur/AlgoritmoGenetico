#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <math.h>
#include "Individuo.h"
#define N 20
using namespace std;

/*
    Falta métodos para la validación de los valors de cada individuo que formará parte de la población
*/

class FuncionAptitud
{
  private:
    static double primeraSuma(Individuo individuo);
    static double multipOrdenada(Individuo individuo);
    static double segundaSuma(Individuo individuo);

  public:
    FuncionAptitud();
    ~FuncionAptitud();
    static double calcularAptitud(Individuo individuo);
};

FuncionAptitud::FuncionAptitud() {}
FuncionAptitud::~FuncionAptitud() {}

double FuncionAptitud::primeraSuma(Individuo individuo)
{
    double suma = 0.0;
    for (int x = 0; x < N; x++)
    {
        double cosenoAux = pow(individuo.getValores()[x].getCoseno(), 4);
        suma += cosenoAux;
    }
    return suma;
}

double FuncionAptitud::multipOrdenada(Individuo individuo)
{
    double multiplicacion = 1.0;
    for (int x = 0; x < N; x++)
    {
        double cosenoAux = pow(individuo.getValores()[x].getCoseno(), 2);
        multiplicacion *= cosenoAux;
    }
    return multiplicacion;
}

double FuncionAptitud::segundaSuma(Individuo individuo)
{
    double suma = 0.0;
    for (int x = 0; x < N; x++)
    {
        double valorAux = individuo.getValores()[x].getValor();
        double multipAux = x * (pow(valorAux, 2));
        suma += multipAux;
    }
    return suma;
}

double FuncionAptitud::calcularAptitud(Individuo individuo)
{
    double resultado = 0.0;
    resultado = (primeraSuma(individuo) - (2 * multipOrdenada(individuo)));
    resultado = resultado / sqrt(segundaSuma(individuo));
    resultado = abs(resultado);
    resultado *= -1;
    return resultado;
}
