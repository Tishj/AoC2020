/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day13part1.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/13 14:58:50 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/12/13 17:26:29 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <map>
#include <limits>
#include <vector>

using namespace std;

vector<string>    split_on_char(string line, char c)
{
	vector<string>    split;
	char prev = c;
	for (size_t i = 0; i < line.size(); i++)
	{
		size_t delim = line.find_first_of(c, i + 1);
		if (delim == std::string::npos)
		{
			split.push_back(line.substr(i, line.size() - i));
			break ;
		}
		else
		{
			if (delim == i)
				for (; line[delim] == c; delim++) {}
			split.push_back(line.substr(i, delim - i));
		}
		i = delim;
	}
	return (split);
}

int main(void)
{
	int timestamp;
	cin >> timestamp;
	cin.ignore();
	std::cout << timestamp << std::endl;
	map<int, int>	bus_departure;
	string	input;
	getline(cin, input);
	std::cout << input << std::endl;
	vector<string>	numbers = split_on_char(input, ',');
	for (auto it = numbers.begin(); it != numbers.end(); it++)
	{
		if (!isdigit((*it)[0]))
			continue ;
		int num = stoi(*it);
		std::cout << num << std::endl;
		bus_departure[num] = ((timestamp / num) * num) + ((timestamp % num) ? num : 0);
	}
	size_t diff = numeric_limits<size_t>::max();
	int bus_id = 0;
	for (auto it = bus_departure.begin(); it != bus_departure.end(); it++)
	{
		size_t tmp = it->second - timestamp;
		if (it->second - timestamp < diff)
		{
			diff = (it->second - timestamp);
			bus_id = it->first;
		}
	}
	std::cout << bus_id * diff << std::endl;
	return (0);
}
