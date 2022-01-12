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
    /*
    {
        NAMESPACE::vector<int> default_vector;
        print_attributes(default_vector);
        print_content(default_vector);
    }

    {
        NAMESPACE::vector<int> *pointer_default_vector = new NAMESPACE::vector<int>;
        print_attributes(*pointer_default_vector);
        print_content(*pointer_default_vector);
        delete pointer_default_vector;
    }

    {
        NAMESPACE::vector<int> fill_vector(0);
        print_attributes(fill_vector);
        print_content(fill_vector);
    }

    {
        NAMESPACE::vector<int> fill_vector_sized(19);
        print_attributes(fill_vector_sized);
        print_content(fill_vector_sized);
    }

    {
        NAMESPACE::vector<int> fill_vector_valued(19, 42);
        print_attributes(fill_vector_valued);
        print_content(fill_vector_valued);
    }
    */
    {
        int range_array[] = {45, 87846, 12, 965, 5};

        NAMESPACE::vector<int>::iterator it(&(range_array[0]));
        NAMESPACE::vector<int> range_vector(it, it + 5);
        print_attributes(range_vector);
        print_content(range_vector);
    }

    {
        int range_array[] = {-89, 561, 874, 7777, 987, -6};
        NAMESPACE::vector<int>::iterator it(&(range_array[0]));
        NAMESPACE::vector<int> range_vector(it, it + 6);
        NAMESPACE::vector<int> copy_vector(range_vector);
        print_attributes(copy_vector);
        print_content(copy_vector);
    }

    {
        int range_array[] = {54, 98, -3250, 0, 54, -3};
        NAMESPACE::vector<int>::iterator it(&(range_array[0]));
        NAMESPACE::vector<int> range_vector(it, it + 6);
        NAMESPACE::vector<int> assign_vector = range_vector;
        print_attributes(assign_vector);
        print_content(assign_vector);

        int begin = *(assign_vector.begin());
        NAMESPACE::vector<int>::iterator c_it = assign_vector.begin();
        const int c_begin = *(c_it);
        std::cout << begin << " " << c_begin << std::endl;

        int end = *(assign_vector.end() - 1);
        c_it = assign_vector.end() - 1;
        const int c_end = *(c_it);
        std::cout << end << " " << c_end << std::endl;
    }

    {
        int range_array[] = {54, 98, -3250, 0, 54, -3};
        NAMESPACE::vector<int>::iterator it(&(range_array[0]));
        NAMESPACE::vector<int> range_vector(it, it + 6);

        int begin = *(range_vector.begin());
        NAMESPACE::vector<int>::iterator c_it = range_vector.begin();
        const int c_begin = *(c_it);
        std::cout << begin << " " << c_begin << std::endl;

        int end = *(range_vector.end() - 1);
        c_it = range_vector.end() - 1;
        const int c_end = *(c_it);
        std::cout << end << " " << c_end << std::endl;
    }
    /* REVERSE ITERATORS NOT IMPLEMENTED
    {
        int range_array[] = {54, 98, -3250, 0, 54, -3};
        NAMESPACE::vector<int>::iterator it(&(range_array[0]));
        NAMESPACE::vector<int> range_vector(it, it + 6);
        int rbegin = *(range_vector.rbegin());
        const int c_rbegin = *(range_vector.rbegin());
        std::cout << rbegin << " " << c_rbegin << std::endl;
    }

{
            int range_array[] = {54, 98, -3250, 0, 54, -3};
        NAMESPACE::vector<int>::iterator it(&(range_array[0]));
        NAMESPACE::vector<int> range_vector(it, it + 6);
        int rbegin = *(range_vector.rbegin());
        const int c_rbegin = *(range_vector.rbegin());
        std::cout << rbegin << " " << c_rbegin << std::endl;
        }
*/
}