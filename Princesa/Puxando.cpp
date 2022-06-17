#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void show_vet(std::vector<int> vet, int sword) {
    for (int i = 0; i < (int) vet.size(); i++)
        std::cout << vet[i] << (i == sword? "> " : "  ");
    std::cout << std::endl;
}

int main() {
    int size {}, sword {};
    std::cin >> size >> sword;
    std::vector<int> vet(size);
    for (int i = 0; i < size; i++)
        vet[i] = i + 1; // preenche o vetor
    sword -= 1;
    while(vet.size() > 1) {
        show_vet(vet, sword);
        sword = (sword + 1) % vet.size();
        vet.erase(vet.begin() + sword);
        sword = sword % vet.size();
    }
    show_vet(vet, sword);
}