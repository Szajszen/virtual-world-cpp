#include "wilk.h"
#include <iostream>
#include <string>

class Organizm;


Wilk::Wilk(Swiat* biezacySwiat, int polozenieX, int polozenieY, int dlugoscZycia)
	:Zwierze(biezacySwiat, 9, 5, polozenieX, polozenieY, dlugoscZycia) {
}

std::string Wilk::getNazwa() {
	return ("Wilk");
}

void Wilk::rysowanie() {
	std::cout << "w ";
}

void Wilk::rozmnazanie(Punkt pkt) {

}

Organizm* Wilk::rozmnazanieKonkretneZwierze(Punkt p) {
	return new Wilk(biezacySwiat, p.getX(), p.getY(), 0);
}

Wilk::~Wilk() {

}
