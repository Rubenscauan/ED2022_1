#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<string> floresta;
    int nl{}, nc{};
    cin >> nl >> nc;
    for(int i = 0;i < nl;i++){
        string linha;
        cin >> linha;
        floresta.push_back(linha);
    }

    for(auto linha : floresta){
        for(auto c : linha){
            cout << c;
        }
        cout << endl;
    }
}