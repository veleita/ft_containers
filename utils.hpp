/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:48:40 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/10/12 17:01:02 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
	/*
	 * IS_INTEGRAL
	 *
	 * True for:
	 * 			- bool				- char					
	 * 			- int				- wchar_t				
	 * 			- short int			- signed char			
	 * 			- long int			- unsigned char			
	 * 			- long long int		- unsigned long int
	 * 			- unsigned int		- unsigned short int
	 *			- unsigned long long int
	 *
	 * Reference:
	 *				- https://www.cplusplus.com/reference/type_traits/is_integral/
	 * 				- https://accu.org/journals/overload/9/43/frogley_442/
	*/

	template <typename T>
		struct is_integral
		{
			static const bool	value = false;
		};

	template <>
		struct is_integral<bool>
		{
			static const bool	value = true;
		};

	template <>
		struct is_integral<char>
		{
			static const bool	value = true;
		};

	template <>
		struct is_integral<wchar_t>
		{
			static const bool	value = true;
		};

	template <>
		struct is_integral<int>
		{
			static const bool	value = true;
		};

	template <>
		struct is_integral<const int>
		{
			static const bool	value = true;
		};

	template <>
		struct is_integral<short int>
		{
			static const bool	value = true;
		};

	template <>
		struct is_integral<long int>
		{
			static const bool	value = true;
		};

	template <>
		struct is_integral<signed char>
		{
			static const bool	value = true;
		};

	template <>
		struct is_integral<unsigned char>
		{
			static const bool	value = true;
		};

	template <>
		struct is_integral<long long int>
		{
			static const bool	value = true;
		};

	template <>
		struct is_integral<unsigned int>
		{
			static const bool	value = true;
		};

	template <>
		struct is_integral<unsigned short int>
		{
			static const bool	value = true;
		};

	template <>
		struct is_integral<unsigned long long int>
		{
			static const bool	value = true;
		};

};
