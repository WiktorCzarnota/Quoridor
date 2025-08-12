#include <iostream>
#include "game.hpp"

#define ALPHA 120
#define BETHA 121

game::game() {
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			wals[i][j] = 0;
		}
	}
	a.set_pos(5, 9);
	a.set_id(ALPHA);
	b.set_pos(5, 1);
	b.set_id(BETHA);
}
game::game(game& orginal) {
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			wals[i][j] = orginal.wals[i][j];
		}
	}
	a.set_pos(orginal.a.get_posX(), orginal.a.get_posY());
	b.set_pos(orginal.b.get_posX(), orginal.b.get_posY());
}

void game::add_wals(int rodzaj,int wiersz, int kolumna) {   
	wals[kolumna-1][wiersz-1] = rodzaj;
}

void game::player_move(int wchich_player,int x,int y) {
	if (wchich_player == 1) {
		a.set_pos(x,y);
	}
	else if (wchich_player == 2) {
		b.set_pos(x, y);
	}
}

bool game::check_move(int posx, int posy, int gracz) {
	int x = 0, y = 0, x_2 = 0, y_2 = 0,gracz_2 = 0;
	if (gracz == 1) {
		x = a.get_posX();
		y = a.get_posY();
		x_2 = b.get_posX();
		y_2 = b.get_posY();
		gracz_2 = 2;
	}
	else if (gracz == 2) {
		x = b.get_posX();
		y = b.get_posY();
		x_2 = a.get_posX();
		y_2 = a.get_posY();
		gracz_2 = 1;
	}

	if (blocked_wall(posx, posy, gracz)) {
		return false;
	}
	else if (gracz_blisko(posx, posy, gracz)) { //  inny gracz jest blisko
		if (posx == x_2 && posy == y_2)
			return false;
		else {
			if (jeden_krok(posx, posy, gracz)) 
				return true;
			else if (blocked_wall(posx, posy, gracz_2))
				return false;
			else if (jeden_krok(posx, posy, gracz_2))
				return true;
		}
	}
	if (jeden_krok(posx, posy, gracz)) {
		return true;
	}
	else
		return false;

}

bool game::jeden_krok(int posx, int posy, int gracz) { // cza pion idzie jedno pole TYLKO --- true = tak
	int x = 0, y = 0;
	if (gracz == 1) {
		x = a.get_posX();
		y = a.get_posY();
	}
	else if (gracz == 2) {
		x = b.get_posX();
		y = b.get_posY();
	}
	if (posx == x && posy - 1 == y) // czy to gory
		return true;
	else if (posx == x && posy + 1 == y) // czy dol
		return true;
	else if (posx - 1 == x && posy == y) // czy lewo
		return true;
	else if (posx + 1 == x && posy == y) // czy prawo
		return true;
	else
		return false;
}

bool game::gracz_blisko(int posx, int posy, int gracz) { // true = jedno pole od gracza jest inny gracz
	int x = 0, y = 0, x_2 = 0, y_2 = 0;
	if (gracz == 1) {
		x = a.get_posX();
		y = a.get_posY();
		x_2 = b.get_posX();
		y_2 = b.get_posY();
	}
	else if (gracz == 2) {
		x = b.get_posX();
		y = b.get_posY();
		x_2 = a.get_posX();
		y_2 = a.get_posY();
	}

	if ((x == x_2 && y == y_2 - 1) || (x == x_2 && y == y_2 + 1) || (x == x_2 - 1 && y == y_2) || (x == x_2 + 1 && y == y_2)) {
		return true;
	}
	else
		return false;
}

bool game::blocked_wall(int posx, int posy, int gracz) {  // true = ne da sie przejsc bo sciana
	int x = 0, y = 0;									  // false = sciana nie zawadza
	if (gracz == 1) {
		x = a.get_posX();
		y = a.get_posY();
	}
	else if (gracz == 2) {
		x = b.get_posX();
		y = b.get_posY();
	}

	if (posx == x) {//  ruch góra dó³
		if (posy == y - 1) {// kiedy idzie do góry
			if (wals[posy - 1][posx - 1] == 2 || wals[posy - 1][posx - 2] == 2) {
				return true;// nie mozna przejsc
			}
			else
				return false;
		}
		else if (posy == y + 1) {// kiedy idzie nadó³
			if (wals[y - 1][x - 1] == 2 || wals[y - 1][x - 2] == 2) {
				return true;// nie mozna przejsc
			}
			else
				return false;
		}
		else
			return false;
	}
	else if (posy == y) {//  ruch lewo prawo
		if (posx == x - 1) {// ruch w lewo
			if (wals[posy - 1][posx - 1] == 1 || wals[posy - 2][posx - 1] == 1)
				return true;//nie da sie przejsc
			else
				return false;
		}
		else if (posx == x + 1) {// ruch w prawo
			if(wals[y - 1][x - 1] == 1 || wals[y - 2][x - 1] == 1)
				return true;//nie da sie przejsc
		else
			return false;
		}
		else
			return false;
	}
	else
		return false;

}

bool game::check_wal(int rodzaj, int posx, int posy, game *gra) {
	if (rodzaj == 1) {
		if (wals[posx][posy] == 1 || wals[posx][posy] == 2)
			return false;
		else {
			if (posy == 0) {
				if (wals[posy + 1][posx] == 1) {
					return false;
				}
				else {
					if (0) {
						return false;
					}
					else {
						return true;
					}
				}
			}
			else if (posy == 7) {
				if (wals[posy - 1][posx] == 1) {
					return false;
				}
				else {
					if (0) {
						return false;
					}
					else {
						return true;
					}
				}
			}
			else {
				if (wals[posy + 1][posx] == 1 || wals[posy - 1][posx] == 1) {
					return false;
				}
				else {
					if (0) {
						return false;
					}
					else {
						return true;
					}
				}
			}
		}
	}
	else if (rodzaj == 2) {
		if (wals[posx][posy] == 1 || wals[posx][posy] == 2)
			return false;
		else {
			if (posx == 0) {
				if (wals[posy][posx + 1] == 2) {
					return false;
				}
				else {
					if (0) {
						return false;
					}
					else {
						return true;
					}
				}
			}
			else if (posx == 7) {
				if (wals[posy][posx - 1] == 2) {
					return false;
				}
				else {
					if (box_gaming(rodzaj,posx,posy,gra)) {
						return false;
					}
					else {
						return true;
					}
				}
			}
			if (wals[posy][posx + 1] == 2 || wals[posy][posx - 1] == 2) {
				return false;
			}
			else {
				if (0) {
					return false;
				}
				else {
					return true;
				}
			}
		}
	}
}

bool game::box_gaming(int rodzaj, int posx, int posy, game *gra) { // true = nie ma przejscia do wina



	return false;
}

int game:: winn() {
	if (a.get_posY() == 1)
		return 1;
	else if (b.get_posY() == 9)
		return 2;
	else
		return 0;
}