#pragma once
#include "Zwierze.h"

class Lis :public Zwierze {
public:
	Lis(Swiat* biezacySwiat, int polozenieX, int polozenieY, int dlugoscZycia);
	~Lis() override;
	std::string getNazwa() override;
	void rysowanie() override;
	void akcja() override;
	void rozmnazanie(Punkt p);
	Organizm* rozmnazanieKonkretneZwierze(Punkt p);
};