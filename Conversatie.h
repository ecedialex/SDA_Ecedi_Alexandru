//
// Created by alexe on 7/1/2022.
//

#ifndef SDA_ECEDI_ALEXANDRU_312_CONVERSATIE_H
#define SDA_ECEDI_ALEXANDRU_312_CONVERSATIE_H

#include "Array.h"
#include "string"
#include "Lista.h"

using namespace std;

class Conversatie {
private:
    int id;
    int id_1;
    int id_2;
    Lista<pair<int, string>> mesaje;
public:
    Conversatie();

    Conversatie(int id, int id_1, int id_2);

    ~Conversatie();

    int getId() const;

    int getIdUser1() const;

    int getIdUser2() const;

    Lista<pair<int, string>> getMesaje() const;

    void setId(int id);

    void setIdUser1(int id_user1);

    void setIdUser2(int id_user2);

    void addMesaj(int id_user_trimitor, string mesaj);

    friend ostream &operator<<(ostream &out, Conversatie &c);

    friend istream &operator>>(istream &in, Conversatie &c);
};


#endif //SDA_ECEDI_ALEXANDRU_312_CONVERSATIE_H
