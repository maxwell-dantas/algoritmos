#include <iostream>

struct ll_int_node {
    int value;
    ll_int_node *next;
};

struct linked_list {
    private:
        ll_int_node *first_, *last_;
        unsigned int size_;

    public:
        linked_list() {
            this->first_ = nullptr;
            this->last_ = nullptr;
            this->size_ = 0;
        }

        ~linked_list() {
            while (this->first_ != nullptr) {
                this->pop_front();
            }
        }

        unsigned int get_size() {return this->size_;}

        void push_back(int value) {
            ll_int_node *new_node = new ll_int_node;
            if (new_node == nullptr) {return;}

            new_node->value = value;
            new_node->next = nullptr;

            if (this->last_ == nullptr) {
                this->first_ = new_node;
                this->last_ = new_node;
                this->size_++;
                return;
            }

            this->last_->next = new_node; // o último atual aponta para o novo último
            this->last_ = new_node; // o último atual passa a ser o novo último
            this->size_++;
        }

        void push_front(int value) {
            ll_int_node *new_node = new ll_int_node;
            if (new_node == nullptr) {return;}

            new_node->value = value;
            new_node->next = nullptr;

            if (this->first_ == nullptr) {
                this->first_ = new_node;
                this->last_ = new_node;
                this->size_++;
                return;
            }

            new_node->next = this->first_; // o novo primeiro aponta para o primeiro anterior
            this->first_ = new_node; // o primeimro atual aponta para o novo primeiro
            this->size_++;
        }

        void pop_back() {
            if (this->size_ == 0) {return;}

            if (this->first_ == this->last_) {
                delete this->first_;
                this->first_ = nullptr;
                this->last_ = nullptr;
                this->size_--;
                return;
            }

            ll_int_node *current_node = this->first_;

            while (current_node->next != this->last_) {
                current_node = current_node->next;
            }

            ll_int_node *to_remove = this->last_;

            this->last_ = current_node;
            this->last_->next = nullptr;
            delete to_remove;
            this->size_--;
        }

        void pop_front() {
            if (this->size_ == 0) {return;}

            ll_int_node *to_remove = this->first_;
            
            if (this->last_ == this->first_) {
                this->last_ = nullptr;
            }

            this->first_ = this->first_->next;

            delete to_remove;
            this->size_--;
        }

        int get_at(unsigned int index) {
            if (index >= this->size_) {return -1;}

            unsigned int count = 0;
            ll_int_node *current_node = this->first_;

            while (current_node != this->last_) {
                if (index == count) {
                    return current_node->value;
                }
                current_node = current_node->next;
                count++;
            }
            return current_node->value;
        }

        void print() {
            ll_int_node *current_node = this->first_;

            while (current_node != nullptr) {
                std::cout << "value: " << current_node->value << " | address: " << current_node << std::endl;
                current_node = current_node->next;
            }
        }
};

int main() {
    linked_list *ll = new linked_list;
    
    for (unsigned int i = 0; i < 10; i++) {
        ll->push_back((i+1)*10);
    }

    ll->print();

    delete ll;

    return 0;
}