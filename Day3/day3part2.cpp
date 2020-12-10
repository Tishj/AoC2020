/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day3part2.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 10:15:00 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/12/03 13:00:39 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

int main(void)
{
	vector<string>	map;
	while (!cin.eof())
	{
		map.push_back(std::string());
		getline(cin, map[map.size() - 1]);
	}
	size_t trees[5] = {0};
	std::pair<size_t, size_t>	steps[5] = {
		std::pair<size_t, size_t>(1, 1),
		std::pair<size_t, size_t>(1, 3),
		std::pair<size_t, size_t>(1, 5),
		std::pair<size_t, size_t>(1, 7),
		std::pair<size_t, size_t>(2, 1),
	};
	for (size_t i = 1; i < map.size(); i++)
		for (size_t j = 0; j < 5; j++)
			trees[j] += (i * steps[j].first < map.size() && map[(i * steps[j].first)][(steps[j].second * i) % map[i].size()] == '#');
	size_t sum = 1;
	for (size_t i = 0; i < 5; i++)
		sum *= trees[i];
	std::cout << sum << std::endl;
	return (0);
}
