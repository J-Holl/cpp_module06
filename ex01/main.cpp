/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:31:39 by jholl             #+#    #+#             */
/*   Updated: 2022/05/24 15:07:22 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>

typedef struct	s_data
{
	std::string	name;
	std::string	other_name;
	long long int x;
	double y;
	
}		Data;


uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int	main(void)
{
	Data data;
	data.name = "toto le jojo";
	data.other_name = "jojo le toto";
	data.x = 123456789;
	data.y = -12345.6789;

	Data *data_ptr;
	data_ptr = &data;

	std::cout << "Name: " << data_ptr->name << " Other_name: " <<
	data_ptr->other_name <<  " X: " << data_ptr->x << " Y: " << data_ptr->y << std::endl;
	std::cout << data_ptr << std::endl;
	std::cout << std::endl;

	uintptr_t raw = serialize(data_ptr);
	std::cout << "The bits are still the same but interpreted differently: " << raw << std::endl;
	data_ptr = NULL;
	std::cout << std::endl;

	data_ptr = deserialize(raw);
	std::cout << "We still got access to data member after serialize and deserialize:" << std::endl;
	std::cout << "Name: " << data_ptr->name << " Other_name: " <<
	data_ptr->other_name <<  " X: " << data_ptr->x << " Y: " << data_ptr->y << std::endl;
	std::cout << data_ptr << " We still got the same adress after serialize and deserialize." << std::endl;
	return (0);
}
