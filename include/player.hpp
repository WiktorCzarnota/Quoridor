#ifndef player_hpp
#define player_hpp
#include <iostream>

class player {
	int posX, posY;// pozycja gracza na planszy
	char id;// jakim znakiem ASCII ma byc przedstawiony pionek
public:
	/** @brief Zwraca wsp�rz�dn� X gracza.
  * Metoda zwraca aktualn� warto�� wsp�rz�dnej X obiektu typu player.
  * @return Zwraca warto�� typu int reprezentuj�c� wsp�rz�dn� X gracza.
  */
	int get_posX();
	/** @brief Zwraca wsp�rz�dn� Y gracza.
  * Metoda zwraca aktualn� warto�� wsp�rz�dnej Y obiektu typu player.
  * @return Zwraca warto�� typu int reprezentuj�c� wsp�rz�dn� Y gracza.
  */
	int get_posY();
	/** @brief Zwraca identyfikator gracza.
  * Metoda zwraca unikalny identyfikator gracza.
  * @return Zwraca warto�� typu char reprezentuj�c� identyfikator gracza.
  */
	char get_id();
	/** @brief Ustawia pozycj� gracza.
  * Metoda ustawia wsp�rz�dne X i Y obiektu typu player.
  * @param[int] x Nowa wsp�rz�dna X gracza.
  * @param[int] y Nowa wsp�rz�dna Y gracza.
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