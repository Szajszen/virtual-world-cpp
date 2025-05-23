#include "Organizm.h"

Organizm::Organizm(Swiat* biezacySwiat, int sila, int inicjatywa, int polozenieX, int polozenieY, int dlugoscZycia)
	:biezacySwiat(biezacySwiat), sila(sila), inicjatywa(inicjatywa), dlugoscZycia(dlugoscZycia), polozenieX(polozenieX), polozenieY(polozenieY) {
	this->czyUmarl = 0;

	if (polozenieX == -1 && polozenieY == -1) return;
	//else biezacySwiat->organizmyPlansza[polozenieX][polozenieY] = this;
}

Punkt Organizm::losujWolneMiejsce() {
	Punkt nowyPkt;
	while (true) {
		int x = rand() % biezacySwiat->getRozmiarSwiataX();
		int y = rand() % biezacySwiat->getRozmiarSwiataY();
		nowyPkt.setX(x);
		nowyPkt.setY(y);
		if (czyWolneMiejsce(nowyPkt)) return nowyPkt;
	}
	nowyPkt.setX(-1);
	nowyPkt.setY(-1);
	return nowyPkt;
}

Punkt Organizm::losoweMiejsceObok(Punkt p) {
	int x, y, numer;
	Punkt nowyPkt;
	while (true) {
		numer = rand() % 4;
		if (numer == 0) {
			//w lewo
			if (p.getX() != 0) {
				x = p.getX() - 1;
				y = p.getY();
				nowyPkt.setX(x);
				nowyPkt.setY(y);
				return nowyPkt;
			}
		}
		if (numer == 1) {
			//w prawo
			if (p.getX() != biezacySwiat->getRozmiarSwiataX() - 1) {
				x = p.getX() + 1;
				y = p.getY();
				nowyPkt.setX(x);
				nowyPkt.setY(y);
				return nowyPkt;
			}
		}
		if (numer == 2) {
			//w dol
			if (p.getY() != biezacySwiat->getRozmiarSwiataY() - 1) {
				x = p.getX();
				y = p.getY() + 1;
				nowyPkt.setX(x);
				nowyPkt.setY(y);
				return nowyPkt;
			}
		}
		if (numer == 3) {
			// w gore
			if (p.getY() != 0) {
				x = p.getX();
				y = p.getY() - 1;
				nowyPkt.setX(x);
				nowyPkt.setY(y);
				return nowyPkt;
			}
		}
	}
}

Punkt Organizm::wolneMiejsceObok(Punkt p) {
	int x, y;
	Punkt nowyPkt;
	//w lewo
	if (p.getX() != 0) {
		x = p.getX() - 1;
		y = p.getY();
		nowyPkt.setX(x);
		nowyPkt.setY(y);
		if (czyWolneMiejsce(nowyPkt)) return nowyPkt;
	}
	//w prawo
	if (p.getX() != biezacySwiat->getRozmiarSwiataX() - 1) {
		x = p.getX() + 1;
		y = p.getY();
		nowyPkt.setX(x);
		nowyPkt.setY(y);
		if (czyWolneMiejsce(nowyPkt)) return nowyPkt;
	}
	//w dol
	if (p.getY() != biezacySwiat->getRozmiarSwiataY() - 1) {
		x = p.getX();
		y = p.getY() + 1;
		nowyPkt.setX(x);
		nowyPkt.setY(y);
		if (czyWolneMiejsce(nowyPkt)) return nowyPkt;
	}
	// w gore
	if (p.getY() != 0) {
		x = p.getX();
		y = p.getY() - 1;
		nowyPkt.setX(x);
		nowyPkt.setY(y);
		if (czyWolneMiejsce(nowyPkt)) return nowyPkt;
	}
	nowyPkt.setX(-1);
	nowyPkt.setY(-1);
	return nowyPkt;
}

void Organizm::wykonajRuch(Punkt p) {
	int x = p.getX();
	int y = p.getY();
	biezacySwiat->organizmyPlansza[this->getX()][this->getY()] = NULL;
	biezacySwiat->organizmyPlansza[x][y] = this;
	this->setX(x);
	this->setY(y);
}

bool Organizm::umiejetnoscSpecjalna(Organizm* atak, Organizm* obrona) {
	return 0;
}

bool Organizm::czyZwierze() {
	return 0;
}

bool Organizm::czyOdbijaAtak(Organizm* organizm) {
	return 0;
}

bool Organizm::czyWolneMiejsce(Punkt pkt) {
	if (biezacySwiat->organizmyPlansza[pkt.getX()][pkt.getY()] == NULL)
		return 1;
	else return 0;
}

int Organizm::getInicjatywa() {
	return inicjatywa;
}
int Organizm::getDlugoscZycia() {
	return dlugoscZycia;
}

int Organizm::getSila() {
	return sila;
}

int Organizm::getX() {
	return polozenieX;
}

int Organizm::getY() {
	return polozenieY;
}

bool Organizm::getCzyUmarl() {
	return czyUmarl;
}

void Organizm::setCzyUmarl(bool n) {
	this->czyUmarl = n;
}

void Organizm::setX(int x) {
	this->polozenieX = x;
}

void Organizm::setY(int y) {
	this->polozenieY = y;
}

void Organizm::setDlugoscZycia(int dlugoscZycia) {
	this->dlugoscZycia = dlugoscZycia;
}

void Organizm::setSila(int sila) {
	this->sila = sila;
}

void Organizm::setSwiat(Swiat* swiat) {
	this->biezacySwiat = swiat;
}

Organizm::~Organizm() {

}
