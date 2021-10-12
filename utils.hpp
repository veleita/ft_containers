/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:48:40 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/10/12 17:44:24 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		struct is_integral	{	static const bool	value = false;	};

	template <>
		struct is_integral<bool>	{	static const bool	value = true;	};			// bool

	template <>
		struct is_integral<char>	{	static const bool	value = true;	};			// char

	template <>
		struct is_integral<wchar_t>	{	static const bool	value = true;	};			// wchar_t

	template <>
		struct is_integral<int>	{	static const bool	value = true;	};				// int

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
		struct is_integral<unsigned short int>	{	static const bool	value = true;	};	// unsigned short int

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
};
