#ifndef player_hpp
#define player_hpp
#include <iostream>

class player {
	int posX, posY;// pozycja gracza na planszy
	char id;// jakim znakiem ASCII ma byc przedstawiony pionek
public:
	/** @brief Zwraca wspó³rzêdn¹ X gracza.
  * Metoda zwraca aktualn¹ wartoœæ wspó³rzêdnej X obiektu typu player.
  * @return Zwraca wartoœæ typu int reprezentuj¹c¹ wspó³rzêdn¹ X gracza.
  */
	int get_posX();
	/** @brief Zwraca wspó³rzêdn¹ Y gracza.
  * Metoda zwraca aktualn¹ wartoœæ wspó³rzêdnej Y obiektu typu player.
  * @return Zwraca wartoœæ typu int reprezentuj¹c¹ wspó³rzêdn¹ Y gracza.
  */
	int get_posY();
	/** @brief Zwraca identyfikator gracza.
  * Metoda zwraca unikalny identyfikator gracza.
  * @return Zwraca wartoœæ typu char reprezentuj¹c¹ identyfikator gracza.
  */
	char get_id();
	/** @brief Ustawia pozycjê gracza.
  * Metoda ustawia wspó³rzêdne X i Y obiektu typu player.
  * @param[int] x Nowa wspó³rzêdna X gracza.
  * @param[int] y Nowa wspó³rzêdna Y gracza.
  */
	void set_pos(int x, int y);
	/** @brief Ustawia identyfikator gracza.
  * Metoda ustawia literowy identyfikator gracza.
  * @param indyk Nowy identyfikator gracza (literka).
  */
	void set_id(char indyk);

	player();						//konstruktor
	player(char i, int x, int y);	//konstruktor z parametrami
};
#endif