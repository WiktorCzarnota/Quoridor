#ifndef game_hpp
#define game_hpp

#include <iostream>
#include "player.hpp"

class game {
public:
	int wals[8][8];//tablica zawieraj¹ce jakie sciany zosta³y postawione
	// 1 = vertykalna, 2 = horyzontalna, 0 = brak sciany

	player a;//dane gracza A
	player b;//dane gracza B

	game();
	game(game &orginal);

	/**
 * Dodaje œcianê na planszy.
 *
 * @param rodzaj Typ œciany (1 - pionowa, 2 - pozioma).
 * @param wiersz Wiersz w tablicy `wals`.
 * @param kolumna Kolumna w tablicy `wals`.
 */
	void add_wals(int rodzaj, int x, int y);
	/**
 * Aktualizuje pozycjê pionka gracza na planszy.
 *
 * @param wchich_player Numer gracza (1 lub 2).
 * @param x Nowa pozycja X pionka.
 * @param y Nowa pozycja Y pionka.
 */
	void player_move(int rodzaj, int kolumna, int wiersz);

	/**
 * Sprawdza, czy ruch gracza jest dozwolony.
 *
 * @param posx Nowa pozycja X pionka.
 * @param posy Nowa pozycja Y pionka.
 * @param gracz Numer gracza (1 lub 2).
 * @return True, jeœli ruch jest dozwolony, false w przeciwnym razie.
 */
	bool check_move(int posx,int posy,int gracz);
	/**
 * Sprawdza, czy œciana blokuje ruch gracza.
 *
 * @param posx Nowa pozycja X pionka.
 * @param posy Nowa pozycja Y pionka.
 * @param gracz Numer gracza (1 lub 2).
 * @return True, jeœli œciana blokuje ruch, false w przeciwnym razie.
 */
	bool check_wal(int rodzaj,int posx, int posy, game *gra);

	/**
 * Sprawdza, czy któryœ z graczy wygra³.
 *
 * @return 1 jeœli gracz 1 wygra³, 2 jeœli gracz 2 wygra³, 0 jeœli nikt nie wygra³.
 */
	int winn();

	/**
 * Sprawdza, czy œciana blokuje ruch gracza.
 *
 * @param posx Nowa pozycja X pionka gracza.
 * @param posy Nowa pozycja Y pionka gracza.
 * @param gracz Numer gracza (1 lub 2).
 * @return True, jeœli œciana blokuje ruch, False w przeciwnym razie.
 */
	bool blocked_wall(int posx, int posy, int gracz);
	/**
 * Sprawdza, czy inny pionek znajduje siê w odleg³oœci jednego pola od
 * pionka gracza.
 *
 * @param posx Nowa pozycja X pionka gracza.
 * @param posy Nowa pozycja Y pionka gracza.
 * @param gracz Numer gracza (1 lub 2).
 * @return True, jeœli inny pionek jest w odleg³oœci jednego pola, False w przeciwnym razie.
 */
	bool gracz_blisko(int posx, int posy, int gracz);
	/**
 * Sprawdza, czy pionek mo¿e wykonaæ ruch o jedno pole.
 *
 * @param posx Nowa pozycja X pionka gracza.
 * @param posy Nowa pozycja Y pionka gracza.
 * @param gracz Numer gracza (1 lub 2).
 * @return True, jeœli ruch o jedno pole jest mo¿liwy, False w przeciwnym razie.
 */
	bool jeden_krok(int posx, int posy, int gracz);
	/**
 * Nieudana funkcja do sprawdzania czy nie blokuje zwyciêstwa 
 * 
 * @return False, nic nie robi¹c
 */
	bool box_gaming(int rodzaj, int posx, int posy,game* gra);

	friend class plansza;
};
#endif