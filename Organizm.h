#pragma once
#include <iostream>
#include <string>
#include "Swiat.h"
#include "Punkt.h"
class Swiat;

class Organizm {
protected:
	Swiat* biezacySwiat;
	int sila;
	int inicjatywa;
	int polozenieX;
	int polozenieY;
	int dlugoscZycia;
	bool czyUmarl;
public:
	Organizm(Swiat* biezacySwiat, int sila, int inicjatywa, int polozenieX, int polozenieY, int dlugoscZycia);
	int getSila();
	int getInicjatywa();
	int getDlugoscZycia();
	int getX();
	int getY();
	bool getCzyUmarl();
	void setCzyUmarl(bool n);
	void wykonajRuch(Punkt p);
	virtual std::string getNazwa() = 0;
	void setX(int x);
	void setY(int y);
	void setDlugoscZycia(int dlugoscZycia);
	void setSila(int sila);
	void setSwiat(Swiat* swiat);

	virtual bool umiejetnoscSpecjalna(Organizm* atak, Organizm* obrona);
	virtual void rozmnazanie(Punkt pkt) = 0;
	virtual Organizm* rozmnazanieKonkretneZwierze(Punkt p) = 0;
	virtual void akcja() = 0;
	virtual void kolizja(Organizm* organizm) = 0;
	virtual void rysowanie() = 0;
	virtual Punkt losujWolneMiejsce();
	virtual Punkt wolneMiejsceObok(Punkt pkt);
	virtual Punkt losoweMiejsceObok(Punkt pkt);
	virtual bool czyWolneMiejsce(Punkt pkt);
	virtual bool czyZwierze();
	virtual bool czyOdbijaAtak(Organizm* organizm);
	virtual ~Organizm();
};