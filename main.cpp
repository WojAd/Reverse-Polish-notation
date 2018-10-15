#include "ONP.h"

#include <fstream>

int main()
{
	using namespace std;
	fstream plik;

	try
	{
		plik.open("data.txt", ios::in);
		if (!plik.is_open())
			throw 0;
		while (!plik.eof())
		{
			ONP Obliczenia;
			plik >> Obliczenia;
			cout << Obliczenia << endl;
		}
	}
	catch (int& e)
	{
		if (e == 0)
		{
			cout << endl << "Plik nie istnieje" << endl;
		}
		if (e == 1)
		{
			cout << endl << "Plik jest pusty" << endl;
		}
		if (e == 2)
		{
			cout << endl << "blad skladni, niewlasciwa ilosc operatorow" << endl;
		}
		if (e == 3)
		{
			cout << endl << "Napotkano niestandardowy znak" << endl;
		}
	}
	catch (...)
	{
		cout << endl << "nieznany blad" << endl;
	}

	cout << endl << "Koniec programu" << endl;
	cin.get();


	return 0;
}