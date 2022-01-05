#include "test_vector.hpp"

template <class T>
void print_attributes(NAMESPACE::vector<T> &vct)
{
    std::cout << "Empty vector: " << vct.empty() << std::endl;
    std::cout << "Vector size: " << vct.size() << std::endl;
    std::cout << "Vector max size: " << vct.max_size() << std::endl;
    std::cout << "Vector capacity: " << vct.capacity() << std::endl;
}

void test_v_constructors()
{
    NAMESPACE::vector<int> default_vector;
    print_attributes(default_vector);
}