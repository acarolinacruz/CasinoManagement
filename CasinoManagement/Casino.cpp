#include "Casino.h"
#include "Player.h"
#include "Uteis.h"
#include <fstream>

using namespace std;

// Creating a player object
PLAYER* objPlayer = new PLAYER(1, "test 1", "viseu", 18);

// FIRST GENERAL FUNCIONALITY FOR PROJECT
// Construtor do Casino, sendo dado o nome do casino
// Casino::Casino (string nome)
CASINO::CASINO(string pName) {

    // cout << __FUNCTION__ << endl;
}

CASINO::~CASINO() {
    // cout << __FUNCTION__ << endl;
    // scroll through the map and list freeing up allocated memory
    map<string, list<PLAYER*>*>::iterator itMAP;
    for (itMAP = Dados.begin(); itMAP != Dados.end(); ++itMAP) {

        for (list<PLAYER*>::iterator itLISTA = itMAP->second->begin();
            itLISTA != itMAP->second->end();
            ++itLISTA) {      // scroll through the players list
            delete ((*itLISTA)); // freeing up allocated memory of a player
        }
        // freeing up allocated memory of the list
        delete (itMAP->second);
    }
    /// DADOS não foi alocado por nós GC
}



// Creating a new player
// Asking the user the needed info to create a player
bool CASINO::AddPlayer(int pId, string pName, string pCity, int pAge) {
    cout << __FUNCTION__ << endl;
    PLAYER* NewPlayer = new PLAYER(pId, pName, pCity, pAge);
    if (!NewPlayer) { // erro
        cout << "Ups! It was not possible to create a player..." << endl;
        return 0;
    }

    return AddPlayer(NewPlayer); // put on map
}
// THIRTH GENERAL FUNCIONALITY FOR PROJECT
// Adicionar Utilizadores/Jogadores
// bool Casino::Add(User *ut) 
bool CASINO::AddPlayer(PLAYER* P) {
    cout << __FUNCTION__ << endl;
    // put on the MAP / list
    map<string, list<PLAYER*>*>::iterator it;
    list<PLAYER*>* ListaPlayers;
    it = Dados.find(P->GetCity());
    if (it != Dados.end())       // exists
        ListaPlayers = it->second; // pointer to the existent list
    else {
        ListaPlayers = new list<PLAYER*>(); // creates new list
    }
    ListaPlayers->push_back(P);         // add P on list
    Dados[P->GetCity()] = ListaPlayers; // add list to the map
    return 1;
}


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!! H E R E !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!! ADD NEEDED FILE HERE AND TEST IT !!!!!!!!!!!!!!!!!!!
// SECOND GENERAL FUNCIONALITY FOR PROJECT
// As configurações do Casino dadas em ficheiro XML, com todas as informações. 
// bool Casino::Load(const string &ficheiro)
bool CASINO::ReadFile(const string& file_name) {
    cout << endl << __FUNCTION__ << endl;
    ifstream F(file_name);
    if (!F.is_open())
        return false;
    string linha;
    list<string> lcampos;
    int ret;
    while (!F.eof()) {
        getline(F, linha);
        ret = UTEIS::SplitLinha(linha, ';', lcampos);
        if (ret == 4) // it has to have id + city + name + age
        {
            int id = stoi(UTEIS::GetPosicao(0, lcampos));
            string city = UTEIS::GetPosicao(1, lcampos);
            string name = UTEIS::GetPosicao(2, lcampos);
            int age = stoi(UTEIS::GetPosicao(3, lcampos));
            /* cout << "Id = " << id << endl;
             cout << "City = " << ciy << endl;
             cout << "Name = " << name << endl;
             cout << "Age = " << age << endl;*/
            AddPlayer(id, name, city, age);
        }
    }
    F.close();
    return true;
}
void CASINO::Show() {
    cout << __FUNCTION__ << endl;
    map<string, list<PLAYER*>*>::iterator itMAP;
    for (itMAP = Dados.begin(); itMAP != Dados.end(); ++itMAP) {
        cout << " Cidade : " << itMAP->first << " [" << itMAP->second->size() << "]"
            << endl;
        for (list<PLAYER*>::iterator itLISTA = itMAP->second->begin();
            itLISTA != itMAP->second->end();
            ++itLISTA) { // scroll through the players list
            (*itLISTA)->Show();
        }
    }
}
bool CASINO::Remove(PLAYER* P) {
    cout << __FUNCTION__ << endl;
    // verify if exists city key
    map<string, list<PLAYER*>*>::iterator itMAP;
    itMAP = Dados.find(P->GetCity());
    if (itMAP == Dados.end()) // it doesn't exists(!)
        return 0;
    itMAP->second->remove(P); // remove from the list
    return 1;
}
bool CASINO::Remove(string pName) {
    cout << __FUNCTION__ << endl;
    map<string, list<PLAYER*>*>::iterator itMAP;
    for (itMAP = Dados.begin(); itMAP != Dados.end(); ++itMAP) {
        for (list<PLAYER*>::iterator itLISTA = itMAP->second->begin();
            itLISTA != itMAP->second->end();
            ++itLISTA) { // scroll through the players list
            if ((*itLISTA)->GetName().compare(pName) == 0) { // equals
                itMAP->second->erase(itLISTA);                 // delete
                return true;
            }
        }
    }
    return false;
}

bool CASINO::SaveFile(string file) {
    cout << endl << __FUNCTION__ << endl;
    ofstream F(file); //***
    if (!F.is_open())
        return false; //***
    map<string, list<PLAYER*>*>::iterator itMap;
    for (itMap = Dados.begin(); itMap != Dados.end(); ++itMap) {
        // show all players from list
        for (list<PLAYER*>::iterator itL = itMap->second->begin();
            itL != itMap->second->end(); ++itL) {
            PLAYER* P = (*itL);
            F << P->GetCity() << ";" << P->GetName() << ";" << P->GetAge()
                << endl; //***
        }
    }
    F.close();
    return true;
}

PLAYER* CASINO::SearchPlayer(string name) {
    cout << endl << __FUNCTION__ << endl;
    map<string, list<PLAYER*>*>::iterator itMap;
    for (itMap = Dados.begin(); itMap != Dados.end(); ++itMap) {
        // show all players from list
        for (list<PLAYER*>::iterator itL = itMap->second->begin();
            itL != itMap->second->end(); ++itL)
            if ((*itL)->GetName().compare(name) == 0) { // coincide
                return *itL;
            }
    }
    return NULL;
}

string CASINO::GetMachineMorePlayed() {
    cout << endl << __FUNCTION__ << endl;
    string MachineMorePlayed = "";
    int ContadorMachineMorePlayed = 0;
    map<string, list<PLAYER*>*>::iterator itMap;
    for (itMap = Dados.begin(); itMap != Dados.end(); ++itMap) {
        if (itMap->second->size() > ContadorMachineMorePlayed) {
            ContadorMachineMorePlayed = itMap->second->size(); // save the new max
            MachineMorePlayed = itMap->first;
        }
    }
    return MachineMorePlayed;
    // see why it is not returning the more played machine, it always return the
    // func
}

