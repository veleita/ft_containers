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
    std::cout << "CONSTRUCTORS\n";
    {
        std::cout << "Default:\n";
        NAMESPACE::vector<int> default_vector;
        print_attributes(default_vector);
        print_content(default_vector);
    }

    {
        std::cout << "Pointer:\n";
        NAMESPACE::vector<int> *pointer_default_vector = new NAMESPACE::vector<int>;
        print_attributes(*pointer_default_vector);
        print_content(*pointer_default_vector);
        delete pointer_default_vector;
    }

    {
        std::cout << "Empty fill:\n";
        NAMESPACE::vector<int> fill_vector(0);
        print_attributes(fill_vector);
        print_content(fill_vector);
    }

    {
        std::cout << "Sized fill:\n";
        NAMESPACE::vector<int> fill_vector_sized(19);
        print_attributes(fill_vector_sized);
        print_content(fill_vector_sized);
    }
    std::cout << std::endl;
    {
        std::cout << "Valued fill:\n";
        NAMESPACE::vector<int> fill_vector_valued(19, 42);
        print_attributes(fill_vector_valued);
        print_content(fill_vector_valued);
    }
    std::cout << std::endl;
    {
        std::cout << "Range:\n";
        int range_array[] = {45, 87846, 12, 965, 5};

        NAMESPACE::vector<int>::iterator it(&(range_array[0]));
        NAMESPACE::vector<int> range_vector(it, it + 5);
        print_attributes(range_vector);
        print_content(range_vector);
    }
    std::cout << std::endl;
    {
        std::cout << "Copy:\n";
        int range_array[] = {-89, 561, 874, 7777, 987, -6};
        NAMESPACE::vector<int>::iterator it(&(range_array[0]));
        NAMESPACE::vector<int> range_vector(it, it + 6);
        NAMESPACE::vector<int> copy_vector(range_vector);
        print_attributes(copy_vector);
        print_content(copy_vector);
    }
    std::cout << std::endl;
    {
        std::cout << "Assign:\n";
        int range_array[] = {54, 98, -3250, 0, 54, -3};
        NAMESPACE::vector<int>::iterator it(&(range_array[0]));
        NAMESPACE::vector<int> range_vector(it, it + 6);
        NAMESPACE::vector<int> assign_vector = range_vector;
        print_attributes(assign_vector);
        print_content(assign_vector);
    }
}

void test_v_iterators()
{
    std::cout << "ITERATORS\n";
    {
        std::cout << "begin(), end():\n";
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
        std::cout << end << " " << c_end << std::endl << std::endl;
    }

    {
        std::cout << "rbegin(), rend():\n";
        int range_array[] = {54, 98, -3250, 0, 54, -3};
        NAMESPACE::vector<int>::iterator it(&(range_array[0]));
        NAMESPACE::vector<int> range_vector(it, it + 6);
        int rbegin = *(range_vector.rbegin());
        const int c_rbegin = *(range_vector.rbegin());
        std::cout << rbegin << " " << c_rbegin << std::endl;

        int rend = *(range_vector.rend() - 1);
        const int c_rend = *(range_vector.rend());
        std::cout << rend << " " << c_rend << std::endl;
    }
}

void test_v_capacity()
{
    std::cout << "CAPACITY\n";
    {
        std::cout << "size:\n";
        NAMESPACE::vector<int> v_small(20);
        print_attributes(v_small);
        print_content(v_small);
        std::cout << std::endl;

        NAMESPACE::vector<int> v_big(100000);
        print_attributes(v_big);
        std::cout << std::endl;
    }
   
    {
        std::cout << "resize:\n";
        NAMESPACE::vector<int> v_extension(40);
        v_extension.resize(85);
        print_attributes(v_extension);
        std::cout << std::endl;
   
        NAMESPACE::vector<int> v_reduction(40);
        v_reduction.resize(5);
        print_attributes(v_reduction);
        print_content(v_reduction);
        std::cout << std::endl;
        
        NAMESPACE::vector<int> v_to_empty(4);
        v_to_empty.resize(0);
        print_attributes(v_to_empty);
        print_content(v_to_empty);
        std::cout << std::endl;
    }

    {
        std::cout << "capacity:\n";
        NAMESPACE::vector<int> v_capacity_short(40);
        v_capacity_short.push_back(42);
        v_capacity_short.push_back(42);
        print_attributes(v_capacity_short);
        print_content(v_capacity_short);
        std::cout << std::endl;
   
        NAMESPACE::vector<int> v_capacity_big(40000);
        v_capacity_big.push_back(42);
        v_capacity_big.push_back(42);
        print_attributes(v_capacity_big);
        std::cout << std::endl;
    }
    
    {
        std::cout << "reserve:\n";
        NAMESPACE::vector<int> v_base;
        v_base.reserve(100);
        v_base.push_back(42);
        print_attributes(v_base);
        print_content(v_base);
        std::cout << std::endl;
    }
}
