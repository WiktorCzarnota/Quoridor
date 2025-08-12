#ifndef plansza_hpp
#define plansza_hpp

#include <stdio.h>
#include <iostream>
#include "game.hpp"
#include "interfejs.hpp"

// Ni�ej jest wygl�d stosowany w grze

#define EMPTY 0xFF		// czarny block
#define BLOCK 176		// pole
#define ALPHA 120		// gracz 1
#define BETHA 121		// gracz 2
#define VERTYCAL 186	// sciana vertykalan
#define HORYZONTAL 205	// sciana horyzontalna

class plansza {
	char sciany_v[9][9];		// tablica ze znakami scianami vertykalnymi 
	char sciany_h[9][9];		// tablica ze znakimi scianami horyzontalnymi 
	char srodek_pola[9][9];		// tablica ze znakimi u�ywanymi na �rodku pola 
public:

	/**
 * @brief Drukuje wiersz planszy gry z uwzgl�dnieniem p�l, pionk�w i �cian.
 *
 * Funkcja `board_line` drukuje wiersz planszy gry z uwzgl�dnieniem p�l gry (BLOCK),
 * pionk�w ('a' i 'b') oraz �cian pionowych (VERTYCAL).
 *
 * @param kwadrat Rozmiar bloku kwadratowego na planszy.
 * @param nr_wiersza Numer wiersza, dla kt�rego drukowany jest wiersz planszy.
 * @param gra Wska�nik na obiekt game zawieraj�cy stan gry.
 */
	void board_line(int kwadrat, int nr_wiersza, game *gra);

	/**
 * @brief Drukuje wiersz przerwy na planszy gry.
 *
 * Funkcja `przerwa` drukuje wiersz przerwy na planszy gry, uwzgl�dniaj�c �ciany
 * pionowe i poziome oraz pola puste.
 *
 * @param kwadrat Rozmiar bloku kwadratowego na planszy.
 * @param nr_wiersza Numer wiersza, dla kt�rego drukowany jest wiersz przerwy.
 * @param gra Wska�nik na obiekt game zawieraj�cy stan gry.
 */
	void przerwa(int kwadrat, int nr_wiersza, game *gra);

	/** @brief Drukuje nag��wek planszy (litery A-I). */
	void naglowek();

	/**
 * @brief Rysuje plansz� gry.
 *
 * Funkcja `board` rysuje plansz� gry na ekranie, uwzgl�dniaj�c pola gry (BLOCK),
 * pionki ('a' i 'b'), �ciany pionowe (VERTYCAL) i poziome (HORYZONTAL).
 * Wykorzystuje funkcje `naglowek`, `board_line`, `przerwa` i `poka_sciane` do
 * wygenerowania odpowiednich element�w graficznych.
 *
 * @param gra Wska�nik na obiekt game zawieraj�cy stan gry.
 * @param ui Wska�nik na obiekt interfejs zawieraj�cy funkcje interfejsu u�ytkownika.
 * @return Zwraca 0.
 */
	int board(game *gra, interfejs *ui);

	/** @brief Aktualizuje stan planszy gry.
  Funkcja update odpowiada za aktualizowanie stanu planszy gry w oparciu o bie��c� pozycj�
  element�w gry (pionk�w 'a' i 'b') oraz rozmieszczenie �cian.
  @param gra Wska�nik na obiekt game zawieraj�cy stan gry.
*/
	void update(game *gra);

	/**
 * @brief Wy�wietla informacje o �cianach i turze gracza.
 *
 * Funkcja `poka_sciane` wy�wietla na ekranie informacje o ilo�ci dost�pnych �cian
 * dla ka�dego gracza ('x' i 'y') oraz o tym, kt�ry gracz ma aktualnie tur�.
 *
 * @param ui Wska�nik na obiekt interfejs zawieraj�cy funkcje interfejsu u�ytkownika.
 */
	void poka_sciane(interfejs *ui);

	plansza();		//konstruktor
};
#endif