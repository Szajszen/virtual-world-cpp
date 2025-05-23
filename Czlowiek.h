#pragma once
#include "Zwierze.h"

class Czlowiek :public Zwierze {
private:
	void calopalenie();
	int calopalenieLicznik;
	bool calopalenieAktywne;

public:
	Czlowiek(Swiat* biezacySwiat, int polozenieX, int polozenieY, int dlugoscZycia);
	~Czlowiek() override;
	std::string getNazwa() override;
	void rysowanie() override;
	void akcja() override;
	void rozmnazanie(Punkt p);
	Organizm* rozmnazanieKonkretneZwierze(Punkt p);
	bool czyCalopalenieAktywne() const;

};