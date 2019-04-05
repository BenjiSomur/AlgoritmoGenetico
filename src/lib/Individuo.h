#include "Valor.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <math.h>
#include <vector>
#include <bits/stdc++.h>
#include <time.h>

using namespace std;

class Individuo
{
  private:
    vector<Valor> individuos;
    double aptitud;
    void ordenar();

  public:
    Individuo();
    void agregarValor(Valor elemento);
    double getAptitud();
    void setAptitud(double aptitud);
    vector<Valor> getValores();
    static bool compararIndividuos(Individuo a, Individuo b);
    ~Individuo();
};

Individuo::Individuo() {}

Individuo::~Individuo() {}
vector<Valor> Individuo::getValores()
{
    return this->individuos;
}

void Individuo::setAptitud(double aptitud)
{
    this->aptitud = aptitud;
}

double Individuo::getAptitud()
{
    return this->aptitud;
}

void Individuo::agregarValor(Valor elemento)
{
    this->individuos.push_back(elemento);
    this->ordenar();
}

void Individuo::ordenar()
{
    sort(this->individuos.begin(), this->individuos.end(), Valor::compararValores);
}

bool Individuo::compararIndividuos(Individuo a, Individuo b)
{
    return a.getAptitud() < b.getAptitud();
}