/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <1veleita1@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 07:26:38 by mzomeno-          #+#    #+#             */
/*   Updated: 2022/02/09 10:32:34 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    std::cout << "Vector content: ";
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
	std::cout << std::endl;
    {
        std::cout << "Pointer:\n";
        NAMESPACE::vector<int> *pointer_default_vector = new NAMESPACE::vector<int>;
        print_attributes(*pointer_default_vector);
        print_content(*pointer_default_vector);
        delete pointer_default_vector;
    }
	std::cout << std::endl;
    {
        std::cout << "Empty fill:\n";
        NAMESPACE::vector<int> fill_vector(0);
        print_attributes(fill_vector);
        print_content(fill_vector);
    }
	std::cout << std::endl;
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

        NAMESPACE::vector<int> vct(10);
		for (unsigned int i = 0; i < vct.size(); i++)
			vct[i] = rand() % 10;
        print_attributes(vct);
        print_content(vct);
    }
    std::cout << std::endl;
    {
        std::cout << "Copy:\n";
        NAMESPACE::vector<int> vct(10);
		for (unsigned int i = 0; i < vct.size(); i++)
			vct[i] = rand() % 10;
        NAMESPACE::vector<int> copy_vector(vct);
        print_attributes(copy_vector);
        print_content(copy_vector);
    }
    std::cout << std::endl;
    {
        std::cout << "Assign:\n";
        NAMESPACE::vector<int> vct(10);
		for (unsigned int i = 0; i < vct.size(); i++)
			vct[i] = rand() % 10;
        NAMESPACE::vector<int> assign_vector = vct;
        print_attributes(assign_vector);
        print_content(assign_vector);
    }
}

void test_v_iterators()
{
    std::cout << "ITERATORS\n";
    {
        std::cout << "begin(), end():\n";
        NAMESPACE::vector<int> vct(10);
		for (unsigned int i = 0; i < vct.size(); i++)
			vct[i] = rand() % 10;

        int begin = *(vct.begin());
        NAMESPACE::vector<int>::iterator c_it = vct.begin();
        const int c_begin = *(c_it);
        print_content(vct);
        std::cout << "Iterator: " << begin << " | Const iterator: " << c_begin << std::endl;

        int end = *(vct.end() - 1);
        c_it = vct.end() - 1;
        const int c_end = *(c_it);
        print_content(vct);
        std::cout << "Iterator: " << end << " | Const iterator: " << c_end << std::endl << std::endl;
    }

    {
        std::cout << "rbegin(), rend():\n";
        NAMESPACE::vector<int> vct(10);
		for (unsigned int i = 0; i < vct.size(); i++)
			vct[i] = rand() % 10;
        
		int rbegin = *(vct.rbegin());
        const int c_rbegin = *(vct.rbegin());
        print_content(vct);
        std::cout << "Iterator: " << rbegin << " | Const iterator: " << c_rbegin << std::endl;

        int rend = *(vct.rend() - 1);
        const int c_rend = *(vct.rend() - 1);
        print_content(vct);
        std::cout << "Iterator: " << rend << " | Const iterator: " << c_rend << std::endl;
    }
}

void test_v_access()
{
    std::cout << "ACCESS\n";
    {
        std::cout << "[] operator:\n";
        NAMESPACE::vector<int> vct(10);
		for (unsigned int i = 0; i < vct.size(); i++)
			vct[i] = rand() % 10;

        int element = vct[1];
        const int c_element = vct[1];
        std::cout << element << " " << c_element << std::endl << std::endl;;
	}
    {
        std::cout << "at():\n";
        NAMESPACE::vector<int> vct(10);
		for (unsigned int i = 0; i < vct.size(); i++)
			vct[i] = rand() % 10;

        int element = vct.at(3);
        const int c_element = vct.at(4);
        std::cout << element << " " << c_element << std::endl << std::endl;;
    }
    {
        std::cout << "front():\n";
        NAMESPACE::vector<int> vct(10);
		for (unsigned int i = 0; i < vct.size(); i++)
			vct[i] = rand() % 10;

        int element = vct.front();
        const int c_element = vct.front();
        std::cout << element << " " << c_element << std::endl << std::endl;;
    }
    {
        std::cout << "back():\n";
        NAMESPACE::vector<int> vct(10);
		for (unsigned int i = 0; i < vct.size(); i++)
			vct[i] = rand() % 10;

        int element = vct.back();
        const int c_element = vct.back();
        std::cout << element << " " << c_element << std::endl << std::endl;;
    }
    {
        std::cout << "data():\n";
        NAMESPACE::vector<int> vct(10);
		for (unsigned int i = 0; i < vct.size(); i++)
			vct[i] = rand() % 10;

		std::cout << *(vct.data()) << " " 
			<< *(vct.data() + vct.size() - 1) << std::endl;
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
    }
}

void test_v_modifiers()
{
    std::cout << "MODIFIERS\n";
    {
        std::cout << "clear:\n";
        NAMESPACE::vector<int> vct(10);
		for (unsigned int i = 0; i < vct.size(); i++)
			vct[i] = rand() % 10;
        print_attributes(vct);
        print_content(vct);
		vct.clear();
        print_attributes(vct);
        print_content(vct);
        std::cout << std::endl;
	}
    {
        std::cout << "insert:\n";
        NAMESPACE::vector<int> vct(10);
		for (unsigned int i = 0; i < vct.size(); i++)
			vct[i] = rand() % 10;

		vct.insert(vct.begin() + 2, 42);
        print_attributes(vct);
        print_content(vct);

		vct.insert(vct.begin() + 2, 24, 666);
        print_attributes(vct);
        print_content(vct);

		vct.insert(vct.end(), vct.begin(), vct.begin() + 5);
        print_attributes(vct);
        print_content(vct);

        std::cout << std::endl;
	}
    {
        std::cout << "erase:\n";
        NAMESPACE::vector<int> vct(10);
		for (unsigned int i = 0; i < vct.size(); i++)
			vct[i] = rand() % 10;

		vct.erase(vct.begin() + 2);
        print_attributes(vct);
        print_content(vct);

		vct.erase(vct.begin() + 1, vct.end() - 2);
        print_attributes(vct);
        print_content(vct);

        std::cout << std::endl;
	}
	{
        std::cout << "push_back:\n";
		NAMESPACE::vector<int> empty_v;
		empty_v.push_back(435);
        print_attributes(empty_v);
        print_content(empty_v);
		
		NAMESPACE::vector<int> base_v(72);
		base_v.push_back(5);
        print_attributes(base_v);
        print_content(base_v);

        std::cout << std::endl;
	}
	{
        std::cout << "pop_back:\n";
        NAMESPACE::vector<int> vct(10);
		for (unsigned int i = 0; i < vct.size(); i++)
			vct[i] = rand() % 10;
		vct.pop_back();
		vct.pop_back();
        print_attributes(vct);
        print_content(vct);

        std::cout << std::endl;
	}
	{
        std::cout << "resize:\n";
        NAMESPACE::vector<int> vct(10);
		for (unsigned int i = 0; i < vct.size(); i++)
			vct[i] = rand() % 10;

		vct.resize(10);
        print_attributes(vct);
        print_content(vct);

		vct.resize(3);
        print_attributes(vct);
        print_content(vct);

        std::cout << std::endl;
	}
	{
        std::cout << "assign:\n";
        NAMESPACE::vector<int> base_v(10);
		for (unsigned int i = 0; i < base_v.size(); i++)
			base_v[i] = rand() % 10;
		NAMESPACE::vector<int>::iterator it = base_v.begin();

		base_v.assign(it, it + 5);
        print_attributes(base_v);
        print_content(base_v);

		base_v.assign(it + 1, it + 9);
        print_attributes(base_v);
        print_content(base_v);

		base_v.assign(3, 42);
        print_attributes(base_v);
        print_content(base_v);

        std::cout << std::endl;
	}
	{
        std::cout << "swap:\n";
        NAMESPACE::vector<int> v_one(10);
		for (unsigned int i = 0; i < v_one.size(); i++)
			v_one[i] = rand() % 10;
        print_attributes(v_one);
        print_content(v_one);
        NAMESPACE::vector<int> v_two(10);
		for (unsigned int i = 0; i < v_two.size(); i++)
			v_two[i] = rand() % 10;
        print_attributes(v_two);
        print_content(v_two);
		v_one.swap(v_two);
        print_attributes(v_one);
        print_content(v_one);
        print_attributes(v_two);
        print_content(v_two);
	}
}

void test_v_operators()
{
        NAMESPACE::vector<int> v_one(10);
        NAMESPACE::vector<int> v_two(10);
		std::cout << (v_one == v_two) << std::endl;
		std::cout << (v_one != v_two) << std::endl;
		v_one.push_back(42);
		std::cout << (v_one < v_two) << std::endl;
		std::cout << (v_one <= v_two) << std::endl;
		v_two.push_back(21);
		std::cout << (v_one > v_two) << std::endl;
		std::cout << (v_one >= v_two) << std::endl;
}
