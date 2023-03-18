//
// Created by alexe on 7/1/2022.
//

#include "Utilizator.h"
#include "ostream"
#include "fstream"

using namespace std;

Utilizator::Utilizator() {
    this->id = 0;
    this->nume = "";
    this->varsta = 0;
    this->email = "";
    this->parola = "";
}

Utilizator::Utilizator(int id, string nume, int varsta, string email, string parola) {
    this->id = id;
    this->nume = nume;
    this->varsta = varsta;
    this->email = email;
    this->parola = parola;
}

Utilizator::~Utilizator() {
    ;
}

int Utilizator::getId() const {
    return id;
}

string Utilizator::getNume() const {
    return nume;
}

int Utilizator::getVarsta() const {
    return varsta;
}

string Utilizator::getEmail() const {
    return email;
}

string Utilizator::getParola() const {
    return parola;
}

Lista<int> Utilizator::getPrieteni() const {
    return prieteni;
}

Lista<int> Utilizator::getEvenimente() const {
    return evenimente;
}

void Utilizator::setId(int id) {
    this->id = id;
}

void Utilizator::setNume(string nume) {
    this->nume = nume;
}

void Utilizator::setVarsta(int varsta) {
    this->varsta = varsta;
}

void Utilizator::setEmail(string email) {
    this->email = email;
}

void Utilizator::setParola(string parola) {
    this->parola = parola;
}

void Utilizator::addPrieten(int id) {
    prieteni.adauga(id);
}

void Utilizator::addEveniment(int id) {
    evenimente.adauga(id);
}

void Utilizator::removePrieten(int id) {
    for (int i = 0; i < prieteni.getDim(); i++) {
        if (prieteni[i] == id) {
            prieteni.sterge(i);
            break;
        }
    }
}

void Utilizator::removeEveniment(int id) {
    for (int i = 0; i < evenimente.getDim(); i++) {
        if (evenimente[i] == id) {
            evenimente.sterge(i);
            break;
        }
    }
}

ostream &operator<<(ostream &out, Utilizator &u) {
    out << u.id << " " << u.nume << " " << u.varsta << " " << u.email << " " << u.parola << " ";

    out << u.prieteni.getDim() << " ";
    for (int i = 0; i < u.prieteni.getDim(); i++) {
        out << u.prieteni[i] << " ";
    }

    out << u.evenimente.getDim() << " ";
    for (int i = 0; i < u.evenimente.getDim(); i++) {
        out << u.evenimente[i] << " ";
    }

    return out;
}

istream &operator>>(istream &in, Utilizator &u) {
    in >> u.id >> u.nume >> u.varsta >> u.email >> u.parola;
    int nr;
    in >> nr;
    for (int i = 0; i < nr; i++) {
        int id;
        in >> id;
        u.prieteni.adauga(id);
    }

    in >> nr;
    for (int i = 0; i < nr; i++) {
        int id;
        in >> id;
        u.evenimente.adauga(id);
    }

    return in;
}

bool Utilizator::operator<(const Utilizator &u) {
    return this->nume < u.nume;
}

bool Utilizator::operator>(const Utilizator &u) {
    return this->nume > u.nume;
}

bool Utilizator::operator==(const Utilizator &u) {
    return this->nume == u.nume && this->varsta == u.varsta && this->email == u.email && this->parola == u.parola;
}

Utilizator &Utilizator::operator=(const Utilizator &u) {
    this->id = u.id;
    this->varsta = u.varsta;
    this->email = u.email;
    this->parola = u.parola;
    this->prieteni = u.prieteni;
    this->evenimente = u.evenimente;
    this->nume = u.nume;
}

Utilizator::Utilizator(int id, string nume, int varsta, string email, string parola, Lista<int> prieteni,
                       Lista<int> evenimente) {
    this->id = id;
    this->nume = nume;
    this->varsta = varsta;
    this->email = email;
    this->parola = parola;
    this->prieteni=prieteni;
    this->evenimente=evenimente;
}
