#include <iostream>
#include "player.hpp"
#include "plansza.hpp"


int player::get_posX() {
	return posX;
}
int player::get_posY() {
	return posY;
}
char player::get_id() {
	return id;
}
void player::set_pos(int x, int y) {
	posX = x;
	posY = y;
}
void player::set_id(char indyk) {
	id = indyk;
}

player::player():posX(1),posY(1),id(ALPHA) {}
player::player(char i, int x, int y) {
	id = i;
	posX = x;
	posY = y;
}