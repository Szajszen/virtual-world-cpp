#include <iostream>
#include "Trawa.h"

class Organizm;


Trawa::Trawa(Swiat* biezacySwiat, int polozenieX, int polozenieY, int dlugoscZycia)
	:Rosliny(biezacySwiat, 0, 0, polozenieX, polozenieY, dlugoscZycia) {
}

void Trawa::rysowanie() {
	std::cout << "# ";
}

void Trawa::akcja() {
	if (rand() % 100 < 5) rozprzestrzenianie();
}

Organizm* Trawa::rozmnazanieKonkretneZwierze(Punkt p) {
	return  new Trawa(biezacySwiat, -1, -1, 0);
}

void Trawa::rozmnazanie(Punkt pkt) {
	Organizm* nowy;
	nowy = new Trawa(biezacySwiat, pkt.getX(), pkt.getY(), 0);
	biezacySwiat->organizmyPlansza[pkt.getX()][pkt.getY()] = nowy;
	biezacySwiat->organizmy.push_back(nowy);
}

bool Trawa::umiejetnoscSpecjalna(Organizm* atak, Organizm* obrona) {
	return 0;
}

std::string Trawa::getNazwa() {
	return "Trawa";
}

Trawa::~Trawa() {

}
