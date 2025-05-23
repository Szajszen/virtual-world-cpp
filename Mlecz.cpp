#include <iostream>
#include "Mlecz.h"

class Organizm;


Mlecz::Mlecz(Swiat* biezacySwiat, int polozenieX, int polozenieY, int dlugoscZycia)
	:Rosliny(biezacySwiat, 0, 0, polozenieX, polozenieY, dlugoscZycia) {
}

void Mlecz::rysowanie() {
	std::cout << "m ";
}

void Mlecz::akcja() {
	for (int i = 0; i < 3; i++)
		if (rand() % 100 < 5) rozprzestrzenianie();
}

Organizm* Mlecz::rozmnazanieKonkretneZwierze(Punkt p) {
	return  new Mlecz(biezacySwiat, -1, -1, 0);
}

void Mlecz::rozmnazanie(Punkt pkt) {
	Organizm* nowy;
	nowy = new Mlecz(biezacySwiat, pkt.getX(), pkt.getY(), 0);
	biezacySwiat->organizmyPlansza[pkt.getX()][pkt.getY()] = nowy;
	biezacySwiat->organizmy.push_back(nowy);
}

bool Mlecz::umiejetnoscSpecjalna(Organizm* atak, Organizm* obrona) {
	return 0;
}

std::string Mlecz::getNazwa() {
	return "Mlecz";
}

Mlecz::~Mlecz() {

}
