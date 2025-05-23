#include <iostream>
#include "Rosliny.h"


Rosliny::Rosliny(Swiat* biezacySwiat, int sila, int inicjatywa, int polozenieX, int polozenieY, int dlugoscZycia)
	:Organizm(biezacySwiat, sila, 0, polozenieX, polozenieY, dlugoscZycia) {
}

void Rosliny::akcja() {
	if (this->getNazwa().compare("Mlecz")) {
		int wiek = this->getDlugoscZycia() + 1;
		this->setDlugoscZycia(wiek);
	}

	if (rand() % 100 > 90) {
		rozprzestrzenianie();
	}
	else;
}

void Rosliny::rozprzestrzenianie() {
	Punkt pkt = this->losujWolneMiejsce();
	if (pkt.getX() == -1)
		return;
	else {
		std::cout << "Rozsiana nowa roslina: " << this->getNazwa() << "[" << pkt.getX() << "][" << pkt.getY() << "]" << std::endl;
		rozmnazanie(pkt);
	}
}

bool Rosliny::czyZwierze() {
	return 0;
}

void Rosliny::kolizja(Organizm* organizm) {
}


Rosliny::~Rosliny() {

}
