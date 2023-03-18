//
// Created by alexe on 7/1/2022.
//

#ifndef SDA_ECEDI_ALEXANDRU_312_SERVICE_H
#define SDA_ECEDI_ALEXANDRU_312_SERVICE_H

#include "string"
#include "ArboreBinarCautare.h"
#include "Array.h"
#include "Utilizator.h"
#include "Eveniment.h"
#include "Conversatie.h"

using namespace std;

class Service {
private:
    TAD_ARRAY<Utilizator> users;
    ArboreBinarCautare<Eveniment> events;
    Lista<Conversatie> chats;
    string UsersFile;
    string EventsFile;

    void saveUsersToFile();

    void ReadUsersFromFile();

    void SaveEventsToFile();

    void ReadEventsFromFile();

public:
    Service();

    Service(string UsersFile, string EventsFile);

    ~Service();

    void addUser(const Utilizator &u);

    void addEvent(const Eveniment &e);

    Utilizator getUser(int id);

    Eveniment getEvent(int id);

    Conversatie getChat(int id);

    Conversatie getChatBetween(int id_user1, int id_user2);

    void updateUser(int id, const Utilizator &u);

    void updateEvent(int id, const Eveniment &e);

    void deleteUser(int id);

    void deleteEvent(int id);

    void creeazaChat(const Conversatie &c);

    void participareEveniment(int id_user, int id_eveniment);

    void stergereParticipare(int id_user, int id_eveniment);

    TAD_ARRAY<Utilizator> getUtilizatori();

    Lista<Eveniment> getEvenimente();

    Lista<Conversatie> getConversatii();

    Conversatie getConversatie(int id);

    void addFriend(int id_user1, int id_user2);

    void removeFriend(int id1, int id2);

    Lista<int> getFriends(int id_user);

    Lista<int> getParticipanti(int id_eveniment);

    void trimiteMesaj(int id1, int id2, string mesaj);


};


#endif //SDA_ECEDI_ALEXANDRU_312_SERVICE_H
