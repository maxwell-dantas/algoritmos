#include <chrono>
#include <iostream>
#include <stdexcept>
class vector
{
private:
    int *data;
    unsigned int size_, capacity_;
    void increase_capacity()
    {
        this->capacity_ *= 2;
        int *new_data = new int[this->capacity_];
        for (int i = 0; i < this->size_; ++i)
            new_data[i] = data[i];
        delete[] this->data;
        this->data = new_data;
    }

public:
    vector()
    {
        this->size_ = 0;
        this->capacity_ = 100;
        this->data = new int[100];
    }
    void push_back(int value)
    {
        if (this->size() == this->capacity())
            increase_capacity();
        this->data[this->size_++] = value;
    }

    int get_at(int index)
    {
        if (index < 0 or index >= size())
            throw std::out_of_range("Index out of range");
        return this->data[index];
    }

    unsigned int size()
    {
        return this->size_;
    }

    unsigned int capacity()
    {
        return this->capacity_;
    }

    ~vector()
    {
        delete[] this->data;
    }
};

int main(int argc, char **argv)
{
    vector v1;
    int n;
    auto inicio = std::chrono::high_resolution_clock::now();

    std::cin >> n;
    while (n != -1)
    {
        v1.push_back(n);
        std::cin >> n;
    }

    auto fim = std::chrono::high_resolution_clock::now();
    auto duracao = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio).count();
    std::cerr << "Tempo de execução: " << duracao << "ms." << std::endl;
    std::cout << "Elementos lidos: " << v1.size() << std::endl;
    std::cout << "Capacidade atual: " << v1.capacity() << std::endl;
    return 0;
}