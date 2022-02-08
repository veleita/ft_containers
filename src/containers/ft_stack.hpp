/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <1veleita1@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 07:09:43 by mzomeno-          #+#    #+#             */
/*   Updated: 2022/02/08 10:55:19 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

# include <ft_vector.hpp>

namespace ft
{
	/* Reference: https://www.cplusplus.com/reference/stack/stack/ */
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			/* TYPE DEFINITIONS */
			typedef Container		container_type;
			typedef T				value_type;
			typedef size_t			size_type;


		public:

			container_type	underlaying_ctnr;
			
			/* CONSTRUCTORS */
			explicit stack (const container_type& ctnr = container_type())
			:	underlaying_ctnr(ctnr)
			{}

			/* MEMBER FUNCTIONS */

			/* empty(): true if the stack is empty, false otherwise */
			bool empty() const	{	return (underlaying_ctnr.empty());	}

			/* size(): returns the size of the stack */
			size_type size() const	{	return underlaying_ctnr.size();	}

			/* top(): returns a reference to the top element in the stack */
			value_type	&top()	{	return underlaying_ctnr.back();	}
			const value_type	&top() const
			{	return underlaying_ctnr.back();	}

			/* push(): insert element on top */
			void push( const value_type	&val )
			{	underlaying_ctnr.push_back(val);	}

			/* pop(): remove the top element */
			void pop()	{	underlaying_ctnr.pop_back();	}

			/* DESTRUCTOR */
			~stack()
			{}
	};
	
	/* NON-MEMBER FUNCTION OVERLOADS */

	/* Call the relational operators of the underlaying container
	 * (ft::vector by default) */
	template <class T, class Container>
		bool operator==(const stack< T, Container > &lhs, const stack< T, Container > &rhs)
		{
			return (lhs.underlaying_ctnr == rhs.underlaying_ctnr);
		}
	
	template <class T, class Container>
		bool operator!=(const stack< T, Container > &lhs, const stack< T, Container > &rhs)
		{
			return (lhs.underlaying_ctnr != rhs.underlaying_ctnr);
		}

	template <class T, class Container>
		bool operator<(const stack< T, Container > &lhs, const stack< T, Container > &rhs)
		{
			return (lhs.underlaying_ctnr < rhs.underlaying_ctnr);
		}
		
	template <class T, class Container>
		bool operator<=(const stack< T, Container > &lhs, const stack< T, Container > &rhs)
		{
			return (lhs.underlaying_ctnr <= rhs.underlaying_ctnr);
		}

	template <class T, class Container>
		bool operator> (const stack< T,Container > &lhs, const stack< T, Container > &rhs)
		{
			return (lhs.underlaying_ctnr > rhs.underlaying_ctnr);
		}

	template <class T, class Container>
		bool operator>= (const stack< T, Container > &lhs, const stack< T, Container > &rhs)
		{
			return (lhs.underlaying_ctnr >= rhs.underlaying_ctnr);
		}
}

#endif
