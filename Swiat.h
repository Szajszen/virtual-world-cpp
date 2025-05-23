#pragma once

#include <iostream>
#include <cstdlib>
#include <vector> 
#include <ctime>
#include "Organizm.h"
#include "Punkt.h"

class Organizm;

class Swiat {
	int rozmiarSwiataX;
	int rozmiarSwiataY;
	bool czyKoniecGry;
	bool czyCzlowiekZyje;
public:
	Swiat();
	Swiat(int rozmiarSwiataX, int rozmiarSwiataY);
	Swiat(Swiat&& zapisanySwiat);
	~Swiat();
	int getRozmiarSwiataX();
	int getRozmiarSwiataY();
	void setRozmiarSwiataX(int x);
	void setRozmiarSwiataY(int y);
	bool getCzyKoniecGry();
	bool getCzyCzlowiekZyje();
	void setCzyKoniecGry(bool n);
	void setCzyCzlowiekZyje(bool n);
	void losoweMiejsce(int rozmiarSwiataX, int rozmiarSwiataY, Organizm*** organizmyPlansza, Organizm* nowyOrganizm);
	void wykonajTure();
	void rysujSwiat();
	void zapiszSwiat();
	static Swiat* otworzSwiat();
	bool czyCzlowiekUmarl();
	void kolejkaSortOrganizmy();
	void usunOrganizm(Organizm* organizm);
	Organizm*** organizmyPlansza;
	std::vector<Organizm*> organizmy;
};

