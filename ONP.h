#ifndef ONP_H
#define ONP_H

/*
Klasa zostala napisana wczasie wykonywania dodatkowego zadania na zajecia prowadzone przez UKSW

Klasa sluzy do obliczania wyniku podawanego do strumienia na podstawie danych pobieranych ze strumienia wedlug zasad odwrotnej notacji polskiej.

ver 1.0
- Klasa dziala z podstawowymi operatorami +, -, /, *

Adrian Wojciechowski
*/

#include <iostream>
#include <string>
#include <deque>
#include <math.h>

class ONP
{
	void AddToStos(std::string Data);

public:
	ONP();
	~ONP();

	std::deque<int> Stos;

	friend std::istream& operator >> (std::istream& is, ONP& q);
	friend std::ostream& operator << (std::ostream& os, const ONP& q);
};

#endif	//ONP_H