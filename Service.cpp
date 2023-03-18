//
// Created by alexe on 7/1/2022.
//

#include "Service.h"
#include "iostream"
#include "ostream"
#include "fstream"
#include "Lista.h"

using namespace std;

Service::Service() {
    ;
}

Service::Service(string UsersFile, string EventsFile) {
    this->UsersFile = UsersFile;
    this->EventsFile = EventsFile;
    try {
        ReadEventsFromFile();
        ReadUsersFromFile();
    } catch (string &e) {
        cout << e << endl;
    }
}

Service::~Service() {
    ;
}

void Service::saveUsersToFile() {
    ofstream fout(UsersFile);

    if (!fout.is_open()) {
        throw string("Fisierul cu utilizatori nu poate fi dischis!");
    }
    TAD_ARRAY<Utilizator> aux;
    for (int i = 0; i < users.getNoElems(); i++) {
        aux.addElem(users.getAll()[i]);
    }
    for (int i = 0; i < aux.getNoElems(); i++) {
        fout << aux.getAll()[i] << endl;
    }
    fout.close();
}

void Service::ReadUsersFromFile() {
    ifstream fin(UsersFile);

    if (!fin.is_open()) {
        throw string("Fisierul cu utilizatori nu poate fi dischis!");
    }

    Utilizator u;
    while (fin >> u) {
        this->users.addElem(u);
    }
}

void Service::SaveEventsToFile() {
    ofstream fout(EventsFile);

    if (!fout.is_open()) {
        throw string("Fisierul cu evenimente nu poate fi dischis!");
    }

    Lista<Eveniment> lista = this->events.get_lista_ordonata();

    for (int i = 0; i < lista.getDim(); i++) {
        fout << lista[i] << endl;
    }
    fout.close();
}

void Service::ReadEventsFromFile() {
    ifstream fin(EventsFile);

    if (!fin.is_open()) {
        throw string("Fisierul cu evenimente nu poate fi dischis!");
    }

    while (!fin.eof()) {
        Eveniment e;
        fin >> e;
        if (fin.eof()) {
            break;
        }
        this->events.adauga(e);
    }
}

void Service::addUser(const Utilizator &u) {
    users.addElem(u);
    saveUsersToFile();

}

void Service::addEvent(const Eveniment &e) {
    events.adauga(e);
    SaveEventsToFile();
}

TAD_ARRAY<Utilizator> Service::getUtilizatori() {
    TAD_ARRAY<Utilizator> aux;
    for (int i = 0; i < users.getNoElems(); i++) {
        aux.addElem(users.getAll()[i]);
    }
    return aux;
}

Lista<Eveniment> Service::getEvenimente() {
    return events.get_lista_ordonata();

}

Conversatie Service::getConversatie(int id) {
    for (int i = 0; i < chats.getDim(); i++)
        if (chats[i].getId() == id)
            return chats[i];
}

void Service::creeazaChat(const Conversatie &c) {

    chats.adauga(c);
}

Lista<Conversatie> Service::getConversatii() {
    return chats;
}

void Service::trimiteMesaj(int id1, int id2, string mesaj) {

    for (int i = 0; i < chats.getDim(); i++) {
        if ((chats[i].getIdUser1() == id1 && chats[i].getIdUser2() == id2) ||
            (chats[i].getIdUser1() == id2 && chats[i].getIdUser2() == id1)) {
            chats[i].addMesaj(id1, mesaj);
            cout << "Mesaj trimis." << endl;
            return;
        }
    }
}

void Service::updateUser(int id, const Utilizator &u) {
    for (int i = 0; i < users.getNoElems(); i++) {
        if (users.getAll()[i].getId() == id) {
            this->users.deleteElem(users.getAll()[i]);
            this->users.addElem(u);
            return;
        }
    }
    saveUsersToFile();
    throw string("Utilizatorul cu id-ul " + to_string(id) + " nu exista!");
}

void Service::updateEvent(int id, const Eveniment &e) {
    Lista<Eveniment> lista = this->events.get_lista_ordonata();
    for (int i = 0; i < lista.getDim(); i++) {
        if (lista[i].getId() == id) {
            this->events.sterge(lista[i]);
            this->events.adauga(e);
            SaveEventsToFile();
            return;
        }
    }
    throw string("Evenimentul cu id-ul " + to_string(id) + " nu exista!");
}

