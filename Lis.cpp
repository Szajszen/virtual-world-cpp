#include "Lis.h"
#include <iostream>
#include <string>

class Organizm;


Lis::Lis(Swiat* biezacySwiat, int polozenieX, int polozenieY, int dlugoscZycia)
	:Zwierze(biezacySwiat, 3, 7, polozenieX, polozenieY, dlugoscZycia) {
}

void Lis::akcja() {
	Punkt p;
	p = losoweMiejsceObok(Punkt(this->getX(), this->getY()));
	if (biezacySwiat->organizmyPlansza[p.getX()][p.getY()] != NULL && !((p.getX() == this->getX() && p.getY() == this->getY()))) {
		if (!this->getNazwa().compare(biezacySwiat->organizmyPlansza[p.getX()][p.getY()]->getNazwa()))
			kolizja(biezacySwiat->organizmyPlansza[p.getX()][p.getY()]);
		else {
			if (biezacySwiat->organizmyPlansza[p.getX()][p.getY()]->getSila() > this->getSila()) {
				std::cout << "Lis nie porusza sie na pole[" << biezacySwiat->organizmyPlansza[p.getX()][p.getY()]->getX() << "]";
				std::cout << "[" << biezacySwiat->organizmyPlansza[p.getX()][p.getY()]->getY() << "] z ";
				std::cout << biezacySwiat->organizmyPlansza[p.getX()][p.getY()]->getNazwa() << std::endl;
			}
			else kolizja(biezacySwiat->organizmyPlansza[p.getX()][p.getY()]);
		}
	}
	else if (biezacySwiat->organizmyPlansza[p.getX()][p.getY()] == NULL && !(p.getX() == this->getX() && p.getY() == this->getY()))
		wykonajRuch(p);
}

std::string Lis::getNazwa() {
	return ("Lis");
}

void Lis::rysowanie() {
	std::cout << "l ";
}

void Lis::rozmnazanie(Punkt pkt) {

}

Organizm* Lis::rozmnazanieKonkretneZwierze(Punkt p) {
	return new Lis(biezacySwiat, p.getX(), p.getY(), 0);
}

Lis::~Lis() {

}
