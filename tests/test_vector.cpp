#include "test_vector.hpp"

/* CONSTRUCTORS */

void test_v_constructors()
{

    NAMESPACE::vector<int> first; // empty vector of ints
    std::cout << "Default constructor called\n";

    std::cout << "The contents are:";
    for (NAMESPACE::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    NAMESPACE::vector<int> second(4, 100); // four ints with value 100
    std::cout << "Fill constructor called\n";

    NAMESPACE::vector<int> third(second.begin(), second.end()); // iterating through second
    std::cout << "Range constructor from vector called\n";

    NAMESPACE::vector<int> fourth(third); // a copy of third
    std::cout << "Copy constructor called\n";

    std::cout << "The contents are:";
    for (NAMESPACE::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    int myints[] = {16, 2, 77, 29};
    NAMESPACE::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int)); // first, last position of the array
    std::cout << "Range constructor from array called\n";

    std::cout << "The contents are:";
    for (NAMESPACE::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}