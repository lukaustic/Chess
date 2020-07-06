#include <iostream>
#include "Piece.h"
using namespace std;

char prikaz[38][57] = { /*Zablon table koja ce se iscrtavati*/
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', 'A', ' ', ' ', ' ', ' ', ' ', 'B', ' ', ' ', ' ', ' ', ' ', 'C', ' ', ' ', ' ', ' ', ' ', 'D', ' ', ' ', ' ', ' ', ' ', 'E', ' ', ' ', ' ', ' ', ' ', 'F', ' ', ' ', ' ', ' ', ' ', 'G', ' ', ' ', ' ', ' ', ' ', 'H', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' '},
	{' ', ' ', '8', ' ', '#', ' ', ' ', 'T', ' ', ' ', '#', ' ', ' ', 'S', ' ', ' ', '#', ' ', ' ', 'L', ' ', ' ', '#', ' ', ' ', 'D', ' ', ' ', '#', ' ', ' ', 'K', ' ', ' ', '#', ' ', ' ', 'L', ' ', ' ', '#', ' ', ' ', 'S', ' ', ' ', '#', ' ', ' ', 'T', ' ', ' ', '#', ' ', '8', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' '},
	{' ', ' ', '7', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', '7', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' '},
	{' ', ' ', '6', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '6', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' '},
	{' ', ' ', '5', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '5', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' '},
	{' ', ' ', '4', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '4', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' '},
	{' ', ' ', '3', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '3', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' '},
	{' ', ' ', '2', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', '2', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' '},
	{' ', ' ', '1', ' ', '#', ' ', ' ', 'T', ' ', ' ', '#', ' ', ' ', 'S', ' ', ' ', '#', ' ', ' ', 'L', ' ', ' ', '#', ' ', ' ', 'D', ' ', ' ', '#', ' ', ' ', 'K', ' ', ' ', '#', ' ', ' ', 'L', ' ', ' ', '#', ' ', ' ', 'S', ' ', ' ', '#', ' ', ' ', 'T', ' ', ' ', '#', ' ', '1', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', 'A', ' ', ' ', ' ', ' ', ' ', 'B', ' ', ' ', ' ', ' ', ' ', 'C', ' ', ' ', ' ', ' ', ' ', 'D', ' ', ' ', ' ', ' ', ' ', 'E', ' ', ' ', ' ', ' ', ' ', 'F', ' ', ' ', ' ', ' ', ' ', 'G', ' ', ' ', ' ', ' ', ' ', 'H', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
};

Piece tabla[8][8]; /*Virtuelna tabla koja sadrzi sve figure*/
Piece privremena; /*Cuva stanje tabele pre odigranog poteza, kako bi se tabla vratila na staro stanje ukoliko je rezultat pomeranja figure sah */
char pojedene_crne[16] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}; /*Niz koji pamti koje figure su sklonjene sa table*/
char pojedene_bele[16] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
int x_sah; /*X pozicija figure koja je izazvala sah*/
int y_sah; /*Y pozicija figure koja je izazvala sah*/
char figura_sah; /*Tip figure koja izaziva sah*/
char trenutni_igrac = 'b'; /*Pamti ko je na potezu*/
char izabrana_kolona; /*Cuva slovo kolone unesenog polja*/
char izabran_red; /*Cuva broj reda unesenog polja*/
bool sah_stanje; /*Prati da li je u trenutku igre sah ili nije*/
bool mala_rokada_beli = true; /*Prati da li je mala rokada belog igraca moguca*/
bool velika_rokada_beli = true; /*Prati da li je velika rokada belog igraca moguca*/
bool mala_rokada_crni = true; /*Prati da li je mala rokada crnog igraca moguca*/
bool velika_rokada_crni = true; /*Prati da li je velika rokada crnog igraca moguca*/
bool odradi_malu_rokadu_beli = false; /*Ako ikad stanje oredje na true odradice se rokada*/
bool odradi_veliku_rokadu_beli = false; /*Ako ikad stanje oredje na true odradice se rokada*/
bool odradi_malu_rokadu_crni = false; /*Ako ikad stanje oredje na true odradice se rokada*/
bool odradi_veliku_rokadu_crni = false; /*Ako ikad stanje oredje na true odradice se rokada*/
bool zameni_figuru = false; /*Ako pesak stigne do kraja table postavlja signal da zahteva zamenu*/

void zameniIgraca(); /*Menja igrace*/
void Start(); /*Postavlja figure na tablu na pocetna mesta*/
void Odigraj(); /*Pomera figuru sa polja na polje*/
void Unos(int faza); /*Unosi polje sa kojim se igra*/
void Iscrtaj(); /*Iscrtava tablu na ekran*/
bool Sah(int x, int y, char igrac); /*Proverava da li je sah*/
bool poljeSeMozeBlokirati(int x, int y, char igrac); /*Ista funkcija kao i Sah sa izmenom da ne racuna pesake koji se nemogu prepreciti ukoso na prazno polje da blokiraju napad*/
bool mogucPotez(int x, int y, int x1, int y1); /*Proverava da li se moze odigrati potez*/
bool SahMat(int x, int y, int x1, int y1, char figura); /*Provera da li je igri dosao kraj*/

int main()
{
	Start();
	while (true)
	{
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (tabla[i][j].getName() == 'K' && tabla[i][j].getPlayer() == trenutni_igrac) 	/*Provera pozicije kralja trenutnog igraca kako bi se prosledila funkciji za odredjivanje saha*/
				{
					sah_stanje = Sah(i, j, trenutni_igrac);
					if (sah_stanje)
						if (SahMat(i, j, x_sah, y_sah, figura_sah)) /*Ukoliko je dati sah sahmat izaci iz igre i proglasiti pobednika*/
						{
							system("cls");
							Iscrtaj();
							cout << "\t\t\t SAH-MAT!" << endl << endl;
							if (trenutni_igrac == 'b')
								cout << "\t\t     CRNI JE POBEDIO!" << endl << endl;
							else
								cout << "\t\t     BELI JE POBEDIO!" << endl << endl;
							system("pause");
							exit(0);
						}
				}
		Odigraj();
		zameniIgraca();
	}
}

bool SahMat(int x, int y, int x1, int y1, char figura)
{
	bool sah_mat = true; /*Lazna predpostavka da sah mat postoji pa odakle trazimo svaki moguci izlaz*/

	if (x < 7 && (tabla[x + 1][y].getPlayer() != trenutni_igrac && !Sah(x + 1, y, trenutni_igrac)))
		sah_mat = false;
	if (x > 0 && (tabla[x - 1][y].getPlayer() != trenutni_igrac && !Sah(x - 1, y, trenutni_igrac)))
		sah_mat = false;
	if (y < 7 && (tabla[x][y + 1].getPlayer() != trenutni_igrac && !Sah(x, y + 1, trenutni_igrac)))
		sah_mat = false;
	if (y > 0 && (tabla[x][y - 1].getPlayer() != trenutni_igrac && !Sah(x, y - 1, trenutni_igrac)))
		sah_mat = false;																								/*Ako kralj ima bezbedno polje na koje moze da se pomeri sah mata nema*/
	if (x < 7 && y < 7 && (tabla[x + 1][y + 1].getPlayer() != trenutni_igrac && !Sah(x + 1, y + 1, trenutni_igrac)))
		sah_mat = false;
	if (x > 0 && y > 0 && (tabla[x - 1][y - 1].getPlayer() != trenutni_igrac && !Sah(x - 1, y - 1, trenutni_igrac)))
		sah_mat = false;
	if (x < 7 && y > 0 && (tabla[x + 1][y - 1].getPlayer() != trenutni_igrac && !Sah(x + 1, y - 1, trenutni_igrac)))
		sah_mat = false;
	if (x > 0 && y < 7 && (tabla[x - 1][y + 1].getPlayer() != trenutni_igrac && !Sah(x - 1, y + 1, trenutni_igrac)))
		sah_mat = false;
	
	if (figura == 'S') /*Ako sah pravi skakac i on je u polju pod napadom onda nije sah mat*/
	{
		zameniIgraca();
		if (Sah(x1, y1, trenutni_igrac))
			sah_mat = false;

		zameniIgraca();
	}
	
	if (x1 > x && y1 == y) /*Ako sah preti odozdo*/
	{
		zameniIgraca();
		for (int i = x + 1; i < x1; i++)
			if (poljeSeMozeBlokirati(i, y, trenutni_igrac)) /*Proverava sva polja izmedju kralja i figure koja ga napada*/
				sah_mat = false;

		if (Sah(x1, y1, trenutni_igrac)) /*Proverava da li se figura koja napada moze pojesti*/
			sah_mat = false;

		zameniIgraca();
	}

	if (x > x1 && y1 == y) /*Ako sah preti odozgo*/
	{
		zameniIgraca();
		for (int i = x - 1; i > x1; i--)
			if (poljeSeMozeBlokirati(i, y, trenutni_igrac)) /*Proverava sva polja izmedju kralja i figure koja ga napada*/
				sah_mat = false;

		if (Sah(x1, y1, trenutni_igrac)) /*Proverava da li se figura koja napada moze pojesti*/
			sah_mat = false;

		zameniIgraca();
	}

	if (x1 == x && y1 < y) /*Ako sah preti sa leve strane*/
	{
		zameniIgraca();
		for (int i = y - 1; i > y1; i--)
			if (poljeSeMozeBlokirati(x, i, trenutni_igrac)) /*Proverava sva polja izmedju kralja i figure koja ga napada*/
				sah_mat = false;

		if (Sah(x1, y1, trenutni_igrac)) /*Proverava da li se figura koja napada moze pojesti*/
			sah_mat = false;

		zameniIgraca();
	}

	if (x1 == x && y1 > y) /*Ako sah preti sa leve strane*/
	{
		zameniIgraca();
		for (int i = y + 1; i < y1; i++)
			if (poljeSeMozeBlokirati(x, i, trenutni_igrac)) /*Proverava sva polja izmedju kralja i figure koja ga napada*/
				sah_mat = false;

		if (Sah(x1, y1, trenutni_igrac)) /*Proverava da li se figura koja napada moze pojesti*/
			sah_mat = false;

		zameniIgraca();
	}

	if (x1 > x && y1 > y) /*Ako sah preti sa donje leve strane*/
	{
		zameniIgraca();
		int j = y + 1;
		for (int i = x + 1; i < x1; i++)
		{
			if (poljeSeMozeBlokirati(i, j, trenutni_igrac)) /*Proverava sva polja izmedju kralja i figure koja ga napada*/
				sah_mat = false;
			j++;
		}

		if (Sah(x1, y1, trenutni_igrac)) /*Proverava da li se figura koja napada moze pojesti*/
			sah_mat = false;

		zameniIgraca();
	}

	if (x1 < x && y1 < y) /*Ako sah preti sa gornje desne strane*/
	{
		zameniIgraca();
		int j = y - 1;
		for (int i = x - 1; i > x1; i--)
		{
			if (poljeSeMozeBlokirati(i, j, trenutni_igrac)) /*Proverava sva polja izmedju kralja i figure koja ga napada*/
				sah_mat = false;
			j--;
		}

		if (Sah(x1, y1, trenutni_igrac)) /*Proverava da li se figura koja napada moze pojesti*/
			sah_mat = false;

		zameniIgraca();
	}

	if (x1 > x && y1 < y) /*Ako sah preti sa donje desne strane*/
	{
		zameniIgraca();
		int j = y - 1;
		for (int i = x + 1; i < x1; i++)
		{
			if (poljeSeMozeBlokirati(i, j, trenutni_igrac)) /*Proverava sva polja izmedju kralja i figure koja ga napada*/
				sah_mat = false;
			j--;
		}

		if (Sah(x1, y1, trenutni_igrac)) /*Proverava da li se figura koja napada moze pojesti*/
			sah_mat = false;

		zameniIgraca();
	}

	if (x1 < x && y1 > y) /*Ako sah preti sa gornje desne strane*/
	{
		zameniIgraca();
		int j = y + 1;
		for (int i = x - 1; i > x1; i--)
		{
			if (poljeSeMozeBlokirati(i, j, trenutni_igrac)) /*Proverava sva polja izmedju kralja i figure koja ga napada*/
				sah_mat = false;
			j++;
		}

		if (Sah(x1, y1, trenutni_igrac)) /*Proverava da li se figura koja napada moze pojesti*/
			sah_mat = false;

		zameniIgraca();
	}

	if (sah_mat == true) /*Ako nije osporen Mat u ranijim uslovima igra se privodi kraju*/
		return true;
	else
		return false;
}

void zameniIgraca()
{
	if (trenutni_igrac == 'b') 
		trenutni_igrac = 'c';	/*Proveri koji je trenutno aktivan igrac i postavi drugog*/
	else
		trenutni_igrac = 'b';
}

void Start()
{
	tabla[0][0] = Piece('T', 'c');
	tabla[0][1] = Piece('S', 'c');
	tabla[0][2] = Piece('L', 'c');
	tabla[0][3] = Piece('D', 'c');
	tabla[0][4] = Piece('K', 'c');
	tabla[0][5] = Piece('L', 'c');
	tabla[0][6] = Piece('S', 'c');
	tabla[0][7] = Piece('T', 'c');
	tabla[1][0] = Piece('P', 'c');
	tabla[1][1] = Piece('P', 'c');
	tabla[1][2] = Piece('P', 'c');
	tabla[1][3] = Piece('P', 'c');
	tabla[1][4] = Piece('P', 'c');
	tabla[1][5] = Piece('P', 'c');
	tabla[1][6] = Piece('P', 'c');
	tabla[1][7] = Piece('P', 'c');	/*Postavi figure na startne pozicije virtuelne table*/
	tabla[7][0] = Piece('T', 'b');
	tabla[7][1] = Piece('S', 'b');
	tabla[7][2] = Piece('L', 'b');
	tabla[7][3] = Piece('D', 'b');
	tabla[7][4] = Piece('K', 'b');
	tabla[7][5] = Piece('L', 'b');
	tabla[7][6] = Piece('S', 'b');
	tabla[7][7] = Piece('T', 'b');
	tabla[6][0] = Piece('P', 'b');
	tabla[6][1] = Piece('P', 'b');
	tabla[6][2] = Piece('P', 'b');
	tabla[6][3] = Piece('P', 'b');
	tabla[6][4] = Piece('P', 'b');
	tabla[6][5] = Piece('P', 'b');
	tabla[6][6] = Piece('P', 'b');
	tabla[6][7] = Piece('P', 'b');
	for (int i = 2; i < 6; i++)
		for (int j = 0; j < 8; j++)			/*Oznaci sva ostala polja kao prazna*/
			tabla[i][j] = Piece(' ', ' ');
}

void Odigraj()
{
	int strRed; /*Red figure sa kojom igramo*/
	int strKolona; /*Kolona figure sa kojom igramo*/
	int endRed; /*Red destinacije figure sa kojom igramo*/
	int endKolona; /*Kolona destinacije figure sa kojom igramo*/
	bool sah_posle_poteza; /*Proverava dal je doslo do saha kad se odigrao potez*/
	while (true)
	{
		do {
			do {

				Unos(1);
				strKolona = izabrana_kolona;	/*Unesi poziciju figure sa kojom igramo*/
				strRed = izabran_red;

				if (tabla[strRed][strKolona].getPlayer() != trenutni_igrac)
				{
					system("cls");
					Iscrtaj();
					if (sah_stanje)												/*Ako se na datom polje ne nalazi nasa figura, ponoviti unos i izbaciti uposorenje*/
						cout << "\t\t\t   SAH!" << endl;
					cout << "Na ovom polju nema vase figure" << endl << endl;
					system("pause");
				}
			} while (tabla[strRed][strKolona].getPlayer() != trenutni_igrac);

			Unos(2);
			endKolona = izabrana_kolona;	/*Unesi destinaciju figure sa kojom igramo*/
			endRed = izabran_red;

			if (!mogucPotez(strRed, strKolona, endRed, endKolona))
			{
				system("cls");
				Iscrtaj();
				if (sah_stanje)
					cout << "\t\t\t   SAH!" << endl;						/*Ako potez nije izvodljiv, ponoviti prvi unos i izbaciti upozorenje*/
				cout << "Nemoguc potez" << endl << endl;
				system("pause");
			}
		} while (!mogucPotez(strRed, strKolona, endRed, endKolona));

		privremena.setName(tabla[endRed][endKolona].getName());
		privremena.setPlayer(tabla[endRed][endKolona].getPlayer());
		tabla[endRed][endKolona].setName(tabla[strRed][strKolona].getName());		/*Zamena pocetnog i krajnjeg polja i pamcenje starog stanja krajnjeg polja*/
		tabla[endRed][endKolona].setPlayer(tabla[strRed][strKolona].getPlayer());
		tabla[strRed][strKolona].setName(' ');
		tabla[strRed][strKolona].setPlayer(' ');

		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (tabla[i][j].getName() == 'K' && tabla[i][j].getPlayer() == trenutni_igrac) /*Trazi poziciju kralja trenutnog igraca da bi proverio da li je doslo do saha usled odigranog poteza*/
					sah_posle_poteza = Sah(i, j, trenutni_igrac);

		if(sah_posle_poteza)
		{
			tabla[strRed][strKolona].setName(tabla[endRed][endKolona].getName());
			tabla[strRed][strKolona].setPlayer(tabla[endRed][endKolona].getPlayer());
			tabla[endRed][endKolona].setName(privremena.getName());
			tabla[endRed][endKolona].setPlayer(privremena.getPlayer());
			system("cls");																/*Ukoliko novo stanje na tabeli dovodi do saha, potez postaje neizvodljiv i tabela se vraca na prethodno stanje*/
			Iscrtaj();
			cout << "Nemoguc potez" << endl << endl;
			system("pause");
			continue;				/*Ukoliko je doslo do saha, vrati se na pocetak poteza*/
		}

		if (privremena.getPlayer() == 'b')
			for (int i = 0; i < 16; i++)						/*Ako je pojedena bela figura, upisi njeno ime na prvo slobodno mesto u nizu pojedenih*/
				if (pojedene_bele[i] == ' ')
				{
					pojedene_bele[i] = privremena.getName();
					break;
				}

		if (privremena.getPlayer() == 'c')
			for (int i = 0; i < 16; i++)
				if (pojedene_crne[i] == ' ')
				{
					pojedene_crne[i] = privremena.getName();
					break;
				}

		if (endRed == 0 && tabla[endRed][endKolona].getName() == 'P') /*Ako je beli pesak dosao do kraja table*/
		{
			for(int i = 0; i < 16; i++) /*Ukoliko beli ima neku figuru koju je izgubio*/
				if (pojedene_bele[i] == 'T' || pojedene_bele[i] == 'S' || pojedene_bele[i] == 'L' || pojedene_bele[i] == 'D')
				{
					char c; /*Unos*/
					bool top = false, skakac = false, lovac = false, dama = false;
					do {
						top = false;
						skakac = false;
						lovac = false;
						dama = false;
						system("cls");
						Iscrtaj();
						cout << "Izaberite figuru( ";
						for (int i = 0; i < 16; i++)
						{
							if (pojedene_bele[i] == 'T')
							{
								cout << "T ";
								top = true;
							}
							if (pojedene_bele[i] == 'S')
							{
								cout << "S ";
								skakac = true;
							}
							if (pojedene_bele[i] == 'L')
							{
								cout << "L ";
								lovac = true;
							}
							if (pojedene_bele[i] == 'D')
							{
								cout << "D ";
								dama = true;
							}
						}
						cout << "): ";
						fflush(stdin);
						cin >> c;
						if (((c != 'T' && c != 't') || top == false) && ((c != 'S' && c != 's') || skakac == false) && ((c != 'L' && c != 'l') || lovac == false) && ((c != 'D' && c != 'd') || dama == false))
						{
							system("cls");
							Iscrtaj();
							cout << "Morate uneti ponudjenu figuru!" << endl << endl;
							system("pause");
						}
					} while (((c != 'T' && c != 't') || top == false) && ((c != 'S' && c != 's') || skakac == false) && ((c != 'L' && c != 'l') || lovac == false) && ((c != 'D' && c != 'd') || dama == false));
					tabla[endRed][endKolona].setName(toupper(c));
					break;
				}
		}

		if (endRed == 7 && tabla[endRed][endKolona].getName() == 'P') /*Ako je crni pesak dosao do kraja table*/
		{
			for (int i = 0; i < 16; i++) /*Ukoliko crni ima neku figuru koju je izgubio*/
				if (pojedene_crne[i] == 'T' || pojedene_crne[i] == 'S' || pojedene_crne[i] == 'L' || pojedene_crne[i] == 'D')
				{
					char c; /*Unos*/
					bool top = false, skakac = false, lovac = false, dama = false;
					do {
						top = false;
						skakac = false;
						lovac = false;
						dama = false;
						system("cls");
						Iscrtaj();
						cout << "Izaberite figuru( ";
						for (int i = 0; i < 16; i++)
						{
							if (pojedene_crne[i] == 'T')
							{
								cout << "T ";
								top = true;
							}
							if (pojedene_crne[i] == 'S')
							{
								cout << "S ";
								skakac = true;
							}
							if (pojedene_crne[i] == 'L')
							{
								cout << "L ";
								lovac = true;
							}
							if (pojedene_crne[i] == 'D')
							{
								cout << "D ";
								dama = true;
							}
						}
						cout << "): ";
						fflush(stdin);
						cin >> c;
						if (((c != 'T' && c != 't') || top == false) && ((c != 'S' && c != 's') || skakac == false) && ((c != 'L' && c != 'l') || lovac == false) && ((c != 'D' && c != 'd') || dama == false))
						{
							system("cls");
							Iscrtaj();
							cout << "Morate uneti ponudjenu figuru!" << endl << endl;
							system("pause");
						}
					} while (((c != 'T' && c != 't') || top == false) && ((c != 'S' && c != 's') || skakac == false) && ((c != 'L' && c != 'l') || lovac == false) && ((c != 'D' && c != 'd') || dama == false));
					tabla[endRed][endKolona].setName(toupper(c));
					break;
				}
		}

		if (tabla[0][0].getName() != 'T' || tabla[0][0].getPlayer() != 'c')
			velika_rokada_crni = false;
		if (tabla[0][7].getName() != 'T' || tabla[0][7].getPlayer() != 'c')
			mala_rokada_crni = false;
		if (tabla[7][0].getName() != 'T' || tabla[7][0].getPlayer() != 'b') /*Ako su pomereni topovi sa svojih startnih pozicija igraci gube mogucnost rokade*/
			velika_rokada_beli = false;
		if (tabla[7][7].getName() != 'T' || tabla[7][7].getPlayer() != 'b')
			mala_rokada_beli = false;

		if (tabla[0][4].getName() != 'K' || tabla[0][4].getPlayer() != 'c')
		{
			velika_rokada_crni = false;
			mala_rokada_crni = false;
		}
		if (tabla[7][4].getName() != 'K' || tabla[7][4].getPlayer() != 'b') /*Ako su pomereni kraljevi sa svojih startnih pozicija igraci gube mogucnost rokade*/
		{
			velika_rokada_beli = false;
			mala_rokada_beli = false;
		}

		if (odradi_malu_rokadu_beli == true)
		{
			tabla[7][7].setName(' ');
			tabla[7][7].setPlayer(' ');
			tabla[7][5].setName('T');
			tabla[7][5].setPlayer('b');				/*Kad se dobije komanda za rokadu, top se rotira i onemoguci se ponavljanje rokade*/
			mala_rokada_beli = false;
			velika_rokada_beli = false;
			odradi_malu_rokadu_beli = false;
		}

		if (odradi_veliku_rokadu_beli == true)
		{
			cout << "KOD ZA VELIKU ROKADU" << endl;
			system("pause");
			tabla[7][0].setName(' ');
			tabla[7][0].setPlayer(' ');
			tabla[7][3].setName('T');
			tabla[7][3].setPlayer('b');				/*Kad se dobije komanda za rokadu, top se rotira i onemoguci se ponavljanje rokade*/
			mala_rokada_beli = false;
			velika_rokada_beli = false;
			odradi_veliku_rokadu_beli = false;
		}

		if (odradi_malu_rokadu_crni == true)
		{
			tabla[0][7].setName(' ');
			tabla[0][7].setPlayer(' ');
			tabla[0][5].setName('T');
			tabla[0][5].setPlayer('c');				/*Kad se dobije komanda za rokadu, top se rotira i onemoguci se ponavljanje rokade*/
			mala_rokada_crni = false;
			velika_rokada_crni = false;
			odradi_malu_rokadu_crni = false;
		}

		if (odradi_veliku_rokadu_crni == true)
		{
			tabla[0][0].setName(' ');
			tabla[0][0].setPlayer(' ');
			tabla[0][3].setName('T');
			tabla[0][3].setPlayer('c');				/*Kad se dobije komanda za rokadu, top se rotira i onemoguci se ponavljanje rokade*/
			mala_rokada_crni = false;
			velika_rokada_crni = false;
			odradi_veliku_rokadu_crni = false;
		}
		break;
	}
}

void Unos(int faza)
{
	char red; /*Red koji se unosi*/
	char kolona; /*Kolona koja se unosi*/
	do {
		if (faza == 1 && trenutni_igrac == 'b') {
			system("cls");
			Iscrtaj();
			if (sah_stanje)
				cout << "\t\t\t   SAH" << endl;
			cout << "Beli igrac bira" << endl << endl;
		}
		if (faza == 1 && trenutni_igrac == 'c') {
			system("cls");
			Iscrtaj();										/*Proverava koj igrac bira ili pomera figuru radi ispisivanja adekvatne poruke*/
			if (sah_stanje)
				cout << "\t\t\t   SAH" << endl;
			cout << "Crni igrac bira" << endl << endl;
		}
		if (faza == 2 && trenutni_igrac == 'b')
			cout << "Beli igrac napada" << endl << endl;
		if (faza == 2 && trenutni_igrac == 'c')
			cout << "Crni igrac napada" << endl << endl;
		cout << "Unesite polje: ";
		fflush(stdin);
		cin >> kolona >> red;								/*Unos kolone i reda*/
		if (red != '1' && red != '2' && red != '3' && red != '4' && red != '5' && red != '6' && red != '7' && red != '8')
		{
			cout << "Morate uneti postojeci red(1-8)";
			cout << endl << endl;							/*Upozorenje ako nije unet ispravan red*/
			system("pause");
		}
		if (kolona != 'a' && kolona != 'A' && kolona != 'b' && kolona != 'B' && kolona != 'c' && kolona != 'C' && kolona != 'd' && kolona != 'D' && kolona != 'e' && kolona != 'E' && kolona != 'f' && kolona != 'F' && kolona != 'g' && kolona != 'G' && kolona != 'h' && kolona != 'H')
		{
			cout << "Morate uneti postojecu kolonu(A-H)";
			cout << endl << endl;							/*Upozorenje ako nije uneta ispravana kolona*/
			system("pause");
		}
	} while ((red != '1' && red != '2' && red != '3' && red != '4' && red != '5' && red != '6' && red != '7' && red != '8') || (kolona != 'a' && kolona != 'A' && kolona != 'b' && kolona != 'B' && kolona != 'c' && kolona != 'C' && kolona != 'd' && kolona != 'D' && kolona != 'e' && kolona != 'E' && kolona != 'f' && kolona != 'F' && kolona != 'g' && kolona != 'G' && kolona != 'h' && kolona != 'H')); /*Ponavalja unos ukoliko nije izabran ispravan red ili kolona*/

	if (red == '1')
		izabran_red = 7;

	if (red == '2')
		izabran_red = 6;

	if (red == '3')
		izabran_red = 5;

	if (red == '4')
		izabran_red = 4;

	if (red == '5')			/*Konvertuje unet broj u red koji predstavlja to polje na virtuelnoj tabli*/
		izabran_red = 3;

	if (red == '6')
		izabran_red = 2;

	if (red == '7')
		izabran_red = 1;

	if (red == '8')
		izabran_red = 0;

	if (kolona == 'a' || kolona == 'A')
		izabrana_kolona = 0;

	if (kolona == 'b' || kolona == 'B')
		izabrana_kolona = 1;

	if (kolona == 'c' || kolona == 'C')
		izabrana_kolona = 2;

	if (kolona == 'd' || kolona == 'D')
		izabrana_kolona = 3;				/*Konvertuje uneto slovo u kolonu koja predstavlja to polje na virtuelnoj tabli*/

	if (kolona == 'e' || kolona == 'E')
		izabrana_kolona = 4;

	if (kolona == 'f' || kolona == 'F')
		izabrana_kolona = 5;

	if (kolona == 'g' || kolona == 'G')
		izabrana_kolona = 6;

	if (kolona == 'h' || kolona == 'H')
		izabrana_kolona = 7;
}

void Iscrtaj()
{												/*Zamenjuje polja na sablon tabli sa vrednostima iz virtuelne tabele*/
	prikaz[3][6] = tabla[0][0].getPlayer();
	prikaz[3][7] = tabla[0][0].getName();
	prikaz[3][12] = tabla[0][1].getPlayer();
	prikaz[3][13] = tabla[0][1].getName();
	prikaz[3][18] = tabla[0][2].getPlayer();
	prikaz[3][19] = tabla[0][2].getName();
	prikaz[3][24] = tabla[0][3].getPlayer();
	prikaz[3][25] = tabla[0][3].getName();
	prikaz[3][30] = tabla[0][4].getPlayer();
	prikaz[3][31] = tabla[0][4].getName();
	prikaz[3][36] = tabla[0][5].getPlayer();
	prikaz[3][37] = tabla[0][5].getName();
	prikaz[3][42] = tabla[0][6].getPlayer();
	prikaz[3][43] = tabla[0][6].getName();
	prikaz[3][48] = tabla[0][7].getPlayer();
	prikaz[3][49] = tabla[0][7].getName();
	prikaz[7][6] = tabla[1][0].getPlayer();
	prikaz[7][7] = tabla[1][0].getName();
	prikaz[7][12] = tabla[1][1].getPlayer();
	prikaz[7][13] = tabla[1][1].getName();
	prikaz[7][18] = tabla[1][2].getPlayer();
	prikaz[7][19] = tabla[1][2].getName();
	prikaz[7][24] = tabla[1][3].getPlayer();
	prikaz[7][25] = tabla[1][3].getName();
	prikaz[7][30] = tabla[1][4].getPlayer();
	prikaz[7][31] = tabla[1][4].getName();
	prikaz[7][36] = tabla[1][5].getPlayer();
	prikaz[7][37] = tabla[1][5].getName();
	prikaz[7][42] = tabla[1][6].getPlayer();
	prikaz[7][43] = tabla[1][6].getName();
	prikaz[7][48] = tabla[1][7].getPlayer();
	prikaz[7][49] = tabla[1][7].getName();
	prikaz[11][6] = tabla[2][0].getPlayer();
	prikaz[11][7] = tabla[2][0].getName();
	prikaz[11][12] = tabla[2][1].getPlayer();
	prikaz[11][13] = tabla[2][1].getName();
	prikaz[11][18] = tabla[2][2].getPlayer();
	prikaz[11][19] = tabla[2][2].getName();
	prikaz[11][24] = tabla[2][3].getPlayer();
	prikaz[11][25] = tabla[2][3].getName();
	prikaz[11][30] = tabla[2][4].getPlayer();
	prikaz[11][31] = tabla[2][4].getName();
	prikaz[11][36] = tabla[2][5].getPlayer();
	prikaz[11][37] = tabla[2][5].getName();
	prikaz[11][42] = tabla[2][6].getPlayer();
	prikaz[11][43] = tabla[2][6].getName();
	prikaz[11][48] = tabla[2][7].getPlayer();
	prikaz[11][49] = tabla[2][7].getName();
	prikaz[15][6] = tabla[3][0].getPlayer();
	prikaz[15][7] = tabla[3][0].getName();
	prikaz[15][12] = tabla[3][1].getPlayer();
	prikaz[15][13] = tabla[3][1].getName();
	prikaz[15][18] = tabla[3][2].getPlayer();
	prikaz[15][19] = tabla[3][2].getName();
	prikaz[15][24] = tabla[3][3].getPlayer();
	prikaz[15][25] = tabla[3][3].getName();
	prikaz[15][30] = tabla[3][4].getPlayer();
	prikaz[15][31] = tabla[3][4].getName();
	prikaz[15][36] = tabla[3][5].getPlayer();
	prikaz[15][37] = tabla[3][5].getName();
	prikaz[15][42] = tabla[3][6].getPlayer();
	prikaz[15][43] = tabla[3][6].getName();
	prikaz[15][48] = tabla[3][7].getPlayer();
	prikaz[15][49] = tabla[3][7].getName();
	prikaz[19][6] = tabla[4][0].getPlayer();
	prikaz[19][7] = tabla[4][0].getName();
	prikaz[19][12] = tabla[4][1].getPlayer();
	prikaz[19][13] = tabla[4][1].getName();
	prikaz[19][18] = tabla[4][2].getPlayer();
	prikaz[19][19] = tabla[4][2].getName();
	prikaz[19][24] = tabla[4][3].getPlayer();
	prikaz[19][25] = tabla[4][3].getName();
	prikaz[19][30] = tabla[4][4].getPlayer();
	prikaz[19][31] = tabla[4][4].getName();
	prikaz[19][36] = tabla[4][5].getPlayer();
	prikaz[19][37] = tabla[4][5].getName();
	prikaz[19][42] = tabla[4][6].getPlayer();
	prikaz[19][43] = tabla[4][6].getName();
	prikaz[19][48] = tabla[4][7].getPlayer();
	prikaz[19][49] = tabla[4][7].getName();
	prikaz[23][6] = tabla[5][0].getPlayer();
	prikaz[23][7] = tabla[5][0].getName();
	prikaz[23][12] = tabla[5][1].getPlayer();
	prikaz[23][13] = tabla[5][1].getName();
	prikaz[23][18] = tabla[5][2].getPlayer();
	prikaz[23][19] = tabla[5][2].getName();
	prikaz[23][24] = tabla[5][3].getPlayer();
	prikaz[23][25] = tabla[5][3].getName();
	prikaz[23][30] = tabla[5][4].getPlayer();
	prikaz[23][31] = tabla[5][4].getName();
	prikaz[23][36] = tabla[5][5].getPlayer();
	prikaz[23][37] = tabla[5][5].getName();
	prikaz[23][42] = tabla[5][6].getPlayer();
	prikaz[23][43] = tabla[5][6].getName();
	prikaz[23][48] = tabla[5][7].getPlayer();
	prikaz[23][49] = tabla[5][7].getName();
	prikaz[27][6] = tabla[6][0].getPlayer();
	prikaz[27][7] = tabla[6][0].getName();
	prikaz[27][12] = tabla[6][1].getPlayer();
	prikaz[27][13] = tabla[6][1].getName();
	prikaz[27][18] = tabla[6][2].getPlayer();
	prikaz[27][19] = tabla[6][2].getName();
	prikaz[27][24] = tabla[6][3].getPlayer();
	prikaz[27][25] = tabla[6][3].getName();
	prikaz[27][30] = tabla[6][4].getPlayer();
	prikaz[27][31] = tabla[6][4].getName();
	prikaz[27][36] = tabla[6][5].getPlayer();
	prikaz[27][37] = tabla[6][5].getName();
	prikaz[27][42] = tabla[6][6].getPlayer();
	prikaz[27][43] = tabla[6][6].getName();
	prikaz[27][48] = tabla[6][7].getPlayer();
	prikaz[27][49] = tabla[6][7].getName();
	prikaz[31][6] = tabla[7][0].getPlayer();
	prikaz[31][7] = tabla[7][0].getName();
	prikaz[31][12] = tabla[7][1].getPlayer();
	prikaz[31][13] = tabla[7][1].getName();
	prikaz[31][18] = tabla[7][2].getPlayer();
	prikaz[31][19] = tabla[7][2].getName();
	prikaz[31][24] = tabla[7][3].getPlayer();
	prikaz[31][25] = tabla[7][3].getName();
	prikaz[31][30] = tabla[7][4].getPlayer();
	prikaz[31][31] = tabla[7][4].getName();
	prikaz[31][36] = tabla[7][5].getPlayer();
	prikaz[31][37] = tabla[7][5].getName();
	prikaz[31][42] = tabla[7][6].getPlayer();
	prikaz[31][43] = tabla[7][6].getName();
	prikaz[31][48] = tabla[7][7].getPlayer();
	prikaz[31][49] = tabla[7][7].getName();

	for (int i = 0; i < 35; i++)
	{
		for (int j = 0; j < 57; j++)
			cout << prikaz[i][j];		/*Iscrtava sablon tablu*/

		cout << endl;
	}
	cout << endl << endl;
}

bool Sah(int x, int y, char igrac)
{
	if(x >= 1)
		for (int i = x - 1; i >= 0; i--) /*Proverava sva polja na gore do kraja table*/
		{
			if (tabla[i][y].getPlayer() == igrac) /*Ako naidje na sopstvenu figuru zaustavlja proveru*/
				break;

			if (tabla[i][y].getPlayer() != igrac && tabla[i][y].getPlayer() != ' ') /*Ako naidje na protivnicku proverava da li im je u liniji napada, ako jeste vraca sah, ako nije prekida proveru*/
			{
				if ((tabla[i][y].getName() == 'T' || tabla[i][y].getName() == 'D' || (tabla[i][y].getName() == 'K' && i == x - 1)) && tabla[i][y].getPlayer() != igrac)
				{
					x_sah = i;		/*cuva mesto figure koja je izazvala sah*/
					y_sah = y;
					figura_sah = tabla[i][y].getName();
					return true;
				}
				else
					break;
			}
		}
	
	if(x <= 6)
		for (int i = x + 1; i < 8; i++) /*Proverava sva polja na dole do kraja table*/
		{
			if (tabla[i][y].getPlayer() == igrac) /*Ako naidje na sopstvenu figuru zaustavlja proveru*/
				break;

			if (tabla[i][y].getPlayer() != igrac && tabla[i][y].getPlayer() != ' ') /*Ako naidje na protivnicku proverava da li im je u liniji napada, ako jeste vraca sah, ako nije prekida proveru*/
			{
				if ((tabla[i][y].getName() == 'T' || tabla[i][y].getName() == 'D' || (tabla[i][y].getName() == 'K' && i == x + 1)) && tabla[i][y].getPlayer() != igrac)
				{
					x_sah = i;		/*cuva mesto figure koja je izazvala sah*/
					y_sah = y;
					figura_sah = tabla[i][y].getName();
					return true;
				}
				else
					break;
			}
		}

	if(y <= 6)
		for (int i = y + 1; i < 8; i++) /*Proverava sva polja u desno do kraja table*/
		{
			if (tabla[x][i].getPlayer() == igrac) /*Ako naidje na sopstvenu figuru zaustavlja proveru*/
				break;

			if (tabla[x][i].getPlayer() != igrac && tabla[x][i].getPlayer() != ' ') /*Ako naidje na protivnicku proverava da li im je u liniji napada, ako jeste vraca sah, ako nije prekida proveru*/
			{
				if ((tabla[x][i].getName() == 'T' || tabla[x][i].getName() == 'D' || (tabla[x][i].getName() == 'K' && i == y + 1)) && tabla[x][i].getPlayer() != igrac)
				{
					x_sah = x;		/*cuva mesto figure koja je izazvala sah*/
					y_sah = i;
					figura_sah = tabla[x][i].getName();
					return true;
				}
				else
					break;
			}
		}
	
	if(y >= 1)
		for (int i = y - 1; i >= 0; i--) /*Proverava sva polja u levo do kraja table*/
		{
			if (tabla[x][i].getPlayer() == igrac) /*Ako naidje na sopstvenu figuru zaustavlja proveru*/
				break;

			if (tabla[x][i].getPlayer() != igrac && tabla[x][i].getPlayer() != ' ') /*Ako naidje na protivnicku proverava da li im je u liniji napada, ako jeste vraca sah, ako nije prekida proveru*/
			{
				if ((tabla[x][i].getName() == 'T' || tabla[x][i].getName() == 'D' || (tabla[x][i].getName() == 'K' && i == y - 1)) && tabla[x][i].getPlayer() != igrac)
				{
					x_sah = x;		/*cuva mesto figure koja je izazvala sah*/
					y_sah = i;
					figura_sah = tabla[x][i].getName();
					return true;
				}
				else
					break;
			}
		}

	if (x >= 1 && y <= 6)
	{
		int j = y + 1;
		for (int i = x - 1; i >= 0; i--) /*Proverava sva polja u desno na gore do kraja table*/
		{
			if (tabla[i][j].getPlayer() == igrac) /*Ako naidje na sopstvenu figuru zaustavlja proveru*/
				break;

			if (tabla[i][j].getPlayer() != igrac && tabla[i][j].getPlayer() != ' ') /*Ako naidje na protivnicku proverava da li im je u liniji napada, ako jeste vraca sah, ako nije prekida proveru*/
			{
				if ((tabla[i][j].getName() == 'L' || tabla[i][j].getName() == 'D' || (tabla[i][j].getName() == 'K' && i == x - 1 && j == y + 1) || (tabla[i][j].getName() == 'P' && i == x - 1 && j == y + 1 && tabla[i][j].getPlayer() == 'c')) && tabla[i][j].getPlayer() != igrac)
				{
					x_sah = i;		/*cuva mesto figure koja je izazvala sah*/
					y_sah = j;
					figura_sah = tabla[i][j].getName();
					return true;
				}
				else
					break;
			}
			if (j == 7)
				break;
			j++;
		}
	}

	if (x <= 6 && y <= 6)
	{
		int j = y + 1;
		for (int i = x + 1; i < 8; i++) /*Proverava sva polja u desno na dole do kraja table*/
		{
			if (tabla[i][j].getPlayer() == igrac) /*Ako naidje na sopstvenu figuru zaustavlja proveru*/
				break;

			if (tabla[i][j].getPlayer() != igrac && tabla[i][j].getPlayer() != ' ') /*Ako naidje na protivnicku proverava da li im je u liniji napada, ako jeste vraca sah, ako nije prekida proveru*/
			{
				if ((tabla[i][j].getName() == 'L' || tabla[i][j].getName() == 'D' || (tabla[i][j].getName() == 'K' && i == x + 1 && j == y + 1) || (tabla[i][j].getName() == 'P' && i == x + 1 && j == y + 1 && tabla[i][j].getPlayer() == 'b')) && tabla[i][j].getPlayer() != igrac)
				{
					x_sah = i;		/*cuva mesto figure koja je izazvala sah*/
					y_sah = j;
					figura_sah = tabla[i][j].getName();
					return true;
				}
				else
					break;
			}
			if (j == 7)
				break;
			j++;
		}
	}

	if (x >= 1 && y >= 1)
	{
		int j = y - 1;
		for (int i = x - 1; i >= 0; i--) /*Proverava sva polja u levo na gore do kraja table*/
		{
			if (tabla[i][j].getPlayer() == igrac) /*Ako naidje na sopstvenu figuru zaustavlja proveru*/
				break;

			if (tabla[i][j].getPlayer() != igrac && tabla[i][j].getPlayer() != ' ') /*Ako naidje na protivnicku proverava da li im je u liniji napada, ako jeste vraca sah, ako nije prekida proveru*/
			{
				if ((tabla[i][j].getName() == 'L' || tabla[i][j].getName() == 'D' || (tabla[i][j].getName() == 'K' && i == x - 1 && j == y - 1) || (tabla[i][j].getName() == 'P' && i == x - 1 && j == y - 1 && tabla[i][j].getPlayer() == 'c')) && tabla[i][j].getPlayer() != igrac)
				{
					x_sah = i;		/*cuva mesto figure koja je izazvala sah*/
					y_sah = j;
					figura_sah = tabla[i][j].getName();
					return true;
				}
				else
					break;
			}
			if (j == 0)
				break;
			j--;
		}
	}

	if (x <= 6 && y >= 1)
	{
		int j = y - 1;
		for (int i = x + 1; i < 8; i++) /*Proverava sva polja u levo na dole do kraja table*/
		{
			if (tabla[i][j].getPlayer() == igrac) /*Ako naidje na sopstvenu figuru zaustavlja proveru*/
				break;

			if (tabla[i][j].getPlayer() != igrac && tabla[i][j].getPlayer() != ' ') /*Ako naidje na protivnicku proverava da li im je u liniji napada, ako jeste vraca sah, ako nije prekida proveru*/
			{
				if ((tabla[i][j].getName() == 'L' || tabla[i][j].getName() == 'D' || (tabla[i][j].getName() == 'K' && i == x + 1 && j == y - 1) || (tabla[i][j].getName() == 'P' && i == x + 1 && j == y - 1 && tabla[i][j].getPlayer() == 'b')) && tabla[i][j].getPlayer() != igrac)
				{
					x_sah = i;		/*cuva mesto figure koja je izazvala sah*/
					y_sah = j;
					figura_sah = tabla[i][j].getName();
					return true;
				}
				else
					break;
			}
			if (j == 0)
				break;
			j--;
		}
	}

	if (x >= 2 && y >= 1 && tabla[x - 2][y - 1].getName() == 'S' && tabla[x - 2][y - 1].getPlayer() != igrac)
	{
		x_sah = x - 2;		/*cuva mesto figure koja je izazvala sah*/
		y_sah = y - 1;
		figura_sah = tabla[x - 2][y - 1].getName();
		return true;
	}
	if (x >= 2 && y <= 6 && tabla[x - 2][y + 1].getName() == 'S' && tabla[x - 2][y + 1].getPlayer() != igrac)
	{
		x_sah = x - 2;		/*cuva mesto figure koja je izazvala sah*/
		y_sah = y + 1;
		figura_sah = tabla[x - 2][y + 1].getName();
		return true;
	}
	if (x <= 5 && y >= 1 && tabla[x + 2][y - 1].getName() == 'S' && tabla[x + 2][y - 1].getPlayer() != igrac)
	{
		x_sah = x + 2;		/*cuva mesto figure koja je izazvala sah*/
		y_sah = y - 1;
		figura_sah = tabla[x + 2][y - 1].getName();
		return true;
	}
	if (x <= 5 && y <= 6 && tabla[x + 2][y + 1].getName() == 'S' && tabla[x + 2][y + 1].getPlayer() != igrac)
	{
		x_sah = x + 2;		/*cuva mesto figure koja je izazvala sah*/
		y_sah = y + 1;
		figura_sah = tabla[x + 2][y + 1].getName();
		return true;
	}																						/*Proverava da li mu preti sah od nekog skakaca*/
	if (x >= 1 && y >= 2 && tabla[x - 1][y - 2].getName() == 'S' && tabla[x - 1][y - 2].getPlayer() != igrac)
	{
		x_sah = x - 1;		/*cuva mesto figure koja je izazvala sah*/
		y_sah = y - 2;
		figura_sah = tabla[x - 1][y - 2].getName();
		return true;
	}
	if (x >= 1 && y <= 5 && tabla[x - 1][y + 2].getName() == 'S' && tabla[x - 1][y + 2].getPlayer() != igrac)
	{
		x_sah = x - 1;		/*cuva mesto figure koja je izazvala sah*/
		y_sah = y + 2;
		figura_sah = tabla[x - 1][y + 2].getName();
		return true;
	}
	if (x <= 6 && y >= 2 && tabla[x + 1][y - 2].getName() == 'S' && tabla[x + 1][y - 2].getPlayer() != igrac)
	{
		x_sah = x + 1;		/*cuva mesto figure koja je izazvala sah*/
		y_sah = y - 2;
		figura_sah = tabla[x + 1][y - 2].getName();
		return true;
	}
	if (x <= 6 && y <= 5 && tabla[x + 1][y + 2].getName() == 'S' && tabla[x + 1][y + 2].getPlayer() != igrac)
	{
		x_sah = x + 1;		/*cuva mesto figure koja je izazvala sah*/
		y_sah = y + 2;
		figura_sah = tabla[x + 1][y + 2].getName();
		return true;
	}
	
	return false; /*Ukoliko nije otkrio stanje saha, odgovara da ga nema*/
}

bool mogucPotez(int x, int y, int x1, int y1)
{

	if (x == x1 && y == y1) /*Ako je uneto startno polje potez se ne moze odigrati*/
		return false;

	if (tabla[x1][y1].getPlayer() == tabla[x][y].getPlayer()) /*Ako se na destinaciji nalazi sopstvena figura potez se ne moze odigrati*/
		return false;

	if(tabla[x][y].getName() == 'P') /*Sekvenca ukoliko se pomera pesak*/
	{
		if (tabla[x][y].getPlayer() == 'b') /*Beli pesak moze da odigra pod sledecim uslovima*/
			if (x1 == x - 1 && y1 == y && tabla[x1][y1].getName() == ' ' || x1 == x - 1 && y1 == y + 1 && tabla[x1][y1].getPlayer() == 'c' || x1 == x - 1 && y1 == y - 1 && tabla[x1][y1].getPlayer() == 'c' || x == 6 && x1 == x - 2 && y1 == y && tabla[x - 1][y1].getName() == ' ' && tabla[x1][y1].getName() == ' ')
				return true;

		if (tabla[x][y].getPlayer() == 'c') /*Crni pesak moze da odigra pod sledecim uslovima*/
			if (x1 == x + 1 && y1 == y && tabla[x1][y1].getName() == ' ' || x1 == x + 1 && y1 == y + 1 && tabla[x1][y1].getPlayer() == 'b' || x1 == x + 1 && y1 == y - 1 && tabla[x1][y1].getPlayer() == 'b' || x == 1 && x1 == x + 2 && y1 == y && tabla[x + 1][y1].getName() == ' ' && tabla[x1][y1].getName() == ' ')
				return true;

		return false; /*Nisu ispunjeni uslovi, pesak ne moze da odigra*/
	}

	if (tabla[x][y].getName() == 'T') /*Sekvenca ukoliko se pomera top*/
	{
		
		if (x1 != x && y1 != y) /*Ako pomeranje nije u x/y osi potez se ne moze odigrati*/
			return false;

		if (x1 > x) 
			for (int i = x + 1; i < x1; i++)		/*Ako se top pomera na dole i naleti na popunjeno polje izmedju sebe i cilja potez se ne moze odigrati*/
				if (tabla[i][y].getName() != ' ')
					return false;

		if (x1 < x)
			for (int i = x - 1; i > x1; i--)		/*Ako se top pomera na gore i naleti na popunjeno polje izmedju sebe i cilja potez se ne moze odigrati*/
				if (tabla[i][y].getName() != ' ')
					return false;

		if (y1 > y)
			for (int i = y + 1; i < y1; i++)		/*Ako se top pomera u desno i naleti na popunjeno polje izmedju sebe i cilja potez se ne moze odigrati*/
				if (tabla[x][i].getName() != ' ')
					return false;

		if (y1 < y)
			for (int i = y - 1; i > y1; i--)		/*Ako se top pomera u levo i naleti na popunjeno polje izmedju sebe i cilja potez se ne moze odigrati*/
				if (tabla[x][i].getName() != ' ')
					return false;
		
		return true; /*Uslovi za obustavljanje kretanja nisu ispunjeni, potez se moze odigrati*/
	}

	if (tabla[x][y].getName() == 'S') /*Sekvenca ukoliko se pomera skakac*/
	{
		if ((x1 == x - 2 || x1 == x + 2) && (y1 == y + 1 || y1 == y - 1))
			return true;
		else if ((x1 == x - 1 || x1 == x + 1) && (y1 == y + 2 || y1 == y - 2))	/*Ukoliko cilj nije u skladu sa pravilima kretanja skakaca, ne igra se*/
			return true;
		else
			return false;
	}

	if (tabla[x][y].getName() == 'L') /*Sekvenca ukoliko se pomera lovac*/
	{
		if (abs(x1 - x) != abs(y1 - y)) /*Ako pomeranje nije dijagonalno obustavlja se potez*/
			return false;

		if (x1 < x && y1 > y)
		{
			int j = y + 1;
			for (int i = x - 1; i > x1; i--)	/*Ako je neko polje popunjeno pre cilja dok se lovac krece u desno na gore obustavlja se potez*/
			{
				if (tabla[i][j].getName() != ' ')
					return false;
				j++;
			}
		}

		if (x1 < x && y > y1)
		{
			int j = y - 1;
			for (int i = x - 1; i > x1; i--)	/*Ako je neko polje popunjeno pre cilja dok se lovac krece u levo na gore obustavlja se potez*/
			{
				if (tabla[i][j].getName() != ' ')
					return false;
				j--;
			}
		}

		if (x < x1 && y > y1)
		{
			int j = y - 1;
			for (int i = x + 1; i < x1; i++) /*Ako je neko polje popunjeno pre cilja dok se lovac krece u levo na dole obustavlja se potez*/
			{
				if (tabla[i][j].getName() != ' ')
					return false;
				j--;
			}
		}

		if (x < x1 && y1 > y)
		{
			int j = y + 1;
			for (int i = x + 1; i < x1; i++) /*Ako je neko polje popunjeno pre cilja dok se lovac krece u desno na dole obustavlja se potez*/
			{
				if (tabla[i][j].getName() != ' ')
					return false;
				j++;
			}
		}
		return true; /*Uslovi za obustavljanje kretanja nisu ispunjeni, potez se moze odigrati*/
	}

	if (tabla[x][y].getName() == 'D') /*Sekvenca ukoliko se pomera lovac*/
	{
		if ((x1 != x && y1 != y) && (abs(x1 - x) != abs(y1 - y))) /*Ukoliko pomeranje nije u x/y osi niti dijagonalno obustavlja se potez*/
			return false;

		if (x1 > x && y1 == y) /*Provera na dole*/
			for (int i = x + 1; i < x1; i++)
				if (tabla[i][y].getName() != ' ')
					return false;

		if (x1 < x && y1 == y) /*Provera na gore*/
			for (int i = x - 1; i > x1; i--)
				if (tabla[i][y].getName() != ' ')
					return false;
		
		if (y1 > y && x1 == x) /*Provera u desno*/
			for (int i = y + 1; i < y1; i++)
				if (tabla[x][i].getName() != ' ')
					return false;

		if (y1 < y && x1 == x) /*Provera u levo*/
			for (int i = y - 1; i > y1; i--)
				if (tabla[x][i].getName() != ' ')
					return false;

		if (x1 < x && y1 > y && abs(x1 - x) == abs(y1 - y))
		{
			int j = y + 1;
			for (int i = x - 1; i > x1; i--)	/*Provera u desno na gore*/
			{
				if (tabla[i][j].getName() != ' ')
					return false;
				j++;
			}
		}

		if (x1 < x && y > y1 && abs(x1 - x) == abs(y1 - y))
		{
			int j = y - 1;
			for (int i = x - 1; i > x1; i--)	/*Provera u levo na gore*/
			{
				if (tabla[i][j].getName() != ' ')
					return false;
				j--;
			}
		}

		if (x < x1 && y > y1 && abs(x1 - x) == abs(y1 - y))
		{
			int j = y - 1;
			for (int i = x + 1; i < x1; i++)	/*Provera u levo na dole*/
			{
				if (tabla[i][j].getName() != ' ')
					return false;
				j--;
			}
		}

		if (x < x1 && y1 > y && abs(x1 - x) == abs(y1 - y))
		{
			int j = y + 1;
			for (int i = x + 1; i < x1; i++)	/*Provera u desno na dole*/
			{
				if (tabla[i][j].getName() != ' ')
					return false;
				j++;
			}
		}
		return true; /*Uslovi za obustavljanje kretanja nisu ispunjeni, potez se moze odigrati*/
	} 

	if (tabla[x][y].getName() == 'K') /*Sekvenca ukoliko se pomera kralj*/
	{
		if (velika_rokada_crni && tabla[x][y].getPlayer() == 'c' && y1 == y - 2 && x1 == x) /*Ako je crni igrac odigrao veliku rokadu*/
		{
			for (int i = y - 1; i > 0; i--)
				if (tabla[x][i].getName() != ' ')	/*Ako izmedju kralja i topa nisu sva prazna polja, rokada se ne moze odigrati*/
					return false;
			if (Sah(x, y, 'c') || Sah(x, y - 1, 'c') || Sah(x, y - 2, 'c')) /*Ako je bilo koje polje kroz koje kralj prolazi pod napadom rokada se ne igra*/
				return false;

			odradi_veliku_rokadu_crni = true;
			return true; /*Uslovi za rokadu su moguci, odigrace se*/
		}

		if (mala_rokada_crni && tabla[x][y].getPlayer() == 'c' && y1 == y + 2 && x1 == x) /*Ako je crni igrac odigrao malu rokadu*/
		{
			for (int i = y + 1; i < 7; i++)
				if (tabla[x][i].getName() != ' ')	/*Ako izmedju kralja i topa nisu sva prazna polja, rokada se ne moze odigrati*/
					return false;
			if (Sah(x, y, 'c') || Sah(x, y + 1, 'c') || Sah(x, y + 2, 'c')) /*Ako je bilo koje polje kroz koje kralj prolazi pod napadom rokada se ne igra*/
				return false;

			odradi_malu_rokadu_crni = true;
			return true; /*Uslovi za rokadu su moguci, odigrace se*/
		}

		if (velika_rokada_beli && tabla[x][y].getPlayer() == 'b' && y1 == y - 2 && x1 == x) /*Ako je beli igrac odigrao veliku rokadu*/
		{
			for (int i = y - 1; i > 0; i--)
				if (tabla[x][i].getName() != ' ')	/*Ako izmedju kralja i topa nisu sva prazna polja, rokada se ne moze odigrati*/
					return false;

			if (Sah(x, y, 'b') || Sah(x, y - 1, 'b') || Sah(x, y - 2, 'b')) /*Ako je bilo koje polje kroz koje kralj prolazi pod napadom rokada se ne igra*/
				return false;

			odradi_veliku_rokadu_beli = true;
			return true; /*Uslovi za rokadu su moguci, odigrace se*/
		}

		if (mala_rokada_beli && tabla[x][y].getPlayer() == 'b' && y1 == y + 2 && x1 == x) /*Ako je beli igrac odigrao malu rokadu*/
		{
			for (int i = y + 1; i < 7; i++)
				if (tabla[x][i].getName() != ' ')	/*Ako izmedju kralja i topa nisu sva prazna polja, rokada se ne moze odigrati*/
					return false;
				
			if (Sah(x, y, 'b') || Sah(x, y + 1, 'b') || Sah(x, y + 2, 'b')) /*Ako je bilo koje polje kroz koje kralj prolazi pod napadom rokada se ne igra*/
				return false;

			odradi_malu_rokadu_beli = true;
			return true; /*Uslovi za rokadu su moguci, odigrace se*/
		}

		if (abs(x1 - x) > 1 || abs(y1 - y) > 1) /*Ukoliko cilj nije u skladu sa pravilima kretanja kralja, ne igra se*/
			return false;
		return true;
	}
}

bool poljeSeMozeBlokirati(int x, int y, char igrac)
{
	if (x >= 1)
		for (int i = x - 1; i >= 0; i--) /*Proverava sva polja na gore do kraja table*/
		{
			if (tabla[i][y].getPlayer() == igrac) /*Ako naidje na sopstvenu figuru zaustavlja proveru*/
				break;

			if (tabla[i][y].getPlayer() != igrac && tabla[i][y].getPlayer() != ' ') /*Ako naidje na protivnicku proverava da li im je u liniji napada, ako jeste vraca sah, ako nije prekida proveru*/
			{
				if ((tabla[i][y].getName() == 'T' || tabla[i][y].getName() == 'D') && tabla[i][y].getPlayer() != igrac)
					return true;
				else
					break;
			}
		}

	if (x <= 6)
		for (int i = x + 1; i < 8; i++) /*Proverava sva polja na dole do kraja table*/
		{
			if (tabla[i][y].getPlayer() == igrac) /*Ako naidje na sopstvenu figuru zaustavlja proveru*/
				break;

			if (tabla[i][y].getPlayer() != igrac && tabla[i][y].getPlayer() != ' ') /*Ako naidje na protivnicku proverava da li im je u liniji napada, ako jeste vraca sah, ako nije prekida proveru*/
			{
				if ((tabla[i][y].getName() == 'T' || tabla[i][y].getName() == 'D') && tabla[i][y].getPlayer() != igrac)
					return true;
				else
					break;
			}
		}

	if (y <= 6)
		for (int i = y + 1; i < 8; i++) /*Proverava sva polja u desno do kraja table*/
		{
			if (tabla[x][i].getPlayer() == igrac) /*Ako naidje na sopstvenu figuru zaustavlja proveru*/
				break;

			if (tabla[x][i].getPlayer() != igrac && tabla[x][i].getPlayer() != ' ') /*Ako naidje na protivnicku proverava da li im je u liniji napada, ako jeste vraca sah, ako nije prekida proveru*/
			{
				if ((tabla[x][i].getName() == 'T' || tabla[x][i].getName() == 'D') && tabla[x][i].getPlayer() != igrac)
					return true;
				else
					break;
			}

			if(x >= 1 && tabla[x - 1][i].getName() == 'P' && tabla[x - 1][i].getPlayer() == 'c') /*ako iznad praznog polja koje se proverava se nalazi crni pesak, polje se moze preseci*/
				return true;
			if(x >= 2 && tabla[x - 2][i].getName() == 'P' && tabla[x - 2][i].getPlayer() == 'c' && tabla[x - 1][i].getPlayer() == ' ')
				return true;
			if(x <= 6 && tabla[x + 1][i].getName() == 'P' && tabla[x + 1][i].getPlayer() == 'b') /*ako ispod praznog polja koje se proverava se nalazi beli pesak, polje se moze preseci*/
				return true;
			if(x <= 5 && tabla[x + 2][i].getName() == 'P' && tabla[x + 2][i].getPlayer() == 'b' && tabla[x + 1][i].getPlayer() == ' ')
				return true;
		}

	if (y >= 1)
		for (int i = y - 1; i >= 0; i--) /*Proverava sva polja u levo do kraja table*/
		{
			if (tabla[x][i].getPlayer() == igrac) /*Ako naidje na sopstvenu figuru zaustavlja proveru*/
				break;

			if (tabla[x][i].getPlayer() != igrac && tabla[x][i].getPlayer() != ' ') /*Ako naidje na protivnicku proverava da li im je u liniji napada, ako jeste vraca sah, ako nije prekida proveru*/
			{
				if ((tabla[x][i].getName() == 'T' || tabla[x][i].getName() == 'D') && tabla[x][i].getPlayer() != igrac)
					return true;
				else
					break;
			}

			if (x >= 1 && tabla[x - 1][i].getName() == 'P' && tabla[x - 1][i].getPlayer() == 'c') /*ako iznad praznog polja koje se proverava se nalazi crni pesak, polje se moze preseci*/
				return true;
			if (x >= 2 && tabla[x - 2][i].getName() == 'P' && tabla[x - 2][i].getPlayer() == 'c' && tabla[x - 1][i].getPlayer() == ' ')
				return true;
			if (x <= 6 && tabla[x + 1][i].getName() == 'P' && tabla[x + 1][i].getPlayer() == 'b') /*ako ispod praznog polja koje se proverava se nalazi beli pesak, polje se moze preseci*/
				return true;
			if (x <= 5 && tabla[x + 2][i].getName() == 'P' && tabla[x + 2][i].getPlayer() == 'b' && tabla[x + 1][i].getPlayer() == ' ')
				return true;
		}

	if (y <= 6 && x >= 1)
	{
		int j = y + 1;
		for (int i = x - 1; i >= 0; i--) /*Proverava sva polja u desno na gore do kraja table*/
		{
			if (tabla[i][j].getPlayer() == igrac) /*Ako naidje na sopstvenu figuru zaustavlja proveru*/
				break;

			if (tabla[i][j].getPlayer() != igrac && tabla[i][j].getPlayer() != ' ') /*Ako naidje na protivnicku proverava da li im je u liniji napada, ako jeste vraca sah, ako nije prekida proveru*/
			{
				if ((tabla[i][j].getName() == 'L' || tabla[i][j].getName() == 'D') && tabla[i][j].getPlayer() != igrac)
					return true;
				else
					break;
			}

			if (i >= 1 && tabla[i - 1][j].getName() == 'P' && tabla[i - 1][j].getPlayer() == 'c') /*ako iznad praznog polja koje se proverava se nalazi crni pesak, polje se moze preseci*/
				return true;
			if (i >= 2 && tabla[i - 2][j].getName() == 'P' && tabla[i - 2][j].getPlayer() == 'c' && tabla[i - 1][j].getPlayer() == ' ')
				return true;
			if (i <= 6 && tabla[i + 1][j].getName() == 'P' && tabla[i + 1][j].getPlayer() == 'b') /*ako ispod praznog polja koje se proverava se nalazi beli pesak, polje se moze preseci*/
				return true;
			if (i <= 5 && tabla[i + 2][j].getName() == 'P' && tabla[i + 2][j].getPlayer() == 'b' && tabla[i + 1][j].getPlayer() == ' ')
				return true;

			if (j == 7)
				break;
			j++;
		}
	}

	if (y <= 6 && x <= 6)
	{
		int j = y + 1;
		for (int i = x + 1; i < 8; i++) /*Proverava sva polja u desno na dole do kraja table*/
		{
			if (tabla[i][j].getPlayer() == igrac) /*Ako naidje na sopstvenu figuru zaustavlja proveru*/
				break;

			if (tabla[i][j].getPlayer() != igrac && tabla[i][j].getPlayer() != ' ') /*Ako naidje na protivnicku proverava da li im je u liniji napada, ako jeste vraca sah, ako nije prekida proveru*/
			{
				if ((tabla[i][j].getName() == 'L' || tabla[i][j].getName() == 'D') && tabla[i][j].getPlayer() != igrac)
					return true;
				else
					break;
			}

			if (i >= 1 && tabla[i - 1][j].getName() == 'P' && tabla[i - 1][j].getPlayer() == 'c') /*ako iznad praznog polja koje se proverava se nalazi crni pesak, polje se moze preseci*/
				return true;
			if (i >= 2 && tabla[i - 2][j].getName() == 'P' && tabla[i - 2][j].getPlayer() == 'c' && tabla[i - 1][j].getPlayer() == ' ')
				return true;
			if (i <= 6 && tabla[i + 1][j].getName() == 'P' && tabla[i + 1][j].getPlayer() == 'b') /*ako ispod praznog polja koje se proverava se nalazi beli pesak, polje se moze preseci*/
				return true;
			if (i <= 5 && tabla[i + 2][j].getName() == 'P' && tabla[i + 2][j].getPlayer() == 'b' && tabla[i + 1][j].getPlayer() == ' ')
				return true;

			if (j == 7)
				break;
			j++;
		}
	}

	if (y >= 1 && x >= 1)
	{
		int j = y - 1;
		for (int i = x - 1; i >= 0; i--) /*Proverava sva polja u levo na gore do kraja table*/
		{
			if (tabla[i][j].getPlayer() == igrac) /*Ako naidje na sopstvenu figuru zaustavlja proveru*/
				break;

			if (tabla[i][j].getPlayer() != igrac && tabla[i][j].getPlayer() != ' ') /*Ako naidje na protivnicku proverava da li im je u liniji napada, ako jeste vraca sah, ako nije prekida proveru*/
			{
				if ((tabla[i][j].getName() == 'L' || tabla[i][j].getName() == 'D') && tabla[i][j].getPlayer() != igrac)
					return true;
				else
					break;
			}

			if (i >= 1 && tabla[i - 1][j].getName() == 'P' && tabla[i - 1][j].getPlayer() == 'c') /*ako iznad praznog polja koje se proverava se nalazi crni pesak, polje se moze preseci*/
				return true;
			if (i >= 2 && tabla[i - 2][j].getName() == 'P' && tabla[i - 2][j].getPlayer() == 'c' && tabla[i - 1][j].getPlayer() == ' ')
				return true;
			if (i <= 6 && tabla[i + 1][j].getName() == 'P' && tabla[i + 1][j].getPlayer() == 'b') /*ako ispod praznog polja koje se proverava se nalazi beli pesak, polje se moze preseci*/
				return true;
			if (i <= 5 && tabla[i + 2][j].getName() == 'P' && tabla[i + 2][j].getPlayer() == 'b' && tabla[i + 1][j].getPlayer() == ' ')
				return true;

			if (j == 0)
				break;
			j--;
		}
	}

	if (y >= 1 && x <= 6)
	{
		int j = y - 1;
		for (int i = x + 1; i < 8; i++) /*Proverava sva polja u levo na dole do kraja table*/
		{
			if (tabla[i][j].getPlayer() == igrac) /*Ako naidje na sopstvenu figuru zaustavlja proveru*/
				break;

			if (tabla[i][j].getPlayer() != igrac && tabla[i][j].getPlayer() != ' ') /*Ako naidje na protivnicku proverava da li im je u liniji napada, ako jeste vraca sah, ako nije prekida proveru*/
			{
				if ((tabla[i][j].getName() == 'L' || tabla[i][j].getName() == 'D') && tabla[i][j].getPlayer() != igrac)
					return true;
				else
					break;
			}

			if (i >= 1 && tabla[i - 1][j].getName() == 'P' && tabla[i - 1][j].getPlayer() == 'c') /*ako iznad praznog polja koje se proverava se nalazi crni pesak, polje se moze preseci*/
				return true;
			if (i >= 2 && tabla[i - 2][j].getName() == 'P' && tabla[i - 2][j].getPlayer() == 'c' && tabla[i - 1][j].getPlayer() == ' ')
				return true;
			if (i <= 6 && tabla[i + 1][j].getName() == 'P' && tabla[i + 1][j].getPlayer() == 'b') /*ako ispod praznog polja koje se proverava se nalazi beli pesak, polje se moze preseci*/
				return true;
			if (i <= 5 && tabla[i + 2][j].getName() == 'P' && tabla[i + 2][j].getPlayer() == 'b' && tabla[i + 1][j].getPlayer() == ' ')
				return true;

			if (j == 0)
				break;
			j--;
		}
	}

	if (x >= 2 && y >= 1 && tabla[x - 2][y - 1].getName() == 'S' && tabla[x - 2][y - 1].getPlayer() != igrac)
		return true;
	if (x >= 2 && y <= 6 && tabla[x - 2][y + 1].getName() == 'S' && tabla[x - 2][y + 1].getPlayer() != igrac)
		return true;
	if (x <= 5 && y >= 1 && tabla[x + 2][y - 1].getName() == 'S' && tabla[x + 2][y - 1].getPlayer() != igrac)
		return true;
	if (x <= 5 && y <= 6 && tabla[x + 2][y + 1].getName() == 'S' && tabla[x + 2][y + 1].getPlayer() != igrac)
		return true;
	if (x >= 1 && y >= 2 && tabla[x - 1][y - 2].getName() == 'S' && tabla[x - 1][y - 2].getPlayer() != igrac)
		return true;
	if (x >= 1 && y <= 5 && tabla[x - 1][y + 2].getName() == 'S' && tabla[x - 1][y + 2].getPlayer() != igrac)
		return true;
	if (x <= 6 && y >= 2 && tabla[x + 1][y - 2].getName() == 'S' && tabla[x + 1][y - 2].getPlayer() != igrac)
		return true;
	if (x <= 6 && y <= 5 && tabla[x + 1][y + 2].getName() == 'S' && tabla[x + 1][y + 2].getPlayer() != igrac)
		return true;

	return false; /*Ukoliko nije otkrio stanje saha, odgovara da ga nema*/
}