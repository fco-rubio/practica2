#include "../Comportamientos_Jugador/auxiliar.hpp"
#include <iostream>
#include "motorlib/util.h"

Action ComportamientoAuxiliar::think(Sensores sensores)
{
	Action accion = IDLE;

	switch (sensores.nivel)
	{
	case 0:
		accion = ComportamientoAuxiliarNivel_0 (sensores);
		break;
	case 1:
		accion = ComportamientoAuxiliarNivel_1 (sensores);
		break;
	case 2:
		// accion = ComportamientoAuxiliarNivel_2 (sensores);
		break;
	case 3:
		// accion = ComportamientoAuxiliarNivel_3 (sensores);
		break;
	case 4:
		// accion = ComportamientoAuxiliarNivel_4 (sensores);
		break;
	}

	return accion;
}

int ComportamientoAuxiliar::interact(Action accion, int valor)
{
	return 0;
}

int ComportamientoAuxiliar::VeoCasillaInteresante (char i, char c, char d, bool zap, Sensores sensores) {
	if (c == 'X' && sensores.agentes[2]=='_') return 2;
	else if (i == 'X'  && sensores.agentes[1]=='_') return 1;
	else if (d == 'X'  && sensores.agentes[3]=='_') return 3;
	else if (!zap) {
		if (c == 'D' && sensores.agentes[2]=='_') return 2;
		else if (i == 'D' && sensores.agentes[1]=='_' ) return 1;
		else if (d == 'D'  && sensores.agentes[3]=='_') return 3;
		
	}
	switch(sensores.rumbo) {
		case norte:
			if (c == 'C' && sensores.agentes[2]=='_' && sensores.agentes[3]=='_' && !casillasVisitadas[sensores.posF-1][sensores.posC]) return 2;
			else if (i == 'C' && sensores.agentes[1]=='_' && !casillasVisitadas[sensores.posF-1][sensores.posC-1]) return 1;
			else if (d == 'C' && sensores.agentes[3]=='_' && !casillasVisitadas[sensores.posF-1][sensores.posC+1]) return 3;
			else if (c == 'D' && sensores.agentes[2]=='_' && !casillasVisitadas[sensores.posF-1][sensores.posC]) return 2;
			else if (i == 'D' && sensores.agentes[1]=='_' && !casillasVisitadas[sensores.posF-1][sensores.posC-1]) return 1;
			else if (d == 'D'  && sensores.agentes[3]=='_' && !casillasVisitadas[sensores.posF-1][sensores.posC+1]) return 3;
			break;
		case sur:
			if (c == 'C' && sensores.agentes[2]=='_' && sensores.agentes[3]=='_' && !casillasVisitadas[sensores.posF+1][sensores.posC]) return 2;
			else if (i == 'C' && sensores.agentes[1]=='_' && !casillasVisitadas[sensores.posF+1][sensores.posC+1]) return 1;
			else if (d == 'C' && sensores.agentes[3]=='_' && !casillasVisitadas[sensores.posF+1][sensores.posC-1]) return 3;
			else if (c == 'D' && sensores.agentes[2]=='_' && !casillasVisitadas[sensores.posF+1][sensores.posC]) return 2;
			else if (i == 'D' && sensores.agentes[1]=='_' && !casillasVisitadas[sensores.posF+1][sensores.posC+1]) return 1;
			else if (d == 'D'  && sensores.agentes[3]=='_' && !casillasVisitadas[sensores.posF+1][sensores.posC-1]) return 3;
			break;
		case este:
			if (c == 'C' && sensores.agentes[2]=='_' && sensores.agentes[3]=='_' && !casillasVisitadas[sensores.posF][sensores.posC+1]) return 2;
			else if (i == 'C' && sensores.agentes[1]=='_' && !casillasVisitadas[sensores.posF-1][sensores.posC+1]) return 1;
			else if (d == 'C' && sensores.agentes[3]=='_' && !casillasVisitadas[sensores.posF+1][sensores.posC+1]) return 3;
			else if (c == 'D' && sensores.agentes[2]=='_' && !casillasVisitadas[sensores.posF][sensores.posC+1]) return 2;
			else if (i == 'D' && sensores.agentes[1]=='_' && !casillasVisitadas[sensores.posF-1][sensores.posC+1]) return 1;
			else if (d == 'D'  && sensores.agentes[3]=='_' && !casillasVisitadas[sensores.posF+1][sensores.posC+1]) return 3;
			break;
		case oeste:
			if (c == 'C' && sensores.agentes[2]=='_' && sensores.agentes[3]=='_' && !casillasVisitadas[sensores.posF][sensores.posC-1]) return 2;
			else if (i == 'C' && sensores.agentes[1]=='_' && !casillasVisitadas[sensores.posF+1][sensores.posC-1]) return 1;
			else if (d == 'C' && sensores.agentes[3]=='_' && !casillasVisitadas[sensores.posF-1][sensores.posC-1]) return 3;
			else if (c == 'D' && sensores.agentes[2]=='_' && !casillasVisitadas[sensores.posF][sensores.posC-1]) return 2;
			else if (i == 'D' && sensores.agentes[1]=='_' && !casillasVisitadas[sensores.posF+1][sensores.posC-1]) return 1;
			else if (d == 'D'  && sensores.agentes[3]=='_' && !casillasVisitadas[sensores.posF-1][sensores.posC-1]) return 3;
			break;
		case noreste:
			if (c == 'C' && sensores.agentes[2]=='_' && sensores.agentes[3]=='_' && !casillasVisitadas[sensores.posF-1][sensores.posC+1]) return 2;
			else if (i == 'C' && sensores.agentes[1]=='_' && !casillasVisitadas[sensores.posF-1][sensores.posC]) return 1;
			else if (d == 'C' && sensores.agentes[3]=='_' && !casillasVisitadas[sensores.posF][sensores.posC+1]) return 3;
			else if (c == 'D' && sensores.agentes[2]=='_' && !casillasVisitadas[sensores.posF-1][sensores.posC+1]) return 2;
			else if (i == 'D' && sensores.agentes[1]=='_' && !casillasVisitadas[sensores.posF-1][sensores.posC]) return 1;
			else if (d == 'D'  && sensores.agentes[3]=='_' && !casillasVisitadas[sensores.posF][sensores.posC+1]) return 3;
			break;
		case noroeste:
			if (c == 'C' && sensores.agentes[2]=='_' && sensores.agentes[5]=='_' && sensores.agentes[3]=='_' && !casillasVisitadas[sensores.posF-1][sensores.posC-1]) return 2;
			else if (i == 'C' && sensores.agentes[1]=='_' && !casillasVisitadas[sensores.posF][sensores.posC-1]) return 1;
			else if (d == 'C' && sensores.agentes[3]=='_' && !casillasVisitadas[sensores.posF-1][sensores.posC]) return 3;
			else if (c == 'D' && sensores.agentes[2]=='_' && !casillasVisitadas[sensores.posF-1][sensores.posC-1]) return 2;
			else if (i == 'D' && sensores.agentes[1]=='_' && !casillasVisitadas[sensores.posF][sensores.posC-1]) return 1;
			else if (d == 'D'  && sensores.agentes[3]=='_' && !casillasVisitadas[sensores.posF-1][sensores.posC]) return 3;
			break;
		case sureste:
			if (c == 'C' && sensores.agentes[2]=='_' && sensores.agentes[3]=='_' && !casillasVisitadas[sensores.posF+1][sensores.posC+1]) return 2;
			else if (i == 'C' && sensores.agentes[1]=='_' && !casillasVisitadas[sensores.posF][sensores.posC+1]) return 1;
			else if (d == 'C' && sensores.agentes[3]=='_' && !casillasVisitadas[sensores.posF+1][sensores.posC]) return 3;
			else if (c == 'D' && sensores.agentes[2]=='_' && !casillasVisitadas[sensores.posF+1][sensores.posC+1]) return 2;
			else if (i == 'D' && sensores.agentes[1]=='_' && !casillasVisitadas[sensores.posF][sensores.posC+1]) return 1;
			else if (d == 'D'  && sensores.agentes[3]=='_' && !casillasVisitadas[sensores.posF+1][sensores.posC]) return 3;
			break;
		case suroeste:
			if (c == 'C' && sensores.agentes[2]=='_' && sensores.agentes[3]=='_' && !casillasVisitadas[sensores.posF+1][sensores.posC-1]) return 2;
			else if (i == 'C' && sensores.agentes[1]=='_' && !casillasVisitadas[sensores.posF+1][sensores.posC]) return 1;
			else if (d == 'C' && sensores.agentes[3]=='_' && !casillasVisitadas[sensores.posF][sensores.posC-1]) return 3;
			else if (c == 'D' && sensores.agentes[2]=='_' && !casillasVisitadas[sensores.posF+1][sensores.posC-1]) return 2;
			else if (i == 'D' && sensores.agentes[1]=='_' && !casillasVisitadas[sensores.posF+1][sensores.posC]) return 1;
			else if (d == 'D'  && sensores.agentes[3]=='_' && !casillasVisitadas[sensores.posF][sensores.posC-1]) return 3;
			break;
	}
	if (c == 'C' && sensores.agentes[2]=='_' && sensores.agentes[3]=='_' && sensores.agentes[5]=='_') return 2;
	else if (i == 'C' && sensores.agentes[1]=='_') return 1;
	else if (d == 'C' && sensores.agentes[3]=='_') return 3;
	else if (c == 'D' && sensores.agentes[2]=='_') return 2;
	else if (i == 'D' && sensores.agentes[1]=='_' ) return 1;
	else if (d == 'D'  && sensores.agentes[3]=='_') return 3;
	else return 0;
	
}


