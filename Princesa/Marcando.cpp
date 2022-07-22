#include <iostream>
#include <vector>
#include <list>
using namespace std;


vector<int> PreencherVetor(int tamanho,vector<int> &vetor){
    for(int i = 0; i < tamanho;i++){
        vetor.push_back(i);
    }
    return vetor;
}

void apagarPosicao(int posicao,vector<int> &vetor){
    for(int i = posicao; i < vetor.size();i++){
        vetor[posicao] = vetor[posicao+1];
        posicao++;
    }
    vetor.pop_back();
}

vector<bool> PreencherBool(int tamanho,vector<bool> & vetor){
    for(int i = 0; i < tamanho;i++){
        vetor.push_back(true);
    }
    return vetor;
    
}

void printar(vector<int> vetor){
    cout << "[";
    for(int i = 0; i < vetor.size();i++){
        if(i == vetor.size() - 1){
            cout << vetor[i] << "]\n";
            return;
        }
        cout << vetor[i] << ", ";
    }
}

void princesa_puxando(int escolhido,vector<int> &vetor){
    while(vetor.size() > 1){
        vetor.erase(vetor.begin() + (escolhido + 1) % vetor.size());
        escolhido = (escolhido + 1) % vetor.size();
        printar(vetor);
    }
}

void princesa_marcando(int escolhido,vector<int> &vetor){
    vector<bool> aux;
    PreencherBool(vetor.size(),aux);
    for(int i = escolhido; vetor.size() > 1; i++){
        if(aux[i+1] == true){
            aux[i+1] = false;
            apagarPosicao((escolhido+1)%vetor.size(),vetor);
            
            escolhido = (escolhido+1)%vetor.size();
            printar(vetor);
        }
    }
}


int main()
{
    vector<int> vetor;
    PreencherVetor(6,vetor);
    princesa_marcando(0,vetor);
    return 0;
    
}