void Service::deleteUser(int id) {
    for (int i = 0; i < users.getNoElems(); i++) {
        if (users.getAll()[i].getId() == id) {
            this->users.deleteElem(users.getAll()[i]);
            saveUsersToFile();
            return;
        }
    }
    throw string("Utilizatorul cu id-ul " + to_string(id) + " nu exista!");
}


void Service::deleteEvent(int id) {
    Lista<Eveniment> lista = this->events.get_lista_ordonata();

    for (int i = 0; i < lista.getDim(); i++) {
        if (lista[i].getId() == id) {
            //this->deleteEventFromList(id);
            this->events.sterge(lista[i]);
            SaveEventsToFile();
            return;
        }
    }
    throw string("Evenimentul cu id-ul " + to_string(id) + " nu exista!");
}

Utilizator Service::getUser(int id) {
    TAD_ARRAY<Utilizator> lista;
    for (int i = 0; i < users.getNoElems(); i++)
        lista.addElem(users.getAll()[i]);
    for (int i = 0; i < lista.getNoElems(); i++) {
        if (lista.getAll()[i].getId() == id) {
            return lista.getAll()[i];
        }
    }

    throw string("Utilizatorul cu id-ul " + to_string(id) + " nu exista!");
}

Eveniment Service::getEvent(int id) {
    Lista<Eveniment> lista = this->events.get_lista_ordonata();

    for (int i = 0; i < lista.getDim(); i++) {
        if (lista[i].getId() == id) {
            return lista[i];
        }
    }

    throw string("Evenimentul cu id-ul " + to_string(id) + " nu exista!");
}

Conversatie Service::getChat(int id) {
    for (int i = 0; i < chats.getDim(); i++) {
        if (chats[i].getId() == id) {
            return chats[i];
        }
    }

    throw string("Chatul cu id-ul " + to_string(id) + " nu exista!");
}

void Service::addFriend(int id_user1, int id_user2) {
    if (id_user1 == id_user2)
        throw string("Id-urile nu pot fi identice!");

    TAD_ARRAY<Utilizator> usersList;
    for (int i = 0; i < users.getNoElems(); i++)
        usersList.addElem(users.getAll()[i]);

    Utilizator *u1 = nullptr;
    Utilizator *u2 = nullptr;
    for (int i = 0; i < usersList.getNoElems(); i++) {
        if (usersList.getAll()[i].getId() == id_user1) {
            u1 = &usersList.getAll()[i];
        }
        if (usersList.getAll()[i].getId() == id_user2) {
            u2 = &usersList.getAll()[i];
        }
    }
    if (u1 == nullptr || u2 == nullptr)
        throw string("Utilizatorul cu id-ul " + to_string(id_user1) + " sau cu id-ul " + to_string(id_user2) +
                     " nu exista!");

    Lista<int> prieteniU1 = u1->getPrieteni();
    Lista<int> prieteniU2 = u2->getPrieteni();

    for (int i = 0; i < prieteniU1.getDim(); i++) {
        if (prieteniU1[i] == u2->getId()) {
            throw string("Userii sunt deja prieteni!");
        }
    }
    u1->addPrieten(u2->getId());
    u2->addPrieten(u1->getId());
    this->users.deleteElem(*u1);
    this->users.deleteElem(*u2);

    this->users.addElem(*u1);
    this->users.addElem(*u2);
    saveUsersToFile();
}

void Service::removeFriend(int id1, int id2) {
    TAD_ARRAY<Utilizator> lista;
    for (int i = 0; i < users.getNoElems(); i++)
        lista.addElem(users.getAll()[i]);
    Utilizator *u1 = nullptr;
    Utilizator *u2 = nullptr;

    for (int i = 0; i < lista.getNoElems(); i++) {
        if (lista.getAll()[i].getId() == id1) {
            u1 = &lista.getAll()[i];
        }
        if (lista.getAll()[i].getId() == id2) {
            u2 = &lista.getAll()[i];
        }
    }
    Lista<int> prieteniU1 = u1->getPrieteni();
    Lista<int> prieteniU2 = u2->getPrieteni();
    for (int i = 0; i < prieteniU1.getDim(); i++) {
        if (prieteniU1[i] == u2->getId()) {
            u1->removePrieten(u2->getId());
            u2->removePrieten(u1->getId());

            this->users.deleteElem(*u1);
            this->users.deleteElem(*u2);

            this->users.addElem(*u1);
            this->users.addElem(*u2);
            return;
        }
    }

    throw string(
            "Utilizatorul cu id-ul " + to_string(id2) + " nu este prieten cu utilizatorul cu id-ul " + to_string(id1) +
            "!");
}

