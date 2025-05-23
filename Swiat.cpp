#include <algorithm>
#include <cstdio>
#include <conio.h>
#include <iostream>
#include <fstream>
#include "Swiat.h"
#include "Punkt.h"
#include "Zwierze.h"
#include "Rosliny.h"
#include "Owca.h"
#include "Trawa.h"
#include "Wilk.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "Czlowiek.h"
#include "BarszczSosnowskiego.h"
#include <windows.h>

int Swiat::getRozmiarSwiataX() {
	return this->rozmiarSwiataX;
}

int Swiat::getRozmiarSwiataY() {
	return this->rozmiarSwiataY;
}

void Swiat::setRozmiarSwiataX(int x) {
	rozmiarSwiataX = x;
}

void Swiat::setRozmiarSwiataY(int y) {
	rozmiarSwiataY = y;
}

bool Swiat::getCzyKoniecGry() {
	return this->czyKoniecGry;
}

bool Swiat::getCzyCzlowiekZyje() {
	return this->czyCzlowiekZyje;
}

void Swiat::setCzyCzlowiekZyje(bool n) {
	this->czyCzlowiekZyje = n;
}

void Swiat::setCzyKoniecGry(bool n) {
	this->czyKoniecGry = n;
}

void Swiat::losoweMiejsce(int rozmiarSwiataX, int rozmiarSwiataY, Organizm*** organizmyPlanszy, Organizm* nowyOrganizm) {
	int x = (std::rand() % rozmiarSwiataX) + 0;
	int y = (std::rand() % rozmiarSwiataY) + 0;

	if (organizmyPlanszy[x][y] != NULL) return;
	else {
		nowyOrganizm->setX(x);
		nowyOrganizm->setY(y);
		organizmyPlanszy[x][y] = nowyOrganizm;
		organizmy.push_back(nowyOrganizm);
	}
}

Swiat::Swiat() {
	this->rozmiarSwiataX = 0;
	this->rozmiarSwiataY = 0;
	czyCzlowiekZyje = 1;
	czyKoniecGry = 0;
	organizmy.reserve(0);
}

