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
		accion = ComportamientoRescatadorNivel_1 (sensores);
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

int VeoCasillaInteresanteR (char i, char c, char d, bool zap, Sensores sensores) {
	if (c == 'X' && sensores.agentes[2]=='_') return 2;
	else if (i == 'X'  && sensores.agentes[1]=='_') return 1;
	else if (d == 'X'  && sensores.agentes[3]=='_') return 3;
	else if (!zap) {
		if (c == 'D' && sensores.agentes[2]=='_') return 2;
		else if (i == 'D' && sensores.agentes[1]=='_' ) return 1;
		else if (d == 'D'  && sensores.agentes[3]=='_') return 3;
		
	}
	if (c == 'C' && sensores.agentes[2]=='_' && sensores.agentes[3]=='_') return 2;
	else if (i == 'C' && sensores.agentes[1]=='_') return 1;
	else if (d == 'C' && sensores.agentes[3]=='_') return 3;
	else if (c == 'D' && sensores.agentes[2]=='_') return 2;
	else if (i == 'D' && sensores.agentes[1]=='_' ) return 1;
	else if (d == 'D'  && sensores.agentes[3]=='_') return 3;
	else return 0;
}


char ViablePorAlturaR (char casilla, int dif, bool zap) {
	if (abs(dif)<=1 or (zap and abs(dif)<=2))
		return casilla;
	else
		return 'P';
}
void SituarSensorEnMapaR(vector<vector<unsigned char>> &m, vector<vector<unsigned char>> &a, Sensores sensores) {
	m[sensores.posF][sensores.posC] = sensores.superficie[0];
	int pos=1,j=0;
	switch (sensores.rumbo)
	{
	case norte:
		for (j=-1;j<2;j++){
			m[sensores.posF-1][sensores.posC+j]=sensores.superficie[pos];
			a[sensores.posF-1][sensores.posC+j]=sensores.cota[pos];
			pos++;
		}
		for (j=-2;j<3;j++) {
			m[sensores.posF-2][sensores.posC+j]=sensores.superficie[pos];
			a[sensores.posF-2][sensores.posC+j]=sensores.cota[pos];
			pos++;
		}
		for (j=-3;j<4;j++) {
			m[sensores.posF-3][sensores.posC+j]=sensores.superficie[pos];
			a[sensores.posF-3][sensores.posC+j]=sensores.cota[pos];
			pos++;
		}
		break;
	
	case noreste:
		for (j=0;j<2;j++) { //posicion 1 y 2
			m[sensores.posF - 1][sensores.posC+j] = sensores.superficie[pos];
			a[sensores.posF - 1][sensores.posC+j] = sensores.cota[pos];
			pos++;
		}
		//posicion 3
		m[sensores.posF][sensores.posC+1] = sensores.superficie[pos];
		a[sensores.posF][sensores.posC+1] = sensores.cota[pos];
		pos++;
		for(j=0;j<3;j++) { //posicion 4 5 y 6
			m[sensores.posF -2][sensores.posC+j] = sensores.superficie[pos];
			a[sensores.posF -2][sensores.posC+j] = sensores.cota[pos];
			pos++;
		}
		for (j=-1;j<1;j++) { //posicion 7 y 8
			m[sensores.posF +j][sensores.posC +2] = sensores.superficie[pos];
			a[sensores.posF +j][sensores.posC +2] = sensores.cota[pos];
			pos++;
		}
		for (j=0;j<4;j++) { //posicion 9 10 11 y 12
			m[sensores.posF - 3][sensores.posC + j] = sensores.superficie[pos];
			a[sensores.posF - 3][sensores.posC + j] = sensores.cota[pos];
			pos++;
		}
		for (j=-2;j<1;j++) { //posicion 13 14 y 15
			m[sensores.posF +j][sensores.posC +3] =sensores.superficie[pos];
			a[sensores.posF +j][sensores.posC +3] =sensores.cota[pos];
			pos++;
		
		}

		break;
	
	case este:
		for (j=-1;j<2;j++){
			m[sensores.posF+j][sensores.posC+1]=sensores.superficie[pos];
			a[sensores.posF+j][sensores.posC+1]=sensores.cota[pos];
			pos++;
		}
		for (j=-2;j<3;j++) {
			m[sensores.posF+j][sensores.posC+2]=sensores.superficie[pos];
			a[sensores.posF+j][sensores.posC+2]=sensores.cota[pos];
			pos++;
		}
		for (j=-3;j<4;j++) {
			m[sensores.posF+j][sensores.posC+3]=sensores.superficie[pos];
			a[sensores.posF+j][sensores.posC+3]=sensores.cota[pos];
			pos++;
		}
		break;
	case sureste:
		for (j=0;j<2;j++) { //posicion 1 y 2
			m[sensores.posF +j][sensores.posC + 1] = sensores.superficie[pos];
			a[sensores.posF +j][sensores.posC + 1] = sensores.superficie[pos];
			pos++;
		}
		//posicion 3
		m[sensores.posF+1][sensores.posC] = sensores.superficie[pos];
		pos++;
		for(j=0;j<3;j++) { //posicion 4 5 y 6
			m[sensores.posF + j][sensores.posC+2] = sensores.superficie[pos];
			a[sensores.posF + j][sensores.posC+2] = sensores.cota[pos];
			pos++;
		}
		for (j=1;j>-1;j--) { //posicion 7 y 8
			m[sensores.posF +2][sensores.posC +j] = sensores.superficie[pos];
			a[sensores.posF +2][sensores.posC +j] = sensores.cota[pos];
			pos++;
		}
		for (j=0;j<4;j++) { //posicion 9 10 11 y 12
			m[sensores.posF + j][sensores.posC + 3] = sensores.superficie[pos];
			a[sensores.posF + j][sensores.posC + 3] = sensores.superficie[pos];
			pos++;
		}
		for (j=2;j>-1;j--) { //posicion 13 14 y 15
			m[sensores.posF +3][sensores.posC +j] =sensores .superficie[pos];
			a[sensores.posF +3][sensores.posC +j] =sensores .superficie[pos];
			pos++;
		
		}	
		break;
		
	case sur:
		for (j=1;j>-2;j--){
			m[sensores.posF+1][sensores.posC+j]=sensores.superficie[pos];
			pos++;
		}
		for (j=2;j>-3;j--) {
			m[sensores.posF+2][sensores.posC+j]=sensores.superficie[pos];
			pos++;
		}
		for (j=3;j>-4;j--) {
			m[sensores.posF+3][sensores.posC+j]=sensores.superficie[pos];
			pos++;
		}
		break;
		
	case suroeste:
		for (j=0;j>-2;j--) { //posicion 1 y 2
			m[sensores.posF + 1][sensores.posC+j] = sensores.superficie[pos];
			a[sensores.posF + 1][sensores.posC+j] = sensores.cota[pos];
			pos++;
		}
		//posicion 3
		m[sensores.posF][sensores.posC-1] = sensores.superficie[pos];
		a[sensores.posF][sensores.posC-1] = sensores.cota[pos];
		pos++;
		for(j=0;j>-3;j--) { //posicion 4 5 y 6
			m[sensores.posF +2][sensores.posC+j] = sensores.superficie[pos];
			a[sensores.posF +2][sensores.posC+j] = sensores.cota[pos];
			pos++;
		}
		for (j=1;j>-1;j--) { //posicion 7 y 8
			m[sensores.posF +j][sensores.posC -2] = sensores.superficie[pos];
			a[sensores.posF +j][sensores.posC -2] = sensores.cota[pos];
			pos++;
		}
		for (j=0;j>-4;j--) { //posicion 9 10 11 y 12
			m[sensores.posF + 3][sensores.posC + j] = sensores.superficie[pos];
			a[sensores.posF + 3][sensores.posC + j] = sensores.cota[pos];
			pos++;
		}
		for (j=2;j<-1;j--) { //posicion 13 14 y 15
			m[sensores.posF +j][sensores.posC -3] =sensores.superficie[pos];
			a[sensores.posF +j][sensores.posC -3] =sensores.cota[pos];
			pos++;
		
		}
		
		break;
	case oeste:
		for (j=1;j>-2;j--){
			m[sensores.posF+j][sensores.posC-1]=sensores.superficie[pos];
			a[sensores.posF+j][sensores.posC-1]=sensores.cota[pos];
			pos++;
		}
		for (j=2;j>-3;j--) {
			m[sensores.posF+j][sensores.posC-2]=sensores.superficie[pos];
			a[sensores.posF+j][sensores.posC-2]=sensores.cota[pos];
			pos++;
		}
		for (j=3;j>-4;j--) {
			m[sensores.posF+j][sensores.posC-3]=sensores.superficie[pos];
			a[sensores.posF+j][sensores.posC-3]=sensores.cota[pos];
			pos++;
		}
		break;
	case noroeste: 
		for (j=0;j>-2;j--) { //posicion 1 y 2
			m[sensores.posF + j][sensores.posC - 1] = sensores.superficie[pos];
			a[sensores.posF + j][sensores.posC -1] = sensores.cota[pos];
			pos++;
		}
		//posicion 3
		m[sensores.posF - 1][sensores.posC] = sensores.superficie[pos];
		a[sensores.posF - 1][sensores.posC] = sensores.cota[pos];
		pos++;
		for(j=0;j>-3;j--) { //posicion 4 5 y 6
			m[sensores.posF + j][sensores.posC -2] = sensores.superficie[pos];
			a[sensores.posF + j][sensores.posC -2] = sensores.cota[pos];
			pos++;
		}
		for (j=-1;j<1;j++) { //posicion 7 y 8
			m[sensores.posF - 2][sensores.posC + j] = sensores.superficie[pos];
			a[sensores.posF - 2][sensores.posC + j] = sensores.cota[pos];
			pos++;
		}
		for (j=0;j>-4;j--) { //posicion 9 10 11 y 12
			m[sensores.posF + j][sensores.posC - 3] = sensores.superficie[pos];
			a[sensores.posF + j][sensores.posC - 3] = sensores.cota[pos];
			pos++;
		}
		for (j=-2;j<1;j++) { //posicion 13 14 y 15
			m[sensores.posF - 3][sensores.posC + j] =sensores.superficie[pos];
			a[sensores.posF - 3][sensores.posC + j] =sensores.cota[pos];
			pos++;
		
		}
		break;
	
	
	}
	
}

