#pragma once

#include <iostream>
#include <string>
const int INITIAL_CAPACITY = 1;
template<class T>
class Vector {
public:
    class Iterator {
        int current_index;
        Vector<T>* container;
    public:
        Iterator(Vector<T>* vec, int index = 0) : current_index(index), container(vec) {}

        T& operator*() {
            return container->operator[](current_index);
        }

        Iterator& operator++() {
            current_index++;
            return *this;
        }

        bool operator==(const Iterator& other) const {
            return current_index == other.current_index;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }
    };

    Iterator begin() {
        return Iterator(this, 0);
    }

    Iterator end() {
        return(Iterator(this, m_size));
    }

    Vector() {
        m_capacity = INITIAL_CAPACITY;
        m_size = 0;
        m_data = new T[m_capacity];
    }

    ~Vector() {
        clear();
        delete [] m_data;
    }
    void grow() {
        size_t newSize = m_capacity*2;
        T * newArray = new T[newSize];
        for (size_t i = 0; i < m_size; i++) {
            newArray[i] = m_data[i];
        }
        delete m_data;
        m_data = newArray;
        m_capacity = newSize;
    }

    void push_back(T item) {
        if (m_size == m_capacity) {
            grow();
        }
        m_data[m_size++] = item;
    }

    void pop_back() {
        m_size--;
    }


    void insert(T item, int position) {
        if (position < 0 || position >m_size) {
            throw std::out_of_range("Index is out of range");
        }
        if (m_size == m_capacity) {
//            std::cout << "made it here" << std::endl;
            grow();
        }
        if (position == m_size) {
//            std::cout << "made it there" << std::endl;
            push_back(item);
        }
        else {
//            std::cout << "made it everywhere" << std::endl;
            T temp1 = m_data[position];
            m_data[position] = item;
            position++;

            while (position < m_size) {
//                std::cout << position << "< " << m_size << ", " << m_data[position] << std::endl;
                T temp2 = m_data[position];
                m_data[position] = temp1;
                temp1 = temp2;
                position++;
            }
            m_data[position] = temp1;
            m_size++;
        }
//        std::cout << "why am I here??" << std::endl;

    }

    void remove(int position) {
        if (position < 0 || position > m_size) {
            throw std::out_of_range("Index is out of range");
        }
        if (m_size > 0) {
            m_size--;
            while (position < m_size) {
                m_data[position] = m_data[position+1];
                position++;
            }
        }



    }

    T& operator[](int index) {
        if (index < 0 || index > m_size) {
            throw std::out_of_range("Index is out of range");
        }
        return m_data[index];
    }

    int size() const {
        return m_size;
    }

    void clear() {
        m_size = 0;
    }


private:
    T * m_data;
    size_t m_capacity;
    size_t m_size;
};
