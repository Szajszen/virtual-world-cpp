#pragma once
#include "Zwierze.h"

class Zolw :public Zwierze {
public:
	Zolw(Swiat* biezacySwiat, int polozenieX, int polozenieY, int dlugoscZycia);
	~Zolw() override;
	std::string getNazwa() override;
	void rysowanie() override;
	void akcja() override;
	void rozmnazanie(Punkt p);
	bool czyOdbijaAtak(Organizm* organizm) override;
	Organizm* rozmnazanieKonkretneZwierze(Punkt p);
};