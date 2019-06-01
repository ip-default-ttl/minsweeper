#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
class emptypos {
protected:
    unsigned short int x;
    unsigned short int y;
    unsigned short int nearby;
public:
    emptypos (unsigned short int a, unsigned short int b) {x=a; y=b;}
    ~emptypos () {x=0;y=0;nearby=0;}
};
class mine {
protected:
    unsigned int x;
    unsigned int y;
    bool explode;
public:
}
struct pole {
    int length; 
    int width;
    emptypos* empt;
    mine* min;
    };

//прототипы
inline void message1 ();
inline void message2 ();
//конец

int main () {
    string* command;
    command = new string [1];
    while (command<>"exit") 
return 0;
}

inline void message1() {
    system ("clear");
    cout << "----------------------------------------------------------------------------------"<<endl;
    cout << "|                      Welcome to Conslole minesweeper                           |"<<endl;
    cout << "----------------------------------------------------------------------------------"<<endl;
}

inline void message2 () {
    system ("clear");
    cout << "----------------------------------------------------------------------------------"<<endl;
    cout << "|                               Console minesweeper                              |"<<endl;
    cout << "----------------------------------------------------------------------------------"<<endl;
}

inline void main_help () {
    message2 ();
    cout << 
}
