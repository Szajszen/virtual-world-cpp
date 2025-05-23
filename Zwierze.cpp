#include "Zwierze.h"
#include "Punkt.h"


Zwierze::Zwierze(Swiat* biezacySwiat, int sila, int inicjatywa, int polozenieX, int polozenieY, int dlugoscZycia)
	:Organizm(biezacySwiat, sila, inicjatywa, polozenieX, polozenieY, dlugoscZycia) {
	szansaNaRuch = 1;
}


void Zwierze::akcja() {
	Punkt p;
	if (rand() % 100 >= (int)(szansaNaRuch * 100)) return;
	else {
		p = losoweMiejsceObok(Punkt(this->getX(), this->getY()));
		if (biezacySwiat->organizmyPlansza[p.getX()][p.getY()] != NULL && !(p.getX() == this->getX() && p.getY() == this->getY())) {
			kolizja(biezacySwiat->organizmyPlansza[p.getX()][p.getY()]);
		}
		else if (!(p.getX() == this->getX() && p.getY() == this->getY()))
			wykonajRuch(p);
	}
}


void Zwierze::kolizja(Organizm* organizm) {
	if (!this->getNazwa().compare(organizm->getNazwa())) {
		if (organizm->getDlugoscZycia() > 2) {
			Punkt nowyPkt = wolneMiejsceObok(Punkt(organizm->getX(), organizm->getY()));
			if (nowyPkt.getX() != -1) {
				Organizm* nowyO;
				nowyO = rozmnazanieKonkretneZwierze(nowyPkt);
				biezacySwiat->organizmy.push_back(nowyO);
				biezacySwiat->organizmyPlansza[nowyPkt.getX()][nowyPkt.getY()] = nowyO;
				std::cout << "Nowonarodzony " << nowyO->getNazwa() << "[" << nowyO->getX() << "][" << nowyO->getY() << "]" << std::endl;
			}
		}
	}
	else {
		if (organizm->umiejetnoscSpecjalna(this, organizm)) return;
		if (this->umiejetnoscSpecjalna(this, organizm)) return;
		if (organizm->czyOdbijaAtak(this)) {
			std::cout << organizm->getNazwa() << "[" << organizm->getX() << "][" << organizm->getY() << "] odbil atak od ";
			std::cout << this->getNazwa() << "[" << this->getX() << "][" << this->getY() << "]" << std::endl;
			return;
		}

		if (this->getSila() >= organizm->getSila()) {
			if (organizm->czyZwierze()) {
				std::cout << this->getNazwa() << "[" << this->getX() << "][" << this->getY() << "] atakuje i zabija ";
				std::cout << organizm->getNazwa() << "[" << organizm->getX() << "][" << organizm->getY() << "]" << std::endl;
			}
			else {
				std::cout << this->getNazwa() << "[" << this->getX() << "][" << this->getY() << "] zjada";
				std::cout << organizm->getNazwa() << "[" << organizm->getX() << "][" << organizm->getY() << "]" << std::endl;
			}
			biezacySwiat->usunOrganizm(organizm);
			wykonajRuch(Punkt(organizm->getX(), organizm->getY()));
		}
		else {
			std::cout << this->getNazwa() << "[" << this->getX() << "][" << this->getY() << "] atakuje i ginie od ";
			std::cout << organizm->getNazwa() << "[" << organizm->getX() << "][" << organizm->getY() << "]" << std::endl;
			biezacySwiat->usunOrganizm(this);
			//wykonajRuch(Punkt(this->getX(), this->getY()));
		}
	}
}

bool Zwierze::czyZwierze() {
	return 1;
}

double Zwierze::getSzansaNaRuch() {
	return this->szansaNaRuch;
}

void Zwierze::setSzansaNaRuch(double szansa) {
	this->szansaNaRuch = szansa;
}

Zwierze::~Zwierze() {

}
