#include "test_vector.hpp"

template <class T>
void print_attributes(NAMESPACE::vector<T> &vct)
{
    std::cout << "Empty vector: " << vct.empty() << std::endl;
    std::cout << "Vector size: " << vct.size() << std::endl;
    std::cout << "Vector max size: " << vct.max_size() << std::endl;
    std::cout << "Vector capacity: " << vct.capacity() << std::endl;
}

template <class T>
void print_content(NAMESPACE::vector<T> &vct)
{
    typename NAMESPACE::vector<T>::const_iterator it;
    std::cout << "Vector content:\n";
    for (it = vct.begin(); it < vct.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void test_v_constructors()
{
    /*    NAMESPACE::vector<int> default_vector;
    print_attributes(default_vector);
    print_content(default_vector);

    NAMESPACE::vector<int> *pointer_default_vector = new NAMESPACE::vector<int>;
    print_attributes(*pointer_default_vector);
    print_content(*pointer_default_vector);
    delete pointer_default_vector;
*/
    NAMESPACE::vector<int> fill_vector(0);
    print_attributes(fill_vector);
    print_content(fill_vector);
}