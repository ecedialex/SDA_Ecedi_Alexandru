//
// Created by alexe on 7/1/2022.
//

#ifndef SDA_ECEDI_ALEXANDRU_312_EVENIMENT_H
#define SDA_ECEDI_ALEXANDRU_312_EVENIMENT_H

#include "string"
#include "Array.h"
#include "Lista.h"

class Eveniment {
private:
    int id;
    string nume;
    string data;
    string locatie;
    Lista<int> participanti;
public:
    Eveniment();

    Eveniment(int id, string nume, string data, string locatie);

    ~Eveniment();

    int getId() const;

    string getNume() const;

    string getData() const;

    string getLocatie() const;

    Lista<int> getParticipanti() const;

    void setId(int id);

    void setNume(string nume);

    void setData(string data);

    void setLocatie(string locatie);

    void addParticipant(int id);

    void removeParticipant(int id);

    friend ostream &operator<<(ostream &out, Eveniment &e);

    friend istream &operator>>(istream &in, Eveniment &e);

    bool operator<(const Eveniment &e);

    bool operator>(const Eveniment &e);
};


#endif //SDA_ECEDI_ALEXANDRU_312_EVENIMENT_H
