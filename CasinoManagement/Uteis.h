#ifndef UTEIS_H
#define UTEIS_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <sstream>
using namespace std;

class UTEIS
{
public:
    // S → string exemplo: cidade;nome;idade
    // car→ delimitador neste caso ;
    // lpartes lista de strings onde são inseridos os valores separados por ;
    // divide uma string por um caracter delimitador
    static int SplitLinha(string s, char car, list<string>& lpartes)
    {
        lpartes.clear();
        stringstream ss(s);
        string item;
        while (getline(ss, item, car))
            lpartes.push_back(item);
        return lpartes.size();
    }
    //s = <NOME>Josezito</NOME>
    //lp = {"NOME"; "Josezito"; "NOME"}
    // ret = 3;
    //s = <PESSOA>
    //lp = {"PESSOA"}
    // ret = 1;
    static int SplitLinhaXML(string s, list<string>& lp)
    {
        char StarTAG[50], TEX[50], EndTAG[50];
        int ret = sscanf_s(s.c_str(), "\t<%[^>]>%[^</]</%[^>]>", StarTAG, TEX, EndTAG);
        if (ret == 0) return ret;
        if (ret >= 1)
            lp.push_back(string(StarTAG));
        if (ret >= 2)
            lp.push_back(string(TEX));
        if (ret == 3)
            lp.push_back(string(EndTAG));
        return ret;
    }
    static void MostrarListaString(list<string>& ls)
    {
        int pos = 0;
        for (list<string>::iterator it = ls.begin(); it != ls.end(); ++it, pos++)
            cout << "Lista[" << pos << "]= " << *it << endl;
    }

    // devolve a string mediante a posicao
    static string GetPosicao(int pos, list<string>& lcampos)
    {
        list<string>::iterator it = lcampos.begin();
        advance(it, pos);
        return *it;
    }



    //draw line
    void drawLine(int n, char symbol)
    {
        for (int i = 0; i < n; i++)
            cout << symbol;
        cout << "\n";
    }

    /*
      void rules()
      {
       // system("cls");
        cout << "\n\n";
        drawLine(80,'-');
        cout << "\t\tRULES OF THE GAME\n";
        drawLine(80,'-');
        cout << "\t1. Choose any number between 1 to 10\n";
        cout << "\t2. If you win you will get 10 times of money you bet\n";
        cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
        drawLine(80,'-');
      }
    */




};

#endif // UTEIS_H
