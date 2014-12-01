/*	
	Stw�rz klas� pkt przechowuj�c�: 
		wsp�rz�dne x, y punkt�w (atrybut klasy), 
		nazw� punktu (atrybut klasy), 
		funkcj�, kt�ra pozwala wypisywa� informacje na temat tworzonych obiekt�w typu pkt, 
		funkcj� ustawiaj�c� sk�adniki klasy pkt, 
		funkcje pobieraj�ce informacje o atrybutach klasy, 
		funkcj�, kt�ra zwraca odleg�o�� tego punktu od pocz�tku uk�adu wsp�rz�dnych,
	Nast�pnie dla takiej klasy w funkcji main utw�rz: 
		funkcj� globaln�, kt�ra oblicza odleg�o�� mi�dzy dwoma obiektami typu pkt, 
		Obiekty klasy pkt w spos�b:
			o statyczny,
			o dynamiczny,
			o tablice 10-o elementow� obiekt�w typu pkt,
			o tablic� wska�nik�w do obiekt�w klasy pkt ; 
		Dla tak stworzonych obiekt�w, zaprezentuj spos�b dost�pu do sk�adowych x, y; 
		Zademonstruj spos�b usuwania obiekt�w stworzonych w spos�b; 
		Pobierz atrybuty klasy dla danego obiektu klasy pkt, 
		Ustaw atrybuty klasy dla tablicy obiekt�w klasy pkt, 
		Wypisz informacje na temat stworzonych obiekt�w.
	UWAGA:
	Atrybuty klasy nale�y umie�ci� w prywatnym zakresie klasy.
*/

#include<iostream>
#include<ctime>
#include"pkt.h"
using namespace std;

float odleglosc(pkt &p_A, pkt &p_B)
{
	float odl, w_a, w_b, w_c, w_d, dl_a, dl_b;

	p_A.pobierz_info(w_a, w_b);
	p_B.pobierz_info(w_c, w_d);
	
	dl_a = (w_c - w_a) * (w_c - w_a);
	dl_b = (w_d - w_b) * (w_d - w_b);

	odl = sqrt(dl_a + dl_b);

	return odl;
}


int main()
{
	
	string nazwa;
	float wsp_x, wsp_y;
	bool wybor = 0;

	do
	{

//#############################################################################################################

		pkt A, B;
		cout << "Obiekty automatyczne:\n" << "Podaj nazwe punktu I: ";
		getline(cin, nazwa);
		cout << "\twartosc x: ";
		cin >> wsp_x;
		cout << "\twartosc y: ";
		cin >> wsp_y;
		cout << endl;
		
		A.ustaw(nazwa, wsp_x, wsp_y);
		getline(cin, nazwa);
	
		cout << "Podaj nazwe punktu II: ";
		getline(cin, nazwa);
		cout << "\twartosc x: ";
		cin >> wsp_x;
		cout << "\twartosc y: ";
		cin >> wsp_y;
					
		B.ustaw(nazwa, wsp_x, wsp_y);
		getline(cin, nazwa);
		cout << "\n" << endl;

		A.wypisz();

		cout << endl;

		B.wypisz();
		cout << "\n" << endl;

		cout << "Dlugosc wektrora wynosi: " << odleglosc(A, B);
		cout << "\n\n\n" << endl;

		
//#############################################################################################################
			
		cout << "Obiekty dynamiczne:\n" << "Podaj nazwe punktu I: ";
		getline(cin, nazwa);
		cout << "\twartosc x: ";
		cin >> wsp_x;
		cout << "\twartosc y: ";
		cin >> wsp_y;
		cout << endl;
		
		pkt *A_dyn = new pkt;

		A_dyn -> ustaw(nazwa, wsp_x, wsp_y);
		getline(cin, nazwa);
	
		cout << "Podaj nazwe punktu II: ";
		getline(cin, nazwa);
		cout << "\twartosc x: ";
		cin >> wsp_x;
		cout << "\twartosc y: ";
		cin >> wsp_y;
				
		pkt *B_dyn = new pkt;

		B_dyn -> ustaw(nazwa, wsp_x, wsp_y);
		cout << "\n" << endl;

		A_dyn -> wypisz();

		cout << endl;

		B_dyn -> wypisz();
		cout << "\n" << endl;

		cout << "Dlugosc wektrora wynosi: " << odleglosc(*A_dyn, *B_dyn);
		cout << "\n\n\n" << endl;

		delete A_dyn, B_dyn;

//#############################################################################################################
	
		cout << "Tablica 10-o elementowa:\n";
		pkt tab[10];
		srand(time(NULL));

		for(int i = 0 ; i < 10 ; ++i)
		{
			string a = "1234567890";
			a = a[i];
			tab[i].ustaw(a, rand()/(float)100, rand()/(float)100);
		}

		cout << "Wyswietlamy rezultat:\n";

		for(int i = 0 ; i < 10 ; ++i)
			tab[i].wypisz();
		
		cout << "\n\n" << endl;
		
//#############################################################################################################
	
		cout << "Tablica wskaznikow do obiektow:\n";

		pkt *tabl[10];

		for(int i = 0 ; i < 10 ; ++i)
		{
			string a = "1234567890";
			a = a[i];
			tabl[i] = new pkt;
			tabl[i] -> ustaw(a, rand()/(float)100, rand()/(float)100);
		}

		cout << "Wyswietlamy rezultat:\n";

		for(int i = 0 ; i < 10 ; ++i)
		{
			tabl[i] -> wypisz();
			delete tabl[i];
		}		

		cout << "\n\n" << endl;

//#############################################################################################################

		cout << "Kontynuowac? ";
		cin >> wybor;
		getline(cin, nazwa);
		cout << endl;
	}
	while(wybor);

	system ("PAUSE");
	return 0;
}