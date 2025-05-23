#include <iostream>
#include "BarszczSosnowskiego.h"
#include "Zwierze.h"

class Organizm;


BarszczSosnowskiego::BarszczSosnowskiego(Swiat* biezacySwiat, int polozenieX, int polozenieY, int dlugoscZycia)
	:Rosliny(biezacySwiat, 10, 0, polozenieX, polozenieY, dlugoscZycia) {
}

void BarszczSosnowskiego::rysowanie() {
	std::cout << "B ";
}

void BarszczSosnowskiego::akcja() {
	if (rand() % 100 < 5) rozprzestrzenianie();
	Punkt p;
	p.setX(this->getX());
	p.setY(this->getY());
	int x, y;
	//barszcz zabija tylko zwierzeta, dlatego przez dynamic_cast sprawdzamy czy organzim dziedziczy po klasie Zwierze
	//w lewo
	if (p.getX() != 0) {
		x = p.getX() - 1;
		y = p.getY();
		if (Zwierze* jakiesZwierze = dynamic_cast <Zwierze*>(biezacySwiat->organizmyPlansza[x][y])) {
			std::cout << " Barszcz zabija zwierze[" << x << "][" << y << "]" << std::endl;
			biezacySwiat->usunOrganizm(biezacySwiat->organizmyPlansza[x][y]);
		}
	}
	//w prawo
	if (p.getX() != biezacySwiat->getRozmiarSwiataX() - 1) {
		x = p.getX() + 1;
		y = p.getY();
		if (Zwierze* jakiesZwierze = dynamic_cast <Zwierze*>(biezacySwiat->organizmyPlansza[x][y])) {
			std::cout << " Barszcz zabija zwierze[" << x << "][" << y << "]" << std::endl;
			biezacySwiat->usunOrganizm(biezacySwiat->organizmyPlansza[x][y]);
		}
	}
	//w dol
	if (p.getY() != biezacySwiat->getRozmiarSwiataY() - 1) {
		x = p.getX();
		y = p.getY() + 1;
		if (Zwierze* jakiesZwierze = dynamic_cast <Zwierze*>(biezacySwiat->organizmyPlansza[x][y])) {
			std::cout << " Barszcz zabija zwierze[" << x << "][" << y << "]" << std::endl;
			biezacySwiat->usunOrganizm(biezacySwiat->organizmyPlansza[x][y]);
		}
	}
	// w gore
	if (p.getY() != 0) {
		x = p.getX();
		y = p.getY() - 1;
		if (Zwierze* jakiesZwierze = dynamic_cast <Zwierze*>(biezacySwiat->organizmyPlansza[x][y])) {
			std::cout << " Barszcz zabija zwierze[" << x << "][" << y << "]" << std::endl;
			biezacySwiat->usunOrganizm(biezacySwiat->organizmyPlansza[x][y]);
		}
	}
}

Organizm* BarszczSosnowskiego::rozmnazanieKonkretneZwierze(Punkt p) {
	return  new BarszczSosnowskiego(biezacySwiat, -1, -1, 0);
}

void BarszczSosnowskiego::rozmnazanie(Punkt pkt) {
	Organizm* nowy;
	nowy = new BarszczSosnowskiego(biezacySwiat, pkt.getX(), pkt.getY(), 0);
	biezacySwiat->organizmyPlansza[pkt.getX()][pkt.getY()] = nowy;
	biezacySwiat->organizmy.push_back(nowy);
}

bool BarszczSosnowskiego::umiejetnoscSpecjalna(Organizm* atak, Organizm* obrona) {
	if (atak->czyZwierze()) {
		std::cout << atak->getNazwa() << " zjada barszcz sosnowskiego i ginie " << std::endl;
		biezacySwiat->usunOrganizm(atak);
	}
	return 1;
}

std::string BarszczSosnowskiego::getNazwa() {
	return "BarszczSosnowskiego";
}

BarszczSosnowskiego::~BarszczSosnowskiego() {

}
