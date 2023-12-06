//#include <iostream>
//#include <conio.h>
//#include "rlutil.h"
//using namespace std;
//using namespace System;
//
//char board[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
//string nombreJ1, nombreJ2;
//char ficha, fichaJ1, fichaJ2;
//int movimientos = 0;
//
//enum opociciones {
//	_opcion1 = 0,
//	_opcion2 = 1,
//	_opcion3 = 2,
//	_Salir = 3
//};
//
//void Show_Background(const char *text, int posx,int posy,bool selected) {
//	if (selected) {
//		rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
//	}
//	else {
//		rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
//	}
//	rlutil::locate(posx, posy);
//	cout << text << endl;
//	rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
//}
//
//void Iniciar_Juego() {
//	rlutil::cls();
//	Console::CursorVisible = true;
//	Console::ForegroundColor = ConsoleColor::Cyan;
//	cout << "BIENVENIDO AL JUEGO DE TRES EN RAYA" << endl;
//	cout << endl;
//	cout << "Nombre del Jugador 1: "; cin >> nombreJ1;
//	cout << "\nNombre del Jugador 2: "; cin >> nombreJ2; cout << endl;;
//	Console::ForegroundColor = ConsoleColor::Yellow;
//	while (true)
//	{
//		rlutil::cls();
//		cout << nombreJ1 << ", Elija una ficha X/O: "; cin >> ficha;
//		if (toupper(ficha) == 'X') {
//			fichaJ1 = 'X';
//			fichaJ2 = 'O';
//			break;
//		}
//		else if (toupper(ficha) == 'O') {
//			fichaJ1 = 'O';
//			fichaJ2 = 'X';
//			break;
//		}
//		else cout << "Por favor elija una ficha valida.." << endl;
//
//	}
//}
//void Print_Board() {
//	system("cls");
//	Console::ForegroundColor = ConsoleColor::Blue;
//	cout << "--------------------" << endl;
//	cout << "   " << "   |   " << "   |   " << endl;
//	cout << " 1 " << board[0] << "  | 2 " << board[1] << "  | 3 " << board[2] << endl;
//	cout << "   " << "   |   " << "   |   " << endl;
//	cout << "--------------------" << endl;
//	cout << "   " << "   |   " << "   |   " << endl;
//	cout << " 4 " << board[3] << "  | 5 " << board[4] << "  | 6 " << board[5] << endl;
//	cout << "   " << "   |   " << "   |   " << endl;
//	cout << "--------------------" << endl;
//	cout << "   " << "   |   " << "   |   " << endl;
//	cout << " 7 " << board[6] << "  | 8 " << board[7] << "  | 9 " << board[8] << endl;
//	cout << "   " << "   |   " << "   |   " << endl;
//	cout << "--------------------" << endl;
//	Console::ForegroundColor = ConsoleColor::White;
//}
//void Print_Turn(int* p) {
//	if (*p == 1) {
//		Console::ForegroundColor = ConsoleColor::Cyan;
//		Console::SetCursorPosition(30, 1);
//		cout << "Turno: " << nombreJ1;
//	}
//
//	if (*p == 2) {
//		Console::ForegroundColor = ConsoleColor::Cyan;
//		Console::SetCursorPosition(30, 1);
//		cout << "Turno: " << nombreJ2;
//	}
//}
//void Play(int* turno) {
//	int jugada;
//	if (*turno == 1) {
//		while (true) {
//			Console::ForegroundColor = ConsoleColor::Green;
//			Console::SetCursorPosition(1, 15);
//			cout << "\nIngresa la posicion: "; cin >> jugada;
//			if (jugada == 1 && board[0] == ' ') { board[0] = fichaJ1; break; }
//			else if (jugada == 2 && board[1] == ' ') { board[1] = fichaJ1; break; }
//			else if (jugada == 3 && board[2] == ' ') { board[2] = fichaJ1; break; }
//			else if (jugada == 4 && board[3] == ' ') { board[3] = fichaJ1; break; }
//			else if (jugada == 5 && board[4] == ' ') { board[4] = fichaJ1; break; }
//			else if (jugada == 6 && board[5] == ' ') { board[5] = fichaJ1; break; }
//			else if (jugada == 7 && board[6] == ' ') { board[6] = fichaJ1; break; }
//			else if (jugada == 8 && board[7] == ' ') { board[7] = fichaJ1; break; }
//			else if (jugada == 9 && board[8] == ' ') { board[8] = fichaJ1; break; }
//			else {
//				cout << "La posicion ingresada esta ocupada, por favor elija otra.." << endl;
//				_sleep(500);
//				system("cls");
//				Print_Board();
//				Print_Turn(turno);
//			}
//		}
//	}
//
//	if (*turno == 2) {
//		while (true) {
//			Console::ForegroundColor = ConsoleColor::Green;
//			Console::SetCursorPosition(1, 15);
//			cout << "\nIngresa la posicion: "; cin >> jugada;
//			if (jugada == 1 && board[0] == ' ') { board[0] = fichaJ2; break; }
//			else if (jugada == 2 && board[1] == ' ') { board[1] = fichaJ2; break; }
//			else if (jugada == 3 && board[2] == ' ') { board[2] = fichaJ2; break; }
//			else if (jugada == 4 && board[3] == ' ') { board[3] = fichaJ2; break; }
//			else if (jugada == 5 && board[4] == ' ') { board[4] = fichaJ2; break; }
//			else if (jugada == 6 && board[5] == ' ') { board[5] = fichaJ2; break; }
//			else if (jugada == 7 && board[6] == ' ') { board[6] = fichaJ2; break; }
//			else if (jugada == 8 && board[7] == ' ') { board[7] = fichaJ2; break; }
//			else if (jugada == 9 && board[8] == ' ') { board[8] = fichaJ2; break; }
//			else {
//				cout << "La posicion ingresada esta ocupada, por favor elija otra.." << endl;
//				_sleep(500);
//				system("cls");
//				Print_Board();
//				Print_Turn(turno);
//			}
//		}
//	}
//	*turno += 1;
//	if (*turno > 2)*turno = 1;
//	Console::ForegroundColor = ConsoleColor::White;
//}
//int Win_Check() {
//	//J1 HORIZONTAL
//	if (board[0] == fichaJ1 && board[1] == fichaJ1 && board[2] == fichaJ1) { return 1; }
//	else if (board[3] == fichaJ1 && board[4] == fichaJ1 && board[5] == fichaJ1) { return 1; }
//	else if (board[6] == fichaJ1 && board[7] == fichaJ1 && board[8] == fichaJ1) { return 1; }
//	//J1 VERTICAL
//	else if (board[0] == fichaJ1 && board[3] == fichaJ1 && board[6] == fichaJ1) { return 1; }
//	else if (board[1] == fichaJ1 && board[4] == fichaJ1 && board[7] == fichaJ1) { return 1; }
//	else if (board[2] == fichaJ1 && board[5] == fichaJ1 && board[8] == fichaJ1) { return 1; }
//	//J1 DIAGONAL
//	else if (board[0] == fichaJ1 && board[4] == fichaJ1 && board[8] == fichaJ1) { return 1; }
//	else if (board[2] == fichaJ1 && board[4] == fichaJ1 && board[6] == fichaJ1) { return 1; }
//
//	//=======================================================================================
//
//	//J2 HORIZONTAL
//	if (board[0] == fichaJ2 && board[1] == fichaJ2 && board[2] == fichaJ2) { return 2; }
//	else if (board[3] == fichaJ2 && board[4] == fichaJ2 && board[5] == fichaJ2) { return 2; }
//	else if (board[6] == fichaJ2 && board[7] == fichaJ2 && board[8] == fichaJ2) { return 2; }
//	//J2 VERTICAL
//	else if (board[0] == fichaJ2 && board[3] == fichaJ2 && board[6] == fichaJ2) { return 2; }
//	else if (board[1] == fichaJ2 && board[4] == fichaJ2 && board[7] == fichaJ2) { return 2; }
//	else if (board[2] == fichaJ2 && board[5] == fichaJ2 && board[8] == fichaJ2) { return 2; }
//	//J2 DIAGONAL
//	else if (board[0] == fichaJ2 && board[4] == fichaJ2 && board[8] == fichaJ2) { return 2; }
//	else if (board[2] == fichaJ2 && board[4] == fichaJ2 && board[6] == fichaJ2) { return 2; }
//
//	if (movimientos >= 9) { return 3; }
//}
//void Win_Banner(int* p) {
//	Console::ForegroundColor = ConsoleColor::Red;
//	if (*p == 1) {
//		cout << "\n::::::::FIN DEL JUEGO:::::::" << endl;
//		cout << "\nGANADOR: " << nombreJ1;
//	}
//	else if (*p == 2) {
//		cout << "\n::::::::FIN DEL JUEGO:::::::" << endl;
//		cout << "\nGANADOR: " << nombreJ2;
//	}
//	else {
//		cout << "\n::::::::FIN DEL JUEGO:::::::" << endl;
//		cout << "\nEMPATE MAMAGUEVO";
//	}
//}
//void Reset_Board() {
//	for (int i = 0; i < 9; i++) {
//		board[i] = ' ';
//	}
//	movimientos = 0;
//}
//void Opcion2() {
//	rlutil::cls();
//	cout << "TRES EN RAYA/TIC TAC TOE" << endl << endl;
//	cout << "CREADOR: JOSEPH ALEXIS HUAMANI MANDUJANO" << endl;
//	cout << "CODIGO: U20221A133" << endl;
//	cout << "NICKNAME: HACKER PRO NERKSITO MASNAKY" << endl;
//	cout << "ENTER PARA VOLVER AL MENU.....";
//	rlutil::anykey();
//	rlutil::cls();
//}
//void Opcion3() {
//	rlutil::cls();
//	cout << ":::::::::COMO JUGAR::::::::" << endl << endl;
//	cout << "1. EL PRIMERO EN LLEGAR A FORMA 3 X/O\nYA SEA HORIZONTAL O VERTICAL O DIAGONAL GANA" << endl;
//	cout << "2. CHAU" << endl;
//	cout << "Enter para volver al menu";
//	rlutil::anykey();
//	rlutil::cls();
//}
//
//int main() {
//	int op = 1;
//	int y = 0;
//	int turno = 1;
//	int controlador;
//	char opcion;
//
//
//	do {
//		rlutil::setBackgroundColor(rlutil::COLOR::GREEN);
//		rlutil::setColor(rlutil::COLOR::WHITE);
//		rlutil::locate(28, 5);
//		cout << "::::TRES EN RAYA/TIC TAC TOE::::" << endl;
//		rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
//		rlutil::setColor(rlutil::COLOR::WHITE);
//		Console::CursorVisible = FALSE;
//		Show_Background("JUGAR ", 30, 10, y == _opcion1);
//		Show_Background("COMO JUGAR ", 30, 11, y == _opcion2);
//		Show_Background("CREDITOS ", 30, 12, y == _opcion3);
//		Show_Background("SALIR ", 30, 13, y == _Salir);
//		rlutil::locate(28, 10 + y);
//		cout << char(175) << endl;
//
//		int key = rlutil::getkey();
//		switch (key)
//		{
//		case 14: {//UP
//			rlutil::locate(28, 10 + y);
//			cout << " " << endl;
//			y--;
//			if (y < 0) y = 0;
//			break;
//		}
//		case 15:
//			rlutil::locate(28, 10 + y);
//			cout << " " << endl;
//			y++;
//			if (y > 3) y = 3;
//			break;
//		case 1:
//			if (y == 0) {
//				Reset_Board();
//				Iniciar_Juego();
//				while (true)
//				{
//					//Dibujar_Tablero();
//					Print_Board();
//					Print_Turn(&turno);
//					//jugar(turno);
//					Play(&turno);
//					Print_Board();
//					movimientos++;
//					controlador = Win_Check();
//					if (controlador == 1 || controlador == 2 || controlador == 3) {
//						Win_Banner(&controlador);
//						do {
//							Console::ForegroundColor = ConsoleColor::Gray;
//							cout << "\n\nDeseas volvere a jugar? Y/N: "; cin >> opcion;
//						} while (toupper(opcion) != 'Y' && toupper(opcion) != 'N');
//						if (toupper(opcion) == 'N') { rlutil::cls(); break; }
//						else {
//							Reset_Board();
//							continue;
//						}
//					}
//				}
//			}
//
//			if (y == 1) {
//				Opcion3();
//			}
//
//			if (y == 2) {
//				Opcion2();
//			}
//
//			if (y == 3) {
//				op = 0;
//			}
//			break;
//		default:
//			break;
//		}
//
//
//
//	} while (op != 0);
//}