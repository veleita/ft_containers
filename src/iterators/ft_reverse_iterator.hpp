#ifndef FT_REVERSE_ITERATOR_HPP
# define FT_REVERSE_ITERATOR_HPP


namespace ft
{
    /* Predefined iterator
	 * Reverses the direction in which a random-access iterator iterates through a range
	 * https://www.cplusplus.com/reference/iterator/reverse_iterator/reverse_iterator/ */
    template <class Iterator>
    class reverse_iterator
    {
    public:
        typedef Iterator iterator_type;
        typedef typename NAMESPACE::iterator_traits<Iterator>::iterator_category iterator_category;
        typedef typename NAMESPACE::iterator_traits<Iterator>::value_type value_type;
        typedef typename NAMESPACE::iterator_traits<Iterator>::difference_type difference_type;
        typedef typename NAMESPACE::iterator_traits<Iterator>::pointer pointer;
        typedef typename NAMESPACE::iterator_traits<Iterator>::reference reference;

        reverse_iterator() : _baseIterator() {}
        explicit reverse_iterator(iterator_type it) : _baseIterator(it) {}
        template <class Iter>
        reverse_iterator(const reverse_iterator<Iter> &rev_it) : _baseIterator(rev_it.base()) {}

        iterator_type base() const { return (_baseIterator); }

        reference operator*() const
        {
            iterator_type prev = _baseIterator - 1;
            return (*prev);
        }
        reverse_iterator operator+(difference_type n) const { return (reverse_iterator(_baseIterator - n)); }
        reverse_iterator operator-(difference_type n) const { return (reverse_iterator(_baseIterator + n)); }
        reverse_iterator operator+=(difference_type n) const
        {
            _baseIterator -= n;
            return (*this);
        }
        reverse_iterator operator-=(difference_type n) const
        {
            _baseIterator += n;
            return (*this);
        }
        reverse_iterator &operator++() const
        {
            _baseIterator++;
            return (*this);
        }
        reverse_iterator &operator++(int) const
        {
            reverse_iterator temp = *this;
            _baseIterator++;
            return temp;
        }
        reverse_iterator &operator--() const
        {
            return --(*this);
        }
        reverse_iterator &operator--(int) const
        {
            reverse_iterator temp = *this;
            _baseIterator--;
            return temp;
        }
        pointer operator->() const { return &(operator*()); }
        reference operator[](difference_type n) const { return (this->base()[-n]); };

    private:
        iterator_type _baseIterator;
    };
};

#endif
