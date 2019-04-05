#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <math.h>

#define PI 3.14159265

using namespace std;

class Valor
{
private:
  int valor;
  double coseno;
  void calcularCoseno();

public:
  Valor(int valor);
  void setValor(double valor);
  int getValor();
  int getCoseno();
  static bool compararValores(Valor a, Valor b)
  {
    return a.getValor() < b.getValor();
  }
  ~Valor();
};

Valor::~Valor()
{
}

Valor::Valor(int valor)
{
  this->coseno = 0.0;
  this->setValor(valor);
}

void Valor::setValor(double valor)
{
  this->valor = valor;
  this->calcularCoseno();
}

int Valor::getValor()
{
  return this->valor;
}

int Valor::getCoseno()
{
  return this->coseno;
}

void Valor::calcularCoseno()
{
  double cosenoAux = 0.0;
  cosenoAux = cos(this->getValor() * PI / 180);
  this->coseno = cosenoAux;
}
