/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day5part1.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/05 11:50:46 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/12/05 12:12:30 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main(void)
{
	vector<string>	passes;
	size_t biggest_id = 0;	

	set<size_t>	ids;
	while (!cin.eof())
	{
		passes.push_back(std::string());
		cin >> passes[passes.size() - 1];
		std::pair<size_t, size_t>	row(0, 127);
		std::pair<size_t, size_t>	col(0, 7);
		size_t i = 0;
		for (; i < 7; i++)
		{
			std::cout << row.first << " " << row.second << std::endl;
			if (passes[passes.size() - 1][i] == 'F')
				row.second -= ((row.second - row.first) / 2) + 1;
			else
				row.first += ((row.second - row.first) / 2) + 1;
		}
		for (; i < 10; i++)
		{
			std::cout << col.first << " " << col.second << std::endl;
			if (passes[passes.size() - 1][i] == 'L')
				col.second -= ((col.second - col.first) / 2) + 1;
			else
				col.first += ((col.second - col.first) / 2) + 1;
		}
		ids.insert(row.first * 8 + col.first);
	}
	size_t prev;
	for (auto it = ids.begin(); it != ids.end(); it++)
	{
		if (it != ids.begin() && prev + 2 == *it)
			break;
		prev = *it;
	}
	std::cout << prev + 1 << std::endl;
}