Action ComportamientoRescatador::ComportamientoRescatadorNivel_0(Sensores sensores)
{
	Action accion;
	// El comportamiento de seguir un camino hasta encontrar un puesto base.
	// Actualización de variables de estado
	SituarSensorEnMapaR(mapaResultado,mapaCotas,sensores);
	if (sensores.superficie[0] == 'D') tiene_zapatillas = true;


	// Definición del comportamiento
	if (sensores.superficie[0] == 'X') {		//LLegué al objetivo
		accion = IDLE;
	}
	else if (giro45Izq!=0) {					//Estoy haciendo un TURN_SL
		accion = TURN_SR;
		giro45Izq--;
	}
	else {
		char i = ViablePorAlturaR(sensores.superficie[1], sensores.cota[1] - sensores.cota[0], tiene_zapatillas);
		char c = ViablePorAlturaR(sensores.superficie[2], sensores.cota[2] - sensores.cota[0], tiene_zapatillas);
		char d = ViablePorAlturaR(sensores.superficie[3], sensores.cota[3] - sensores.cota[0], tiene_zapatillas);
		
		int pos = VeoCasillaInteresanteR(i, c, d, tiene_zapatillas, sensores);
		switch (pos)
		{
		case 2:
			accion = WALK;
			break;
		case 1:
			giro45Izq = 1;
			accion = TURN_L;
			break;
		case 3:
			accion = TURN_SR;
			break;
		case 0:
			accion = TURN_L;
			break;
		}
	}
	
	// Devolver la siguiente acción a hacer
	last_action = accion;
	return accion;
}

