/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day10part1.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/09 09:40:58 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/12/10 19:10:01 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <set>

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
	std::cout << count(adapters) << std::endl;
	return (0);
}
