#include <iostream>
#include <conio.h>
#include "rlutil.h"
using namespace std;
using namespace System;


int turno;
bool comenzo = false;
string NameJ1, NameJ2;
char ficha, fichaJ1, fichaJ2;
int ColorJ1 = 1;
int ColorJ2 = 4;
int contadorficha1 = 9;
int contadorficha2 = 9;
int restantesFicha1 = 9;
int restantesFicha2 = 9;
bool banderas[20] = { false ,false ,false ,false ,false ,false ,false ,false,false,false,false,false,false ,false ,false ,false ,false ,false ,false ,false };
bool banderas2[20] = { false ,false ,false ,false ,false ,false ,false ,false,false,false,false,false,false ,false ,false ,false ,false ,false ,false ,false };
char Board[24] = { char(207),char(207),char(207),char(207),char(207),char(207),char(207),char(207),char(207),char(207),
					char(207),char(207),char(207),char(207),char(207),char(207),char(207),char(207),char(207),char(207),
					char(207),char(207),char(207) };

char Tablero[16][16] = {
		{' ',' ','1',' ','2',' ','3',' ','4',' ','5',' ','6',' ','7',' '},
		{' ','A','A','A','A','A','A','A','A','A','A','A','A','A','A','A'},
		{'1','A','a','B','B','B','B','B','b','B','B','B','B','B','c','A'},
		{' ','A','C','A','A','A','A','A','C','A','A','A','A','A','C','A'},
		{'2','A','C','A','d','B','B','B','e','B','B','B','f','A','C','A'},
		{' ','A','C','A','C','A','A','A','C','A','A','A','C','A','C','A'},
		{'3','A','C','A','C','A','g','B','h','B','i','A','C','A','C','A'},
		{' ','A','C','A','C','A','C','A','A','A','C','A','C','A','C','A'},
		{'4','A','j','B','k','B','l','A','A','A','m','B','n','B','o','A'},
		{' ','A','C','A','C','A','C','A','A','A','C','A','C','A','C','A'},
		{'5','A','C','A','C','A','p','B','q','B','r','A','C','A','C','A'},
		{' ','A','C','A','C','A','A','A','C','A','A','A','C','A','C','A'},
		{'6','A','C','A','s','B','B','B','t','B','B','B','u','A','C','A'},
		{' ','A','C','A','A','A','A','A','C','A','A','A','A','A','C','A'},
		{'7','A','v','B','B','B','B','B','w','B','B','B','B','B','x','A'},
		{' ','A','A','A','A','A','A','A','A','A','A','A','A','A','A','A'},
};

enum Opciones {
	Menu_Opcion1 = 0,
	Menu_Opcion2 = 1,
	Menu_Opcion3 = 2,
	Menu_Salir = 3
};

int Dado6[20][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,1,1,0,0,1,1,0,0},
	{0,0,1,1,0,0,1,1,0,0},
	{0,0,1,1,0,0,1,1,0,0},
	{0,0,1,1,0,0,1,1,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,1,1,0,0,1,1,0,0},
	{0,0,1,1,0,0,1,1,0,0},
	{0,0,1,1,0,0,1,1,0,0},
	{0,0,1,1,0,0,1,1,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,1,1,0,0,1,1,0,0},
	{0,0,1,1,0,0,1,1,0,0},
	{0,0,1,1,0,0,1,1,0,0},
	{0,0,1,1,0,0,1,1,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
};
int Dado5[20][10] = {
  {0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0},
  {0,0,1,1,0,0,1,1,0,0},
  {0,0,1,1,0,0,1,1,0,0},
  {0,0,1,1,0,0,1,1,0,0},
  {0,0,1,1,0,0,1,1,0,0},
  {0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,1,1,0,0,0,0},
  {0,0,0,0,1,1,0,0,0,0},
  {0,0,0,0,1,1,0,0,0,0},
  {0,0,0,0,1,1,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0},
  {0,0,1,1,0,0,1,1,0,0},
  {0,0,1,1,0,0,1,1,0,0},
  {0,0,1,1,0,0,1,1,0,0},
  {0,0,1,1,0,0,1,1,0,0},
  {0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0}
};
int Dado4[20][10] = {
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,1,1,0,0,1,1,0,0},
 {0,0,1,1,0,0,1,1,0,0},
 {0,0,1,1,0,0,1,1,0,0},
 {0,0,1,1,0,0,1,1,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,1,1,0,0,1,1,0,0},
 {0,0,1,1,0,0,1,1,0,0},
 {0,0,1,1,0,0,1,1,0,0},
 {0,0,1,1,0,0,1,1,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}
};
int Dado3[20][10] = {
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}
};
int Dado2[20][10] = {
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}
};
int Dado1[20][10] = {
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}
};

