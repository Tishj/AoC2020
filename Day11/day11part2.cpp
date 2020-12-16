/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day11part2.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/09 09:40:58 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/12/11 12:55:04 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

//need to stop looking further once a taken OR EMPTY seat has been seen

bool	seat_occupied(vector<string>& area, int y, int x, char state)
{
	return (y >= 0 && y < area.size() && x >= 0 && x < area[y].size() && area[y][x] == state);
}

int	adjacent_status(vector<string>& area, int y, int x)
{
	int occupied = 0;
	vector<bool>	dirs(8, true);

	for (size_t i = 1; i < area.size(); i++)
	{
		if (dirs[0] && (seat_occupied(area, y - i, x, '#') || seat_occupied(area, y - i, x, 'L'))) //up
		{
			occupied += seat_occupied(area, y - i, x, '#');
			dirs[0] = false;
		}
		if (dirs[1] && (seat_occupied(area, y - i, x + i, '#') || seat_occupied(area, y - i, x + i, 'L')))
		{
			occupied += seat_occupied(area, y - i, x + i, '#');
			dirs[1] = false;
		}
		if (dirs[2] && (seat_occupied(area, y, x + i, '#') || seat_occupied(area, y, x + i, 'L'))) //right
		{
			occupied += seat_occupied(area, y, x + i, '#');
			dirs[2] = false;
		}
		if (dirs[3] && (seat_occupied(area, y + i, x + i, '#') || seat_occupied(area, y + i, x + i, 'L')))
		{
			occupied += seat_occupied(area, y + i, x + i, '#');
			dirs[3] = false;
		}
		if (dirs[4] && (seat_occupied(area, y + i, x, '#') || seat_occupied(area, y + i, x, 'L'))) //down
		{
			occupied += seat_occupied(area, y + i, x, '#');
			dirs[4] = false;
		}
		if (dirs[5] && (seat_occupied(area, y + i, x - i, '#') || seat_occupied(area, y + i, x - i, 'L')))
		{
			occupied += seat_occupied(area, y + i, x - i, '#');
			dirs[5] = false;
		}
		if (dirs[6] && (seat_occupied(area, y, x - i, '#') || seat_occupied(area, y, x - i, 'L'))) //left
		{
			occupied += seat_occupied(area, y, x - i, '#');
			dirs[6] = false;
		}
		if (dirs[7] && (seat_occupied(area, y - i, x - i, '#') || seat_occupied(area, y - i, x - i, 'L')))
		{
			occupied += seat_occupied(area, y - i, x - i, '#');
			dirs[7] = false;
		}
	}
//	std::cout << "OCCUPADO: " << occupied << std::endl;
	return (occupied);
}

int	simulate(vector<string>& area, vector<string>& tmp)
{
	int changes = 0;
	for (size_t i = 0; i < area.size(); i++)
	{
		for (size_t j = 0; j < area[i].size(); j++)
		{
			if (tmp[i][j] == 'L' && adjacent_status(area, i, j) == 0)
			{
				changes++;
				tmp[i][j] = '#';
			}
			else if (tmp[i][j] == '#' && adjacent_status(area, i, j) >= 5)
			{
				changes++;
				tmp[i][j] = 'L';
			}
		}
	}
	return (changes);
}

void	print_seats(vector<string>& area)
{
	for (size_t i = 0; i < area.size(); i++)
		std::cout << area[i] << std::endl;
	std::cout << std::endl;
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
//		print_seats(area);
		vector<string>	tmp(area);
		int changes = simulate(area, tmp);
//		std::cout << "changes: " << changes << std::endl;
		area = tmp;
		if (last_change == changes)
			break ;
		last_change = changes;
	}
	int occupied = 0;
	for (size_t i = 0; i < area.size(); i++)
	{
		for (size_t j = 0; j < area[i].size(); j++)
			occupied += seat_occupied(area, i, j, '#');
	}
	std::cout << occupied << std::endl;
	return (0);
}
