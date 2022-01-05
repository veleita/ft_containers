#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft
{
    /* Iterator base class:
	**	https://www.cplusplus.com/reference/iterator/iterator/ */
    template <
        class Category, class T, class Distance = ptrdiff_t, class Pointer = T *,
        class Reference = T &>
    struct iterator
    {
        typedef T value_type;
        typedef Distance difference_type;
        typedef Pointer pointer;
        typedef Reference reference;
        typedef Category iterator_category;
    };
};

#endif