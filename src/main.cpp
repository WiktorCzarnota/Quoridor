#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include "plansza.hpp"
#include "player.hpp"
#include "game.hpp"
#include "interfejs.hpp"

using namespace std;

int zasady();
int tura(game *gra,interfejs *ui,plansza *stul);

/**
 * @brief Funkcja startowa gry Quorridor.
 *
 * Funkcja `start` wy�wietla menu gry, umo�liwiaj�c u�ytkownikowi wyb�r
 * spo�r�d opcji: zasady gry, gra z koleg�, gra z robotem. Uruchamia
 * odpowiedni� funkcj� w zale�no�ci od wyboru u�ytkownika.
 *
 * @return Zwraca 0.
 */
int start() {
	system("CLS");
	printf("Oto moja gra Quorridor\n\n");
	printf("Wybierz jedna opcji:\n");
	printf("(z)asady\ngra z (k)olegom\ngra z (r)obotem\n");
	char wybor;
	cin >> wybor;
	if (wybor == 'z') {
		if (zasady())
			start();
	}
	else if (wybor == 'k' || wybor == 'r') {
		interfejs* ui = NULL;
		if (wybor == 'k')
			ui = new user;
		else if (wybor == 'r')
			ui = new robot;
		game* gra = new game;
		plansza* stul = new plansza;
		stul->update(gra);

		while (tura(gra, ui, stul))
			;
		return 0;
	}
	else {
		while (getchar() != '\n');
		start();
	}
	return 0;
}

/**
 * @brief Wy�wietla zasady gry z pliku tekstowego.
 *
 * Funkcja `zasady` wy�wietla zasady gry, wczytuj�c je z pliku tekstowego "zasady.txt".
 * Funkcja korzysta z p�tli `while` do oczekiwania na naci�ni�cie klawisza Enter przez
 * u�ytkownika, aby umo�liwi� mu przeczytanie zasad.
 *
 * @return Zwraca 1 po wy�wietleniu zasad.
 */
int zasady() {
	while (getchar() != '\n')
		;
	system("CLS");
	ifstream inputFile("zasady.txt");
	if (inputFile.is_open()) { 
		string line; 

		while (getline(inputFile, line)) {  
			cout << line << endl;
		}
		inputFile.close();
	}
	else {
		cout << "Failed to open the file." << endl;
	}
	char input = getchar();
	if (input == '\n')
		return 1;
	else
		zasady();
}

/**
 * @brief Wy�wietla ekran wygranej dla okre�lonego gracza.
 *
 * Funkcja `winer_pov` wy�wietla ekran wygranej, gratuluj�c zwyci�stwa
 * graczowi o podanym numerze. U�ytkownik mo�e wybra� powr�t do menu
 * startowego (klawisz 's') lub zako�czenie gry (klawisz 'z').
 *
 * @param gracz Numer zwyci�skiego gracza (1 lub 2).
 * @return Zwraca 0 w przypadku zako�czenia gry, nic w przypadku powrotu do menu.
 */
int winer_pov(int gracz) {
	system("CLS");
	for (int i = 0; i < 9; i++)
	{
		if (i == 4) {
			printf("==========================--Zwyciesca jest gracz %c--============================\n", gracz + 119);
			continue;
		}
		for (int j = 0; j < 80; j++)
		{
			cout << "=";
		}
		putchar('\n');
	}
	char input;
	cout << "\n\n- Wroc do (s)tartu\n- (z)akoncz\n\n";
	cin >> input;
	if (input == 's') {
		start();
	}
	else if (input == 'z') {
		return 0;
	}
	else
		winer_pov(gracz);
}

/**
 * @brief Odgrywa tur� gry.
 *
 * Funkcja `tura` realizuje tur� gry, w kt�rej u�ytkownik wybiera, czy chce postawi�
 * �cian� ('s'), czy ruszy� pionkiem ('p'). Funkcja sprawdza dost�pno�� �cian
 * dla danego gracza, pobiera ruch u�ytkownika i aktualizuje stan gry.
 * Sprawdza r�wnie� warunki wygranej i wy�wietla ekran wygranej, je�li
 * taka nast�pi.
 *
 * @param gra Wska�nik na obiekt game zawieraj�cy stan gry.
 * @param ui Wska�nik na obiekt interfejs zawieraj�cy funkcje interfejsu u�ytkownika.
 * @param stul Wska�nik na obiekt plansza odpowiedzialny za rysowanie planszy.
 * @return Zwraca 1, je�li gra trwa, 0 w przypadku zako�czenia gry.
 */
int tura(game* gra, interfejs* ui, plansza* stul) {
	stul->board(gra, ui);
	char wybor;
	cout << "Co chcesz zrobic\npostawic (s)ciane\nruszyc (p)ionek\n";
	cin >> wybor;
	if (wybor == 's') {
		switch (ui->get_turn())
		{
		case 1:
			if (ui->get_a_wals() == 0) {
				cout << "Nie masz tylu scian\n";
				tura(gra, ui, stul);
			}
			break;
		case 2:
			if (ui->get_b_wals() == 0) {
				cout << "Nie masz tylu scian\n";
				tura(gra, ui, stul);
			}
			break;
		default:
			break;
		}
		ui->wal(gra);
		ui->zabierz_sciane(ui->get_turn());
		stul->update(gra);
	}
	else if (wybor == 'p') {
		ui->move(gra);
		stul->update(gra);
	}
	else {
		tura(gra, ui, stul);
	}
	ui->change_turn();
	if (gra->winn() == 1) {
		delete gra, ui, stul;
		winer_pov(1);
		return 0;
	}
	else if (gra->winn() == 2) {
		delete gra, ui, stul;
		winer_pov(2);
		return 0;
	}
	return 1;
}


int main() {

	start();

	return 0;
}