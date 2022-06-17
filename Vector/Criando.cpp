#include <iostream>
#include <vector>

struct vector{
    int _capacity;
    int _size;
    int *_data;

    vector(int size = 0, int element = 0) : 
    _capacity(size), _size(size), _data(new int[size]){
        for(int i = 0; i < size; i++){
            this -> _data[i] = element;
        }
    }
    ~vector(){
        delete [] _data;
    }

    int size(){return this-> _size;}
    int capacity(){return this-> _capacity;}
    int& operator[](int index){return this-> _data[index];}
    int& front(){return this-> _data[0];}
    int& back(){return this-> _data[this-> _size - 1];}
    
    void reserve(int newCapacity){
        int *_new_data = new int[newCapacity];
        int qtd = std::min(_size, newCapacity);
        for(int i = 0; i < qtd; i++)
            _new_data[i] = _data[i];
        _size = qtd;
        _capacity = newCapacity;
        delete [] _data; //devolve o bloco de memoria antigo
        _data = _new_data; //atualiza o bloco de memoria
    }

    void push_back(int element){
        if(_size == _capacity){
            if(_capacity == 0)
                this->reserve(1);
            else
                this->reserve(2 * _capacity);
        }
        _data[_size] = element;
        _size += 1;
    }

    void pop_back(){
        if(_size == 0)
            return;
        _size--;
    }

    int * begin(){
        return _data;
    }

    int * end(){
        return &_data[_size];
    }

    void insert (int * it, int value){
        int pos = it -_data;
        if(_size == _capacity){
            this -> reserve(2 * _capacity);
        }for (int i = _size; i > pos; i --){
            _data[i] = _data[i - 1];
        }_data[pos] = value;
        _size++;
        _data[pos] = value;
    }
};


int main(){
    vector vetor(5, 1);

    for(int i = 0; i < vetor.size();i++){
        std::cout << vetor[i] << ' ';
    }
    std::cout << std::endl;
}