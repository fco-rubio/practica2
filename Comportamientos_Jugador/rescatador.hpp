#ifndef COMPORTAMIENTORESCATADOR_H
#define COMPORTAMIENTORESCATADOR_H 

#include <chrono>
#include <time.h>
#include <thread>

#include "comportamientos/comportamiento.hpp"

class ComportamientoRescatador : public Comportamiento
{

public:
  ComportamientoRescatador(unsigned int size = 0) : Comportamiento(size)
  {
    // Inicializar Variables de Estado Niveles 0,1,4
    last_action = IDLE;
    tiene_zapatillas = false;
    giro45Izq = 0;
  }
  ComportamientoRescatador(std::vector<std::vector<unsigned char>> mapaR, std::vector<std::vector<unsigned char>> mapaC) : Comportamiento(mapaR,mapaC)
  {
    // Inicializar Variables de Estado Niveles 2,3
  }
  ComportamientoRescatador(const ComportamientoRescatador &comport) : Comportamiento(comport) {}
  ~ComportamientoRescatador() {}

  Action think(Sensores sensores);

  int interact(Action accion, int valor);

  Action ComportamientoRescatadorNivel_0(Sensores sensores);
  Action ComportamientoRescatadorNivel_1(Sensores sensores);
  Action ComportamientoRescatadorNivel_2(Sensores sensores);
  Action ComportamientoRescatadorNivel_3(Sensores sensores);
  Action ComportamientoRescatadorNivel_4(Sensores sensores);

  void rellenaMatrizCasillasVisitadas(Sensores sensores);
  int VeoCasillaInteresanteNivel0 (char i, char c, char d, bool zap, Sensores sensores);
  int VeoCasillaInteresanteNivel1 (char i, char c, char d, bool zap, Sensores sensores);
private:
  // Variables de Estado
  Action last_action;     //Almacena la ultima accion realizada por el agente
  bool tiene_zapatillas;  //Indica si ya pasó por una casilla de tipo zapatillas
  int giro45Izq;          //Indica si está haciendo un TURN_SL. (0 indica que no)
  vector<vector<int>> casillasVisitadas = vector<vector<int>>(100, vector<int>(100,0));
};

#endif
