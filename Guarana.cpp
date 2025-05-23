#include <iostream>
#include "Guarana.h"

class Organizm;


Guarana::Guarana(Swiat* biezacySwiat, int polozenieX, int polozenieY, int dlugoscZycia)
	:Rosliny(biezacySwiat, 0, 0, polozenieX, polozenieY, dlugoscZycia) {
}

void Guarana::rysowanie() {
	std::cout << "g ";
}

void Guarana::akcja() {
	if (rand() % 100 < 5) rozprzestrzenianie();
}

Organizm* Guarana::rozmnazanieKonkretneZwierze(Punkt p) {
	return  new Guarana(biezacySwiat, -1, -1, 0);
}

void Guarana::rozmnazanie(Punkt pkt) {
	Organizm* nowy;
	nowy = new Guarana(biezacySwiat, pkt.getX(), pkt.getY(), 0);
	biezacySwiat->organizmyPlansza[pkt.getX()][pkt.getY()] = nowy;
	biezacySwiat->organizmy.push_back(nowy);
}

bool Guarana::umiejetnoscSpecjalna(Organizm* atak, Organizm* obrona) {
	Punkt p;
	p.setX(this->getX());
	p.setY(this->getY());
	biezacySwiat->usunOrganizm(this);
	atak->wykonajRuch(p);
	atak->setSila(atak->getSila() + 3);
	std::cout << atak->getNazwa() << " zjada Guarana i zwieksza swoja sile o 3 (aktualna sila - " << atak->getSila() << ")" << std::endl;
	return 1;
}

std::string Guarana::getNazwa() {
	return "Guarana";
}

Guarana::~Guarana() {

}