char ViablePorAlturaA(char casilla, int dif) {
	if (abs(dif)<=1)
		return casilla;
	else
		return 'P';
}
void SituarSensorEnMapaA(vector<vector<unsigned char>> &m, vector<vector<unsigned char>> &a, Sensores sensores) {
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

void ComportamientoAuxiliar::rellenaMatrizCasillasVisitadas(Sensores sensores) {
	casillasVisitadas[sensores.posF][sensores.posC] = 1;
}

Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_0(Sensores sensores)
{
	Action accion;
	SituarSensorEnMapaA(mapaResultado,mapaCotas,sensores);
	rellenaMatrizCasillasVisitadas(sensores);
	if (sensores.superficie[0] == 'D') tiene_zapatillas = true;
	if (sensores.superficie[0] == 'X') {		//LLegué al objetivo
		accion = IDLE;
	}
	else if (giro45Izq!=0) {					//Estoy haciendo un TURN_SL
		giro45Izq--;
		accion = TURN_SR;
	}
	else {
		char i = ViablePorAlturaA(sensores.superficie[1], sensores.cota[1] - sensores.cota[0]);
		char c = ViablePorAlturaA(sensores.superficie[2], sensores.cota[2] - sensores.cota[0]);
		char d = ViablePorAlturaA(sensores.superficie[3], sensores.cota[3] - sensores.cota[0]);
		int pos = VeoCasillaInteresante(i, c, d, tiene_zapatillas, sensores);
		switch (pos)
		{
		case 2:
			accion = WALK;
			break;
		
		case 1:
			giro45Izq = 6;
			accion = TURN_SR;
			break;
		case 3:
			accion = TURN_SR;
			break;
		
		case 0:
			accion = TURN_SR;
			break;
		}
		
	}
	last_action = accion;
	return accion;
}

Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_1(Sensores sensores)
{
	Action accion;
	SituarSensorEnMapaA(mapaResultado,mapaCotas,sensores);
	rellenaMatrizCasillasVisitadas(sensores);
	if (sensores.superficie[0] == 'D') tiene_zapatillas = true;
	if (sensores.superficie[0] == 'X') {		//LLegué al objetivo
		accion = IDLE;
	}
	else if (giro45Izq!=0) {					//Estoy haciendo un TURN_SL
		giro45Izq--;
		accion = TURN_SR;
	}
	else {
		char i = ViablePorAlturaA(sensores.superficie[1], sensores.cota[1] - sensores.cota[0]);
		char c = ViablePorAlturaA(sensores.superficie[2], sensores.cota[2] - sensores.cota[0]);
		char d = ViablePorAlturaA(sensores.superficie[3], sensores.cota[3] - sensores.cota[0]);
		int pos = VeoCasillaInteresante(i, c, d, tiene_zapatillas, sensores);
		switch (pos)
		{
		case 2:
			accion = WALK;
			break;
		
		case 1:
			giro45Izq = 6;
			accion = TURN_SR;
			break;
		case 3:
			accion = TURN_SR;
			break;
		
		case 0:
			accion = TURN_SR;
			break;
		}
		
	}
	last_action = accion;
	return accion;
}


Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_2(Sensores sensores)
{
}

Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_3(Sensores sensores)
{
}

Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_4(Sensores sensores)
{
}