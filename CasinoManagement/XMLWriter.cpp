#include <iostream>
#include <fstream>
#include "XMLWriter.h"
using namespace std;

XMLWriter::XMLWriter() {
    cout << " # " << __FUNCTION__ << " # " << endl;
}
XMLWriter::~XMLWriter() {
    cout << " # " << __FUNCTION__ << " # " << endl;

}
void XMLWriter::WriteStartDocument(string ficheiro) {
    cout << " # " << __FUNCTION__ << " # " << endl;
    // abertura do ficheiro
    file.open(ficheiro, ofstream::out); // sempre conteudo vazio
    if (file.is_open()) // verificar o sucesso da abertura do ficheiro
        cout << "ok" << endl;
    else
        cout << "Problemas a abrir o ficheiro!" << endl;
}
void XMLWriter::WriteEndDocument() {
    cout << " # " << __FUNCTION__ << " # " << endl;

}
void XMLWriter::WriteElementString(string el, string valor) {
    cout << " # " << __FUNCTION__ << " # " << endl;

    if (file.is_open()) {  // proteger o código
      // tabuladores
        for (int i = 0; i < stkelementos.size(); i++)
            file << "\t";
        file << "<" << el << ">" << valor << "</" << el << ">" << endl;
    }
}
void XMLWriter::WriteStartElement(string el) {
    cout << " # " << __FUNCTION__ << " # " << endl;
    if (file.is_open()) { // verificar o sucesso da abertura do ficheiro
      // tabuladores
        for (int i = 0; i < stkelementos.size(); i++)
            file << "\t";
        file << "<" << el << ">" << endl;
        stkelementos.push(el);// coloca na pilha
    }
}
void XMLWriter::WriteEndElement() {
    cout << " # " << __FUNCTION__ << " # " << endl;
    if (file.is_open() && stkelementos.size() > 0) {// proteger o código
      // tabuladores
        for (int i = 1; i < stkelementos.size(); i++)
            file << "\t";
        file << "</" << stkelementos.top() << ">" << endl;
        stkelementos.pop();// retira da pilha
    }
}