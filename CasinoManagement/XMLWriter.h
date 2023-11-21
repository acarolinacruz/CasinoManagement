#include <string>
#include <fstream>
#include <stack>
#ifndef XMLWRITER_H
#define XMLWRITER_H
using namespace std;


class XMLWriter
{
private:
	fstream file; // apenas acessivel na class
	stack<string> stkelementos;
public:
	XMLWriter();  // construtor
	~XMLWriter(); // destrutor
	void WriteStartDocument(string ficheiro);
	void WriteEndDocument();
	void WriteElementString(string el, string valor);
	void WriteStartElement(string el);
	void WriteEndElement();
};

#endif