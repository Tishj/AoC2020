/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day17part2.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/17 12:52:47 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/12/17 16:56:05 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unistd.h>

using namespace std;

void	add_neighbours(map<tuple<int, int, int, int>, int>&	neighbours, const tuple<int, int, int, int>& cur)
{
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			for (int k = -1; k <= 1; k++)
			{
				for (int m = -1; m <= 1; m++)
				{
					if (i == 0 && j == 0 && k == 0 && m == 0)
						continue ;
					neighbours[std::make_tuple(std::get<0>(cur) + i, std::get<1>(cur) + j, std::get<2>(cur) + k, std::get<3>(cur) + m)]++;
				}
			}
		}
	}
}

set<tuple<int, int, int, int>>	new_cycle(set<tuple<int, int, int, int>> previous)
{
	map<tuple<int, int, int, int>, int>	active_neighbours;
	set<tuple<int, int, int, int>>	newActive;

	for (auto it = previous.begin(); it != previous.end(); it++)
	{
		add_neighbours(active_neighbours, *it);
	}
	for (auto it = active_neighbours.begin(); it != active_neighbours.end(); it++)
	{
		if (previous.find(it->first) != previous.end())
		{
			if (it->second == 2 || it->second == 3)
				newActive.insert(it->first);
		}
		else
		{
			if (it->second == 3)
				newActive.insert(it->first);
		}
	}
	return (newActive);
}

int main(void)
{
	set<tuple<int, int, int, int>>	active;

		
	for (size_t i = 0; !cin.eof(); i++)
	{
		string line;
		getline(cin, line);
		for (size_t j = 0; j < line.size(); j++)
		{
			if (line[j] == '#')
				active.insert(tuple<int, int, int, int>(j, i, 0, 0));
		}
	}
	for (size_t i = 0; i < 6; i++)
	{
		active = new_cycle(active);
	}
	std::cout << active.size() << std::endl;
	return (0);
}
