class linked_list {
    private:
        struct node {
            int value;
            node *next;  
        };

        node *head, *tail;
        unsigned int size_;

    public:
        linked_list() {
            this->head = nullptr;
            this->tail = nullptr;
            this->size_ = 0;
        }

        ~linked_list() {
            while (this->head != nullptr) {
                this->pop_front();
            }
        }

        unsigned int get_size() {return this->size_;}

        void push_back(int value) {
            node *new_node = new node;
            new_node->value = value;
            new_node->next = nullptr;

            if (this->head == nullptr) {
                this->head = new_node;
            } else {
                this->tail->next = new_node;
            }
            this->tail = new_node;
            this->size_++;
        }

        void push_front(int value) {
            node *new_node = new node;
            new_node->value = value;
            
            if (this->tail == nullptr) {
                this->tail = new_node;
            }
            
            new_node->next = this->head;
            this->head = new_node;
            this->size_++;
        }

        void pop_front() {
            if (this->head == nullptr) {return;}

            node *to_remove = this->head;
            this->head = this->head->next;

            if (this->head == nullptr) {
                this->tail = nullptr;
            }

            delete to_remove;
            this->size_--;
        }

        void pop_back() {
            if (this->tail == nullptr) {return;}

            if (this->tail == this->head) {
                delete this->tail;
                this->head = nullptr;
                this->tail = nullptr;
                this->size_--;
                return;
            }

            node *current_node = this->head;
            while (current_node->next != this->tail) {
                current_node = current_node->next;
            }

            current_node->next = nullptr;
            node *to_remove = this->tail;
            this->tail = current_node;
            delete to_remove;
            this->size_--;
        }

        bool remove(int value) {
            if (this->size_ == 0) { return false; }

            if (this->head->value == value) {
                this->pop_front();
                return true;
            }

            node *current_node = this->head;
            
            while (current_node->next != nullptr && current_node->next->value != value) {
                current_node = current_node->next;
            }

            if (current_node->next == nullptr) {
                return false;
            }

            node *to_remove = current_node->next;

            if (to_remove == this->tail) {
                this->tail = current_node;
                this->tail->next = nullptr;
            } else {
                current_node->next = to_remove->next;
            }

            delete to_remove;
            this->size_--;
            return true;
        }

        bool remove_at(unsigned int index) {
            if (this->size_ == 0 || index >= this->size_) { return false; }

            if (index == 0) {
                this->pop_front();
                return true;
            }

            node *current_node = this->head;
            unsigned int count = 0;

            while (count != index - 1) {
                current_node = current_node->next;
                count++;
            }

            node *to_remove = current_node->next;

            if (to_remove == this->tail) {
                this->tail = current_node;
                this->tail->next = nullptr;
            } else {
                current_node->next = to_remove->next;
            }

            delete to_remove;
            this->size_--;
            return true;
        }
};