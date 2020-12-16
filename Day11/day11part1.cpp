/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day11part1.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/09 09:40:58 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/12/11 11:53:22 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

bool	seat_occupied(vector<string>& area, int y, int x)
{
	return (y >= 0 && y < area.size() && x >= 0 && x < area[y].size() && area[y][x] == '#');
}

int	adjacent_status(vector<string>& area, int y, int x, int dist)
{
	int occupied = 0;

	occupied += seat_occupied(area, y, x + 1);
	occupied += seat_occupied(area, y, x - 1);
	occupied += seat_occupied(area, y + 1, x);
	occupied += seat_occupied(area, y + 1, x - 1);
	occupied += seat_occupied(area, y + 1, x + 1);
	occupied += seat_occupied(area, y - 1, x);
	occupied += seat_occupied(area, y - 1, x + 1);
	occupied += seat_occupied(area, y - 1, x - 1);
	return (occupied);
}

int	simulate(vector<string>& area, vector<string>& tmp)
{
	int changes = 0;
	for (size_t i = 0; i < area.size(); i++)
	{
		for (size_t j = 0; j < area[i].size(); j++)
		{
			if (tmp[i][j] == 'L' && adjacent_status(area, i, j, 2) == 0)
			{
				changes++;
				tmp[i][j] = '#';
			}
			else if (tmp[i][j] == '#' && adjacent_status(area, i, j, 2) >= 4)
			{
				changes++;
				tmp[i][j] = 'L';
			}
		}
	}
	return (changes);
}

int main(void)
{
	vector<string>	area;

	while (!cin.eof())
	{
		string tmp;
		getline(cin, tmp);
		area.push_back(tmp);
	}
	int last_change = 0;
	while (1)
	{
		vector<string>	tmp(area);
		int changes = simulate(area, tmp);
		std::cout << "changes: " << changes << std::endl;
		area = tmp;
		if (last_change == changes)
			break ;
		last_change = changes;
	}
	int occupied = 0;
	for (size_t i = 0; i < area.size(); i++)
	{
		for (size_t j = 0; j < area[i].size(); j++)
			occupied += seat_occupied(area, i, j);
	}
	std::cout << occupied << std::endl;
	return (0);
}
