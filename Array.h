
#ifndef SDA_ECEDI_ALEXANDRU_312_ARRAY_H
#define SDA_ECEDI_ALEXANDRU_312_ARRAY_H

using namespace std;

template<class T>
class TAD_ARRAY {
private:
    T *elems; //data membru
    int capacitate; //data membru
    int noElems; //data membru

    ///Modifica capacitatea array-ului elems daca este plin
    void resize() {
        T *newElems = new T[capacitate * 2];
        for (int i = 0; i < noElems; i++) {
            newElems[i] = elems[i];

        }
        capacitate *= 2;
        delete[] elems;
        elems = newElems;
    }

public:
    ///Constructorul initialieaza datele membru
    TAD_ARRAY() {
        capacitate = 5;
        noElems = 0;
        elems = new T[capacitate];
    }

    TAD_ARRAY(const TAD_ARRAY<T> &t) {
        capacitate = t.capacitate;
        noElems = t.noElems;
        for (int i = 0; i < t.capacitate; i++) {
            elems[i] = t.elems[i];
        }
    }

    ///Adauga un element la array
    /// \param t - elementul de adaugat
    ///         prec  - t este un element de tip User
    void addElem(T u) {
        if (noElems == capacitate)
            resize();
        elems[noElems++] = u;
    }

    ///Sterge elementul u din array
    ///\param e - elementul pe care vrem sa-l stergem
    void deleteElem(T u) {
        T *newElems = new T[capacitate];
        int noNewElems = 0;
        for (int i = 0; i < noElems; i++) {
            if (!(elems[i] == u)) {
                newElems[noNewElems++] = elems[i];
            }
        }
        delete[]elems;
        elems = newElems;
        noElems = noNewElems;
    }

    void updateElem(T v, T n) {
        T *newElems = new T[capacitate];
        int noNewElems = 0;
        for (int i = 0; i < noElems; i++) {
            if (!(elems[i] == v)) {
                newElems[noNewElems++] = elems[i];
            } else {
                newElems[noNewElems++] = n;
            }
        }
        delete[]elems;
        elems = newElems;

    }

    bool ifExist(T u) {
        int i = 0;
        while (i < noElems) {
            if (elems[i] == u)
                return true;
            i++;
        }
        return false;
    }

    ///\return elementul de pe pozitia data
    T getAt(int pozitie) {
        if (pozitie >= 0 && pozitie < noElems)
            return elems[pozitie];
    }

    ///\returneaza toate elementele
    T *getAll() {
        return elems;
    }

    ///\returneaza capacitatea array-ului users
    int getCapacitate() {
        return capacitate;
    }

    ///\returneaza numarul de elemente inregistrate
    int getNoElems() {
        return noElems;
    }

    ~TAD_ARRAY() {
        ;
    }
};


#endif //SDA_ECEDI_ALEXANDRU_312_ARRAY_H
