/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:48:40 by mzomeno-          #+#    #+#             */
/*   Updated: 2022/02/08 09:37:17 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft
{
	/*
	 * IS_INTEGRAL
	 *
	 * true for:
	 * 			- bool				- char					
	 * 			- int				- wchar_t				
	 * 			- short int			- signed char			
	 * 			- long int			- unsigned char			
	 * 			- long long int		- unsigned long int
	 * 			- unsigned int		- unsigned short int
	 *			- unsigned long long int
	 *
	 * false for everything else
	 *
	 * Reference:
	 *				- https://www.cplusplus.com/reference/type_traits/is_integral/
	 * 				- https://accu.org/journals/overload/9/43/frogley_442/
	*/

	template <typename T>
		struct is_integral				{	static const bool	value = false;	};

	template <>
		struct is_integral<bool>		{	static const bool	value = true;	};		// bool

	template <>
		struct is_integral<char>		{	static const bool	value = true;	};		// char

	template <>
		struct is_integral<wchar_t>		{	static const bool	value = true;	};		// wchar_t

	template <>
		struct is_integral<int>			{	static const bool	value = true;	};		// int

	template <>
		struct is_integral<const int>	{	static const bool	value = true;	};		// const int

	template <>
		struct is_integral<short int>	{	static const bool	value = true;	};		// short int

	template <>
		struct is_integral<long int>	{	static const bool	value = true;	};		// long int

	template <>
		struct is_integral<signed char>	{	static const bool	value = true;	};		// signed char

	template <>
		struct is_integral<unsigned char>	{	static const bool	value = true;	};	// unsigned char

	template <>
		struct is_integral<long long int>	{	static const bool	value = true;	};	// long long int

	template <>
		struct is_integral<unsigned int>	{	static const bool	value = true;	};	// unsigned int

	template <>
		struct is_integral<unsigned short int>		{	static const bool	value = true;	};	// unsigned short int

	template <>
		struct is_integral<unsigned long long int>	{	static const bool	value = true;	};	// unsigned long long int


	/*
	 * ENABLE_IF
	 *
	 * Enables a type if a given condition is met. Otherwise, it won't compile
	 *
	 */
	template<bool Cond, class T = void>
		struct enable_if {};

	template<class T>
		struct enable_if<true, T>	{	typedef T type;	};


	/*
	 * PAIR
	 *
	 * Provides a way to store two heterogeneous objects as a single unit.
	 *
	 * Reference: https://en.cppreference.com/w/cpp/utility/pair
	 *
	 */
	template <class T1, class T2>
		class pair
		{
			public:
				/* Public attributes */
				T1	first;
				T2	second;


				/* Constructors */
				pair() : first(0), second(0) {};

				template<class U, class V>
				pair(const pair<U, V> &copy) : first(copy.first), second(copy.second) {};

				pair(T1 first, T2 second) : first(first), second(second) {};


				/* Operator overloads (=, ==, !=, <, <=, >, >=) */
				pair	&operator=(const pair &rhs)
				{
					if (*this == rhs)
						return (*this);
					this->first = rhs.first;
					this->second = rhs.second;
					return (*this);
				}
				
				bool	operator==(const ft::pair<T1,T2>& rhs)
				{
					return (this->first == rhs.first && this->second == rhs.second);
				}
				
				bool operator!= (const ft::pair<T1,T2>& rhs)
				{
					return (this->first != rhs.first && this->second != rhs.second);
				}
		
				bool operator< (const ft::pair<T1,T2>& rhs)
				{
					return (this->first < rhs.first && this->second < rhs.second);
				}
		
				bool operator<= (const ft::pair<T1,T2>& rhs)
				{
					return (this->first <= rhs.first && this->second <= rhs.second);
				}

				bool operator> (const ft::pair<T1,T2>& rhs)
				{
					return (this->first > rhs.first && this->second > rhs.second);
				}

				bool operator>= (const ft::pair<T1,T2>& rhs)
				{
					return (this->first >= rhs.first && this->second >= rhs.second);
				}

				/* Destructor */
				~pair() {};
		};

	/*
	 * MAKE PAIR
	 *
	 * Pair constructor
	 *
	 * Reference: https://www.cplusplus.com/reference/utility/make_pair/
	 *
	 */	
	template <class T1,class T2>
		pair<T1,T2> make_pair (T1 x, T2 y)
		{
			return ( pair<T1,T2>(x,y) );
		}

	/*
	 * EQUAL
	 *
	 * Reference: https://www.enseignement.polytechnique.fr/informatique/INF478/docs/Cpp/en/cpp/algorithm/equal.html
	 *
	 */
   template<class InputIt1, class InputIt2>
	   bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
	   {
		   while (first1 != last1)
		   {
			   if (!(*first1 == *first2))
				   return false;
			   first1++;
			   first2++;
		   }
		   return true;
	   }	
   
   template<class InputIt1, class InputIt2, class BinaryPredicate>
	   bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p)
	   {
		   while (first1 != last1)
		   {
			   if (p(*first1, *first2))
				   return false;
			   first1++;
			   first2++;
		   }
		   return true;
	   }

   /*
	* LEXICOGRAPHICAL COMPARE
	*
	* Reference: 
	* 			- https://www.cplusplus.com/reference/algorithm/lexicographical_compare/
	* 			- https://www.fluentcpp.com/2019/12/20/how-to-compare-cpp-containers/
	*
	*/

	template <class InputIterator1, class InputIterator2>
		bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			first1++;
			first2++;
  		}
  		return (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2, class Compare>
		bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || !comp(*first2, *first1))
				return false;
			else if (comp(*first1, *first2))
				return true;
			first1++;
			first2++;
  		}
  		return (first2 != last2);
	}
};

#endif
