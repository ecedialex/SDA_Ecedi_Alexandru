//
// Created by alexe on 7/1/2022.
//

#include "Ui.h"

Ui::Ui() {
    ;
}

Ui::Ui(Service &s) {
    this->service = s;
}

Ui::~Ui() {
    ;
}

void Ui::show_menu() {
    int opt = -1;
    while (opt != 4) {
        options();
        cout << "Alegeti optiunea:";
        cin >> opt;
        if (opt == 1)
            CrudUser();
        else if (opt == 2)
            CrudEvent();
        else if (opt == 3)
            Chats_Friends();
        else if (opt == 4)
            exit(0);

    }
}

void Ui::options() {
    cout << "1.CRUD User \n";
    cout << "2.CRUD Event \n";
    cout << "3.Prieteni,chat,participa event \n";
    cout << "4.Exit. \n";
}

void Ui::addUser() {
    int id, varsta;
    string nume, email, parola;
    cout << "Id: ";
    cin >> id;

    cout << "Nume: ";
    cin >> nume;

    cout << "Varsta: ";
    cin >> varsta;

    cout << "Email: ";
    cin >> email;

    cout << "Parola: ";
    cin >> parola;
    try {
        service.addUser(Utilizator(id, nume, varsta, email, parola));
        cout << "Utilizatorul a fost adaugat cu succes!" << endl;
    } catch (string msg) {
        cout << msg << endl;
    }
}

void Ui::updateUser() {
    int id, varsta;
    string nume, email, parola;

    cout << "Id: ";
    cin >> id;

    cout << "Nume nou: ";
    cin >> nume;

    cout << "Varsta noua: ";
    cin >> varsta;

    cout << "Email nou: ";
    cin >> email;

    cout << "Parola noua: ";
    cin >> parola;

    try {
        service.updateUser(id, Utilizator(id, nume, varsta, email, parola));
        cout << "Utilizatorul a fost modificat cu succes!" << endl;
    } catch (string msg) {
        cout << msg << endl;
    }
}

void Ui::DeleteUser() {
    int id;

    cout << "Id: ";
    cin >> id;

    try {
        service.deleteUser(id);
        cout << "Utilizatorul a fost sters cu succes!" << endl;
    } catch (string msg) {
        cout << msg << endl;
    }
}

void Ui::showUsers() {
    for (int i = 0; i < service.getUtilizatori().getNoElems(); i++)
        cout << service.getUtilizatori().getAll()[i] << endl;
}

void Ui::addEvent() {
    int id;;
    string nume, data, locatie;

    cout << "Id: ";
    cin >> id;

    cout << "Nume: ";
    cin >> nume;

    cout << "Data: ";
    cin >> data;

    cout << "Locatie: ";
    cin >> locatie;

    try {
        service.addEvent(Eveniment(id, nume, data, locatie));
        cout << "Eveniment adaugat!" << endl;
    } catch (string msg) {
        cout << msg << endl;
    }
}

void Ui::updateEvent() {
    int id;
    string nume, data, locatie;
    cout << "Id: ";
    cin >> id;
    cout << "Nume nou: ";
    cin >> nume;
    cout << "Data noua: ";
    cin >> data;
    cout << "Locatie noua: ";
    cin >> locatie;
    try {
        service.updateEvent(id, Eveniment(id, nume, data, locatie));
        cout << "Eveniment modificat!" << endl;
    } catch (string msg) {
        cout << msg << endl;
    }
}

void Ui::deleteEvent() {
    int id;
    cout << "Id: ";
    cin >> id;
    try {
        service.deleteEvent(id);
        cout << "Eveniment sters" << endl;
    } catch (string msg) {
        cout << msg << endl;
    }
}

void Ui::showEvents() {
    Lista<Eveniment> list = service.getEvenimente();
    for (int i = 0; i < list.getDim(); i++) {
        cout << "Id: " << list[i].getId() << ", " <<
             "Nume: " << list[i].getNume() << ", " <<
             "Data: " << list[i].getData() << ", " <<
             "Locatie: " << list[i].getLocatie() << endl;
    }
}

void Ui::adaugaPrieten() {
    int id1, id2;
    cout << "Id utilizator 1: ";
    cin >> id1;
    cout << "Id utilizator 2: ";
    cin >> id2;
    try {
        service.addFriend(id1, id2);
        cout << "Prietenie adaugata cu succes" << endl;
    } catch (string msg) {
        cout << msg << endl;
    }
}

void Ui::stergePrieten() {
    int id1, id2;
    cout << "Id utilizator 1: ";
    cin >> id1;
    cout << "Id utilizator 2: ";
    cin >> id2;
    try {
        service.removeFriend(id1, id2);
        cout << "Prietenie stearsa cu succes" << endl;
    } catch (string msg) {
        cout << msg << endl;
    }
}

void Ui::creazaChat() {
    int id, id_utilizator_1, id_utilizator_2;

    cout << "Id chat: ";
    cin >> id;

    cout << "Id utilizator 1: ";
    cin >> id_utilizator_1;

    cout << "Id utilizator 2: ";
    cin >> id_utilizator_2;

    try {
        service.creeazaChat(Conversatie(id, id_utilizator_1, id_utilizator_2));
        cout << "Chat creat cu succes!" << endl;
    } catch (string msg) {
        cout << msg << endl;
    }
}

