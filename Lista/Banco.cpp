#include <iostream>
#include <list>
#include <vector>

struct Cliente {
    std::string nome;
    int docs;
    int paciencia;

    Cliente(std::string nome, int docs, int paciencia) : nome(nome), docs(docs), paciencia(paciencia) {}

    std::string str() {
        return nome + ":" + std::to_string(docs) + ":" + std::to_string(paciencia); 
    }
};

class Banco {
private:
    std::vector<Cliente*> caixas;
    std::list<Cliente*> fila_entrada {};
    std::list<Cliente*> fila_saida {};
    int docs_received {0};
    int docs_lost {0};
    int tics {0};
    int quantidade {0};
    
public:
    Banco(int caixas) : caixas(caixas){}

    void insere(Cliente *client) {
        this->fila_entrada.push_back(client);
        
        ++quantidade;
    }

    bool vazio() {
        return this->quantidade == 0;
    }


    void passar_tempo() {
        if (!this->fila_saida.empty()) {
            for (auto it = fila_saida.begin(); it != fila_saida.end(); it++) {
                this->docs_lost += (*it)->docs;
                
                auto backup = it;
                
                it = this->fila_saida.erase(it);
                
                delete *backup;
            }

            --quantidade;
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

    void show_all() {
        for(auto &client : this->caixas) {
            std::cout << "[" << (client == nullptr ? "" : client->str()) << "]";
        }
        
        std::cout << "\nin :{ ";
        
        for(auto &client : this->fila_entrada)
            std::cout << (client == nullptr ? "" : client->str()) << " ";
        
        std::cout << "}\nout:{ ";
        
        for(auto &client : this->fila_saida)
            std::cout << (client == nullptr ? "" : client->str()) << " ";
        
        std::cout << "}\n";
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

