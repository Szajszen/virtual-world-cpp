#include <iostream>
#include "WilczeJagody.h"

class Organizm;


WilczeJagody::WilczeJagody(Swiat* biezacySwiat, int polozenieX, int polozenieY, int dlugoscZycia)
	:Rosliny(biezacySwiat, 99, 0, polozenieX, polozenieY, dlugoscZycia) {
}

void WilczeJagody::rysowanie() {
	std::cout << "j ";
}

void WilczeJagody::akcja() {
	if (rand() % 100 < 5) rozprzestrzenianie();
}

Organizm* WilczeJagody::rozmnazanieKonkretneZwierze(Punkt p) {
	return  new WilczeJagody(biezacySwiat, -1, -1, 0);
}

void WilczeJagody::rozmnazanie(Punkt pkt) {
	Organizm* nowy;
	nowy = new WilczeJagody(biezacySwiat, pkt.getX(), pkt.getY(), 0);
	biezacySwiat->organizmyPlansza[pkt.getX()][pkt.getY()] = nowy;
	biezacySwiat->organizmy.push_back(nowy);
}

bool WilczeJagody::umiejetnoscSpecjalna(Organizm* atak, Organizm* obrona) {
	if (atak->getSila() >= 99) {
		biezacySwiat->usunOrganizm(this);
		std::cout << atak->getNazwa() << " zjada wilcze jagody i je niszczy" << std::endl;
	}
	else if (atak->czyZwierze()) {
		biezacySwiat->usunOrganizm(atak);
		std::cout << atak->getNazwa() << " zjada wilcze jagody i ginie" << std::endl;
	}


	return 1;
}

std::string WilczeJagody::getNazwa() {
	return "WilczeJagody";
}

WilczeJagody::~WilczeJagody() {

}
