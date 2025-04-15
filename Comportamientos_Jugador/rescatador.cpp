#include "../Comportamientos_Jugador/rescatador.hpp"
#include "motorlib/util.h"

Action ComportamientoRescatador::think(Sensores sensores)
{
	Action accion = IDLE;

	switch (sensores.nivel)
	{
	case 0:
		accion = ComportamientoRescatadorNivel_0 (sensores);
		break;
	case 1:
		// accion = ComportamientoRescatadorNivel_1 (sensores);
		break;
	case 2:
		// accion = ComportamientoRescatadorNivel_2 (sensores);
		break;
	case 3:
		// accion = ComportamientoRescatadorNivel_3 (sensores);
		break;
	case 4:
		// accion = ComportamientoRescatadorNivel_4 (sensores);
		break;
	}

	return accion;
}

int ComportamientoRescatador::interact(Action accion, int valor)
{
	return 0;
}

Action ComportamientoRescatador::ComportamientoRescatadorNivel_0(Sensores sensores)
{
	Action accion;
	// El comportamiento de seguir un camino hasta encontrar un puesto base.
	// Actualización de variables de estado
	if (sensores.superficie[0] == 'D') tiene_zapatillas = true;


	// Definición del comportamiento
	if (sensores.superficie[0] == 'X') {		//LLegué al objetivo
		accion = IDLE;
	}
	else if (giro45Izq!=0) {					//Estoy haciendo un TURN_SL
		accion = TURN_SR;
		giro45Izq--;
	}
	else if (sensores.superficie[2] =='C' ) {
		accion = WALK;
	}
	else if (sensores.superficie[1] == 'C' ) {
		giro45Izq = 1;
		accion = TURN_L;
	}
	else if (sensores.superficie[3] == 'C') {
		accion = TURN_SR;
	}
	else {
		accion = TURN_L;
	}


	// Devolver la siguiente acción a hacer
	last_action = accion;
	return accion;
}

Action ComportamientoRescatador::ComportamientoRescatadorNivel_1(Sensores sensores)
{
}

Action ComportamientoRescatador::ComportamientoRescatadorNivel_2(Sensores sensores)
{
}

Action ComportamientoRescatador::ComportamientoRescatadorNivel_3(Sensores sensores)
{
}

Action ComportamientoRescatador::ComportamientoRescatadorNivel_4(Sensores sensores)
{
}