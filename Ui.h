//
// Created by alexe on 7/1/2022.
//

#ifndef SDA_ECEDI_ALEXANDRU_312_UI_H
#define SDA_ECEDI_ALEXANDRU_312_UI_H

#include "Service.h"

class Ui {
private:
    Service service;

    void options();

    void addUser();

    void updateUser();

    void DeleteUser();

    void showUsers();

    void addEvent();

    void updateEvent();

    void deleteEvent();

    void showEvents();

    void creazaChat();

    void trimiteMesaj();

    void afisareChat();

    void adaugaPrieten();

    void stergePrieten();

    void participareEveniment();

    void stergereParticipareEveniment();

    void afisareParticipanti();

    void CrudUser();

    void CrudEvent();

    void Chats_Friends();

    void afisarePrieteni();

public:
    Ui();

    Ui(Service &s);

    ~Ui();

    void show_menu();
};


#endif //SDA_ECEDI_ALEXANDRU_312_UI_H
