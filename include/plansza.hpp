#ifndef plansza_hpp
#define plansza_hpp

#include <stdio.h>
#include <iostream>
#include "game.hpp"
#include "interfejs.hpp"

// Ni¿ej jest wygl¹d stosowany w grze

#define EMPTY 0xFF		// czarny block
#define BLOCK 176		// pole
#define ALPHA 120		// gracz 1
#define BETHA 121		// gracz 2
#define VERTYCAL 186	// sciana vertykalan
#define HORYZONTAL 205	// sciana horyzontalna

class plansza {
	char sciany_v[9][9];		// tablica ze znakami scianami vertykalnymi 
	char sciany_h[9][9];		// tablica ze znakimi scianami horyzontalnymi 
	char srodek_pola[9][9];		// tablica ze znakimi u¿ywanymi na œrodku pola 
public:

	/**
 * @brief Drukuje wiersz planszy gry z uwzglêdnieniem pól, pionków i œcian.
 *
 * Funkcja `board_line` drukuje wiersz planszy gry z uwzglêdnieniem pól gry (BLOCK),
 * pionków ('a' i 'b') oraz œcian pionowych (VERTYCAL).
 *
 * @param kwadrat Rozmiar bloku kwadratowego na planszy.
 * @param nr_wiersza Numer wiersza, dla którego drukowany jest wiersz planszy.
 * @param gra WskaŸnik na obiekt game zawieraj¹cy stan gry.
 */
	void board_line(int kwadrat, int nr_wiersza, game *gra);

	/**
 * @brief Drukuje wiersz przerwy na planszy gry.
 *
 * Funkcja `przerwa` drukuje wiersz przerwy na planszy gry, uwzglêdniaj¹c œciany
 * pionowe i poziome oraz pola puste.
 *
 * @param kwadrat Rozmiar bloku kwadratowego na planszy.
 * @param nr_wiersza Numer wiersza, dla którego drukowany jest wiersz przerwy.
 * @param gra WskaŸnik na obiekt game zawieraj¹cy stan gry.
 */
	void przerwa(int kwadrat, int nr_wiersza, game *gra);

	/** @brief Drukuje nag³ówek planszy (litery A-I). */
	void naglowek();

	/**
 * @brief Rysuje planszê gry.
 *
 * Funkcja `board` rysuje planszê gry na ekranie, uwzglêdniaj¹c pola gry (BLOCK),
 * pionki ('a' i 'b'), œciany pionowe (VERTYCAL) i poziome (HORYZONTAL).
 * Wykorzystuje funkcje `naglowek`, `board_line`, `przerwa` i `poka_sciane` do
 * wygenerowania odpowiednich elementów graficznych.
 *
 * @param gra WskaŸnik na obiekt game zawieraj¹cy stan gry.
 * @param ui WskaŸnik na obiekt interfejs zawieraj¹cy funkcje interfejsu u¿ytkownika.
 * @return Zwraca 0.
 */
	int board(game *gra, interfejs *ui);

	/** @brief Aktualizuje stan planszy gry.
  Funkcja update odpowiada za aktualizowanie stanu planszy gry w oparciu o bie¿¹c¹ pozycjê
  elementów gry (pionków 'a' i 'b') oraz rozmieszczenie œcian.
  @param gra WskaŸnik na obiekt game zawieraj¹cy stan gry.
*/
	void update(game *gra);

	/**
 * @brief Wyœwietla informacje o œcianach i turze gracza.
 *
 * Funkcja `poka_sciane` wyœwietla na ekranie informacje o iloœci dostêpnych œcian
 * dla ka¿dego gracza ('x' i 'y') oraz o tym, który gracz ma aktualnie turê.
 *
 * @param ui WskaŸnik na obiekt interfejs zawieraj¹cy funkcje interfejsu u¿ytkownika.
 */
	void poka_sciane(interfejs *ui);

	plansza();		//konstruktor
};
#endif