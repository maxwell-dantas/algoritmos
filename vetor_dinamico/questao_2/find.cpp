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

    int find(int value) {
        for (unsigned i = 0; i < this->size_; i++) {
            if (this->data[i] == value) {
                return i;
            }
        }
        return -1;
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