#ifndef SDA_ECEDI_ALEXANDRU_312_UTILIZATOR_H
#define SDA_ECEDI_ALEXANDRU_312_UTILIZATOR_H

#include "string"
#include "Array.h"
#include "Lista.h"

using namespace std;

class Utilizator {
private:
    int id;
    string nume;
    int varsta;
    string email;
    string parola;
    Lista<int> prieteni;
    Lista<int> evenimente;
public:
    Utilizator();

    Utilizator(int id, string nume, int varsta, string email, string parola);

    Utilizator(int id, string nume, int varsta, string email, string parola,Lista<int> prieteni,
    Lista<int> evenimente);

    Utilizator &operator=(const Utilizator &u);

    ~Utilizator();

    int getId() const;

    string getNume() const;

    int getVarsta() const;

    string getEmail() const;

    string getParola() const;

    Lista<int> getPrieteni() const;

    Lista<int> getEvenimente() const;

    void setId(int id);

    void setNume(string nume);

    void setVarsta(int varsta);

    void setEmail(string email);

    void setParola(string parola);

    void addPrieten(int id);

    void addEveniment(int id);

    void removePrieten(int id);

    void removeEveniment(int id);

    friend ostream &operator<<(ostream &out, Utilizator &u);

    friend istream &operator>>(istream &in, Utilizator &u);

    bool operator<(const Utilizator &u);

    bool operator>(const Utilizator &u);

    bool operator==(const Utilizator &u);
};


#endif //SDA_ECEDI_ALEXANDRU_312_UTILIZATOR_H
