#include <iostream>
#include <list>
#include <vector>
#include <sstream>

struct Cliente {
    std::string nome;
    int docs;
    int paciencia;

    Cliente(std::string nome, int docs, int paciencia) : nome(nome), docs(docs), paciencia(paciencia) {}

    friend std::ostream& operator<<(std::ostream& os, const Cliente& c){
    os << c.nome << ":" << c.docs << ":" << c.paciencia << " \n";
    return os;
    }

};

class Banco {
private:
    std::vector<Cliente*> caixas;
    std::list<Cliente*> fila_entrada;
    std::list<Cliente*> fila_saida;
    int docs_received;
    int docs_lost;
    int tics;
    int quantidade;
    
public:
    Banco(int caixas = 1) : caixas(caixas){}

    void entrar(Cliente *cliente) {
        fila_entrada.push_back(cliente);
        quantidade++;
    }

    void esvaziar_banco() {
        this->quantidade = 0;
    }


    void passar_tempo() {
        if (!this->fila_saida.empty()) {
            for (auto it = fila_saida.begin(); it != fila_saida.end(); it++) {
                this->docs_lost += (*it)->docs;
                
                auto aux= it;
                
                it = this->fila_saida.erase(it);
                
                delete *aux;
            }

            quantidade--;
        }


        for (auto &elemento_caixa : this->caixas) {
            if (elemento_caixa != nullptr) {
                if (elemento_caixa->docs > 0) {
                    --elemento_caixa->docs;

                    this->docs_received++;
                } else {
                    auto pessoa = elemento_caixa;
                    this->fila_saida.push_back(pessoa);
                    
                    elemento_caixa = nullptr;
                }
            } else {
                if (fila_entrada.empty()) {
                    break;
                }
                
                elemento_caixa = this->fila_entrada.front();

                this->fila_entrada.pop_front();
            }
        }

        if (!fila_entrada.empty()) {
            for (auto it = fila_entrada.begin(); it != fila_entrada.end(); it++) {
                if ((*it)->paciencia > 0) {
                   (*it)->paciencia--;
                } else {
                    auto pessoa = (*it);
                    
                    fila_saida.push_back(pessoa);
                    
                    it = fila_entrada.erase(it);
                }
            }
        }

        ++tics;
    }

    friend std::ostream& operator<<(std::ostream& os, const Banco& b){
        std::cout << "Caixas :" << std::endl;
        std::cout << std::endl;
        
        for(auto &cliente : b.caixas) {
            if(cliente == nullptr)
                std::cout << ""<< std::endl;
            else 
                std::cout << cliente << std::endl;
        }
        std::cout << std::endl;

        std::cout << "Entrada :" << std::endl;
        std::cout << std::endl;
        
        for(auto &cliente : b.fila_entrada){

            if(cliente == nullptr)
                std::cout << "" << std::endl;
            else 
                std::cout << cliente<< std::endl;
        
        std::cout << std::endl;
        }

        std::cout << "Saida :" << std::endl;
        std::cout << std::endl;
        for(auto &cliente : b.fila_saida){
            
            if(cliente == nullptr)
                std::cout << ""<< std::endl;
            else 
                std::cout << cliente<< std::endl;
        std::cout << "}\n";
        }
        return os;
    }

    int get_received() {
        return this->docs_received;
    }

    int get_lost() {
        return this->docs_lost;
    }

    int get_tics() {
        return this->tics;
    }
};

