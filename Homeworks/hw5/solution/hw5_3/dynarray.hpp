#ifndef DYNARRAY_HPP
#define DYNARRAY_HPP 1

#include <cstddef>
#include <stdexcept>

class Dynarray {
    private:
        int* m_storage;
        std::size_t m_length;
    public:
        Dynarray(): m_storage(new int[0]{}), m_length(0){}
        explicit Dynarray(std::size_t n): m_storage(new int[n]{}), m_length(n){
            for (std::size_t i = 0; i < n; i++){
                m_storage[i] = 0;
            }
        }
        Dynarray(std::size_t n, int x): m_storage(new int[n]{}), m_length(n){
            for (std::size_t i = 0; i < n; i++) {
                m_storage[i] = x;
            }
        }
        Dynarray(const int* begin, const int* end): m_storage(new int[end - begin]{}), m_length(end - begin){
            if (end - begin < 0) {
                throw std::out_of_range{"Dynarray index out of range!"};
            }
            for (std::size_t i = 0; i < m_length; i++) {
                m_storage[i] = *(begin + i);
            }
        }

        Dynarray(const Dynarray& other) : Dynarray(other.m_storage, other.m_storage + other.m_length) {}
        Dynarray& operator = (const Dynarray& other) {
            int* new_data = new int[other.size()];
            for (std::size_t i = 0; i != other.size(); ++i){
                new_data[i] = other.at(i);
            }
            delete[] m_storage;
            m_storage = new_data;
            m_length = other.size();
            return *this;
        }

        ~Dynarray() {delete[] m_storage;}

        std::size_t size() const {
            return m_length;
        }

        bool empty() const {
            return m_length == 0;
        }

        int &at(std::size_t i) {
            if (i >= m_length) {
                throw std::out_of_range{"Dynarray index out of range!"};
            }
            return m_storage[i];
        }

        const int &at(std::size_t i) const {
            if (i >= m_length) {
                throw std::out_of_range{"Dynarray index out of range!"};
            }
            return m_storage[i];
        }
};

#endif // DYNARRAY_HPP