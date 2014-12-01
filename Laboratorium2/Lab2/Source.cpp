#include <iostream>
#include "pkt.h"
#include "prosta.h"

using namespace std;



int main()
{
	pkt p1, p2(2, 5), p3(3, 7), p4(p3);
	prosta pr1, pr2(p2, p3), pr3(pr2);
	p1.wypisz();
	p2.wypisz();// wspolrzedne punktu (2,5)
	p3.wypisz();
	p4.wypisz();
	pr1.wypisz();
	pr2.wypisz();
	// prosta przechodzi przez punkty (2,5) (3,7) i ma r�wnanie y = 2x + 1
	pr3.wypisz();
	//pr1.SprawdzRownoleglosc(pr2);
	// tu ma by� informacja czy proste s� r�wnoleg�e 
	//SprawdzProstopadlosc(pr2, pr3);
	// tu ma by� informacja czy proste s� prostopad�e
	p1 = p2.suma(p3);
	// dodawanie dwoch punkt�w
	p1.wypisz();
	p2 = roznica(p1, p3);
	// odejmowanie dwoch punktow
	wypisz(p2);
	wypisz(pr1);
	// wypisanie informacji o punktach Np.: �Prosta y =ax+b przechodzi przez punkty...
	return 0;
}