//
// Created by alexe on 7/1/2022.
//

#include "Conversatie.h"
#include <iomanip>
#include <fstream>
#include <iostream>

Conversatie::Conversatie() {
    this->id = -1;
    this->id_1 = -1;
    this->id_2 = -1;
}

Conversatie::Conversatie(int id, int id_1, int id_2) {
    this->id = id;
    this->id_1 = id_1;
    this->id_2 = id_2;
}

Conversatie::~Conversatie() {
    ;
}

int Conversatie::getId() const {
    return id;
}

int Conversatie::getIdUser1() const {
    return id_1;
}

int Conversatie::getIdUser2() const {
    return id_2;
}

Lista<pair<int, string>> Conversatie::getMesaje() const {
    return mesaje;
}

void Conversatie::setId(int id) {
    this->id = id;
}

void Conversatie::setIdUser1(int id_user1) {
    this->id_1 = id_user1;
}

void Conversatie::setIdUser2(int id_user2) {
    this->id_2 = id_user2;
}

void Conversatie::addMesaj(int id_user_trimitor, string mesaj) {
    mesaje.adauga(pair<int, string>(id_user_trimitor, mesaj));
}

ostream &operator<<(ostream &out, Conversatie &c) {
    out << c.id << " " << c.id_1 << " " << c.id_2 << " ";
    out << c.mesaje.getDim() << " ";
    for (int i = 0; i < c.mesaje.getDim(); i++) {
        out << c.mesaje[i].first << " " << std::quoted(c.mesaje[i].second) << " ";
    }
    return out;
}

istream &operator>>(istream &in, Conversatie &c) {
    in >> c.id >> c.id_1 >> c.id_2;
    int nr_mesaje;
    in >> nr_mesaje;
    for (int i = 0; i < nr_mesaje; i++) {
        int id_user1;
        string mesaj;
        in >> id_user1 >> std::quoted(mesaj);
        c.mesaje.adauga(pair<int, string>(id_user1, mesaj));
    }

    return in;
}