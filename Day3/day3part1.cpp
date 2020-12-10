/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day3part1.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 10:15:00 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/12/03 13:32:35 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	vector<string>	map;
	while (!cin.eof())
	{
		map.push_back(std::string());
		getline(cin, map[map.size() - 1]);
	}
	size_t trees = 0;
	for (size_t i = 1; i < map.size(); i++)
		trees += (map[i][(3 * i) % map[i].size()] == '#');
	std::cout << trees << std::endl;
}
