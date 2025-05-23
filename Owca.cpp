#include "Owca.h"
#include <iostream>
#include <string>

class Organizm;


Owca::Owca(Swiat* biezacySwiat, int polozenieX, int polozenieY, int dlugoscZycia)
	:Zwierze(biezacySwiat, 4, 4, polozenieX, polozenieY, dlugoscZycia) {
	szansaNaRuch = 1;
}

std::string Owca::getNazwa() {
	return ("Owca");
}

void Owca::rysowanie() {
	std::cout << "o ";
}

void Owca::rozmnazanie(Punkt pkt) {

}

Organizm* Owca::rozmnazanieKonkretneZwierze(Punkt p) {
	return new Owca(biezacySwiat, p.getX(), p.getY(), 0);
}

Owca::~Owca() {

}
