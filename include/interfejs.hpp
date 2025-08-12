#ifndef interfejs_hpp
#define interfejs_hpp

#include <iostream>
#include "game.hpp"

class interfejs {
	int turn;
	int a_wals;
	int b_wals;
public:
	interfejs();
	/**
 * Zwraca numer bie��cego gracza.
 * @return Numer gracza (1 lub 2).
 */
	int get_turn();
	/**
 * Zwraca liczb� nie wykorzystanych scian gracza A.
 * @return Liczba pozosta�ych scian.
 */
	int get_a_wals();
	/**
 * Zwraca liczb� nie wykorzystanych scian gracza B.
 * @return Liczba pozosta�ych scian.
 */
	int get_b_wals();

	/**
 * Zmniejsza liczb� dost�pnych �cian dla danego gracza.
 *
 * @param gracz Numer gracza (1 lub 2).
 */
	void zabierz_sciane(int gracz);
	/**
 * Zmienia kolejno�� graczy.
 */
	void change_turn();


	virtual int move(game* gra) = 0;
	virtual int wal(game* gra) = 0;

};

class user:public interfejs {
public:
	/**
 * Pobiera ruch u�ytkownika i wykonuje go w grze.
 *
 * @param gra Wska�nik na obiekt gry.
 * @return 1 je�li ruch zosta� wykonany poprawnie, 0 w przeciwnym razie.
 */
	int move(game *gra);
	/**
 * Stawia �cian� w grze.
 *
 * @param gra Wska�nik na obiekt gry.
 * @return 1 je�li �ciana zosta�a postawiona poprawnie, 0 w przeciwnym razie.
 */
	int wal(game* gra);
};

class robot:public interfejs {
public:
	/**
 * Robot wykonuje ruch w grze.
 *
 * @param gra Wska�nik na obiekt gry.
 * @return 1.
 */
	int move(game* gra);
	/**
 * Robot stawia �cian� w grze.
 *
 * @param gra Wska�nik na obiekt gry.
 * @return 1.
 */
	int wal(game* gra);
};

#endif