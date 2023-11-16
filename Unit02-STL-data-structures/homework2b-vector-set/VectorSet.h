#pragma once
#include <vector>
#include <algorithm>



template<class T>
class VectorSet {
private:
    std::vector<T> set;
public:
    bool contains(T item) const {
        for (const auto& obj : set) {
            if (obj == item) {
                return true;
            }
        }
        return false;

        // return true if item is in the set and false if not
    }

    bool insert(T item) {
        if (contains(item)) {
            return false;
        }
        set.push_back(item);
        return true;

        // return true if item is inserted and false if item is already in the
        // set
    }

    bool remove(T item) {
        if (contains(item)) {
            return false;
        }
        int location = std::find(set.begin(), set.end(), item);
        set.erase(location);
        // return true if item is removed and false if item wasn't in the set
    }

    int size() const {
        return set.size();

        // return the number of items in the set
    }

    bool empty() const {
        return set.empty();

        // return true if the set is empty and return false otherwise
    }

    void clear() {
        set.resize(0);

        // remove all items from the set
    }
};


