#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h> 
#include "interfejs.hpp"

using namespace std;

interfejs::interfejs():turn(1),a_wals(10),b_wals(10) {}


int interfejs::get_turn() {
	return turn;
}

int interfejs::get_a_wals() {
	return a_wals;
}

int interfejs::get_b_wals() {
	return b_wals;
}

void interfejs::zabierz_sciane(int gracz) {
	if (gracz == 1) {
		a_wals -= 1;
	}
	else if(gracz == 2){
		b_wals -= 1;
	}
}


void interfejs::change_turn() {
	if (turn == 1)
		turn = 2;
	else if (turn == 2)
		turn = 1;
}

int user::move(game *gra) {
	char posx, posy;
	printf("\nPodaj gdzie ma sie ruszyc pionek: ");
	cin >> posx;
	cin >> posy;
	if (posx < 'a' || posx > 'i') {
		cout << "Niepoprawne dane!!!\n";
		while (getchar() != '\n');
		move(gra);
		return 0;
	}
	if ( posy < '1' || posy > '9') {
		cout << "Niepoprawne dane!!!\n";
		while (getchar() != '\n');
		move(gra);
		return 0;
	}
	posx -= 'a' - 1;
	posy -= '1' - 1;
	if (gra->check_move(posx, posy, get_turn())) {
		gra->player_move(get_turn(), posx, posy);
		return 1;
	}
	else {
		cout << "Jest to nilegalny ruch!!!\n";
		while (getchar() != '\n');
		move(gra);
		return 0;
	}
}
int robot::move(game* gra) {
	if (get_turn() == 1) {
		char posx, posy;
		printf("\nPodaj gdzie ma sie ruszyc pionek: ");
		cin >> posx;
		cin >> posy;
		if (posx < 'a' || posx > 'i') {
			cout << "Niepoprawne dane!!!\n";
			while (getchar() != '\n');
			move(gra);
			return 0;
		}
		if (posy < '1' || posy > '9') {
			cout << "Niepoprawne dane!!!\n";
			while (getchar() != '\n');
			move(gra);
			return 0;
		}
		posx -= 'a' - 1;
		posy -= '1' - 1;
		if (gra->check_move(posx, posy, get_turn())) {
			gra->player_move(get_turn(), posx, posy);
			return 1;
		}
		else {
			cout << "Jest to nilegalny ruch!!!\n";
			while (getchar() != '\n');
			move(gra);
			return 0;
		}
	}
	srand(time(NULL));
	int posx = 5, posy = 2;
	do  {
		posx = (rand() % 9) + 1;
		posy = (rand() % 9) + 1;
	} while (!(gra->check_move(posx, posy, get_turn())));
	gra->player_move(get_turn(), posx, posy);
	return 1;
}

int user::wal(game* gra) {
	char posx,posy,rodzaj;
	printf("\nPodaj gdzie chcesz postawic sciane: ");
	cin >> rodzaj;
	cin >> posx;
	cin >> posy;
	if (rodzaj == 'v' || rodzaj == 'h') {
		if (rodzaj == 'v')
			rodzaj = 1;
		else
			rodzaj = 2;
	}
	else{
		cout << "Niepoprawne dane!!!\n";
		while (getchar() != '\n');
		wal(gra);
		return 0;
	}
	
	if (posx < 'a' || posx > 'h') {
		cout << "Niepoprawne dane!!!\n";
		while (getchar() != '\n');
		wal(gra);
		return 0;
	}

	if (posy < '1' || posy > '8') {
		cout << "Niepoprawne dane!!!\n";
		while (getchar() != '\n');
		wal(gra);
		return 0;
	}
	posx -= 'a' - 1;
	posy -= '1' - 1;

	if (gra->check_wal(rodzaj, posx - 1, posy - 1,gra)) {
		gra->add_wals(rodzaj, posx, posy);
		return 1;
	}
	else {
		cout << "Jest to nilegalny ruch!!!\n";
		while (getchar() != '\n');
		wal(gra);
		return 0;
	}
}
int robot::wal(game* gra) {
	if (get_turn() == 1) {
		char posx, posy, rodzaj;
		printf("\nPodaj gdzie chcesz postawic sciane: ");
		cin >> rodzaj;
		cin >> posx;
		cin >> posy;
		if (rodzaj == 'v' || rodzaj == 'h') {
			if (rodzaj == 'v')
				rodzaj = 1;
			else
				rodzaj = 2;
		}
		else {
			cout << "Niepoprawne dane!!!\n";
			while (getchar() != '\n');
			wal(gra);
			return 0;
		}

		if (posx < 'a' || posx > 'h') {
			cout << "Niepoprawne dane!!!\n";
			while (getchar() != '\n');
			wal(gra);
			return 0;
		}

		if (posy < '1' || posy > '8') {
			cout << "Niepoprawne dane!!!\n";
			while (getchar() != '\n');
			wal(gra);
			return 0;
		}
		posx -= 'a' - 1;
		posy -= '1' - 1;

		if (gra->check_wal(rodzaj, posx - 1, posy - 1,gra)) {
			gra->add_wals(rodzaj, posx, posy);
			return 1;
		}
		else {
			cout << "Jest to nilegalny ruch!!!\n";
			while (getchar() != '\n');
			wal(gra);
			return 0;
		}
	}
	srand(time(NULL));
	int posx = 5, posy = 5, rodzaj = 1;
	do  {
		posx = (rand() % 9) + 1;
		posy = (rand() % 9) + 1;
		rodzaj = (rand() % 2) + 1;
	} while (!(gra->check_wal(rodzaj, posx - 1, posy - 1,gra)));
	gra->add_wals(rodzaj, posx, posy);
	return 1;
}