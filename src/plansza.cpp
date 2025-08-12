#include <stdio.h>
#include <iostream>
#include "plansza.hpp"
#include "player.hpp"
#include "game.hpp"
#include "interfejs.hpp"

using namespace std;

plansza::plansza() {
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			sciany_v[i][j] = EMPTY;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			sciany_h[i][j] = EMPTY;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			srodek_pola[i][j] = BLOCK;
		}
	}
	srodek_pola[4][0] = BETHA;
	srodek_pola[4][8] = ALPHA;
}

void plansza:: board_line(int kwadrat, int nr_wiersza,game *gra) {
	for (int wiersze = 0; wiersze < kwadrat / 2; wiersze++)
	{
		if (wiersze == kwadrat / 4) {
			printf(" %d  ", nr_wiersza);
		}
		else {
			printf("    ");
		}
		for (int pola = 0; pola < 9; pola++)
		{
			for (int kolumny = 0; kolumny < kwadrat; kolumny++)
			{
				if ((wiersze == kwadrat / 4) && (kolumny == 3)) { //  <--- srodek kazdego pola
					cout << char(srodek_pola[pola][nr_wiersza-1]);
				}
				else {
					cout << char(BLOCK);
				}	
			}
			cout << char(sciany_v[nr_wiersza-1][pola]);
		}
		putchar('\n');
	}
}

void plansza:: przerwa(int kwadrat,int nr_wiersza,game *gra) {
	printf("    ");
	for (int j = 0; j < 9; j++)
	{
		for (int i = 0; i < kwadrat; i++)
		{
			cout << char(sciany_h[nr_wiersza-1][j]);
		}
		if (gra->wals[nr_wiersza - 1][j] == 2)
			cout << char(sciany_h[nr_wiersza - 1][j]);
		else if (gra->wals[nr_wiersza - 1][j] == 1)
			cout << char(sciany_v[nr_wiersza - 1][j]);
		else
			cout << char(EMPTY);
	}

	putchar('\n');
}

void plansza:: naglowek() {
	printf("    ");
	for (int i = 0; i < 9; i++)
	{
		printf("%4c    ", i + 65);
	}
	putchar('\n');
	putchar('\n');
}

void plansza::poka_sciane(interfejs *ui) {
	printf("\n\n%4csciany gracza x: %2d%33csciany gracza y: %2d\n",' ',ui->get_a_wals(),' ',ui->get_b_wals());
	printf("\n%33ctura gracza:%2c\n", ' ', 'w' + ui->get_turn());
	for (int i = 0; i < 75; ++i)
		printf("-");
	printf("\n\n");
}

int plansza:: board(game *gra,interfejs *ui) {
	int kwadrat = 7;
	system("CLS");
	naglowek();
	for (int i = 0; i < 9; i++)
	{
		board_line(kwadrat, i + 1, gra);
		if (i == 8)
			break;
		przerwa(kwadrat, i+1, gra);
	}
	poka_sciane(ui);
	return 0;
}

void plansza:: update(game *gra) {
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			srodek_pola[i][j] = BLOCK;
		}
	}
	srodek_pola[gra->a.get_posX()-1][gra->a.get_posY()-1] = gra->a.get_id();
	srodek_pola[gra->b.get_posX()-1][gra->b.get_posY()-1] = gra->b.get_id();
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (gra->wals[i][j] == 1 ) {
				sciany_v[i][j] = VERTYCAL;
				sciany_v[i+1][j] = VERTYCAL;
			}
			else if (gra->wals[i][j] == 2) {
				sciany_h[i][j] = HORYZONTAL;
				sciany_h[i][j+1] = HORYZONTAL;
			}
		}
	}
}