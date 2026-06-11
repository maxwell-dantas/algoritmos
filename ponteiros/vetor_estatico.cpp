struct vector {
    private:
        int data[1000];
        unsigned int size_, capacity_;

    public:
        vector() {
            size_ = 0;
            capacity_ = 1000;
        }

        ~vector() {}

        unsigned int size() { 
            return size_;
        }

        unsigned int capacity() {
            return capacity_;
        }

        double percent_occupied() {
            return static_cast<double>(size_) / capacity_ * 100;
        }

        bool insert_at(unsigned int index, int value) {
            if (size_ == capacity_ || index > size_) {return false;}
            for (unsigned int i = size_; i > index ; i--) {
                data[i] = data[i - 1];
            }
            data[index] = value;
            size_++;
            return true;
        }
        bool remove_at(unsigned int index) {
            if (index >= size_) {return false;}
            for (unsigned int i = index; i < size_ - 1; i++) {
                data[i] = data[i + 1];
            }
            size_--;
            return true;
        }

        int get_at(unsigned int index) {
            if (index >= size_) {
                return -1;
            }
            return data[index];
        }

        void clear() {
            size_ = 0;
        }

        void push_back(int value) {
            if (size_ == capacity_) {return;}
            data[size_] = value;
            size_++;
        }

        void push_front(int value) {
            insert_at(0, value);
        } 

        bool pop_back() {
            if (size_ == 0) {return false;}
            size_--;
            return true;
        }

        bool pop_front() {
            return remove_at(0);
        }

        int front() {
            if (size_ == 0) {return -1;}
            return data[0];
        }

        int back() {
            if (size_ == 0) {return -1;}
            return data[size_ - 1];
        }

        bool remove(int value) {
            int idx = find(value);
            if (idx != -1) {
                return remove_at(idx);
            }
            return false;
        }

        int find(int value) {
            for (unsigned int i = 0; i < size_; i++) {
                if (data[i] == value) {
                    return i;
                }
            }
            return -1; // nao encontrou
        }

        int count(int value) {
            int valueCont = 0;
            for (unsigned int i = 0; i < size_; i++) {
                if (data[i] == value) {
                    valueCont++;
                }
            }
            return valueCont;
        }

        int sum() {
            int sumVect = 0;
            for (unsigned int i = 0; i < size_; i++) {
                sumVect += data[i];
            }
            return sumVect;
        }
};