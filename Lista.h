
#ifndef SDA_ECEDI_ALEXANDRU_312_LISTA_H
#define SDA_ECEDI_ALEXANDRU_312_LISTA_H

#include <vector>
using namespace std;

template<class T>
class Lista {
private:
    vector<T> data;

public:
    T &operator[](int index) {
        return this->data[index];
    }

    const T &operator[](int index) const {
        return this->data[index];
    }

    int getDim() const {
        return this->data.size();
    }

    void adauga(const T &value) {
        this->data.push_back(value);
    }

    void sterge(int index) {
        this->data.erase(this->data.begin() + index);
    }
};

#endif