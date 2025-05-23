#include "Czlowiek.h"
#include <iostream>
#include <string>
#include <conio.h>

class Organizm;

Czlowiek::Czlowiek(Swiat* biezacySwiat, int polozenieX, int polozenieY, int dlugoscZycia)
	:Zwierze(biezacySwiat, 5, 4, polozenieX, polozenieY, dlugoscZycia) {
	setSzansaNaRuch(1);
    calopalenieLicznik = 0;
    calopalenieAktywne = false;
}

void Czlowiek::akcja() {
    int ruch;
    bool chwilowoNieaktywnaSzybkosc;
    int x, y;
    x = this->getX();
    y = this->getY();

    while (true) {
        ruch = _getch();
        // Strzalka w gore
        if (ruch == 72) {
            x--;
            break;
        }
        // Strzalka w dol
        else if (ruch == 80) {
            x++;
            break;
        }
        // Strzalka w lewo
        else if (ruch == 75) {
            y--;
            break;
        }
        // Strzalka w prawo
        else if (ruch == 77) {
            y++;
            break;
        }
        else if (ruch == 'q' || ruch == 'Q') {
            if (!calopalenieAktywne) {
                calopalenieAktywne = true;
                calopalenieLicznik = 5;
                std::cout << "Calopalenie zostalo aktywowane" << std::endl;
            }
        }
        else if (ruch == 'z' || ruch == 'Z') {
            biezacySwiat->zapiszSwiat();
        }
        else if (ruch == 'x' || ruch == 'X') biezacySwiat->setCzyKoniecGry(1);
        
    }
    // Check if "Calopalenie" is active and perform the action
    if (calopalenieAktywne) {
        std::cout << "Calopalenie aktywne. Pozostalo tur: " << calopalenieLicznik << std::endl;
        calopalenie();
    }

    Punkt p;
    p.setX(x);
    p.setY(y);

    if (czyWolneMiejsce(p))
        wykonajRuch(p);
    else
        Zwierze::kolizja(biezacySwiat->organizmyPlansza[x][y]);
}

void Czlowiek::calopalenie() {
    if (calopalenieLicznik > 0) {
        calopalenieLicznik--;

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                int newX = getX() + dx;
                int newY = getY() + dy;

                if (newX >= 0 && newX < biezacySwiat->getRozmiarSwiataX() && newY >= 0 && newY < biezacySwiat->getRozmiarSwiataY()) {
                    Organizm* organizm = biezacySwiat->organizmyPlansza[newX][newY];

                    if (organizm != nullptr && organizm != this) {
                        std::cout << "Calopalenie niszczy " << organizm->getNazwa() << " na pozycji (" << newX << ", " << newY << ")" << std::endl;
                        biezacySwiat->usunOrganizm(organizm);
                    }
                }
            }
        }

        if (calopalenieLicznik == 0) {
            calopalenieAktywne = false;
            std::cout << "Calopalenie zostalo zakonczone" << std::endl;
        }
    }
}

bool Czlowiek::czyCalopalenieAktywne() const {
    return calopalenieAktywne;
}

std::string Czlowiek::getNazwa() {
	return ("Czlowiek");
}

void Czlowiek::rysowanie() {
	char a = 1;
	std::cout << a << " ";
}

void Czlowiek::rozmnazanie(Punkt pkt) {
}

Organizm* Czlowiek::rozmnazanieKonkretneZwierze(Punkt p) {
	return new Czlowiek(biezacySwiat, p.getX(), p.getY(), 0);
}

Czlowiek::~Czlowiek() {
	biezacySwiat->setCzyKoniecGry(1);
}
