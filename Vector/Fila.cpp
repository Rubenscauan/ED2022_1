#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> vet){
    for( int i = 0; i < vet.size();i++)
	    cout << vet[i] << " " ;
	cout << endl;
}

int main(){
	
	vector<int> pessoas;
	int tamanho, qtdsaiu, igual, aux;
	cin>>tamanho;
	
	for( int i = 0; i < tamanho ;i++){
	    cin >> aux;
	    pessoas.push_back(aux);
	}	    
	cin >> qtdsaiu;
	
	for( int i = 0; i < qtdsaiu ;i++){
		cin >> igual;
		for( int i = 0; i < pessoas.size() ;i++){
			if( igual == pessoas[i]){
			    pessoas.erase(pessoas.begin()+i);
			    break;
			} 
		}
	}
	
    print(pessoas);
}