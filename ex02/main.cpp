/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:59:07 by jholl             #+#    #+#             */
/*   Updated: 2022/05/24 15:09:11 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
//For rand
#include <ctime>
#include <cstdlib>

void	identify(Base& p)
{
	try
	{
		A & a = dynamic_cast<A &>(p);
		(void) a;
		std::cout << "It's a class A reference." << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
	}

	try
	{
		B & b = dynamic_cast<B &>(p);
		(void) b;
		std::cout << "It's a class B reference." << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
	}
	
	try
	{
		C & c = dynamic_cast<C &>(p);
		(void) c;
		std::cout << "It's a class C reference." << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
	}
}

void	identify(Base* p)
{
	A *a = dynamic_cast<A*>(p);
	if (!a)
		;
	else
		std::cout << "It's a class A pointer." << std::endl;

	B *b = dynamic_cast<B*>(p);
	if (!b)	
		;
	else
		std::cout << "It's a class B pointer." << std::endl;

	C *c = dynamic_cast<C*>(p);
	if (!c)
		;
	else
		std::cout << "It's a class C pointer." << std::endl;
}

Base *generate(void)
{
	srand(time(NULL));
	switch(rand() % 3)
	{
		case 0:
			std::cout << "Random choose class A. That couldn't be better." << std::endl;
			return (new A);

		case 1:
			std::cout << "Random choose class B. That couldn't be better." << std::endl;
			return (new B);

		case 2:
			std::cout << "Random choose class C. That couldn't be better." << std::endl;
			return (new C);

		default:
			std::cout << "Nothing." << std::endl;
			return (NULL);
			break ;
	}
}

int	main(void)
{
	Base *b_ptr = generate();

	identify(b_ptr);
	identify(*b_ptr);

	delete (b_ptr);

	return (0);
}
