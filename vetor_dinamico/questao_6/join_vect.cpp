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

    void resize_capacity() { // O(n)
        this->capacity_ /= 2;
        int *new_data = new int[this->capacity_];
        for (unsigned int i = 0; i < this->size_; i++) {
            new_data[i] = this->data[i];
        }
        delete[] data;
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

    bool remove_at(int index) { // O(n)
        if (index < 0 || index >= this->size_) {
            throw std::out_of_range("Index out of range");
        }

        for (unsigned int i = index; i < this->size_ - 1; i++) {
            this->data[i] = this->data[i + 1];
        }
        this->size_--;

        if (this->size_ * 4 < this->capacity_ && this->capacity_ > 100) {
            this->resize_capacity();
        }
        return true;
    } 

    bool remove(int value) { // O(n)
        int index = this->find(value);
        if (index == -1) {return false;}
        return this->remove_at(index);
    }

    int find(int value) { // O(n)
        for (unsigned i = 0; i < this->size_; i++) {
            if (this->data[i] == value) {
                return i;
            }
        }
        return -1;
    } 

    unsigned int contar_comuns(const vector &other) {
        vector *unique = this->unique_elements();
        unsigned int count = 0;

        for (unsigned int i = 0; i < unique->size_; i++) {
            int num_vect = unique->data[i];
            for (unsigned int j = 0; j < other.size_; j++) {
                if (num_vect == other.data[j]) {
                    count++;
                    break;
                }
            }
        }
        delete unique;
        return count;
    }

    vector *unique_elements() {
        vector *vector_unique = new vector;

        for (unsigned int i = 0; i < this->size_; i++) {
            bool validate = true;

            for (unsigned int j = i + 1; j < this->size_; j++) {
                if (this->data[i] == this->data[j]) {
                    validate = false;
                    break;
                }
            }

            if (validate) {
                vector_unique->push_back(this->data[i]);
            }
        }

        return vector_unique;
    }

    void push_back_vector(const vector &other) {
        for (unsigned int i = 0; i < other.size_; i++) {
            this->push_back(other.data[i]);
        }
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