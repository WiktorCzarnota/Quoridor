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
 * Zwraca numer bie¿¹cego gracza.
 * @return Numer gracza (1 lub 2).
 */
	int get_turn();
	/**
 * Zwraca liczbê nie wykorzystanych scian gracza A.
 * @return Liczba pozosta³ych scian.
 */
	int get_a_wals();
	/**
 * Zwraca liczbê nie wykorzystanych scian gracza B.
 * @return Liczba pozosta³ych scian.
 */
	int get_b_wals();

	/**
 * Zmniejsza liczbê dostêpnych œcian dla danego gracza.
 *
 * @param gracz Numer gracza (1 lub 2).
 */
	void zabierz_sciane(int gracz);
	/**
 * Zmienia kolejnoœæ graczy.
 */
	void change_turn();


	virtual int move(game* gra) = 0;
	virtual int wal(game* gra) = 0;

};

class user:public interfejs {
public:
	/**
 * Pobiera ruch u¿ytkownika i wykonuje go w grze.
 *
 * @param gra WskaŸnik na obiekt gry.
 * @return 1 jeœli ruch zosta³ wykonany poprawnie, 0 w przeciwnym razie.
 */
	int move(game *gra);
	/**
 * Stawia œcianê w grze.
 *
 * @param gra WskaŸnik na obiekt gry.
 * @return 1 jeœli œciana zosta³a postawiona poprawnie, 0 w przeciwnym razie.
 */
	int wal(game* gra);
};

class robot:public interfejs {
public:
	/**
 * Robot wykonuje ruch w grze.
 *
 * @param gra WskaŸnik na obiekt gry.
 * @return 1.
 */
	int move(game* gra);
	/**
 * Robot stawia œcianê w grze.
 *
 * @param gra WskaŸnik na obiekt gry.
 * @return 1.
 */
	int wal(game* gra);
};

#endif