Swiat::Swiat(int x, int y) : rozmiarSwiataX(x), rozmiarSwiataY(y) {
	czyKoniecGry = 0;
	czyCzlowiekZyje = 1;
	organizmy.reserve(rozmiarSwiataX * rozmiarSwiataY / 2);

	Organizm*** organizmyPlansza = new Organizm * *[x];
	for (int i = 0; i < x; ++i) {
		organizmyPlansza[i] = new Organizm * [y];
		for (int j = 0; j < y; ++j)
			organizmyPlansza[i][j] = NULL;
	}
	this->organizmyPlansza = organizmyPlansza;

	if (rozmiarSwiataX * rozmiarSwiataY / 2 < 10) {
		// zapelnianie planszy - zwierzeta:
		losoweMiejsce(x, y, this->organizmyPlansza, new Czlowiek(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new Wilk(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new Owca(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new Owca(this, -1, -1, 0));
		// zapelnianie planszy - rosliny:
		losoweMiejsce(x, y, this->organizmyPlansza, new Trawa(this, -1, -1, 0));
	}
	else {
		// zapelnianie planszy - zwierzeta:
		losoweMiejsce(x, y, this->organizmyPlansza, new Czlowiek(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new Wilk(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new Wilk(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new Wilk(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new Owca(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new Owca(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new Owca(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new Owca(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new Owca(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new Owca(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new Lis(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new Lis(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new Lis(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new Zolw(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new Zolw(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new Antylopa(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new Antylopa(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new Antylopa(this, -1, -1, 0));
		// zapelnianie planszy - rosliny: 
		losoweMiejsce(x, y, this->organizmyPlansza, new Trawa(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new Trawa(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new Trawa(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new Trawa(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new Mlecz(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new Mlecz(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new Mlecz(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new Mlecz(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new Guarana(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new Guarana(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new WilczeJagody(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new BarszczSosnowskiego(this, -1, -1, 0));
		losoweMiejsce(x, y, this->organizmyPlansza, new WilczeJagody(this, -1, -1, 0));
	}

}

void Swiat::rysujSwiat() {
	system("cls");	
	std::cout << "|Autor: Paulina Golwiej | 191719" << std::endl;
	std::cout << "|RUCH -> STRZALKI|" << std::endl;
	std::cout << "|X - wyjscie | q - umiejetnosc specjalna  | z - zapisz gre|" << std::endl;
	std::cout << "|a-antylopa | o-owca | w-wilk | z-zolw | l-lis | #-trawa |" << std::endl;
	std::cout<<  "|g - guarana | j - wilcze jagody | b - barszcz | m - mlecz|" << std::endl << std::endl;
	char a = 254;

	for (int i = 0; i < this->rozmiarSwiataX; i++) {
		std::cout << "| ";
		for (int j = 0; j < this->rozmiarSwiataY; j++) {
			if (this->organizmyPlansza[i][j] == NULL) std::cout << a << " ";
			else if (this->organizmyPlansza[i][j] != NULL) this->organizmyPlansza[i][j]->rysowanie();
		}
		std::cout << "|" << std::endl;
	}
	
	std::cout << std::endl;

	std::cout << " Nacisnij klawisz, aby poruszyc sie w kolejnej turze: " << std::endl;
}


void Swiat::wykonajTure() {
	int wiek;
	if (czyKoniecGry == 1) return;
	kolejkaSortOrganizmy();

	for (int i = 0; i < organizmy.size(); i++) {
		wiek = organizmy[i]->getDlugoscZycia() + 1;
		organizmy[i]->setDlugoscZycia(wiek);
		if (organizmy[i]->getCzyUmarl() == 1) continue;
		else if (organizmy[i]->getDlugoscZycia() >= 2) organizmy[i]->akcja();
	}

	for (int i = 0; i < organizmy.size(); i++) {
		if (organizmy[i]->getCzyUmarl() == true) {
			delete organizmy[i];
			organizmy.erase(organizmy.begin() + i);
		}
	}
}

bool Swiat::czyCzlowiekUmarl() {
	std::cout << "KONIEC GRY" << std::endl;
	return 0;
}

void Swiat::usunOrganizm(Organizm* organizm) {
	this->organizmyPlansza[organizm->getX()][organizm->getY()] = NULL;
	organizm->setCzyUmarl(true);
	if (!organizm->getNazwa().compare("czlowiek")) {
		setCzyCzlowiekZyje(false);
	}
}

void Swiat::kolejkaSortOrganizmy() {
	sort(organizmy.begin(), organizmy.end(),
		[](Organizm* o1, Organizm* o2) {
			int inicj1 = o1->getInicjatywa();
			int inicj2 = o2->getInicjatywa();
			int urodzenie1 = o1->getDlugoscZycia();
			int urodzenie2 = o2->getDlugoscZycia();
			if (inicj1 > inicj2) return 1;
			else if (inicj1 == inicj2 && urodzenie1 < urodzenie2) return 1;
			return 0;
		});
}

void Swiat::zapiszSwiat() {
	std::ofstream plik("SwiatZapisany.txt", std::ofstream::out);
	if (!plik.is_open()) std::cout << "Blad zapisu " << std::endl;
	else {
		plik << rozmiarSwiataX;
		plik << " ";
		plik << rozmiarSwiataY;
		plik << " ";
		plik << czyCzlowiekZyje;
		plik << " ";
		plik << czyKoniecGry;
		plik << "\n";
		for (int i = 0; i < organizmy.size(); i++) {
			plik << organizmy[i]->getNazwa();
			plik << " ";
			plik << organizmy[i]->getCzyUmarl();
			plik << " ";
			plik << organizmy[i]->getDlugoscZycia();
			plik << " ";
			plik << organizmy[i]->getInicjatywa();
			plik << " ";
			plik << organizmy[i]->getSila();
			plik << " ";
			plik << organizmy[i]->getX();
			plik << " ";
			plik << organizmy[i]->getY();
			plik << "\n";
		}
		plik.close();
	}

}
Swiat* Swiat::otworzSwiat() {
	std::ifstream plik;
	plik.open("SwiatZapisany.txt");
	if (!plik.good()) std::cout << "Blad odczytu" << std::endl;
	else {
		int cos;
		std::string string;
		plik >> cos;
		int x = cos;
		plik >> cos;
		int y = cos;
		Swiat* nowySwiat = new Swiat(x, y);
		plik >> cos;
		nowySwiat->setCzyCzlowiekZyje(cos);
		plik >> cos;
		nowySwiat->setCzyKoniecGry(cos);

		while (!plik.eof()) {
			Organizm* nowyOrganizm = NULL;
			int czyUmarl, dlugoscZycia, inicjatywa, sila, x, y, szybkoscAntylopy, czyAktywnaSzybkosc;
			plik >> string;
			plik >> czyUmarl;
			plik >> dlugoscZycia;
			plik >> inicjatywa;
			plik >> sila;
			plik >> x;
			plik >> y;
			if (!string.compare("Owca")) {
				nowyOrganizm = new Owca(nowySwiat, x, y, dlugoscZycia);
				nowyOrganizm->setCzyUmarl(czyUmarl);
			}
			else if (!string.compare("Wilk")) {
				nowyOrganizm = new Wilk(nowySwiat, x, y, dlugoscZycia);
				nowyOrganizm->setCzyUmarl(czyUmarl);
			}
			else if (!string.compare("Lis")) {
				nowyOrganizm = new Lis(nowySwiat, x, y, dlugoscZycia);
				nowyOrganizm->setCzyUmarl(czyUmarl);
			}
			else if (!string.compare("Zolw")) {
				nowyOrganizm = new Zolw(nowySwiat, x, y, dlugoscZycia);
				nowyOrganizm->setCzyUmarl(czyUmarl);
			}
			else if (!string.compare("Antylopa")) {
				nowyOrganizm = new Antylopa(nowySwiat, x, y, dlugoscZycia);
				nowyOrganizm->setCzyUmarl(czyUmarl);
			}
			else if (!string.compare("Trawa")) {
				nowyOrganizm = new Trawa(nowySwiat, x, y, dlugoscZycia);
				nowyOrganizm->setCzyUmarl(czyUmarl);
			}
			else if (!string.compare("Mlecz")) {
				nowyOrganizm = new Mlecz(nowySwiat, x, y, dlugoscZycia);
				nowyOrganizm->setCzyUmarl(czyUmarl);
			}
			else if (!string.compare("Guarana")) {
				nowyOrganizm = new Guarana(nowySwiat, x, y, dlugoscZycia);
				nowyOrganizm->setCzyUmarl(czyUmarl);
			}
			else if (!string.compare("WilczeJagody")) {
				nowyOrganizm = new WilczeJagody(nowySwiat, x, y, dlugoscZycia);
				nowyOrganizm->setCzyUmarl(czyUmarl);
			}
			else if (!string.compare("BarszczSosnowskiego")) {
				nowyOrganizm = new BarszczSosnowskiego(nowySwiat, x, y, dlugoscZycia);
				nowyOrganizm->setCzyUmarl(czyUmarl);
			}
			else if (!string.compare("Czlowiek")) {
				nowyOrganizm = new Czlowiek(nowySwiat, x, y, dlugoscZycia);
				nowyOrganizm->setCzyUmarl(czyUmarl);
			}
			//dodawanie organizmu
			nowySwiat->organizmy.push_back(nowyOrganizm);
			nowySwiat->organizmyPlansza[nowyOrganizm->getX()][nowyOrganizm->getY()] = nowyOrganizm;
		}
		return nowySwiat;
	}
}

Swiat::Swiat(Swiat&& s) {
	this->setRozmiarSwiataX(s.getRozmiarSwiataX());
	this->setRozmiarSwiataY(s.getRozmiarSwiataY());
	this->setCzyCzlowiekZyje(s.getCzyCzlowiekZyje());
	this->setCzyKoniecGry(s.getCzyKoniecGry());

	for (int i = 0; i < organizmy.size(); i++)
		organizmy[i]->setSwiat(this);
}

Swiat::~Swiat() {
	for (int j = 0; j < rozmiarSwiataY; j++)
		delete[] organizmyPlansza[j];
	delete organizmyPlansza;
}

