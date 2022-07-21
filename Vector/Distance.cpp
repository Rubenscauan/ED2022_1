#include <iostream>
NAO ENTENDI  ESSA

bool pode_inserir(std::string &linha, int index, int valor, int proximidade) {
    for (int i = index + 1; i < index + 1 + proximidade; i++) {
        if (i < int(linha.size()) && linha.at(i) == valor + '0') {
            return false;
        }
    }
    for (int i = index - proximidade; i < index; i++) {
        if (i >= 0 && linha.at(i) == valor + '0') { 
            return false;
        }
    }
    return true;
}

bool preencheu(std::string &linha, int index, int limite, int proximidade) {
    if (index == int(linha.size())) {
        return true;
    } else if (linha.at(index) != '.') {
        return preencheu(linha, index + 1, limite, proximidade);
    }

    for (int valor = 0; valor <= limite; valor++) {
        if (pode_inserir(linha, index, valor, proximidade)) {
            linha.at(index) = valor + '0';
            
            if (preencheu(linha, index + 1, limite, proximidade)) {
                return true;
            }
        }
    }

    linha.at(index) = '.';

    return false;
}

void solucao(std::string &linha, int index, int proximidade, int limite = 0) {
    if (!preencheu(linha, index, limite, proximidade)) {
        limite++;

        solucao(linha, index, proximidade, limite);
    } else {
        std::cout << "-> " << linha << std::endl << "N -> " << limite << std::endl;
        return;
    } 
}

int main() {
    std::string linha {};
    int proximidade {};

    std::cin >> linha >> proximidade;

    std::cout << std::endl;
    
    solucao(linha, 0, proximidade);

    return 0;
}
