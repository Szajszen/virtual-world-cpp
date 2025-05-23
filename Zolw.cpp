#include "Zolw.h"
#include <iostream>
#include <string>

class Organizm;


Zolw::Zolw(Swiat* biezacySwiat, int polozenieX, int polozenieY, int dlugoscZycia)
	:Zwierze(biezacySwiat, 2, 1, polozenieX, polozenieY, dlugoscZycia) {
}

std::string Zolw::getNazwa() {
	return ("Zolw");
}

void Zolw::rysowanie() {
	std::cout << "z ";
}

void Zolw::akcja() {
	int wiek = this->getDlugoscZycia();
	this->setDlugoscZycia(wiek + 1);
	int numer = rand() % 100 + 1;
	if (numer > 75) {
		Zwierze::akcja();
	}
}

bool Zolw::czyOdbijaAtak(Organizm* organizm) {
	if (organizm->getSila() < 5) return 1;
	return 0;
}

void Zolw::rozmnazanie(Punkt pkt) {
}

Organizm* Zolw::rozmnazanieKonkretneZwierze(Punkt p) {
	return new Zolw(biezacySwiat, p.getX(), p.getY(), 0);
}

Zolw::~Zolw() {

}
