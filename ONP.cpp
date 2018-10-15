#include "ONP.h"

void ONP::AddToStos(std::string Data)
{
	using namespace std;

	switch (Data[0])
	{
	case '+':
		if (Stos.size() < 2)
			throw(2);
		Stos.at(Stos.size() - 2) += Stos.back();
		Stos.pop_back();
		break;

	case '-':
		if (Stos.size() < 2)
			throw(2);
		Stos.at(Stos.size() - 2) -= Stos.back();
		Stos.pop_back();
		break;

	case '*':
		if (Stos.size() < 2)
			throw(2);
		Stos.at(Stos.size() - 2) *= Stos.back();
		Stos.pop_back();
		break;

	case '/':
		if (Stos.size() < 2)
			throw(2);
		Stos.at(Stos.size() - 2) /= Stos.back();
		Stos.pop_back();
		break;
	default:
		int liczba = 0;
		for (int x = Data.size() - 1, y = 0; x >= 0; x--, y++)
		{
			if (Data[x] < '0' || Data[x] > '9')
				throw 3;
			liczba += (Data[x] - '0') * (int)pow(10, y);
		}
		Stos.push_back(liczba);
		break;
	}
}

//Operator wypisuje do strumienia wynik pod warunkiem, ze na stosie znajduje sie tylko jedna liczba, czyli zgodnie z algorytmem dla odwrotnej notacji polskiej nasz wynik.
std::ostream& operator << (std::ostream& os, const ONP& q)
{
	using namespace std;
	if (q.Stos.size() != 1)
		throw(2);
	os << q.Stos.back();
	return os;
}

//Operator pobiera ze strumienia liczby lub znaki +, -, *, / i wykonuje na nich dzialania poslugujac sie algorytmem dla odwrotnej notacji polskiej
std::istream& operator >> (std::istream& is, ONP& q)
{
	using namespace std;
	string Data;

	is >> Data;
	if (is.eof())
		throw 1;

	do
	{
		q.AddToStos(Data);

		is >> Data;

	} 
	while (is.get() != '\n' && !is.eof());
	q.AddToStos(Data);

	if (q.Stos.size() != 1)
		throw(2);

	return is;
}

ONP::ONP()
{

}

ONP::~ONP()
{
	Stos.clear();
}