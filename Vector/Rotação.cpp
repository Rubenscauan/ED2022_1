#include <iostream>
#include <vector>
using namespace std;

void rotacao(vector<int>& vet, int rotacao){
        rotacao = rotacao % vet.size();
        vector<int> aux;
        for(int i = vet.size() - rotacao; i < vet.size(); i++)//preencher vetor aux
            aux.push_back(vet[i]);
        for(int i = vet.size() - rotacao - 1; i >= 0 ; i--)//trocar a posicao da rotacao
            vet[i + rotacao] = vet[i];
        for(int i = 0; i < aux.size(); i++) //trocar elementos do vetor
            vet[i] = aux[i];
}

void print(vector<int> &vet) {
    cout << "[ ";
    for(int elem : vet)
        cout << elem << " ";
    cout << "]\n";
}

int main(){
    int size, rot;
    cin >> size >> rot;
    vector<int> vet(size);
    for(int i = 0; i < size; i++)
        cin >> vet[i];
    
    rotacao(vet, rot);
    print(vet);
}
