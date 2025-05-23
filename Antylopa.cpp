#include "Antylopa.h"
#include <iostream>
#include <string>

class Organizm;


Antylopa::Antylopa(Swiat* biezacySwiat, int polozenieX, int polozenieY, int dlugoscZycia)
	:Zwierze(biezacySwiat, 4, 4, polozenieX, polozenieY, dlugoscZycia) {
}

void Antylopa::kolizja(Organizm* o) {
	int numer = rand() % 2;
	if (numer > 0 && (o->getSila() > this->getSila())) {
		std::cout << this->getNazwa() << " uciekla przed " << o->getNazwa() << std::endl;
		Punkt p = losoweMiejsceObok(Punkt(this->getX(), this->getY()));
		wykonajRuch(p);
	}
	else Zwierze::kolizja(o);
}

Punkt Antylopa::wolneMiejsceObok(Punkt p) {
	int x, y;
	Punkt nowyPkt;
	//w lewo
	if (p.getX() >= 2) {
		x = p.getX() - 1; //o 1
		y = p.getY();
		nowyPkt.setX(x);
		nowyPkt.setY(y);
		if (czyWolneMiejsce(nowyPkt)) return nowyPkt;
		x = p.getX() - 2; //o 2
		nowyPkt.setX(x);
		if (czyWolneMiejsce(nowyPkt)) return nowyPkt;
	}
	//w prawo
	if (p.getX() <= biezacySwiat->getRozmiarSwiataX() - 3) {
		x = p.getX() + 1; //o 1
		y = p.getY();
		nowyPkt.setX(x);
		nowyPkt.setY(y);
		if (czyWolneMiejsce(nowyPkt)) return nowyPkt;
		x = p.getX() + 2; //o 2
		nowyPkt.setX(x);
		if (czyWolneMiejsce(nowyPkt)) return nowyPkt;
	}
	//w dol
	if (p.getY() <= biezacySwiat->getRozmiarSwiataY() - 3) {
		x = p.getX();
		y = p.getY() + 1; //o 1
		nowyPkt.setX(x);
		nowyPkt.setY(y);
		if (czyWolneMiejsce(nowyPkt)) return nowyPkt;
		y = p.getY() + 2; //o 2
		nowyPkt.setY(y);
		if (czyWolneMiejsce(nowyPkt)) return nowyPkt;
	}
	// w gore
	if (p.getY() <= 2) {
		x = p.getX();
		y = p.getY() - 1; // o 1
		nowyPkt.setX(x);
		nowyPkt.setY(y);
		if (czyWolneMiejsce(nowyPkt)) return nowyPkt;
		y = p.getY() - 2;
		nowyPkt.setY(y);  // o 2
		if (czyWolneMiejsce(nowyPkt)) return nowyPkt;
	}
	nowyPkt.setX(-1);
	nowyPkt.setY(-1);
	return nowyPkt;
}

std::string Antylopa::getNazwa() {
	return ("Antylopa");
}

void Antylopa::rysowanie() {
	std::cout << "a ";
}

void Antylopa::rozmnazanie(Punkt pkt) {

}

Organizm* Antylopa::rozmnazanieKonkretneZwierze(Punkt p) {
	return new Antylopa(biezacySwiat, p.getX(), p.getY(), 0);
}

Antylopa::~Antylopa() {

}
