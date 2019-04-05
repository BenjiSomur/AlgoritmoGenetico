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
    static double primeraSuma(Individuo poblacion);
    static double multipOrdenada(Individuo poblacion);
    static double segundaSuma(Individuo poblacion);

  public:
    FuncionAptitud();
    ~FuncionAptitud();
    static double calcularAptitud(Individuo poblacion);
};

FuncionAptitud::FuncionAptitud() {}
FuncionAptitud::~FuncionAptitud() {}

double FuncionAptitud::primeraSuma(Individuo poblacion)
{
    double suma = 0.0;
    for (int x = 0; x < N; x++)
    {
        double cosenoAux = pow(poblacion.getValores()[x].getCoseno(), 4);
        suma += cosenoAux;
    }
    return suma;
}

double FuncionAptitud::multipOrdenada(Individuo poblacion)
{
    double multiplicacion = 0.0;
    for (int x = 0; x < N; x++)
    {
        double cosenoAux = pow(poblacion.getValores()[x].getCoseno(), 2);
        multiplicacion *= cosenoAux;
    }
    return multiplicacion;
}

double FuncionAptitud::segundaSuma(Individuo poblacion)
{
    double suma = 0.0;
    for (int x = 0; x < N; x++)
    {
        double valorAux = poblacion.getValores()[x].getValor();
        double multipAux = x * (pow(valorAux, 2));
        suma += multipAux;
    }
    return suma;
}

double FuncionAptitud::calcularAptitud(Individuo poblacion)
{
    double resultado = 0.0;
    resultado = (primeraSuma(poblacion) - (2 * multipOrdenada(poblacion)));
    resultado = resultado / sqrt(segundaSuma(poblacion));
    resultado = abs(resultado);
    resultado *= -1;
    return resultado;
}
