/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day10part1.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/09 09:40:58 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/12/10 13:03:49 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

unsigned long count(set<int>& adapters)
{
	map<unsigned long, unsigned long>	connections;

	for (set<int>::reverse_iterator it = adapters.rbegin(); it != adapters.rend(); it++)
	{
		if (it == adapters.rbegin())
			connections[*it]++;
		connections[*it] += connections[*it + 1] + connections[*it + 2] + connections[*it + 3];
	}
	return (connections[0]);
}

int main(void)
{
	set<int>	adapters;

	adapters.insert(0);
	while (!cin.eof())
	{
		int tmp;

		cin >> tmp;
		adapters.insert(tmp);
		if (cin.eof())
			adapters.insert(*(--adapters.end()) + 3);
	}
	int	differences[4] = {0};
	int last = 0;
	for (set<int>::iterator it = adapters.begin(); it != adapters.end(); it++)
	{
		differences[*it - last]++;
//		std::cout << "difference of :" << *it - last << std::endl;
//		std::cout << *it << std::endl;
		last = *it;
	}
	// std::cout << std::endl;
	// std::cout << differences[1] << " " << differences[3] << std::endl;
	// std::cout << differences[1] * differences[3] << std::endl;
	std::cout << count(adapters) << std::endl;
	return (0);
}
