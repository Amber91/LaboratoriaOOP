/*
Napisz program, obliczaj�cy pozwalaj�cy na obliczenie �redniej arytmetycznej z podanych
liczb. Ilo�� liczb nie jest zadawana w czasie dzia�ania programu tylko wyliczana na podstawie
pyta� zadawanych podczas dzia�ania programu.
*/

#include<iostream>

using namespace std;

int main()
{
	float liczba = 1, suma = 0;
	int ilosc = 0;
	
	while(liczba)
	{
		cout << "Podaj liczbe calkowita\\0 liczy srednia\\ ";
		cin >> liczba;
		
		if (liczba)
		{
			cout << endl;
			suma += liczba;
			++ilosc;
		}		
	};

	cout << "Srednia arytmetyczna wynosi: " << suma/ilosc << endl;

	system ("PAUSE");
	return 0;
}