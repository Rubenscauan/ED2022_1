#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void mostrar(vector<string> floresta){
    for(auto line : floresta){
        cout << line << endl;
    }
}

void queimar(vector<string> &floresta, int li ,int ci) {
    int nl = floresta.size();
    int nc = floresta[0].size();
    if (li < 0 || ci < 0 || li >= nl || ci >= nc) 
        return;
    if(floresta[li][ci] != '#')
        return;
    floresta[li][ci] = 'x'; 
    queimar(floresta, li - 1, ci);
    queimar(floresta, li + 1, ci);
    queimar(floresta, li, ci - 1);
    queimar(floresta, li, ci + 1);

}

int main(){
    vector<string> floresta;
    int nl{}, nc{}, li{}, ci{};
    cin >> nl >> nc >> li >> ci;
    for(int i = 0; i < nl; i++){
        string linha;
        cin >> linha;
        floresta.push_back(linha);
    }

    queimar(floresta, li, ci);
    cout << "\n";
    mostrar(floresta);
}