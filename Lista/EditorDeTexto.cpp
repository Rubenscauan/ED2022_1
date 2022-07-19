#include <iostream>
#include <list>
#include <sstream>

//COPIADO DO GIT DOS CODIGOS, ENTENDI A LOGICA MAS NÃO CONSEGUI APLICAR

using namespace std;

struct State{
    list <char> text;
    list <char>::iterator cursor;
    State(){
        cursor = text.begin();
    }

    State(string init) {
        for (int i = 0; i < init.size(); i++) {
            text.push_back(init[i]);
        }
        cursor = text.begin();
    }

    State(const State& other) {
        text = other.text;
        cursor = other.cursor;
    }

    string getText() {
        stringstream ss;
        for (auto it = text.begin(); it != text.end(); it++) {
            ss << *it;
        }
        return ss.str();
    }
};

struct Principal {
    list <State> states;
    list <State>::iterator itc;

    Principal(string init_text = "") {
        states.push_back(State(init_text));
        itc = states.begin();
    }

    void controlZ() {
        if (itc != states.begin()) {
            itc--;
        }
    }

    void controlY() {
        if (itc != states.end()) {
            itc++;
        }
    }

    void insertchar(char c) {
        itc->text.insert(itc->cursor, c);
        itc->cursor++;
    }

    void sendBackspace() {
        if (itc->cursor != itc->text.begin()) {
            itc->text.erase(itc->cursor--);
        }
    }

    void sendDelete() {
        if (itc->cursor != itc->text.end()) {
            itc->text.erase(itc->cursor++);
        }
    }

    void sendUp() {
        int desloc = 0;
        auto it = itc->cursor;

        while(((*prev(it)) != '\n') && (prev(it) != itc->text.end())){
            desloc++;
            it--;
        }
       
        if(prev(it) != itc->text.end()){
            
            do{
                it--;
            }while(((*prev(it)) != '\n') && (prev(it) != itc->text.end()));
          
            for(int i = 0; i < desloc; i++){
                if(((*it) == '\n') || (it == itc->text.end()))
                    break;
                else
                    it++;
            }
            itc->cursor = it;
        }
    }

    void sendDown() {
        int desloc = 0;
        auto it = itc->cursor;
        while(((*next(it)) != '\n') && (next(it) != itc->text.end())){
            desloc++;
            it++;
        }
        if(next(it) != itc->text.end()){
            do{
                it++;
            }while(((*next(it)) != '\n') && (next(it) != itc->text.end()));
            for(int i = 0; i < desloc; i++){
                if(((*it) == '\n') || (it == itc->text.end()))
                    break;
                else
                    it++;
            }
            itc->cursor = it;
        }
    }

    void sendLeft() {
        if (itc->cursor != itc->text.begin()) {
            itc->cursor--;
        }
    }

    void sendRight() {
        if (itc->cursor != itc->text.end()) {
            itc->cursor++;
        }
    }
};

void processKey(Principal& tela, char tecla) {
   if (tecla == 'z')
        tela.controlZ();
    else if (tecla == 'y')
        tela.controlY();
    else if (tecla == 'B')
        tela.sendBackspace();
    else if (tecla == 'D')
        tela.sendDelete();
    else if (tecla == 'U')
        tela.insertchar('\n');
    else if (tecla == 'L')
        tela.insertchar('\t');
    else if (tecla == 'A') {
        tela.sendUp();
    } else if (tecla == 'V') {
        tela.sendDown();
    } else if (tecla == '<') {
        tela.sendLeft();
    } else if (tecla == '>') {
        tela.sendRight();
    } else {
        tela.insertchar(tecla);
    }
}

int main () {
    string texto;
    cin >> texto;
    Principal tela(texto);
    char tecla;
    while (cin >> tecla) {
        processKey(tela, tecla);
        cout << tela.itc->getText() << endl;
    }
    return 0;
}
