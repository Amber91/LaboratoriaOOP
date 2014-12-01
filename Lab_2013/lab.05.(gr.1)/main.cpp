/*
Zdefiniuj klas� LiczbaZespolona oraz stosowne funkcje, konstruktory oraz funkcje
operatorowe, ponadto uzupe�nij klas� LiczbaZespolona tak, aby mo�liwe sta�o si�
wykonywanie nast�puj�cego kodu:
LiczbaZespolona z1, z2(1,2), z3(z2);
cout<< z1; cout<< z2; cout<< z3;
int a;
z1 = z2 + z3;
cout<< z1; cout<< z2; cout<< z3;
z1 = z1 - z3;
cout<< z1; cout<< z2; cout<< z3;
z3 = z1 * z2;
cout<< z1; cout<< z2; cout<< z3;
z1 = z2.liczbaPrzeciwna();
cout<< z1; cout<< z2;
z3 = liczbaSprzezona(z1);
cout<< z1; cout<< z3;
a = !z2; //modul z liczby zespolonej z2
cout<< a;
cout<< z1; cout<< z2; cout<< z3;
UWAGA:
Dla liczby zespolonej z1(a,b) -> z1 = a + bi oraz z2(c,d) -> z2 = c + di
gdzie: a,c -> to cz�ci rzeczywiste, b,d -> cz�ci urojone,
operacje arytmetyczne przedstawiaj� si� nast�puj�co:
- dodawanie: z1 + z2 = (a+c) + (b+d)i,
- odejmowanie: z1- z2 = (a-c) + (b-d)i,
- mno�enie: z1*z2 = (ac-bd)+ (ad+ bc)i,
- modu� z z1: z1 = pierwiastek(a^2 + b^2),
- liczba przeciwna do liczby zespolonej z1: -z1 = -a - bi,
- liczb� sprz�on� z liczb� z1: z1* = a - bi.
*/

#include<iostream>
#include"LiczbaZespolona.h"

using namespace std;

LiczbaZespolona liczbaSprzezona(LiczbaZespolona LZ)
{
	double x, y;
	LZ.pobierz_info(x, y);

	x *= x;
	y *= (-y);

	LZ.ustaw(x, y);

	return LZ;
}

ostream & operator<<(ostream & ekran, LiczbaZespolona LZ)
{
	double x, y;
	LZ.pobierz_info(x, y);

	ekran << "Liczba zespolona: " << x; 
		if(y >= 0)
			ekran << " + " << x << "i" << endl;
		else
			ekran << " - " << -y << "i" << endl;

	return ekran;
}

int main()
{
	LiczbaZespolona z1, z2(1,2), z3(z2);
	cout<< z1; cout<< z2; cout<< z3;
	int a;
	z1 = z2 + z3;
	cout<< z1; cout<< z2; cout<< z3;
	z1 = z1 - z3;
	cout<< z1; cout<< z2; cout<< z3;
	z3 = z1 * z2;
	cout<< z1; cout<< z2; cout<< z3;
	z1 = z2.liczbaPrzeciwna();
	cout<< z1; cout<< z2;
	z3 = liczbaSprzezona(z1);
	cout<< z1; cout<< z3;
	a = !z2; //modul z liczby zespolonej z2
	cout	<< a;
	cout<< z1; cout<< z2; cout<< z3;

	system("PAUSE");
	return 0;
}