Action ComportamientoRescatador::ComportamientoRescatadorNivel_1(Sensores sensores)
{
	Action accion;
	// El comportamiento de seguir un camino hasta encontrar un puesto base.
	// Actualización de variables de estado
	SituarSensorEnMapaR(mapaResultado,mapaCotas,sensores);
	if (sensores.superficie[0] == 'D') tiene_zapatillas = true;


	// Definición del comportamiento
	if (sensores.superficie[0] == 'X') {		//LLegué al objetivo
		accion = IDLE;
	}
	else if (giro45Izq!=0) {					//Estoy haciendo un TURN_SL
		accion = TURN_SR;
		giro45Izq--;
	}
	else {
		char i = ViablePorAlturaR(sensores.superficie[1], sensores.cota[1] - sensores.cota[0], tiene_zapatillas);
		char c = ViablePorAlturaR(sensores.superficie[2], sensores.cota[2] - sensores.cota[0], tiene_zapatillas);
		char d = ViablePorAlturaR(sensores.superficie[3], sensores.cota[3] - sensores.cota[0], tiene_zapatillas);
		
		int pos = VeoCasillaInteresanteR(i, c, d, tiene_zapatillas, sensores);
		switch (pos)
		{
		case 2:
			accion = WALK;
			break;
		case 1:
			giro45Izq = 1;
			accion = TURN_L;
			break;
		case 3:
			accion = TURN_SR;
			break;
		case 0:
			accion = TURN_L;
			break;
		}
	}
	
	// Devolver la siguiente acción a hacer
	last_action = accion;
	return accion;
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