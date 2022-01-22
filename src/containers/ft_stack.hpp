/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <1veleita1@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 07:09:43 by mzomeno-          #+#    #+#             */
/*   Updated: 2022/01/22 08:01:35 by mzomeno-         ###   ########.fr       */
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


			/* CONSTRUCTORS */
			explicit stack (const container_type& ctnr = container_type())
			:	underlaying_container(ctnr)
			{}

		private:
			container_type	underlaying_container;
	};
}

#endif