void Ui::trimiteMesaj() {
    int id_utilizator1, id_utilizator2;
    string mesaj;

    cout << "Id utilizator 1: ";
    cin >> id_utilizator1;

    cout << "Id utilizator 2: ";
    cin >> id_utilizator2;

    cout << "Mesaj: ";
    cin.ignore();
    getline(cin, mesaj);

    try {
        service.trimiteMesaj(id_utilizator1, id_utilizator2, mesaj);
        cout << "Mesaj trimis cu succes!" << endl;
    } catch (string msg) {
        cout << msg << endl;
    }
}

void Ui::afisareChat() {
    int id1, id2;

    cout << "Id utilizator 1: ";
    cin >> id1;

    cout << "Id utilizator 2: ";
    cin >> id2;

    try {
        Conversatie chat = service.getChatBetween(id1, id2);

        cout << chat.getMesaje().getDim() << " mesaje: \n";
        for (int i = 0; i < chat.getMesaje().getDim(); i++) {
            cout << id1 << " - " << id2 << ": " << chat.getMesaje()[i].second << endl;
        }
    } catch (string msg) {
        cout << msg << endl;
    }
}

void Ui::participareEveniment() {
    int idp, ide;
    cout << "Id utilizator: ";
    cin >> idp;
    cout << "Id eveniment: ";
    cin >> ide;
    try {
        service.participareEveniment(idp, ide);
        cout << "Participare inregistrata cu succes" << endl;
    } catch (string msg) {
        cout << msg << endl;
    }
}

void Ui::afisareParticipanti() {
    int id;
    cout << "Id eveniment: ";
    cin >> id;
    Lista<int> participanti = service.getParticipanti(id);
    if (participanti.getDim() == 0)
        cout << "Nu exista participanti! \n";
    else {
        cout << "Participanti: \n";
        for (int i = 0; i < participanti.getDim(); i++) {
            Utilizator u = service.getUser(participanti[i]);
            cout << u.getId() << " " << u.getNume() << endl;
        }
    }


}

void Ui::stergereParticipareEveniment() {
    int id1, id2;

    cout << "Id utilizator: ";
    cin >> id1;

    cout << "Id eveniment: ";
    cin >> id2;

    try {
        service.stergereParticipare(id1, id2);
        cout << "Participare stearsa cu succes" << endl;
    } catch (string msg) {
        cout << msg << endl;
    }
}

void Ui::CrudUser() {
    int opt = -1;
    while (opt != 100) {
        cout << "1.Adauga user. \n";
        cout << "2.Delete user. \n";
        cout << "3.Update user. \n";
        cout << "4.Show users. \n";
        cout << "5.Back. \n";
        cout << "Dati optiunea:";
        cin >> opt;
        if (opt == 1)
            addUser();
        else if (opt == 2)
            DeleteUser();
        else if (opt == 3)
            updateUser();
        else if (opt == 4)
            showUsers();
        else if (opt == 5)
            show_menu();
        else cout << "Optiunea invalida. \n";
    }

}

void Ui::CrudEvent() {
    int opt = -1;
    while (opt != 100) {
        cout << "1.Adauga eveniment. \n";
        cout << "2.Sterge eveniment. \n";
        cout << "3.Update eveniment. \n";
        cout << "4.Show evenimente. \n";
        cout << "5.Back. \n";
        cout << "Dati optiunea:";
        cin >> opt;
        if (opt == 1)
            addEvent();
        else if (opt == 2)
            deleteEvent();
        else if (opt == 3)
            updateEvent();
        else if (opt == 4)
            showEvents();
        else if (opt == 5)
            show_menu();
        else cout << "Optiunea invalida. \n";

    }

}

void Ui::Chats_Friends() {
    int opt = -1;
    while (opt != 11) {
        cout << "1.Adauga prietenie. \n";
        cout << "2.Sterge prietenie. \n";
        cout << "3.Creeaza chat \n";
        cout << "4.Trimite mesaj \n";
        cout << "5.Afisare mesaje intre doi users. \n";
        cout << "6.Participare eveniment. \n";
        cout << "7.Stergere participare eveniment. \n";
        cout << "8.Afisare evenimente participate. \n";
        cout << "9.Afisare prieteni \n";
        cout << "10.Back. \n";
        cout << "Dati optiunea:";
        cin >> opt;

        if (opt == 1)
            adaugaPrieten();
        else if (opt == 2)
            stergePrieten();
        else if (opt == 3)
            creazaChat();
        else if (opt == 4)
            trimiteMesaj();
        else if (opt == 5)
            afisareChat();
        else if (opt == 6)
            participareEveniment();
        else if (opt == 7)
            stergereParticipareEveniment();
        else if (opt == 8)
            afisareParticipanti();
        else if (opt == 9)
            afisarePrieteni();
        else if (opt == 10)
            show_menu();
        else cout << "Optiunea invalida. \n";
    }
}

void Ui::afisarePrieteni() {
    int id;
    cout << "dati id:";
    cin >> id;
    Lista<int> list = service.getFriends(id);
    for (int i = 0; i < list.getDim(); i++) {
        Utilizator u = service.getUser(list[i]);
        cout << "Id: " << u.getId() << ", "
             << "Nume: " << u.getNume() << ", "
             << "Varsta: " << u.getVarsta() << ", "
             << "Email: " << u.getEmail() << ", "
             << "Parola: " << u.getParola() << endl;
    }
}


