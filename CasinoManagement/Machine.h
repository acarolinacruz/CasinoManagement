#ifndef MACHINE_H
#define MACHINE_H
#include <iostream>
#include <map>
#include <list>


using namespace std;


class MACHINE {
private: // attributes
    int id;
    string type;
protected:
public:
    MACHINE();
    ~MACHINE();
    virtual void Show() {
        cout << endl << " ### MACHINE ###";
        cout << endl << "ID: " << id;
        cout << endl << "Type: " << type;
    }
    // GET e SET // id
    int GetId() {
        return id;
    }
    void SetId(int new_id) {
        id = new_id;
    }
    //GET e SET // type
    string GetType() {
        return type;
    }
    void SetType(string new_type) {
        type = new_type;
    }
};



#endif