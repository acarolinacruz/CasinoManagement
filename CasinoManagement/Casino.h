#ifndef CASINO_H
#define CASINO_H
#include <iostream>
#include <map>
#include <list>
#include "Machine.h"
#include "Player.h"

using namespace std;




class CASINO {
	map <string, list<PLAYER*>*> Dados;
	string name;
	string locality;

public:
	//CASINO();
	CASINO(string pName);
	~CASINO();
	//Get's and set's
	string GetName();
	void SetName(string pName);
	string GetLocality();
	void SetLocality(string pLocality);
	//functions from cpp
	bool AddPlayer(int id, string name, string city, int age);

	bool ReadFile(const string& file_name);
	void Show();
	bool Remove(PLAYER* P);
	bool Remove(string nome);
	bool SaveFile(string file);
	PLAYER* SearchPlayer(string name);
	string GetMachineMorePlayed();

	//bool Load(const string & fich);

	//add users / player
	bool AddPlayer(PLAYER* P);

	//add machines 
	bool Add(MACHINE* m);


	//listar estado atual do casino 
	void Listar(ostream& f = std::cout);


	//shut down a given machine according with machine id
	void Desligar(int id_maq);

	//estado da machine
	//ESTADO_MAQUINA Casino::Get_Estado(int id_maq) 

	//calcular a memoria total
	int Memoria_Total();

	list<MACHINE*>* Listar_Tipo(string Tipo, ostream& f = std::cout);





};




#endif