int Throw_Dado() {
	int posy = 5;
	int posy2 = 5;
	int turno;
	srand(time(NULL));
	rlutil::cls();
	cout << NameJ1 << ", PRESIONE ENTER PARA LANZAR DADO...";
	rlutil::anykey();
	int random1 = rand() % 6 + 1;
	switch (random1)
	{
	case 1: {
		for (int i = 0; i < 20; i++) {
			rlutil::locate(10, posy);
			for (int j = 0; j < 10; j++) {
				if (Dado1[i][j] == 0) {
					rlutil::setColor(rlutil::COLOR::WHITE);
					cout << char(219);
				}
				else {
					rlutil::setColor(rlutil::COLOR::BLACK);
					cout << char(219);
				}
			}
			posy++;
		}
		break;
	}
	case 2: {
		for (int i = 0; i < 20; i++) {
			rlutil::locate(10, posy);
			for (int j = 0; j < 10; j++) {
				if (Dado2[i][j] == 0) {
					rlutil::setColor(rlutil::COLOR::WHITE);
					cout << char(219);
				}
				else {
					rlutil::setColor(rlutil::COLOR::BLACK);
					cout << char(219);
				}
			}
			posy++;
		}
		break;
	}
	case 3: {
		for (int i = 0; i < 20; i++) {
			rlutil::locate(10, posy);
			for (int j = 0; j < 10; j++) {
				if (Dado3[i][j] == 0) {
					rlutil::setColor(rlutil::COLOR::WHITE);
					cout << char(219);
				}
				else {
					rlutil::setColor(rlutil::COLOR::BLACK);
					cout << char(219);
				}
			}
			posy++;
		}
		break;
	}
	case 4: {
		for (int i = 0; i < 20; i++) {
			rlutil::locate(10, posy);
			for (int j = 0; j < 10; j++) {
				if (Dado4[i][j] == 0) {
					rlutil::setColor(rlutil::COLOR::WHITE);
					cout << char(219);
				}
				else {
					rlutil::setColor(rlutil::COLOR::BLACK);
					cout << char(219);
				}
			}
			posy++;
		}
		break;
	}
	case 5: {
		for (int i = 0; i < 20; i++) {
			rlutil::locate(10, posy);
			for (int j = 0; j < 10; j++) {
				if (Dado5[i][j] == 0) {
					rlutil::setColor(rlutil::COLOR::WHITE);
					cout << char(219);
				}
				else {
					rlutil::setColor(rlutil::COLOR::BLACK);
					cout << char(219);
				}
			}
			posy++;
		}
		break;
	}
	case 6: {
		for (int i = 0; i < 20; i++) {
			rlutil::locate(10, posy);
			for (int j = 0; j < 10; j++) {
				if (Dado6[i][j] == 0) {
					rlutil::setColor(rlutil::COLOR::WHITE);
					cout << char(219);
				}
				else {
					rlutil::setColor(rlutil::COLOR::BLACK);
					cout << char(219);
				}
			}
			posy++;
		}
		break;
	}
	default:
		break;
	}
	Sleep(500);
	rlutil::locate(74, 1);
	cout << NameJ2 << ", PRESIONE ENTER PARA LANZAR DADO...";
	rlutil::anykey();
	int random2 = rand() % 6 + 1;
	switch (random2)
	{
	case 1: {
		for (int i = 0; i < 20; i++) {
			rlutil::locate(84, posy2);
			for (int j = 0; j < 10; j++) {
				if (Dado1[i][j] == 0) {
					rlutil::setColor(rlutil::COLOR::WHITE);
					cout << char(219);
				}
				else {
					rlutil::setColor(rlutil::COLOR::BLACK);
					cout << char(219);
				}
			}
			posy2++;
		}
		break;
	}
	case 2: {
		for (int i = 0; i < 20; i++) {
			rlutil::locate(84, posy2);
			for (int j = 0; j < 10; j++) {
				if (Dado2[i][j] == 0) {
					rlutil::setColor(rlutil::COLOR::WHITE);
					cout << char(219);
				}
				else {
					rlutil::setColor(rlutil::COLOR::BLACK);
					cout << char(219);
				}
			}
			posy2++;
		}
		break;
	}
	case 3: {
		for (int i = 0; i < 20; i++) {
			rlutil::locate(84, posy2);
			for (int j = 0; j < 10; j++) {
				if (Dado3[i][j] == 0) {
					rlutil::setColor(rlutil::COLOR::WHITE);
					cout << char(219);
				}
				else {
					rlutil::setColor(rlutil::COLOR::BLACK);
					cout << char(219);
				}
			}
			posy2++;
		}
		break;
	}
	case 4: {
		for (int i = 0; i < 20; i++) {
			rlutil::locate(84, posy2);
			for (int j = 0; j < 10; j++) {
				if (Dado4[i][j] == 0) {
					rlutil::setColor(rlutil::COLOR::WHITE);
					cout << char(219);
				}
				else {
					rlutil::setColor(rlutil::COLOR::BLACK);
					cout << char(219);
				}
			}
			posy2++;
		}
		break;
	}
	case 5: {
		for (int i = 0; i < 20; i++) {
			rlutil::locate(84, posy2);
			for (int j = 0; j < 10; j++) {
				if (Dado5[i][j] == 0) {
					rlutil::setColor(rlutil::COLOR::WHITE);
					cout << char(219);
				}
				else {
					rlutil::setColor(rlutil::COLOR::BLACK);
					cout << char(219);
				}
			}
			posy2++;
		}
		break;
	}
	case 6: {
		for (int i = 0; i < 20; i++) {
			rlutil::locate(84, posy2);
			for (int j = 0; j < 10; j++) {
				if (Dado6[i][j] == 0) {
					rlutil::setColor(rlutil::COLOR::WHITE);
					cout << char(219);
				}
				else {
					rlutil::setColor(rlutil::COLOR::BLACK);
					cout << char(219);
				}
			}
			posy2++;
		}
		break;
	}
	default:
		break;
	}
	if (random1 > random2) {
		rlutil::locate(54, 25);
		cout << NameJ1 << " COMIENZA PRIMERO...";
		turno = 1;
	}
	else {
		rlutil::locate(54, 25);
		cout << NameJ2 << " COMIENZA PRIMERO...";
		turno = 2;
	}

	rlutil::locate(54, 30);
	cout << "Presione Enter para comenzar...";
	rlutil::anykey();
	return turno;
}
void Logo_UPC() {
	Console::ForegroundColor = ConsoleColor::Red;
	rlutil::locate(5, 5);
	cout << "           **           " << endl;
	rlutil::locate(5, 6);
	cout << "    *    **        *    " << endl;
	rlutil::locate(5, 7);
	cout << "  **      ***       **  " << endl;
	rlutil::locate(5, 8);
	cout << " **        ***       ** " << endl;
	rlutil::locate(5, 9);
	cout << " **         ***      ** " << endl;
	rlutil::locate(5, 10);
	cout << " **        ***       ** " << endl;
	rlutil::locate(5, 11);
	cout << " **        **        ** " << endl;
	rlutil::locate(5, 12);
	cout << "  ***     ***      ***  " << endl;
	rlutil::locate(5, 13);
	cout << "    ***    **    ***    " << endl;
	rlutil::locate(5, 14);
	cout << "       **********      " << endl;
	Console::ForegroundColor = ConsoleColor::White;
}
void Show_Background(const char* text, int posx, int posy, bool selected) {
	if (selected) {
		rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
	}
	else {
		rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
	}
	rlutil::locate(posx, posy);
	cout << text << endl;
	rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
}
int Menu() {
	int opcion = 1;
	int y = 0;
	rlutil::cls();
	Logo_UPC();
	do {
		rlutil::setBackgroundColor(rlutil::COLOR::GREEN);
		rlutil::setColor(rlutil::COLOR::WHITE);
		rlutil::locate(40, 10);
		cout << "::::BIENVENIDO AL JUEGO DEL MOLINO::::" << endl << endl;
		rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
		Console::CursorVisible = FALSE;
		Show_Background("    JUGAR    ", 52, 15, y == Menu_Opcion1);
		Show_Background(" COMO JUGAR  ", 52, 16, y == Menu_Opcion2);
		Show_Background("  CREDITOS   ", 52, 17, y == Menu_Opcion3);
		Show_Background("    SALIR    ", 52, 18, y == Menu_Salir);
		rlutil::locate(50, 15 + y);
		cout << char(175) << endl;
		int key = rlutil::getkey();
		switch (key)
		{
		case 14: { //UP
			rlutil::locate(50, 15 + y);
			cout << " " << endl;
			y--;
			if (y < 0) y = 0;
			break;
		}
		case 15: { //DOWN
			rlutil::locate(50, 15 + y);
			cout << " " << endl;
			y++;
			if (y > 3) y = 3;
			break;
		}
		case 1: {
			if (y == Menu_Opcion1) return 1; opcion = 0;
			if (y == Menu_Opcion2) return 2; opcion = 0;
			if (y == Menu_Opcion3) return 3; opcion = 0;
			if (y == Menu_Salir) return 4; opcion = 0;
			break;
		}
		default:
			break;
		}
	} while (opcion != 0);
}
void Opcion_Como_Jugar() {
	rlutil::cls();
	Logo_UPC();
	Console::ForegroundColor = ConsoleColor::DarkMagenta;
	rlutil::locate(40, 7);
	cout << "------------INSTRUCCIONES--------------";
	rlutil::locate(40, 8);
	cout << "|1) Cada jugador contara con 9 fichas.|";
	rlutil::locate(40, 9);
	cout << "|                                     |";
	rlutil::locate(40, 10);
	cout << "|2) Colocaran sus fichas uno por uno  |";
	rlutil::locate(40, 11);
	cout << "|   dentro del tablero.               |";
	rlutil::locate(40, 12);
	cout << "|                                     |";
	rlutil::locate(40, 13);
	cout << "|3) Posteriormente cada jugador podra |";
	rlutil::locate(40, 14);
	cout << "|   mover sus fichas siguiendo las    |";
	rlutil::locate(40, 15);
	cout << "|   lineas.                           |";
	rlutil::locate(40, 16);
	cout << "|                                     |";
	rlutil::locate(40, 17);
	cout << "|3) El jugador que logre formar una   |";
	rlutil::locate(40, 18);
	cout << "|   linea de tres, podra quitar una   |";
	rlutil::locate(40, 19);
	cout << "|   ficha del rival.                  |";
	rlutil::locate(40, 20);
	cout << "|                                     |";
	rlutil::locate(40, 21);
	cout << "|4) Ganara quien logre dejar al rival |";
	rlutil::locate(40, 22);
	cout << "|   con dos fichas o sin posibilidad  |";
	rlutil::locate(40, 23);
	cout << "|   de moverse.                       |";
	rlutil::locate(40, 24);
	cout << "---------------------------------------";
	rlutil::locate(40, 25);
	cout << "Presione enter para volver al menu.";
	rlutil::anykey();
	rlutil::cls();
}
void Opcion_Creditos() {
	rlutil::cls();
	Logo_UPC();
	Console::BackgroundColor = ConsoleColor::Yellow;
	Console::ForegroundColor = ConsoleColor::Black;
	rlutil::locate(42, 10);
	cout << "JUEGO DEL MOLINO/9 CABALLEROS NORRIS";
	rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
	rlutil::setColor(rlutil::COLOR::WHITE);
	rlutil::locate(40, 13);
	cout << "CREADOR: JOSEPH ALEXIS HUAMANI MANDUJANO";
	rlutil::locate(40, 15);
	cout << "CODIGO: U20221A133";
	rlutil::locate(40, 17);
	cout << "NICKNAME: Nerk";
	rlutil::locate(40, 19);
	cout << "ENTER PARA VOLVER AL MENU.....";
	rlutil::anykey();
	rlutil::cls();
}
void Start_Game() {
	Console::CursorVisible = TRUE;
	Console::ForegroundColor = ConsoleColor::Blue;
	system("cls");
	cout << "Ingrese nombre del jugador 1: "; cin >> NameJ1;
	cout << "Ingrese nombre del jugador 2: "; cin >> NameJ2;
	cout << "\n";
	do {
		cout << NameJ1 + ", seleccione una ficha X/O: "; cin >> ficha;
		if (toupper(ficha) == 'X') {
			fichaJ1 = 'X';
			fichaJ2 = 'O';
		}
		else {
			fichaJ1 = 'O';
			fichaJ2 = 'X';
		}
	} while (ficha != 'X' && ficha != 'O');

	cout << "\nLa ficha de " << NameJ1 << " es: " << fichaJ1;
	cout << "\nLa ficha de " << NameJ2 << " es: " << fichaJ2;
	cout << "\n\nPresione ENTER para continuar...";
	Console::ForegroundColor = ConsoleColor::White;
	rlutil::anykey();
}
void Print_Board() {
	cout << Board[0] << "****************************";
}
void Dibujar_Tablero() {
	rlutil::cls();
	int i, j;
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 15; j++)
		{
			Console::SetCursorPosition(j, i);
			if (Tablero[i][j] == 'a')
			{
				Console::ForegroundColor = ConsoleColor::White;
				cout << 'a';
			}

			else if (Tablero[i][j] == 'b') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << 'b';
			}

			else if (Tablero[i][j] == 'c') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << 'c';
			}

			else if (Tablero[i][j] == 'd') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << 'd';
			}

			else if (Tablero[i][j] == 'e') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << 'e';
			}

			else if (Tablero[i][j] == 'f') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << 'f';
			}

			else if (Tablero[i][j] == 'g') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << 'g';
			}

			else if (Tablero[i][j] == 'h') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << 'h';
			}

			else if (Tablero[i][j] == 'i') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << 'i';
			}

			else if (Tablero[i][j] == 'j') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << 'j';
			}

			else if (Tablero[i][j] == 'k') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << 'k';
			}

			else if (Tablero[i][j] == 'l') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << 'l';
			}

			else if (Tablero[i][j] == 'm') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << 'm';
			}

			else if (Tablero[i][j] == 'n') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << 'n';
			}

			else if (Tablero[i][j] == 'o') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << 'o';
			}

			else if (Tablero[i][j] == 'p') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << 'p';
			}

			else if (Tablero[i][j] == 'q') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << 'q';
			}

			else if (Tablero[i][j] == 'r') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << 'r';
			}

			else if (Tablero[i][j] == 's') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << 's';
			}

			else if (Tablero[i][j] == 't') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << 't';
			}

			else if (Tablero[i][j] == 'u') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << 'u';
			}

			else if (Tablero[i][j] == 'v') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << 'v';
			}

			else if (Tablero[i][j] == 'w') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << 'w';
			}

			else if (Tablero[i][j] == 'x') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << 'x';
			}

			else if (Tablero[i][j] == 'A') {
				//Console::ForegroundColor = ConsoleColor::DarkCyan;
				cout << ' ';
			}
			else if (Tablero[i][j] == 'B') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << char(205);
			}
			else if (Tablero[i][j] == 'C') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << char(186);
			}
			else if (Tablero[i][j] == '1') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << '1';
			}
			else if (Tablero[i][j] == '2') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << '2';
			}
			else if (Tablero[i][j] == '3') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << '3';
			}
			else if (Tablero[i][j] == '4') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << '4';
			}
			else if (Tablero[i][j] == '5') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << '5';
			}
			else if (Tablero[i][j] == '6') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << '6';
			}
			else if (Tablero[i][j] == '7') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << '7';
			}
			else if (Tablero[i][j] == ' ') {
				Console::ForegroundColor = ConsoleColor::White;
				cout << ' ';
			}

			else if (Tablero[i][j] == fichaJ1) {
				Console::ForegroundColor = ConsoleColor(ColorJ1);
				cout << fichaJ1;
			}

			else if (Tablero[i][j] == fichaJ2) {
				Console::ForegroundColor = ConsoleColor(ColorJ2);
				cout << fichaJ2;
			}
		}
		cout << endl;
	}
}
void Nombre_Ficha_Tablero()
{
	Console::BackgroundColor = ConsoleColor::Black;
	Console::ForegroundColor = ConsoleColor::White;
	Console::SetCursorPosition(17, 0); cout << "Jugador 1: " << NameJ1;

	if (fichaJ1 == 'X') {
		Console::ForegroundColor = ConsoleColor(ColorJ1);
		Console::SetCursorPosition(17, 1);
		cout << "Ficha: X";
		Console::SetCursorPosition(17, 2);
		cout << "Cant.Fichas: " << contadorficha1;
	}
	else {
		Console::ForegroundColor = ConsoleColor(ColorJ1);
		Console::SetCursorPosition(17, 1);
		cout << "Ficha: O";
		Console::SetCursorPosition(17, 2);
		cout << "Cant.Fichas: " << contadorficha1;
	}

	Console::ForegroundColor = ConsoleColor::White;
	Console::SetCursorPosition(39, 0); cout << "Jugador 2: " << NameJ2;

	if (fichaJ2 == 'X') {
		Console::ForegroundColor = ConsoleColor(ColorJ2);
		Console::SetCursorPosition(39, 1);
		cout << "Ficha: X";
		Console::SetCursorPosition(39, 2);
		cout << "Cant.Fichas: " << contadorficha2;
	}
	else {
		Console::ForegroundColor = ConsoleColor(ColorJ2);
		Console::SetCursorPosition(39, 1); cout << "Ficha: O";
		Console::SetCursorPosition(39, 2);
		cout << "Cant.Fichas: " << contadorficha2;
	}

}
void Colocar_Ficha() {
	int columna, fila;
	int posX=0, posY=0;
	bool fuera;
	Console::CursorVisible = TRUE;
	if (turno == 1)
	{	
		do {
			fuera = false;
			system("cls");
			Dibujar_Tablero();
			Nombre_Ficha_Tablero();
			if (Tablero[posY][posX] == fichaJ2 || Tablero[posY][posX] == fichaJ1) {
				Console::SetCursorPosition(0, 16);
				Console::ForegroundColor = ConsoleColor::White;
				cout << "Esta ocupado elija otra posicion";
			}
			Console::SetCursorPosition(0, 17);
			Console::ForegroundColor = ConsoleColor::White;
			do {
				cout << NameJ1 << ", Ingrese el numero de columna: ";
				cin >> columna;
			} while (columna < 0 || columna>7);

			do {
				cout << NameJ1 << ", Ingrese el numero de fila: ";
				cin >> fila;
			} while (fila < 0 || fila>7);

			if (columna == 1 && fila == 1) { posX = 2, posY = 2; } //first part
			else if (columna == 4 && fila == 1) { posX = 8, posY = 2; } //
			else if (columna == 7 && fila == 1) { posX = 14, posY = 2; } //
			else if (columna == 2 && fila == 2) { posX = 4, posY = 4; } //
			else if (columna == 4 && fila == 2) { posX = 8, posY = 4; } //
			else if (columna == 6 && fila == 2) { posX = 12, posY = 4; } //
			else if (columna == 3 && fila == 3) { posX = 6, posY = 6; } //
			else if (columna == 4 && fila == 3) { posX = 8, posY = 6; } //
			else if (columna == 5 && fila == 3) { posX = 10, posY = 6; } //
			else if (columna == 1 && fila == 4) { posX = 2, posY = 8; }//second part
			else if (columna == 2 && fila == 4) { posX = 4, posY = 8; }//
			else if (columna == 3 && fila == 4) { posX = 6, posY = 8; }//
			else if (columna == 5 && fila == 4) { posX = 10, posY = 8; }//
			else if (columna == 6 && fila == 4) { posX = 12, posY = 8; }//
			else if (columna == 7 && fila == 4) { posX = 14, posY = 8; }//
			else if (columna == 3 && fila == 5) { posX = 6, posY = 10; }//third part
			else if (columna == 4 && fila == 5) { posX = 8, posY = 10; }//
			else if (columna == 5 && fila == 5) { posX = 10, posY = 10; }//
			else if (columna == 2 && fila == 6) { posX = 4, posY = 12; }//fourt part
			else if (columna == 4 && fila == 6) { posX = 8, posY = 12; }//
			else if (columna == 6 && fila == 6) { posX = 12, posY = 12; }//
			else if (columna == 1 && fila == 7) { posX = 2, posY = 14; }//fifth part
			else if (columna == 4 && fila == 7) { posX = 8, posY = 14; }//
			else if (columna == 7 && fila == 7) { posX = 14, posY = 14; }//
			else {
				fuera = true;
			}
		} while (fuera==true || Tablero[posY][posX] == fichaJ2 || Tablero[posY][posX] == fichaJ1);
		Console::ForegroundColor = ConsoleColor::White;
		Tablero[posY][posX] = fichaJ1;
		contadorficha1--;
		turno = 2;
	}
	else {
		do {
			fuera = false;
			system("cls");
			Dibujar_Tablero();
			Nombre_Ficha_Tablero();
			if (Tablero[posY][posX] == fichaJ1 || Tablero[posY][posX] == fichaJ2) {
				Console::SetCursorPosition(0, 16);
				Console::ForegroundColor = ConsoleColor::White;
				cout << "Esta ocupado elija otra posicion";
			}
			Console::SetCursorPosition(0, 17);
			Console::ForegroundColor = ConsoleColor::White;
			do {
				cout << NameJ2 << ", Ingrese el numero de columna: ";
				cin >> columna;
			} while (columna < 0 || columna>7);

			do {
				cout << NameJ2 << ", Ingrese el numero de fila: ";
				cin >> fila;
			} while (fila < 0 || fila>7);

			if (columna == 1 && fila == 1) { posX = 2, posY = 2; } //first part
			else if (columna == 4 && fila == 1) { posX = 8, posY = 2; } //
			else if (columna == 7 && fila == 1) { posX = 14, posY = 2; } //
			else if (columna == 2 && fila == 2) { posX = 4, posY = 4; } //
			else if (columna == 4 && fila == 2) { posX = 8, posY = 4; } //
			else if (columna == 6 && fila == 2) { posX = 12, posY = 4; } //
			else if (columna == 3 && fila == 3) { posX = 6, posY = 6; } //
			else if (columna == 4 && fila == 3) { posX = 8, posY = 6; } //
			else if (columna == 5 && fila == 3) { posX = 10, posY = 6; } //
			else if (columna == 1 && fila == 4) { posX = 2, posY = 8; }//second part
			else if (columna == 2 && fila == 4) { posX = 4, posY = 8; }//
			else if (columna == 3 && fila == 4) { posX = 6, posY = 8; }//
			else if (columna == 5 && fila == 4) { posX = 10, posY = 8; }//
			else if (columna == 6 && fila == 4) { posX = 12, posY = 8; }//
			else if (columna == 7 && fila == 4) { posX = 14, posY = 8; }//
			else if (columna == 3 && fila == 5) { posX = 6, posY = 10; }//third part
			else if (columna == 4 && fila == 5) { posX = 8, posY = 10; }//
			else if (columna == 5 && fila == 5) { posX = 10, posY = 10; }//
			else if (columna == 2 && fila == 6) { posX = 4, posY = 12; }//fourt part
			else if (columna == 4 && fila == 6) { posX = 8, posY = 12; }//
			else if (columna == 6 && fila == 6) { posX = 12, posY = 12; }//
			else if (columna == 1 && fila == 7) { posX = 2, posY = 14; }//fifth part
			else if (columna == 4 && fila == 7) { posX = 8, posY = 14; }//
			else if (columna == 7 && fila == 7) { posX = 14, posY = 14; }//
			else {
				fuera = true;
			}
		} while (fuera == true || Tablero[posY][posX] == fichaJ1 || Tablero[posY][posX] == fichaJ2);
		Console::ForegroundColor = ConsoleColor::White;
		Tablero[posY][posX] = fichaJ2;
		contadorficha2--;
		turno = 1;
		fuera = false;
	}
}
void Config_Colores(int p) {

	int opcion = 1;
	int y = 0;
	if (p == 0) {
		system("cls");
		do {
			rlutil::setBackgroundColor(rlutil::COLOR::GREEN);
			rlutil::setColor(rlutil::COLOR::WHITE);
			rlutil::locate(48, 10);
			cout << "::::FICHA JUGADOR 1::::" << endl << endl;
			rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
			Console::CursorVisible = FALSE;
			Show_Background("   BLUE     ", 52, 15, y == 0);
			Show_Background("   RED      ", 52, 16, y == 1);
			Show_Background("   GREEN    ", 52, 17, y == 2);
			Show_Background("   YELLOW   ", 52, 18, y == 3);
			Show_Background("   PURPLE   ", 52, 19, y == 4);
			Show_Background("   GRAY     ", 52, 20, y == 5);
			rlutil::locate(50, 15 + y);
			cout << char(175) << endl;
			int key = rlutil::getkey();
			switch (key)
			{
			case 14: { //UP
				rlutil::locate(50, 15 + y);
				cout << " " << endl;
				y--;
				if (y < 0) y = 0;
				break;
			}
			case 15: { //DOWN
				rlutil::locate(50, 15 + y);
				cout << " " << endl;
				y++;
				if (y > 5) y = 5;
				break;
			}
			case 1: {
				if (y == 0)  ColorJ1 = 1; opcion = 0;
				if (y == 1)  ColorJ1 = 4; opcion = 0;
				if (y == 2)  ColorJ1 = 2; opcion = 0;
				if (y == 3)  ColorJ1 = 6; opcion = 0;
				if (y == 4)  ColorJ1 = 5; opcion = 0;
				if (y == 5)  ColorJ1 = 8; opcion = 0;
				break;
			}
			default:
				break;
			}
		} while (opcion != 0);

	}
	if (p == 1) {
		system("cls");
		do {
			rlutil::setBackgroundColor(rlutil::COLOR::GREEN);
			rlutil::setColor(rlutil::COLOR::WHITE);
			rlutil::locate(48, 10);
			cout << "::::FICHA JUGADOR 2::::" << endl << endl;
			rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
			Console::CursorVisible = FALSE;
			Show_Background("   BLUE     ", 52, 15, y == 0);
			Show_Background("   RED      ", 52, 16, y == 1);
			Show_Background("   GREEN    ", 52, 17, y == 2);
			Show_Background("   YELLOW   ", 52, 18, y == 3);
			Show_Background("   PURPLE   ", 52, 19, y == 4);
			Show_Background("   GRAY     ", 52, 20, y == 5);
			rlutil::locate(50, 15 + y);
			cout << char(175) << endl;
			int key = rlutil::getkey();
			switch (key)
			{
			case 14: { //UP
				rlutil::locate(50, 15 + y);
				cout << " " << endl;
				y--;
				if (y < 0) y = 0;
				break;
			}
			case 15: { //DOWN
				rlutil::locate(50, 15 + y);
				cout << " " << endl;
				y++;
				if (y > 5) y = 5;
				break;
			}
			case 1: {
				if (y == 0)  ColorJ2 = 1; opcion = 0;
				if (y == 1)  ColorJ2 = 4; opcion = 0;
				if (y == 2)  ColorJ2 = 2; opcion = 0;
				if (y == 3)  ColorJ2 = 6; opcion = 0;
				if (y == 4)  ColorJ2 = 5; opcion = 0;
				if (y == 5)  ColorJ2 = 8; opcion = 0;
				break;
			}
			default:
				break;
			}
		} while (opcion != 0);
	}
}
void Menu_Colores() {
	int opcion = 1;
	int y = 0;
	rlutil::cls();
	do {
		rlutil::setBackgroundColor(rlutil::COLOR::GREEN);
		rlutil::setColor(rlutil::COLOR::WHITE);
		rlutil::locate(49, 10);
		cout << ":::::::MENU DE COLORES:::::::" << endl << endl;
		rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
		Console::CursorVisible = FALSE;
		Show_Background("    FICHA JUGADOR 1    ", 52, 15, y == Menu_Opcion1);
		Show_Background("    FICHA JUGADOR 2    ", 52, 16, y == Menu_Opcion2);
		Show_Background("     EMPEZAR JUEGO     ", 52, 17, y == Menu_Opcion3);
		rlutil::locate(50, 15 + y);
		cout << char(175) << endl;
		int key = rlutil::getkey();
		switch (key)
		{
		case 14: { //UP
			rlutil::locate(50, 15 + y);
			cout << " " << endl;
			y--;
			if (y < 0) y = 0;
			break;
		}
		case 15: { //DOWN
			rlutil::locate(50, 15 + y);
			cout << " " << endl;
			y++;
			if (y > 2) y = 2;
			break;
		}
		case 1: {
			if (y == Menu_Opcion1) {
				Config_Colores(Menu_Opcion1);
				system("cls");
			}
			if (y == Menu_Opcion2) {
				Config_Colores(Menu_Opcion2);
				system("cls");
			}
			if (y == Menu_Opcion3)  opcion = 0;
			break;
		}
		default:
			break;
		}
	} while (opcion != 0);

}
int Validar_Comer() {
	//PARA JUGADOR 1
	//CUADRADO GRANDE
	// =======================================================================================================
	//LINEA ARRIBA HORIZONTAL
	if (Tablero[2][2] == fichaJ1 && Tablero[2][8] == fichaJ1 && Tablero[2][14] == fichaJ1 && banderas[0] == false) { banderas[0] = true; return 1; }
	if ((Tablero[2][2] == 'a' && Tablero[2][8] == fichaJ1 && Tablero[2][14] == fichaJ1) || (Tablero[2][2] == fichaJ1 && Tablero[2][8] == 'b' && Tablero[2][14] == fichaJ1) || (Tablero[2][2] == fichaJ1 && Tablero[2][8] == fichaJ1 && Tablero[2][14] == 'c')) { banderas[0] = false; }
	//LINEA IZQUIERDA VERTICAL
	if (Tablero[2][2] == fichaJ1 && Tablero[8][2] == fichaJ1 && Tablero[14][2] == fichaJ1 && banderas[1] == false) { banderas[1] = true; return 1; }
	if ((Tablero[2][2] == 'a' && Tablero[8][2] == fichaJ1 && Tablero[14][2] == fichaJ1) || (Tablero[2][2] == fichaJ1 && Tablero[8][2] == 'j' && Tablero[14][2] == fichaJ1) || (Tablero[2][2] == fichaJ1 && Tablero[8][2] == fichaJ1 && Tablero[14][2] == 'v')) { banderas[1] = false; }
	//LINEA ABAJO HORIZONTAL
	if (Tablero[14][2] == fichaJ1 && Tablero[14][8] == fichaJ1 && Tablero[14][14] == fichaJ1 && banderas[2] == false) { banderas[2] = true; return 1; }
	if ((Tablero[14][2] == 'v' && Tablero[14][8] == fichaJ1 && Tablero[14][14] == fichaJ1) || (Tablero[14][2] == fichaJ1 && Tablero[14][8] == 'w' && Tablero[14][14] == fichaJ1) || (Tablero[14][2] == fichaJ1 && Tablero[14][8] == fichaJ1 && Tablero[14][14] == 'x')) { banderas[2] = false; }
	//LINEA DERECHA VERTICAL
	if (Tablero[2][14] == fichaJ1 && Tablero[8][14] == fichaJ1 && Tablero[14][14] == fichaJ1 && banderas[3] == false) { banderas[3] = true; return 1; }
	if ((Tablero[2][14] == 'c' && Tablero[8][14] == fichaJ1 && Tablero[14][14] == fichaJ1) || (Tablero[2][14] == fichaJ1 && Tablero[8][14] == 'o' && Tablero[14][14] == fichaJ1) || (Tablero[2][14] == fichaJ1 && Tablero[8][14] == fichaJ1 && Tablero[14][14] == 'x')) { banderas[3] = false; }
	//=========================================================================================================
	//CUADRADO MEDIANO
	// =======================================================================================================
	//LINEA ARRIBA HORIZONTAL
	if (Tablero[4][4] == fichaJ1 && Tablero[4][8] == fichaJ1 && Tablero[4][12] == fichaJ1 && banderas[4] == false) { banderas[4] = true; return 1; }
	if ((Tablero[4][4] == 'd' && Tablero[4][8] == fichaJ1 && Tablero[4][12] == fichaJ1) || (Tablero[4][4] == fichaJ1 && Tablero[4][8] == 'e' && Tablero[4][12] == fichaJ1) || (Tablero[4][4] == fichaJ1 && Tablero[4][8] == fichaJ1 && Tablero[4][12] == 'f')) { banderas[4] = false; }
	//LINEA IZQUIERDA VERTICAL
	if (Tablero[4][4] == fichaJ1 && Tablero[8][4] == fichaJ1 && Tablero[12][4] == fichaJ1 && banderas[5] == false) { banderas[5] = true; return 1; }
	if ((Tablero[4][4] == 'd' && Tablero[8][4] == fichaJ1 && Tablero[12][4] == fichaJ1) || (Tablero[4][4] == fichaJ1 && Tablero[8][4] == 'k' && Tablero[12][4] == fichaJ1) || (Tablero[4][4] == fichaJ1 && Tablero[8][4] == fichaJ1 && Tablero[12][4] == 's')) { banderas[5] = false; }
	//LINEA ABAJO HORIZONTAL
	if (Tablero[12][4] == fichaJ1 && Tablero[12][8] == fichaJ1 && Tablero[12][12] == fichaJ1 && banderas[6] == false) { banderas[6] = true; return 1; }
	if ((Tablero[12][4] == 's' && Tablero[12][8] == fichaJ1 && Tablero[12][12] == fichaJ1) || (Tablero[12][4] == fichaJ1 && Tablero[12][8] == 't' && Tablero[12][12] == fichaJ1) || (Tablero[12][4] == fichaJ1 && Tablero[12][8] == fichaJ1 && Tablero[12][12] == 'u')) { banderas[6] = false; }
	//LINEA DERECHA VERTICAL
	if (Tablero[4][12] == fichaJ1 && Tablero[8][12] == fichaJ1 && Tablero[12][12] == fichaJ1 && banderas[7] == false) { banderas[7] = true; return 1; }
	if ((Tablero[4][12] == 'f' && Tablero[8][12] == fichaJ1 && Tablero[12][12] == fichaJ1) || (Tablero[4][12] == fichaJ1 && Tablero[8][12] == 'n' && Tablero[12][12] == fichaJ1) || (Tablero[4][12] == fichaJ1 && Tablero[8][12] == fichaJ1 && Tablero[12][12] == 'u')) { banderas[7] = false; }
	//=========================================================================================================
	//CUADRADO PEQUENO
	// =======================================================================================================
	//LINEA ARRIBA HORIZONTAL
	if (Tablero[6][6] == fichaJ1 && Tablero[6][8] == fichaJ1 && Tablero[6][10] == fichaJ1 && banderas[8] == false) { banderas[8] = true; return 1; }
	if ((Tablero[6][6] == 'g' && Tablero[6][8] == fichaJ1 && Tablero[6][10] == fichaJ1) || (Tablero[6][6] == fichaJ1 && Tablero[6][8] == 'h' && Tablero[6][10] == fichaJ1) || (Tablero[6][6] == fichaJ1 && Tablero[6][8] == fichaJ1 && Tablero[6][10] == 'i')) { banderas[8] = false; }
	//LINEA IZQUIERDA VERTICAL
	if (Tablero[6][6] == fichaJ1 && Tablero[8][6] == fichaJ1 && Tablero[10][6] == fichaJ1 && banderas[9] == false) { banderas[9] = true; return 1; }
	if ((Tablero[6][6] == 'g' && Tablero[8][6] == fichaJ1 && Tablero[10][6] == fichaJ1) || (Tablero[6][6] == fichaJ1 && Tablero[8][6] == 'l' && Tablero[10][6] == fichaJ1) || (Tablero[6][6] == fichaJ1 && Tablero[8][6] == fichaJ1 && Tablero[10][6] == 'p')) { banderas[9] = false; }
	//LINEA ABAJO HORIZONTAL
	if (Tablero[10][6] == fichaJ1 && Tablero[10][8] == fichaJ1 && Tablero[10][10] == fichaJ1 && banderas[10] == false) { banderas[10] = true; return 1; }
	if ((Tablero[10][6] == 'p' && Tablero[10][8] == fichaJ1 && Tablero[10][10] == fichaJ1) || (Tablero[10][6] == fichaJ1 && Tablero[10][8] == 'q' && Tablero[10][10] == fichaJ1) || (Tablero[10][6] == fichaJ1 && Tablero[10][8] == fichaJ1 && Tablero[10][10] == 'r')) { banderas[10] = false; }
	//LINEA DERECHA VERTICAL
	if (Tablero[6][10] == fichaJ1 && Tablero[8][10] == fichaJ1 && Tablero[10][10] == fichaJ1 && banderas[11] == false) { banderas[11] = true; return 1; }
	if ((Tablero[6][10] == 'i' && Tablero[8][10] == fichaJ1 && Tablero[10][10] == fichaJ1) || (Tablero[6][10] == fichaJ1 && Tablero[8][10] == 'm' && Tablero[10][10] == fichaJ1) || (Tablero[6][10] == fichaJ1 && Tablero[8][10] == fichaJ1 && Tablero[10][10] == 'r')) { banderas[11] = false; }
	//=========================================================================================================
	//DIAGONALES
	// =======================================================================================================
	//ADG
	if (Tablero[2][2] == fichaJ1 && Tablero[4][4] == fichaJ1 && Tablero[6][6] == fichaJ1 && banderas[12] == false) { banderas[12] = true; return 1; }
	if ((Tablero[2][2] == 'a' && Tablero[4][4] == fichaJ1 && Tablero[6][6] == fichaJ1) || (Tablero[2][2] == fichaJ1 && Tablero[4][4] == 'd' && Tablero[6][6] == fichaJ1) || (Tablero[2][2] == fichaJ1 && Tablero[4][4] == fichaJ1 && Tablero[6][6] == 'g')) { banderas[12] = false; }
	//BEH
	if (Tablero[2][8] == fichaJ1 && Tablero[4][8] == fichaJ1 && Tablero[6][8] == fichaJ1 && banderas[13] == false) { banderas[13] = true; return 1; }
	if ((Tablero[2][8] == 'b' && Tablero[4][8] == fichaJ1 && Tablero[6][8] == fichaJ1) || (Tablero[2][8] == fichaJ1 && Tablero[4][8] == 'e' && Tablero[6][8] == fichaJ1) || (Tablero[2][8] == fichaJ1 && Tablero[4][8] == fichaJ1 && Tablero[6][8] == 'h')) { banderas[13] = false; }
	//CFI
	if (Tablero[2][14] == fichaJ1 && Tablero[4][12] == fichaJ1 && Tablero[6][10] == fichaJ1 && banderas[14] == false) { banderas[14] = true; return 1; }
	if ((Tablero[2][14] == 'c' && Tablero[4][12] == fichaJ1 && Tablero[6][10] == fichaJ1) || (Tablero[2][14] == fichaJ1 && Tablero[4][12] == 'f' && Tablero[6][10] == fichaJ1) || (Tablero[2][14] == fichaJ1 && Tablero[4][12] == fichaJ1 && Tablero[6][10] == 'i')) { banderas[14] = false; }
	//JKL
	if (Tablero[8][2] == fichaJ1 && Tablero[8][4] == fichaJ1 && Tablero[8][6] == fichaJ1 && banderas[15] == false) { banderas[15] = true; return 1; }
	if ((Tablero[8][2] == 'j' && Tablero[8][4] == fichaJ1 && Tablero[8][6] == fichaJ1) || (Tablero[8][2] == fichaJ1 && Tablero[8][4] == 'k' && Tablero[8][6] == fichaJ1) || (Tablero[8][2] == fichaJ1 && Tablero[8][4] == fichaJ1 && Tablero[8][6] == 'l')) { banderas[15] = false; }
	//MNO
	if (Tablero[8][10] == fichaJ1 && Tablero[8][12] == fichaJ1 && Tablero[8][14] == fichaJ1 && banderas[16] == false) { banderas[16] = true; return 1; }
	if ((Tablero[8][10] == 'm' && Tablero[8][12] == fichaJ1 && Tablero[8][14] == fichaJ1) || (Tablero[8][10] == fichaJ1 && Tablero[8][12] == 'n' && Tablero[8][14] == fichaJ1) || (Tablero[8][10] == fichaJ1 && Tablero[8][12] == fichaJ1 && Tablero[8][14] == 'o')) { banderas[16] = false; }
	//VSP
	if (Tablero[14][2] == fichaJ1 && Tablero[12][4] == fichaJ1 && Tablero[10][6] == fichaJ1 && banderas[17] == false) { banderas[17] = true; return 1; }
	if ((Tablero[14][2] == 'v' && Tablero[12][4] == fichaJ1 && Tablero[10][6] == fichaJ1) || (Tablero[14][2] == fichaJ1 && Tablero[12][4] == 's' && Tablero[10][6] == fichaJ1) || (Tablero[14][2] == fichaJ1 && Tablero[12][4] == fichaJ1 && Tablero[10][6] == 'p')) { banderas[17] = false; }
	//WTQ
	if (Tablero[14][8] == fichaJ1 && Tablero[12][8] == fichaJ1 && Tablero[10][8] == fichaJ1 && banderas[18] == false) { banderas[18] = true; return 1; }
	if ((Tablero[14][8] == 'w' && Tablero[12][8] == fichaJ1 && Tablero[10][8] == fichaJ1) || (Tablero[14][8] == fichaJ1 && Tablero[12][8] == 't' && Tablero[10][8] == fichaJ1) || (Tablero[14][8] == fichaJ1 && Tablero[12][8] == fichaJ1 && Tablero[10][8] == 'q')) { banderas[18] = false; }
	//XUR
	if (Tablero[14][14] == fichaJ1 && Tablero[12][12] == fichaJ1 && Tablero[10][10] == fichaJ1 && banderas[19] == false) { banderas[19] = true; return 1; }
	if ((Tablero[14][14] == 'x' && Tablero[12][12] == fichaJ1 && Tablero[10][10] == fichaJ1) || (Tablero[14][14] == fichaJ1 && Tablero[12][12] == 'u' && Tablero[10][10] == fichaJ1) || (Tablero[14][14] == fichaJ1 && Tablero[12][12] == fichaJ1 && Tablero[10][10] == 'r')) { banderas[19] = false; }
	// =======================================================================================================
	// =======================================================================================================
	// =======================================================================================================
	// =======================================================================================================

}
int Validar_ComerJ2() {
	//PARA JUGADOR 2
	//CUADRADO GRANDE
	// =======================================================================================================
	//LINEA ARRIBA HORIZONTAL
	if (Tablero[2][2] == fichaJ2 && Tablero[2][8] == fichaJ2 && Tablero[2][14] == fichaJ2 && banderas2[0] == false) { banderas2[0] = true; return 2; }
	if ((Tablero[2][2] == 'a' && Tablero[2][8] == fichaJ2 && Tablero[2][14] == fichaJ2) || (Tablero[2][2] == fichaJ2 && Tablero[2][8] == 'b' && Tablero[2][14] == fichaJ2) || (Tablero[2][2] == fichaJ2 && Tablero[2][8] == fichaJ2 && Tablero[2][14] == 'c')) { banderas2[0] = false; }
	//LINEA IZQUIERDA VERTICAL
	if (Tablero[2][2] == fichaJ2 && Tablero[8][2] == fichaJ2 && Tablero[14][2] == fichaJ2 && banderas2[1] == false) { banderas2[1] = true; return 2; }
	if ((Tablero[2][2] == 'a' && Tablero[8][2] == fichaJ2 && Tablero[14][2] == fichaJ2) || (Tablero[2][2] == fichaJ2 && Tablero[8][2] == 'j' && Tablero[14][2] == fichaJ2) || (Tablero[2][2] == fichaJ2 && Tablero[8][2] == fichaJ2 && Tablero[14][2] == 'v')) { banderas2[1] = false; }
	//LINEA ABAJO HORIZONTAL
	if (Tablero[14][2] == fichaJ2 && Tablero[14][8] == fichaJ2 && Tablero[14][14] == fichaJ2 && banderas2[2] == false) { banderas2[2] = true; return 2; }
	if ((Tablero[14][2] == 'v' && Tablero[14][8] == fichaJ2 && Tablero[14][14] == fichaJ2) || (Tablero[14][2] == fichaJ2 && Tablero[14][8] == 'w' && Tablero[14][14] == fichaJ2) || (Tablero[14][2] == fichaJ2 && Tablero[14][8] == fichaJ2 && Tablero[14][14] == 'x')) { banderas2[2] = false; }
	//LINEA DERECHA VERTICAL
	if (Tablero[2][14] == fichaJ2 && Tablero[8][14] == fichaJ2 && Tablero[14][14] == fichaJ2 && banderas2[3] == false) { banderas2[3] = true; return 2; }
	if ((Tablero[2][14] == 'c' && Tablero[8][14] == fichaJ2 && Tablero[14][14] == fichaJ2) || (Tablero[2][14] == fichaJ2 && Tablero[8][14] == 'o' && Tablero[14][14] == fichaJ2) || (Tablero[2][14] == fichaJ2 && Tablero[8][14] == fichaJ2 && Tablero[14][14] == 'x')) { banderas2[3] = false; }
	//=========================================================================================================
	//CUADRADO MEDIANO
	// =======================================================================================================
	//LINEA ARRIBA HORIZONTAL
	if (Tablero[4][4] == fichaJ2 && Tablero[4][8] == fichaJ2 && Tablero[4][12] == fichaJ2 && banderas2[4] == false) { banderas2[4] = true; return 2; }
	if ((Tablero[4][4] == 'd' && Tablero[4][8] == fichaJ2 && Tablero[4][12] == fichaJ2) || (Tablero[4][4] == fichaJ2 && Tablero[4][8] == 'e' && Tablero[4][12] == fichaJ2) || (Tablero[4][4] == fichaJ2 && Tablero[4][8] == fichaJ2 && Tablero[4][12] == 'f')) { banderas2[4] = false; }
	//LINEA IZQUIERDA VERTICAL
	if (Tablero[4][4] == fichaJ2 && Tablero[8][4] == fichaJ2 && Tablero[12][4] == fichaJ2 && banderas2[5] == false) { banderas2[5] = true; return 2; }
	if ((Tablero[4][4] == 'd' && Tablero[8][4] == fichaJ2 && Tablero[12][4] == fichaJ2) || (Tablero[4][4] == fichaJ2 && Tablero[8][4] == 'k' && Tablero[12][4] == fichaJ2) || (Tablero[4][4] == fichaJ2 && Tablero[8][4] == fichaJ2 && Tablero[12][4] == 's')) { banderas2[5] = false; }
	//LINEA ABAJO HORIZONTAL
	if (Tablero[12][4] == fichaJ2 && Tablero[12][8] == fichaJ2 && Tablero[12][12] == fichaJ2 && banderas2[6] == false) { banderas2[6] = true; return 2; }
	if ((Tablero[12][4] == 's' && Tablero[12][8] == fichaJ2 && Tablero[12][12] == fichaJ2) || (Tablero[12][4] == fichaJ2 && Tablero[12][8] == 't' && Tablero[12][12] == fichaJ2) || (Tablero[12][4] == fichaJ2 && Tablero[12][8] == fichaJ2 && Tablero[12][12] == 'u')) { banderas2[6] = false; }
	//LINEA DERECHA VERTICAL
	if (Tablero[4][12] == fichaJ2 && Tablero[8][12] == fichaJ2 && Tablero[12][12] == fichaJ2 && banderas2[7] == false) { banderas2[7] = true; return 2; }
	if ((Tablero[4][12] == 'f' && Tablero[8][12] == fichaJ2 && Tablero[12][12] == fichaJ2) || (Tablero[4][12] == fichaJ2 && Tablero[8][12] == 'n' && Tablero[12][12] == fichaJ2) || (Tablero[4][12] == fichaJ2 && Tablero[8][12] == fichaJ2 && Tablero[12][12] == 'u')) { banderas2[7] = false; }
	//=========================================================================================================
	//CUADRADO PEQUENO
	// =======================================================================================================
	//LINEA ARRIBA HORIZONTAL
	if (Tablero[6][6] == fichaJ2 && Tablero[6][8] == fichaJ2 && Tablero[6][10] == fichaJ2 && banderas2[8] == false) { banderas2[8] = true; return 2; }
	if ((Tablero[6][6] == 'g' && Tablero[6][8] == fichaJ2 && Tablero[6][10] == fichaJ2) || (Tablero[6][6] == fichaJ2 && Tablero[6][8] == 'h' && Tablero[6][10] == fichaJ2) || (Tablero[6][6] == fichaJ2 && Tablero[6][8] == fichaJ2 && Tablero[6][10] == 'i')) { banderas2[8] = false; }
	//LINEA IZQUIERDA VERTICAL
	if (Tablero[6][6] == fichaJ2 && Tablero[8][6] == fichaJ2 && Tablero[10][6] == fichaJ2 && banderas2[9] == false) { banderas2[9] = true; return 2; }
	if ((Tablero[6][6] == 'g' && Tablero[8][6] == fichaJ2 && Tablero[10][6] == fichaJ2) || (Tablero[6][6] == fichaJ2 && Tablero[8][6] == 'l' && Tablero[10][6] == fichaJ2) || (Tablero[6][6] == fichaJ2 && Tablero[8][6] == fichaJ2 && Tablero[10][6] == 'p')) { banderas2[9] = false; }
	//LINEA ABAJO HORIZONTAL
	if (Tablero[10][6] == fichaJ2 && Tablero[10][8] == fichaJ2 && Tablero[10][10] == fichaJ2 && banderas2[10] == false) { banderas2[10] = true; return 2; }
	if ((Tablero[10][6] == 'p' && Tablero[10][8] == fichaJ2 && Tablero[10][10] == fichaJ2) || (Tablero[10][6] == fichaJ2 && Tablero[10][8] == 'q' && Tablero[10][10] == fichaJ2) || (Tablero[10][6] == fichaJ2 && Tablero[10][8] == fichaJ2 && Tablero[10][10] == 'r')) { banderas2[10] = false; }
	//LINEA DERECHA VERTICAL
	if (Tablero[6][10] == fichaJ2 && Tablero[8][10] == fichaJ2 && Tablero[10][10] == fichaJ2 && banderas2[11] == false) { banderas2[11] = true; return 2; }
	if ((Tablero[6][10] == 'i' && Tablero[8][10] == fichaJ2 && Tablero[10][10] == fichaJ2) || (Tablero[6][10] == fichaJ2 && Tablero[8][10] == 'm' && Tablero[10][10] == fichaJ2) || (Tablero[6][10] == fichaJ2 && Tablero[8][10] == fichaJ2 && Tablero[10][10] == 'r')) { banderas2[11] = false; }
	//=========================================================================================================
	//DIAGONALES
	// =======================================================================================================
	//ADG
	if (Tablero[2][2] == fichaJ2 && Tablero[4][4] == fichaJ2 && Tablero[6][6] == fichaJ2 && banderas2[12] == false) { banderas2[12] = true; return 2; }
	if ((Tablero[2][2] == 'a' && Tablero[4][4] == fichaJ2 && Tablero[6][6] == fichaJ2) || (Tablero[2][2] == fichaJ2 && Tablero[4][4] == 'd' && Tablero[6][6] == fichaJ2) || (Tablero[2][2] == fichaJ2 && Tablero[4][4] == fichaJ2 && Tablero[6][6] == 'g')) { banderas2[12] = false; }
	//BEH
	if (Tablero[2][8] == fichaJ2 && Tablero[4][8] == fichaJ2 && Tablero[6][8] == fichaJ2 && banderas2[13] == false) { banderas2[13] = true; return 2; }
	if ((Tablero[2][8] == 'b' && Tablero[4][8] == fichaJ2 && Tablero[6][8] == fichaJ2) || (Tablero[2][8] == fichaJ2 && Tablero[4][8] == 'e' && Tablero[6][8] == fichaJ2) || (Tablero[2][8] == fichaJ2 && Tablero[4][8] == fichaJ2 && Tablero[6][8] == 'h')) { banderas2[13] = false; }
	//CFI
	if (Tablero[2][14] == fichaJ2 && Tablero[4][12] == fichaJ2 && Tablero[6][10] == fichaJ2 && banderas2[14] == false) { banderas2[14] = true; return 2; }
	if ((Tablero[2][14] == 'c' && Tablero[4][12] == fichaJ2 && Tablero[6][10] == fichaJ2) || (Tablero[2][14] == fichaJ2 && Tablero[4][12] == 'f' && Tablero[6][10] == fichaJ2) || (Tablero[2][14] == fichaJ2 && Tablero[4][12] == fichaJ2 && Tablero[6][10] == 'i')) { banderas2[14] = false; }
	//JKL
	if (Tablero[8][2] == fichaJ2 && Tablero[8][4] == fichaJ2 && Tablero[8][6] == fichaJ2 && banderas2[15] == false) { banderas2[15] = true; return 2; }
	if ((Tablero[8][2] == 'j' && Tablero[8][4] == fichaJ2 && Tablero[8][6] == fichaJ2) || (Tablero[8][2] == fichaJ2 && Tablero[8][4] == 'k' && Tablero[8][6] == fichaJ2) || (Tablero[8][2] == fichaJ2 && Tablero[8][4] == fichaJ2 && Tablero[8][6] == 'l')) { banderas2[15] = false; }
	//MNO
	if (Tablero[8][10] == fichaJ2 && Tablero[8][12] == fichaJ2 && Tablero[8][14] == fichaJ2 && banderas2[16] == false) { banderas2[16] = true; return 2; }
	if ((Tablero[8][10] == 'm' && Tablero[8][12] == fichaJ2 && Tablero[8][14] == fichaJ2) || (Tablero[8][10] == fichaJ2 && Tablero[8][12] == 'n' && Tablero[8][14] == fichaJ2) || (Tablero[8][10] == fichaJ2 && Tablero[8][12] == fichaJ2 && Tablero[8][14] == 'o')) { banderas2[16] = false; }
	//VSP
	if (Tablero[14][2] == fichaJ2 && Tablero[12][4] == fichaJ2 && Tablero[10][6] == fichaJ2 && banderas2[17] == false) { banderas2[17] = true; return 2; }
	if ((Tablero[14][2] == 'v' && Tablero[12][4] == fichaJ2 && Tablero[10][6] == fichaJ2) || (Tablero[14][2] == fichaJ2 && Tablero[12][4] == 's' && Tablero[10][6] == fichaJ2) || (Tablero[14][2] == fichaJ2 && Tablero[12][4] == fichaJ2 && Tablero[10][6] == 'p')) { banderas2[17] = false; }
	//WTQ
	if (Tablero[14][8] == fichaJ2 && Tablero[12][8] == fichaJ2 && Tablero[10][8] == fichaJ2 && banderas2[18] == false) { banderas2[18] = true; return 2; }
	if ((Tablero[14][8] == 'w' && Tablero[12][8] == fichaJ2 && Tablero[10][8] == fichaJ2) || (Tablero[14][8] == fichaJ2 && Tablero[12][8] == 't' && Tablero[10][8] == fichaJ2) || (Tablero[14][8] == fichaJ2 && Tablero[12][8] == fichaJ2 && Tablero[10][8] == 'q')) { banderas2[18] = false; }
	//XUR
	if (Tablero[14][14] == fichaJ2 && Tablero[12][12] == fichaJ2 && Tablero[10][10] == fichaJ2 && banderas2[19] == false) { banderas2[19] = true; return 2; }
	if ((Tablero[14][14] == 'x' && Tablero[12][12] == fichaJ2 && Tablero[10][10] == fichaJ2) || (Tablero[14][14] == fichaJ2 && Tablero[12][12] == 'u' && Tablero[10][10] == fichaJ2) || (Tablero[14][14] == fichaJ2 && Tablero[12][12] == fichaJ2 && Tablero[10][10] == 'r')) { banderas2[19] = false; }
}
void Comer() {
	int Eliminar_Columna, Eliminar_Fila;
	int posX, posY;
	int salir = 1;
	int salir2 = 1;

	if (Validar_Comer() == 1) {
		do {


			Dibujar_Tablero();
			Nombre_Ficha_Tablero();
			do {
				Console::SetCursorPosition(0, 17);
				Console::ForegroundColor = ConsoleColor::White;
				cout << NameJ1 << ", USTED PUEDE ELIMINAR UNA FICHA DEL RIVAL.";
				Console::SetCursorPosition(0, 18);
				cout << "ESCRIBA LA COLUMNA DE LA FICHA A ELIMINAR: "; cin >> Eliminar_Columna;
				Console::SetCursorPosition(0, 19);
				cout << "ESCRIBA LA FILA DE LA FICHA A ELIMINAR: "; cin >> Eliminar_Fila;
			} while ((Eliminar_Columna < 0 || Eliminar_Columna>7) && (Eliminar_Fila < 0 || Eliminar_Fila>7));


			if (Eliminar_Columna == 1 && Eliminar_Fila == 1) {
				posX = 2, posY = 2;
				if (Tablero[posY][posX] == fichaJ2) {
					Tablero[posY][posX] = 'a'; salir = 0;
				}
			}
			if (Eliminar_Columna == 4 && Eliminar_Fila == 1) {
				posX = 8, posY = 2;
				if (Tablero[posY][posX] == fichaJ2) {
					Tablero[posY][posX] = 'b'; salir = 0;
				}
			}
			if (Eliminar_Columna == 7 && Eliminar_Fila == 1) {
				posX = 14, posY = 2;
				if (Tablero[posY][posX] == fichaJ2) {
					Tablero[posY][posX] = 'c'; salir = 0;
				}
			} //
			if (Eliminar_Columna == 2 && Eliminar_Fila == 2) {
				posX = 4, posY = 4;
				if (Tablero[posY][posX] == fichaJ2) {
					Tablero[posY][posX] = 'd'; salir = 0;
				}
			} //
			if (Eliminar_Columna == 4 && Eliminar_Fila == 2) {
				posX = 8, posY = 4;
				if (Tablero[posY][posX] == fichaJ2) {
					Tablero[posY][posX] = 'e'; salir = 0;
				}
			} //
			if (Eliminar_Columna == 6 && Eliminar_Fila == 2) {
				posX = 12, posY = 4;
				if (Tablero[posY][posX] == fichaJ2) {
					Tablero[posY][posX] = 'f'; salir = 0;
				}
			} //
			if (Eliminar_Columna == 3 && Eliminar_Fila == 3) {
				posX = 6, posY = 6;
				if (Tablero[posY][posX] == fichaJ2) {
					Tablero[posY][posX] = 'g'; salir = 0;
				}
			} //
			if (Eliminar_Columna == 4 && Eliminar_Fila == 3) {
				posX = 8, posY = 6;
				if (Tablero[posY][posX] == fichaJ2) {
					Tablero[posY][posX] = 'h'; salir = 0;
				}
			} //
			if (Eliminar_Columna == 5 && Eliminar_Fila == 3) {
				posX = 10, posY = 6;
				if (Tablero[posY][posX] == fichaJ2) {
					Tablero[posY][posX] = 'i'; salir = 0;
				}
			} //



			if (Eliminar_Columna == 1 && Eliminar_Fila == 4) {
				posX = 2, posY = 8;
				if (Tablero[posY][posX] == fichaJ2) {
					Tablero[posY][posX] = 'j'; salir = 0;
				}
			}//
			if (Eliminar_Columna == 2 && Eliminar_Fila == 4) {
				posX = 4, posY = 8;
				if (Tablero[posY][posX] == fichaJ2) {
					Tablero[posY][posX] = 'k'; salir = 0;
				}
			}//
			if (Eliminar_Columna == 3 && Eliminar_Fila == 4) {
				posX = 6, posY = 8;
				if (Tablero[posY][posX] == fichaJ2) {
					Tablero[posY][posX] = 'l'; salir = 0;
				}
			}//
			if (Eliminar_Columna == 5 && Eliminar_Fila == 4) {
				posX = 10, posY = 8;
				if (Tablero[posY][posX] == fichaJ2) {
					Tablero[posY][posX] = 'm'; salir = 0;
				}
			}//
			if (Eliminar_Columna == 6 && Eliminar_Fila == 4) {
				posX = 12, posY = 8;
				if (Tablero[posY][posX] == fichaJ2) {
					Tablero[posY][posX] = 'n'; salir = 0;
				}
			}//
			if (Eliminar_Columna == 7 && Eliminar_Fila == 4) {
				posX = 14, posY = 8;
				if (Tablero[posY][posX] == fichaJ2) {
					Tablero[posY][posX] = 'o'; salir = 0;
				}
			}//

			if (Eliminar_Columna == 3 && Eliminar_Fila == 5) {
				posX = 6, posY = 10;
				if (Tablero[posY][posX] == fichaJ2) {
					Tablero[posY][posX] = 'p'; salir = 0;
				}
			}//
			if (Eliminar_Columna == 4 && Eliminar_Fila == 5) {
				posX = 8, posY = 10;
				if (Tablero[posY][posX] == fichaJ2) {
					Tablero[posY][posX] = 'q'; salir = 0;
				}
			}//
			if (Eliminar_Columna == 5 && Eliminar_Fila == 5) {
				posX = 10, posY = 10;
				if (Tablero[posY][posX] == fichaJ2) {
					Tablero[posY][posX] = 'r'; salir = 0;
				}
			}//

			if (Eliminar_Columna == 2 && Eliminar_Fila == 6) {
				posX = 4, posY = 12;
				if (Tablero[posY][posX] == fichaJ2) {
					Tablero[posY][posX] = 's'; salir = 0;
				}
			}//
			if (Eliminar_Columna == 4 && Eliminar_Fila == 6) {
				posX = 8, posY = 12;
				if (Tablero[posY][posX] == fichaJ2) {
					Tablero[posY][posX] = 't'; salir = 0;
				}
			}//
			if (Eliminar_Columna == 6 && Eliminar_Fila == 6) {
				posX = 12, posY = 12;
				if (Tablero[posY][posX] == fichaJ2) {
					Tablero[posY][posX] = 'u'; salir = 0;
				}
			}//


			if (Eliminar_Columna == 1 && Eliminar_Fila == 7) {
				posX = 2, posY = 14;
				if (Tablero[posY][posX] == fichaJ2) {
					Tablero[posY][posX] = 'v'; salir = 0;
				}
			}//
			if (Eliminar_Columna == 4 && Eliminar_Fila == 7) {
				posX = 8, posY = 14;
				if (Tablero[posY][posX] == fichaJ2) {
					Tablero[posY][posX] = 'w'; salir = 0;
				}
			}//
			if (Eliminar_Columna == 7 && Eliminar_Fila == 7) {
				posX = 14, posY = 14;
				if (Tablero[posY][posX] == fichaJ2) {
					Tablero[posY][posX] = 'x'; salir = 0;
				}
			}//
		} while (salir != 0);
	}
	if (Validar_ComerJ2() == 2) {
		do {
			Dibujar_Tablero();
			Nombre_Ficha_Tablero();
			do {
				Console::SetCursorPosition(0, 17);
				Console::ForegroundColor = ConsoleColor::White;
				cout << NameJ2 << ", USTED PUEDE ELIMINAR UNA FICHA DEL RIVAL.";
				Console::SetCursorPosition(0, 18);
				cout << "ESCRIBA LA COLUMNA DE LA FICHA A ELIMINAR: "; cin >> Eliminar_Columna;
				Console::SetCursorPosition(0, 19);
				cout << "ESCRIBA LA FILA DE LA FICHA A ELIMINAR: "; cin >> Eliminar_Fila;
			} while ((Eliminar_Columna < 0 || Eliminar_Columna>7) && (Eliminar_Fila < 0 || Eliminar_Fila>7));


			if (Eliminar_Columna == 1 && Eliminar_Fila == 1) {
				posX = 2, posY = 2;
				if (Tablero[posY][posX] == fichaJ1) {
					Tablero[posY][posX] = 'a'; salir2 = 0;
				}
			}
			if (Eliminar_Columna == 4 && Eliminar_Fila == 1) {
				posX = 8, posY = 2;
				if (Tablero[posY][posX] == fichaJ1) {
					Tablero[posY][posX] = 'b'; salir2 = 0;
				}
			}
			if (Eliminar_Columna == 7 && Eliminar_Fila == 1) {
				posX = 14, posY = 2;
				if (Tablero[posY][posX] == fichaJ1) {
					Tablero[posY][posX] = 'c'; salir2 = 0;
				}
			} //
			if (Eliminar_Columna == 2 && Eliminar_Fila == 2) {
				posX = 4, posY = 4;
				if (Tablero[posY][posX] == fichaJ1) {
					Tablero[posY][posX] = 'd'; salir2 = 0;
				}
			} //
			if (Eliminar_Columna == 4 && Eliminar_Fila == 2) {
				posX = 8, posY = 4;
				if (Tablero[posY][posX] == fichaJ1) {
					Tablero[posY][posX] = 'e'; salir2 = 0;
				}
			} //
			if (Eliminar_Columna == 6 && Eliminar_Fila == 2) {
				posX = 12, posY = 4;
				if (Tablero[posY][posX] == fichaJ1) {
					Tablero[posY][posX] = 'f'; salir2 = 0;
				}
			} //
			if (Eliminar_Columna == 3 && Eliminar_Fila == 3) {
				posX = 6, posY = 6;
				if (Tablero[posY][posX] == fichaJ1) {
					Tablero[posY][posX] = 'g'; salir2 = 0;
				}
			} //
			if (Eliminar_Columna == 4 && Eliminar_Fila == 3) {
				posX = 8, posY = 6;
				if (Tablero[posY][posX] == fichaJ1) {
					Tablero[posY][posX] = 'h'; salir2 = 0;
				}
			} //
			if (Eliminar_Columna == 5 && Eliminar_Fila == 3) {
				posX = 10, posY = 6;
				if (Tablero[posY][posX] == fichaJ1) {
					Tablero[posY][posX] = 'i'; salir2 = 0;
				}
			} //
			if (Eliminar_Columna == 1 && Eliminar_Fila == 4) {
				posX = 2, posY = 8;
				if (Tablero[posY][posX] == fichaJ1) {
					Tablero[posY][posX] = 'j'; salir2 = 0;
				}
			}//
			if (Eliminar_Columna == 2 && Eliminar_Fila == 4) {
				posX = 4, posY = 8;
				if (Tablero[posY][posX] == fichaJ1) {
					Tablero[posY][posX] = 'k'; salir2 = 0;
				}
			}//
			if (Eliminar_Columna == 3 && Eliminar_Fila == 4) {
				posX = 6, posY = 8;
				if (Tablero[posY][posX] == fichaJ1) {
					Tablero[posY][posX] = 'l'; salir2 = 0;
				}
			}//
			if (Eliminar_Columna == 5 && Eliminar_Fila == 4) {
				posX = 10, posY = 8;
				if (Tablero[posY][posX] == fichaJ1) {
					Tablero[posY][posX] = 'm'; salir2 = 0;
				}
			}//
			if (Eliminar_Columna == 6 && Eliminar_Fila == 4) {
				posX = 12, posY = 8;
				if (Tablero[posY][posX] == fichaJ1) {
					Tablero[posY][posX] = 'n'; salir2 = 0;
				}
			}//
			if (Eliminar_Columna == 7 && Eliminar_Fila == 4) {
				posX = 14, posY = 8;
				if (Tablero[posY][posX] == fichaJ1) {
					Tablero[posY][posX] = 'o'; salir2 = 0;
				}
			}//
			if (Eliminar_Columna == 3 && Eliminar_Fila == 5) {
				posX = 6, posY = 10;
				if (Tablero[posY][posX] == fichaJ1) {
					Tablero[posY][posX] = 'p'; salir2 = 0;
				}
			}//
			if (Eliminar_Columna == 4 && Eliminar_Fila == 5) {
				posX = 8, posY = 10;
				if (Tablero[posY][posX] == fichaJ1) {
					Tablero[posY][posX] = 'q'; salir2 = 0;
				}
			}//
			if (Eliminar_Columna == 5 && Eliminar_Fila == 5) {
				posX = 10, posY = 10;
				if (Tablero[posY][posX] == fichaJ1) {
					Tablero[posY][posX] = 'r'; salir2 = 0;
				}
			}//
			if (Eliminar_Columna == 2 && Eliminar_Fila == 6) {
				posX = 4, posY = 12;
				if (Tablero[posY][posX] == fichaJ1) {
					Tablero[posY][posX] = 's'; salir2 = 0;
				}
			}//
			if (Eliminar_Columna == 4 && Eliminar_Fila == 6) {
				posX = 8, posY = 12;
				if (Tablero[posY][posX] == fichaJ1) {
					Tablero[posY][posX] = 't'; salir2 = 0;
				}
			}//
			if (Eliminar_Columna == 6 && Eliminar_Fila == 6) {
				posX = 12, posY = 12;
				if (Tablero[posY][posX] == fichaJ1) {
					Tablero[posY][posX] = 'u'; salir2 = 0;
				}
			}//
			if (Eliminar_Columna == 1 && Eliminar_Fila == 7) {
				posX = 2, posY = 14;
				if (Tablero[posY][posX] == fichaJ1) {
					Tablero[posY][posX] = 'v'; salir2 = 0;
				}
			}//
			if (Eliminar_Columna == 4 && Eliminar_Fila == 7) {
				posX = 8, posY = 14;
				if (Tablero[posY][posX] == fichaJ1) {
					Tablero[posY][posX] = 'w'; salir2 = 0;
				}
			}//
			if (Eliminar_Columna == 7 && Eliminar_Fila == 7) {
				posX = 14, posY = 14;
				if (Tablero[posY][posX] == fichaJ1) {
					Tablero[posY][posX] = 'x'; salir2 = 0;
				}
			}//

		} while (salir2 != 0);
	}
}
bool ValidarMovimiento(int columna, int fila, int columnamover, int filamover) {
	if (turno == 1 || Tablero[fila][columna]==fichaJ1) {
		if (columna == 2 && fila == 2 && columnamover == 8 && filamover == 2 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true; //b
		else if (columna == 2 && fila == 2 && columnamover == 2 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true; //j
		else if (columna == 8 && fila == 2 && columnamover == 2 && filamover == 2 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true; //a
		else if (columna == 8 && fila == 2 && columnamover == 14 && filamover == 2 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true; //c
		else if (columna == 8 && fila == 2 && columnamover == 8 && filamover == 4 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true; //e
		else if (columna == 14 && fila == 2 && columnamover == 8 && filamover == 2 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true; //b
		else if (columna == 14 && fila == 2 && columnamover == 14 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true; //o
		else if (columna == 4 && fila == 4 && columnamover == 8 && filamover == 4 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true; //e
		else if (columna == 4 && fila == 4 && columnamover == 4 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true; //k
		else if (columna == 8 && fila == 4 && columnamover == 4 && filamover == 4 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true; //d
		else if (columna == 8 && fila == 4 && columnamover == 12 && filamover == 4 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true; //f
		else if (columna == 8 && fila == 4 && columnamover == 8 && filamover == 6 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true; //h
		else if (columna == 12 && fila == 4 && columnamover == 8 && filamover == 4 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 12 && fila == 4 && columnamover == 12 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 6 && fila == 6 && columnamover == 8 && filamover == 6 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 6 && fila == 6 && columnamover == 6 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 8 && fila == 6 && columnamover == 6 && filamover == 6 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 8 && fila == 6 && columnamover == 10 && filamover == 6 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 8 && fila == 6 && columnamover == 8 && filamover == 4 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 10 && fila == 6 && columnamover == 8 && filamover == 6 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 10 && fila == 6 && columnamover == 10 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 2 && fila == 8 && columnamover == 2 && filamover == 2 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 2 && fila == 8 && columnamover == 4 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 2 && fila == 8 && columnamover == 2 && filamover == 14 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 4 && fila == 8 && columnamover == 2 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 4 && fila == 8 && columnamover == 4 && filamover == 4 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 4 && fila == 8 && columnamover == 6 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 4 && fila == 8 && columnamover == 4 && filamover == 12 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 6 && fila == 8 && columnamover == 6 && filamover == 6 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 6 && fila == 8 && columnamover == 4 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 6 && fila == 8 && columnamover == 6 && filamover == 10 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 10 && fila == 8 && columnamover == 10 && filamover == 6 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 10 && fila == 8 && columnamover == 12 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 10 && fila == 8 && columnamover == 10 && filamover == 10 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 12 && fila == 8 && columnamover == 12 && filamover == 4 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 12 && fila == 8 && columnamover == 10 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 12 && fila == 8 && columnamover == 12 && filamover == 12 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 12 && fila == 8 && columnamover == 14 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 14 && fila == 8 && columnamover == 12 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 14 && fila == 8 && columnamover == 14 && filamover == 2 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 14 && fila == 8 && columnamover == 14 && filamover == 14 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 6 && fila == 10 && columnamover == 6 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 6 && fila == 10 && columnamover == 8 && filamover == 10 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 8 && fila == 10 && columnamover == 6 && filamover == 10 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 8 && fila == 10 && columnamover == 10 && filamover == 10 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 8 && fila == 10 && columnamover == 8 && filamover == 12 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 10 && fila == 10 && columnamover == 8 && filamover == 10 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 10 && fila == 10 && columnamover == 10 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 4 && fila == 12 && columnamover == 4 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 4 && fila == 12 && columnamover == 8 && filamover == 12 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 8 && fila == 12 && columnamover == 4 && filamover == 12 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 8 && fila == 12 && columnamover == 8 && filamover == 10 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 8 && fila == 12 && columnamover == 12 && filamover == 12 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 8 && fila == 12 && columnamover == 8 && filamover == 14 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 12 && fila == 12 && columnamover == 8 && filamover == 12 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 12 && fila == 12 && columnamover == 12 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 2 && fila == 14 && columnamover == 2 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 2 && fila == 14 && columnamover == 8 && filamover == 14 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 8 && fila == 14 && columnamover == 8 && filamover == 12 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 8 && fila == 14 && columnamover == 2 && filamover == 14 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 8 && fila == 14 && columnamover == 14 && filamover == 14 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 14 && fila == 14 && columnamover == 8 && filamover == 14 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 14 && fila == 14 && columnamover == 14 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else {
			return false;
		}
	}

	if(turno==2 && Tablero[fila][columna]==fichaJ2) {
		if (columna == 2 && fila == 2 && columnamover == 8 && filamover == 2 && Tablero[filamover][columnamover]!=fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true; //b
		else if (columna == 2 && fila == 2 && columnamover == 2 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true; //j
		else if (columna == 8 && fila == 2 && columnamover == 2 && filamover == 2 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true; //a
		else if (columna == 8 && fila == 2 && columnamover == 14 && filamover == 2 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true; //c
		else if (columna == 8 && fila == 2 && columnamover == 8 && filamover == 4 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true; //e
		else if (columna == 14 && fila == 2 && columnamover == 8 && filamover == 2 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true; //b
		else if (columna == 14 && fila == 2 && columnamover == 14 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true; //o
		else if (columna == 4 && fila == 4 && columnamover == 8 && filamover == 4 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true; //e
		else if (columna == 4 && fila == 4 && columnamover == 4 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true; //k
		else if (columna == 8 && fila == 4 && columnamover == 4 && filamover == 4 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true; //d
		else if (columna == 8 && fila == 4 && columnamover == 12 && filamover == 4 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true; //f
		else if (columna == 8 && fila == 4 && columnamover == 8 && filamover == 6 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true; //h
		else if (columna == 12 && fila == 4 && columnamover == 8 && filamover == 4 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 12 && fila == 4 && columnamover == 12 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 6 && fila == 6 && columnamover == 8 && filamover == 6 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 6 && fila == 6 && columnamover == 6 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 8 && fila == 6 && columnamover == 6 && filamover == 6 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 8 && fila == 6 && columnamover == 10 && filamover == 6 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 8 && fila == 6 && columnamover == 8 && filamover == 4 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 10 && fila == 6 && columnamover == 8 && filamover == 6 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 10 && fila == 6 && columnamover == 10 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 2 && fila == 8 && columnamover == 2 && filamover == 2 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 2 && fila == 8 && columnamover == 4 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 2 && fila == 8 && columnamover == 2 && filamover == 14 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 4 && fila == 8 && columnamover == 2 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 4 && fila == 8 && columnamover == 4 && filamover == 4 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 4 && fila == 8 && columnamover == 6 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 4 && fila == 8 && columnamover == 4 && filamover == 12 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 6 && fila == 8 && columnamover == 6 && filamover == 6 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 6 && fila == 8 && columnamover == 4 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 6 && fila == 8 && columnamover == 6 && filamover == 10 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 10 && fila == 8 && columnamover == 10 && filamover == 6 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 10 && fila == 8 && columnamover == 12 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 10 && fila == 8 && columnamover == 10 && filamover == 10 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 12 && fila == 8 && columnamover == 12 && filamover == 4 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 12 && fila == 8 && columnamover == 10 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 12 && fila == 8 && columnamover == 12 && filamover == 12 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 12 && fila == 8 && columnamover == 14 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 14 && fila == 8 && columnamover == 12 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 14 && fila == 8 && columnamover == 14 && filamover == 2 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 14 && fila == 8 && columnamover == 14 && filamover == 14 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 6 && fila == 10 && columnamover == 6 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 6 && fila == 10 && columnamover == 8 && filamover == 10 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 8 && fila == 10 && columnamover == 6 && filamover == 10 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 8 && fila == 10 && columnamover == 10 && filamover == 10 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 8 && fila == 10 && columnamover == 8 && filamover == 12 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 10 && fila == 10 && columnamover == 8 && filamover == 10 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 10 && fila == 10 && columnamover == 10 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 4 && fila == 12 && columnamover == 4 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 4 && fila == 12 && columnamover == 8 && filamover == 12 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 8 && fila == 12 && columnamover == 4 && filamover == 12 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 8 && fila == 12 && columnamover == 8 && filamover == 10 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 8 && fila == 12 && columnamover == 12 && filamover == 12 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 8 && fila == 12 && columnamover == 8 && filamover == 14 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 12 && fila == 12 && columnamover == 8 && filamover == 12 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 12 && fila == 12 && columnamover == 12 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 2 && fila == 14 && columnamover == 2 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 2 && fila == 14 && columnamover == 8 && filamover == 14 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 8 && fila == 14 && columnamover == 8 && filamover == 12 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 8 && fila == 14 && columnamover == 2 && filamover == 14 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 8 && fila == 14 && columnamover == 14 && filamover == 14 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 14 && fila == 14 && columnamover == 8 && filamover == 14 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else if (columna == 14 && fila == 14 && columnamover == 14 && filamover == 8 && Tablero[filamover][columnamover] != fichaJ1 && Tablero[filamover][columnamover] != fichaJ2) return true;
		else {
			return false;
		}
	}
}
void FaseMovimiento() {
	int columna, fila, columna2, fila2;
	int posX, posY;
	if (turno == 1)
	{
		do {
			system("cls");
			Dibujar_Tablero();
			Nombre_Ficha_Tablero();
			Console::SetCursorPosition(0, 17);
			Console::ForegroundColor = ConsoleColor::White;
			do {
				cout << NameJ1 << ", Ingrese el numero de columna de su ficha: ";
				cin >> columna;
			} while (columna < 0 || columna>7);
			columna = columna * 2;
			do {
				cout << NameJ1 << ", Ingrese el numero de fila de su ficha: ";
				cin >> fila;
			} while (fila < 0 || fila>7);
			fila = fila * 2;
		} while (Tablero[fila][columna] != fichaJ1);

		if (columna == 2 && fila == 2) {
			if (Tablero[fila][columna] == fichaJ1) {
				Tablero[fila][columna] = 'a';
			}
		}
		if (columna == 8 && fila == 2) {
			if (Tablero[fila][columna] == fichaJ1) {
				Tablero[fila][columna] = 'b';
			}
		}
		if (columna == 14 && fila == 2) {
			if (Tablero[fila][columna] == fichaJ1) {
				Tablero[fila][columna] = 'c';
			}
		} //
		if (columna == 4 && fila == 4) {

			if (Tablero[fila][columna] == fichaJ1) {
				Tablero[fila][columna] = 'd';
			}
		} //
		if (columna == 8 && fila == 4) {

			if (Tablero[fila][columna] == fichaJ1) {
				Tablero[fila][columna] = 'e';
			}
		} //
		if (columna == 12 && fila == 4) {

			if (Tablero[fila][columna] == fichaJ1) {
				Tablero[fila][columna] = 'f';
			}
		} //
		if (columna == 6 && fila == 6) {

			if (Tablero[fila][columna] == fichaJ1) {
				Tablero[fila][columna] = 'g';
			}
		} //
		if (columna == 8 && fila == 6) {

			if (Tablero[fila][columna] == fichaJ1) {
				Tablero[fila][columna] = 'h';
			}
		} //
		if (columna == 10 && fila == 6) {

			if (Tablero[fila][columna] == fichaJ1) {
				Tablero[fila][columna] = 'i';
			}
		} //



		if (columna == 2 && fila == 8) {

			if (Tablero[fila][columna] == fichaJ1) {
				Tablero[fila][columna] = 'j';
			}
		}//
		if (columna == 4 && fila == 8) {

			if (Tablero[fila][columna] == fichaJ1) {
				Tablero[fila][columna] = 'k';
			}
		}//
		if (columna == 6 && fila == 8) {

			if (Tablero[fila][columna] == fichaJ1) {
				Tablero[fila][columna] = 'l';
			}
		}//
		if (columna == 10 && fila == 8) {

			if (Tablero[fila][columna] == fichaJ1) {
				Tablero[fila][columna] = 'm';
			}
		}//
		if (columna == 12 && fila == 8) {

			if (Tablero[fila][columna] == fichaJ1) {
				Tablero[fila][columna] = 'n';
			}
		}//
		if (columna == 14 && fila == 8) {

			if (Tablero[fila][columna] == fichaJ1) {
				Tablero[fila][columna] = 'o';
			}
		}//

		if (columna == 6 && fila == 10) {

			if (Tablero[fila][columna] == fichaJ1) {
				Tablero[fila][columna] = 'p';
			}
		}//
		if (columna == 8 && fila == 10) {

			if (Tablero[fila][columna] == fichaJ1) {
				Tablero[fila][columna] = 'q';
			}
		}//
		if (columna == 10 && fila == 10) {

			if (Tablero[fila][columna] == fichaJ1) {
				Tablero[fila][columna] = 'r';
			}
		}//

		if (columna == 4 && fila == 12) {

			if (Tablero[fila][columna] == fichaJ1) {
				Tablero[fila][columna] = 's';
			}
		}//
		if (columna == 8 && fila == 12) {

			if (Tablero[fila][columna] == fichaJ1) {
				Tablero[fila][columna] = 't';
			}
		}//
		if (columna == 12 && fila == 12) {

			if (Tablero[fila][columna] == fichaJ1) {
				Tablero[fila][columna] = 'u';
			}
		}//


		if (columna == 2 && fila == 14) {

			if (Tablero[fila][columna] == fichaJ1) {
				Tablero[fila][columna] = 'v';
			}
		}//
		if (columna == 8 && fila == 14) {

			if (Tablero[fila][columna] == fichaJ1) {
				Tablero[fila][columna] = 'w';
			}
		}//
		if (columna == 14 && fila == 14) {

			if (Tablero[fila][columna] == fichaJ1) {
				Tablero[fila][columna] = 'x';
			}
		}//

		do {
			do {
				cout << NameJ1 << ", Ingrese el numero de columna a la que quiere mover: ";
				cin >> columna2;
			} while (columna2 < 0 || columna2>7);
			columna2 = columna2 * 2;
			do {
				cout << NameJ1 << ", Ingrese el numero de fila a la que quiere mover: ";
				cin >> fila2;
			} while (fila2 < 0 || fila2>7);
			fila2 = fila2 * 2;
		} while (ValidarMovimiento(columna,fila,columna2,fila2)==false);

		Tablero[fila2][columna2] = fichaJ1;
		turno = 2;
	}
	if (turno == 2)
	{
		do {
			system("cls");
			Dibujar_Tablero();
			Nombre_Ficha_Tablero();
			Console::SetCursorPosition(0, 17);
			Console::ForegroundColor = ConsoleColor::White;
			do {
				cout << NameJ2 << ", Ingrese el numero de columna de su ficha: ";
				cin >> columna;
			} while (columna < 0 || columna>7);
			columna = columna * 2;
			do {
				cout << NameJ2 << ", Ingrese el numero de fila de su ficha: ";
				cin >> fila;
			} while (fila < 0 || fila>7);
			fila = fila * 2;
		} while (Tablero[fila][columna] != fichaJ2);

		if (columna == 2 && fila == 2) {
			if (Tablero[fila][columna] == fichaJ2) {
				Tablero[fila][columna] = 'a';
			}
		}
		if (columna == 8 && fila == 2) {
			if (Tablero[fila][columna] == fichaJ2) {
				Tablero[fila][columna] = 'b';
			}
		}
		if (columna == 14 && fila == 2) {
			if (Tablero[fila][columna] == fichaJ2) {
				Tablero[fila][columna] = 'c';
			}
		} //
		if (columna == 4 && fila == 4) {

			if (Tablero[fila][columna] == fichaJ2) {
				Tablero[fila][columna] = 'd';
			}
		} //
		if (columna == 8 && fila == 4) {

			if (Tablero[fila][columna] == fichaJ2) {
				Tablero[fila][columna] = 'e';
			}
		} //
		if (columna == 12 && fila == 4) {

			if (Tablero[fila][columna] == fichaJ2) {
				Tablero[fila][columna] = 'f';
			}
		} //
		if (columna == 6 && fila == 6) {

			if (Tablero[fila][columna] == fichaJ2) {
				Tablero[fila][columna] = 'g';
			}
		} //
		if (columna == 8 && fila == 6) {

			if (Tablero[fila][columna] == fichaJ2) {
				Tablero[fila][columna] = 'h';
			}
		} //
		if (columna == 10 && fila == 6) {

			if (Tablero[fila][columna] == fichaJ2) {
				Tablero[fila][columna] = 'i';
			}
		} //



		if (columna == 2 && fila == 8) {

			if (Tablero[fila][columna] == fichaJ2) {
				Tablero[fila][columna] = 'j';
			}
		}//
		if (columna == 4 && fila == 8) {

			if (Tablero[fila][columna] == fichaJ2) {
				Tablero[fila][columna] = 'k';
			}
		}//
		if (columna == 6 && fila == 8) {

			if (Tablero[fila][columna] == fichaJ2) {
				Tablero[fila][columna] = 'l';
			}
		}//
		if (columna == 10 && fila == 8) {

			if (Tablero[fila][columna] == fichaJ2) {
				Tablero[fila][columna] = 'm';
			}
		}//
		if (columna == 12 && fila == 8) {

			if (Tablero[fila][columna] == fichaJ2) {
				Tablero[fila][columna] = 'n';
			}
		}//
		if (columna == 14 && fila == 8) {

			if (Tablero[fila][columna] == fichaJ2) {
				Tablero[fila][columna] = 'o';
			}
		}//

		if (columna == 6 && fila == 10) {

			if (Tablero[fila][columna] == fichaJ2) {
				Tablero[fila][columna] = 'p';
			}
		}//
		if (columna == 8 && fila == 10) {

			if (Tablero[fila][columna] == fichaJ2) {
				Tablero[fila][columna] = 'q';
			}
		}//
		if (columna == 10 && fila == 10) {

			if (Tablero[fila][columna] == fichaJ2) {
				Tablero[fila][columna] = 'r';
			}
		}//

		if (columna == 4 && fila == 12) {

			if (Tablero[fila][columna] == fichaJ2) {
				Tablero[fila][columna] = 's';
			}
		}//
		if (columna == 8 && fila == 12) {

			if (Tablero[fila][columna] == fichaJ2) {
				Tablero[fila][columna] = 't';
			}
		}//
		if (columna == 12 && fila == 12) {

			if (Tablero[fila][columna] == fichaJ2) {
				Tablero[fila][columna] = 'u';
			}
		}//


		if (columna == 2 && fila == 14) {

			if (Tablero[fila][columna] == fichaJ2) {
				Tablero[fila][columna] = 'v';
			}
		}//
		if (columna == 8 && fila == 14) {

			if (Tablero[fila][columna] == fichaJ2) {
				Tablero[fila][columna] = 'w';
			}
		}//
		if (columna == 14 && fila == 14) {

			if (Tablero[fila][columna] == fichaJ2) {
				Tablero[fila][columna] = 'x';
			}
		}//

		do {
			do {
				cout << NameJ2 << ", Ingrese el numero de columna a la que quiere mover: ";
				cin >> columna2;
			} while (columna2 < 0 || columna2>7);
			columna2 = columna2 * 2;
			do {
				cout << NameJ2 << ", Ingrese el numero de fila a la que quiere mover: ";
				cin >> fila2;
			} while (fila2 < 0 || fila2>7);
			fila2 = fila2 * 2;
		} while (ValidarMovimiento(columna, fila, columna2, fila2)==false);

		Tablero[fila2][columna2] = fichaJ2;
		turno = 1;
	}
}

void Controladora() {
	bool validador = false;
	if (validador == false) {
		if (contadorficha1 == 0 && contadorficha2 == 0) {
			validador = true;
		}
		else {
			Colocar_Ficha();
			Comer();
		}
	}
	if (validador == true) {
		Comer();
		FaseMovimiento();

	}


}

void Tablero_Posibles() {
	if (Validar_Comer() == 1) {
		cout << "---------------------------";
		cout << "| FICHAS A ELIMINAR:      |";
		cout << "| ";
	}
}
//FALTA VALIDAR_COMER(),FaseMovimiento(), Comer(), Restart_Game()



//Restart_Game(){}

int main() {
	int opcion;
	
	int endgame = 1;
	while (endgame != 0)
	{
		opcion = Menu();
		switch (opcion)
		{
		case 1:
			rlutil::cls();
			cout << "INICIANDO JUEGO.....";
			rlutil::msleep(2000);
			Start_Game();
			turno = Throw_Dado();
			Menu_Colores();
			while (true) {
				Controladora();
			}

			break;
		case 2:
			Opcion_Como_Jugar();
			break;
		case 3:
			Opcion_Creditos();
			break;
		case 4:
			endgame = 0;
			break;
		default:
			break;
		}
	}

	system("cls");
	cout << "CERRANDO JUEGO....";
	Sleep(3000);
	return 0;
}