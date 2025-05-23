#pragma once
#include "Zwierze.h"

class Wilk :public Zwierze {
public:
	Wilk(Swiat* biezacySwiat, int polozenieX, int polozenieY, int dlugoscZycia);
	~Wilk() override;
	std::string getNazwa() override;
	void rysowanie() override;
	void rozmnazanie(Punkt p);
	Organizm* rozmnazanieKonkretneZwierze(Punkt p);
};