Lista<int> Service::getFriends(int id_user) {
    TAD_ARRAY<Utilizator> lista;
    for (int i = 0; i < users.getNoElems(); i++)
        lista.addElem(users.getAll()[i]);
    Utilizator *u = nullptr;
    for (int i = 0; i < lista.getNoElems(); i++) {
        if (lista.getAll()[i].getId() == id_user) {
            u = &lista.getAll()[i];
        }
    }
    return u->getPrieteni();
}

Conversatie Service::getChatBetween(int id_user1, int id_user2) {
    for (int i = 0; i < chats.getDim(); i++) {
        if (chats[i].getIdUser1() == id_user1 && chats[i].getIdUser2() == id_user2) {
            return chats[i];
        } else if (chats[i].getIdUser1() == id_user2 && chats[i].getIdUser2() == id_user1) {
            return chats[i];
        }
    }
    throw string("Nu exista niciun chat intre acesti utilizatori!");
}

void Service::participareEveniment(int id_user, int id_eveniment) {
    TAD_ARRAY<Utilizator> listaU;
    for (int i = 0; i < users.getNoElems(); i++) {
        listaU.addElem(users.getAll()[i]);
    }

    Utilizator *u = nullptr;

    for (int i = 0; i < listaU.getNoElems(); i++) {
        if (listaU.getAll()[i].getId() == id_user) {
            u = &listaU.getAll()[i];
        }
    }

    if (u == nullptr) {
        throw string("Utilizatorul cu id-ul " + to_string(id_user) + " nu exista!");
    }

    Lista<Eveniment> listaE = this->events.get_lista_ordonata();

    Eveniment *e = nullptr;

    for (int i = 0; i < listaE.getDim(); i++) {
        if (listaE[i].getId() == id_eveniment) {
            e = &listaE[i];
        }
    }

    if (e == nullptr) {
        throw string("Evenimentul cu id-ul " + to_string(id_eveniment) + " nu exista!");
    }

    Lista<int> participanti = e->getParticipanti();

    for (int i = 0; i < participanti.getDim(); i++) {
        if (participanti[i] == u->getId()) {
            throw string("Utilizatorul cu id-ul " + to_string(id_user) + " participa deja la evenimentul cu id-ul " +
                         to_string(id_eveniment) + "!");
        }
    }

    e->addParticipant(u->getId());
    u->addEveniment(e->getId());

    this->events.sterge(*e);
    this->events.adauga(*e);

    this->users.deleteElem(*u);
    this->users.addElem(*u);
    SaveEventsToFile();
}

Lista<int> Service::getParticipanti(int id_eveniment) {
    Lista<Eveniment> listaE = this->events.get_lista_ordonata();

    Eveniment *e = nullptr;

    for (int i = 0; i < listaE.getDim(); i++) {
        if (listaE[i].getId() == id_eveniment) {
            e = &listaE[i];
        }
    }

    if (e == nullptr) {
        throw string("Evenimentul cu id-ul " + to_string(id_eveniment) + " nu exista!");
    }

    return e->getParticipanti();
}

void Service::stergereParticipare(int id_user, int id_eveniment) {
    TAD_ARRAY<Utilizator> listaU;
    for (int i = 0; i < users.getNoElems(); i++) {
        listaU.addElem(users.getAll()[i]);
    }

    Utilizator *u = nullptr;

    for (int i = 0; i < listaU.getNoElems(); i++) {
        if (listaU.getAll()[i].getId() == id_user) {
            u = &listaU.getAll()[i];
        }
    }

    if (u == nullptr) {
        throw string("Utilizatorul cu id-ul " + to_string(id_user) + " nu exista!");
    }

    Lista<Eveniment> listaE = this->events.get_lista_ordonata();

    Eveniment *e = nullptr;

    for (int i = 0; i < listaE.getDim(); i++) {
        if (listaE[i].getId() == id_eveniment) {
            e = &listaE[i];
        }
    }

    if (e == nullptr) {
        throw string("Evenimentul cu id-ul " + to_string(id_eveniment) + " nu exista!");
    }

    Lista<int> participanti = e->getParticipanti();


    e->removeParticipant(u->getId());
    u->removeEveniment(e->getId());

    this->events.sterge(*e);
    this->events.adauga(*e);

    this->users.deleteElem(*u);
    this->users.addElem(*u);
    SaveEventsToFile();
}
