#pragma once
#include "Zwierze.h"

class Owca :public Zwierze {
public:
	Owca(Swiat* biezacySwiat, int polozenieX, int polozenieY, int dlugoscZycia);
	~Owca() override;
	std::string getNazwa() override;
	void rysowanie() override;
	void rozmnazanie(Punkt p);
	Organizm* rozmnazanieKonkretneZwierze(Punkt p);
};