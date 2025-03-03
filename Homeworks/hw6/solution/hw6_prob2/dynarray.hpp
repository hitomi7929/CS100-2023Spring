#ifndef DYNARRAY_HPP
#define DYNARRAY_HPP

#include <cstddef>
#include <stdexcept>

class Dynarray {
    private:
        int* m_storage;
        std::size_t m_length;
    public:

        using size_type = std::size_t;
        using value_type = int;
        using pointer = int *;
        using reference = int &;
        using const_pointer = const int *;
        using const_reference = const int &;

        static const size_type npos = static_cast<size_type>(-1);

        Dynarray(): m_storage(new value_type[0]{}), m_length(0){}
        explicit Dynarray(size_type n): m_storage(new value_type[n]{}), m_length(n){
            for (size_type i = 0; i < n; i++){
                m_storage[i] = 0;
            }
        }
        Dynarray(size_type n, int x): m_storage(new value_type[n]{}), m_length(n){
            for (size_type i = 0; i < n; i++) {
                m_storage[i] = x;
            }
        }
        Dynarray(const_pointer begin, const_pointer end): m_storage(new value_type[end - begin]{}), m_length(end - begin){
            if (end - begin < 0) {
                throw std::out_of_range{"Dynarray index out of range!"};
            }
            for (size_type i = 0; i < m_length; i++) {
                m_storage[i] = *(begin + i);
            }
        }

        Dynarray(const Dynarray& other) : Dynarray(other.m_storage, other.m_storage + other.m_length) {}
        Dynarray& operator = (const Dynarray& other) {
            int* new_data = new value_type[other.size()];
            for (size_type i = 0; i != other.size(); ++i){
                new_data[i] = other.at(i);
            }
            delete[] m_storage;
            m_storage = new_data;
            m_length = other.size();
            return *this;
        }

        Dynarray(Dynarray &&other) noexcept: m_storage(other.m_storage), m_length(other.m_length) {
            other.m_storage = nullptr;
            other.m_length = 0;
        }
        Dynarray &operator = (Dynarray &&other) noexcept {
            if (this != &other) {
                delete[] m_storage;
                m_storage = other.m_storage;
                m_length = other.m_length;
                other.m_storage = nullptr;
                other.m_length = 0;
            }
            return *this;
        }

        ~Dynarray() {delete[] m_storage;}

        size_type size() const {
            return m_length;
        }

        bool empty() const {
            return m_length == 0;
        }

        reference at(size_type i) {
            if (i >= m_length) {
                throw std::out_of_range{"Dynarray index out of range!"};
            }
            return m_storage[i];
        }

        const_reference at(size_type i) const {
            if (i >= m_length) {
                throw std::out_of_range{"Dynarray index out of range!"};
            }
            return m_storage[i];
        }

        size_type find(value_type x) const {
            for (size_type i = 0; i < m_length; i++) {
                if (m_storage[i] == x) {
                    return i;
                }
            }
            return npos;
        }

        size_type find(value_type x, size_type pos) const {
            if (pos < m_length) {
                for (size_type i = pos; i < m_length; i++) {
                    if (m_storage[i] == x) {
                        return i;
                    }
                }
            }
            return npos;
        }
};

#endif // DYNARRAY_HPP