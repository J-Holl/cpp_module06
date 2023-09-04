/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:37:58 by jholl             #+#    #+#             */
/*   Updated: 2022/05/24 15:10:09 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cstdlib"
#include "climits"
#include "cfloat"
#include "ostream"
#include "iostream"
#include "string"

void convertFromDouble(std::string s)
{
	double digit = atof(s.c_str());
	//char
	std::cout << "char: ";
	if (s == "nan" || digit < static_cast<double>(CHAR_MIN) || digit > static_cast<double>(CHAR_MAX))
		std::cout << "impossible" << std::endl;
	else
	{
		char c = static_cast<char>(digit);
		if (isprint(c))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	//Int
	std::cout << "int: ";
	if (s == "nan" || static_cast<long int>(digit) < INT_MIN || static_cast<long int>(digit) > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(digit) << std::endl;
	//Float
	std::cout << std::fixed;
	std::cout << "float: ";
	if (s != "inf" && s != "+inf" && s != "-inf" && (digit < static_cast<double>(-FLT_MAX) || digit > static_cast<double>(FLT_MAX)))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(digit) << "f" << std::endl;
	//Double
	std::cout << std::fixed;
	std::cout << "double: " << digit << std::endl;
}

void convertFromFloat(std::string s)
{
	double digit = atof(s.c_str());
	//Char
	std::cout << "char: ";
	if (s == "nanf" || digit < static_cast<double>(CHAR_MIN) || digit > static_cast<double>(CHAR_MAX))
		std::cout << "impossible" << std::endl;
	else
	{
		char c = static_cast<char>(digit);
		if (isprint(c))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	//Int
	std::cout << "int: ";
	if (s == "nanf" || static_cast<long int>(digit) < INT_MIN || static_cast<long int>(digit) > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(digit) << std::endl;
	//Float
	std::cout <<  std::fixed;
	std::cout << "float: " << static_cast<float>(digit) << "f" << std::endl;
	//Double
	std::cout << std::fixed;
	std::cout << "double: " << digit << std::endl;
}

void convertFromChar(std::string s)
{
	char c = (s.c_str()[0]);
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << std::fixed;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void convertFromInt(std::string s)
{
	double digit = atof(s.c_str());
	if (digit < INT_MIN || digit > INT_MAX)
	{
		std::cout << "Overflow/underflow WARNING!" << std::endl;
		return ;
	}
	//Char
	std::cout << "char: "; 
	if (digit < static_cast<double>(CHAR_MIN) || digit > static_cast<double>(CHAR_MAX))
		std::cout << "impossible" << std::endl;
	else
	{
		char c = static_cast<char>(digit);
		if (isprint(c))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	//Int
	std::cout << "int: " << static_cast<int>(digit) << std::endl;
	//Float
	std::cout << std::fixed;
	std::cout << "float: " << static_cast<float>(digit) << "f" << std::endl;
	//Double
	std::cout << std::fixed;
	std::cout << "double: " << digit << std::endl;
}

// 0 int | 1 char | 2 double | 3 float | 4 undefined
int	lf_type(std::string s)
{
	bool decimal = false;
	bool is_there_float = false;

	if (s.size() == 1)
	{
		if (std::isprint(s[0]) && !std::isdigit(s[0]))
			return (1); 
	}
	if (s == "-inf" || s == "+inf"|| s == "nan" )
		return (2);
	if (s == "+inff" || s == "-inff" || s == "nanf")
		return (3);
	for (size_t i = 0; i < s.size(); i++)
	{
		if (!i)
		{
			if (s[i] == '-' || s[i] == '+')
				i++;
		}	
		if (!isdigit(s[i]))
		{
			if (s[i] == '.')
			{
				if (decimal)
					return (4);
				if (!s[i + 1])
					return (4);
				if (!std::isdigit(s[i + 1]))
					return (4);
				decimal = true;
			}
			else if (s[i] == 'f')
			{
				if (is_there_float)
					return (4);
				if ((s.size() - 1) != i)
					return (4);
				is_there_float = true;
			}
			else
				return (4);
		}
	}
	if (is_there_float && decimal)
		return (3);
	if (decimal)
		return (2);
	return (0);
}
 
int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Need only one arg." << std::endl;
		return (0);
	}
	else
	{
		if (!av[1][0])
		{
			std::cout << "No empty arg." << std::endl;
			return (0);
		}

		int type = lf_type(av[1]);
		switch (type)
		{
			case 0:
				convertFromInt(av[1]);
				break;
			case 1:
				convertFromChar(av[1]);
				break;
			case 2:
				convertFromDouble(av[1]);
				break;
			case 3:
				convertFromFloat(av[1]);
				break;
			default:
				std::cout << "Litteral must strictly be a char, int, double or float." << std::endl;
				break;
		}
	}
	return (0);
}
