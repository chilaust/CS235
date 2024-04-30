#pragma once
#include <list>
#include <functional>

using namespace std;

const size_t INITIAL_CAPACITY = 7;
const double MAX_FILL = 0.8;

template<class T>
class HashSet {
public:
    HashSet() {
        m_size = 0;
        m_capacity = INITIAL_CAPACITY;
        m_data = new list<T>[INITIAL_CAPACITY];

    }

    ~HashSet() {
        clear();
        delete m_data;
    }

    bool insert(T item) {
        if (fillFactor() >= MAX_FILL) {
            grow();
        }

        size_t hashCode = hash<T>{}(item);
        size_t index = hashCode % m_capacity;

        if (m_data[index].size() != 0) {
            for(auto entry : m_data[index]) {
                if (entry == item) {
                    return false; // Return false if the item already exists
                }
            }
        }

        m_data[index].push_front(item);
        m_size++;
        return true;
    }

    bool remove(T item) {
        size_t hashCode = hash<T>{}(item);
        size_t index = hashCode % m_capacity;

        if (m_data[index].size() != 0) {
            for (auto it = m_data[index].begin(); it != m_data[index].end(); it++) {
                if (*it == item) {
                    m_data[index].erase(it);
                    m_size--;
                    return true;
                }
            }

        }
        return false;

        // implement remove here
        // return true if item was removed, false if item wasn't in the set
    }

    bool contains(T item) const {
        size_t hashCode = hash<T>{}(item);
        size_t index = hashCode % m_capacity;

        if (m_data[index].size() != 0) {
            for (auto entry: m_data[index]) {
                if (entry == item) {
                    return true;
                }
            }
        }
        return false;
    }

    void clear() {

        for (size_t i = 0; i < m_capacity; i++) {
            m_data[i].clear();
        }
        m_size = 0;
    }

    int size() const {
        return m_size;
        // implement size here
        // return the number of elements in the set
    }


private:
    size_t m_size;
    size_t m_capacity;
    list<T>* m_data;


    double fillFactor() {
        return static_cast<double>(m_size)/m_capacity;
    }

    void grow() {

        size_t oldCapacity = m_capacity;
        m_capacity = 2 * m_capacity + 1;
        list<T>* oldData = m_data;
        m_data = new list<T>[m_capacity];
        m_size = 0;

        for (size_t i = 0; i < oldCapacity; i++) {
            for (auto item: oldData[i]) {
                insert(item);
            }
            oldData[i].clear();
        }
        delete [] oldData;
    }

};
