/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day7part2.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 06:59:30 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/12/07 23:02:19 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <map>
#include <list>
#include <iostream>
#include <vector>

//map of bags, every bag potentially contains an amount of another bag

using namespace std;

void	get_info(map<string, list<pair<string, int>> >& bags, string line)
{
	string bag;
	size_t start = 0;
	bool space_skipped = false;
	size_t i = 0;
	for (;i < line.size(); i++)
	{
		if (line[i] == ' ' && !space_skipped)
			space_skipped = true;
		else if (line[i] == ' ')
		{
			bag = line.substr(start, i);
			i += std::string(" bags contain ").size();
			start = i;
			break ;
		}
	}
	(void)bags[bag].size();
	if (line[i] == 'n')
		return ;
	int number;
	string bagtype;
	for (; i < line.size(); i++)
	{
		if (isdigit(line[i]))
		{
			size_t number_length = 0;
			for (; isdigit(line[i + number_length]); number_length++) {}
			number = stoi(line.substr(i, number_length));
			i += number_length;
			start = i + 1;
			space_skipped = false;
		}
		else if (line[i] == ' ' && !space_skipped)
			space_skipped = true;
		else if (line[i] == ' ')
		{
			bagtype = line.substr(start, (i - start));
			pair<string, int> collection(bagtype, number);
			bags[bag].push_back(collection);
			i += std::string(" bags").size();
			if (i < line.size() && line[i] != ' ')
				i++;
			start = i;
			space_skipped = false;
		}
	}
}

vector<string>	split_on_char(string line, vector<string>& splitters)
{
	vector<string>	split;
	for (size_t i = 0; i < line.size(); i++)
	{
		size_t j = 0;
		size_t delim = line.find(splitters[j], i + 1);
		for (; delim == std::string::npos && j < splitters.size(); j++)
		{
			delim = line.find(splitters[j], i + 1);
		}
		if (delim == std::string::npos)
		{
			split.push_back(line.substr(i - 1, line.size() - (i - 1)));
			break ;
		}
		else
		{
			split.push_back(line.substr(i, delim - i));
		}
		i = delim + splitters[j].size() - 1;
	}
	return (split);
}

bool can_contain_bag(map<string, list<pair<string, int>> >& bags, string bag)
{
	if (bag == "shiny gold")
		return (true);
	for (auto it = bags[bag].begin(); it != bags[bag].end(); it++)
	{
		if (can_contain_bag(bags, it->first))
			return (true);
	}
	return (false);
}

int bag_count(map<string, list<pair<string, int>> >& bags, string bag, int amount)
{
	int count = 1;
	for (auto it = bags[bag].begin(); it != bags[bag].end(); it++)
	{
		int tmp = bag_count(bags, it->first, it->second);
		count += tmp;
	}
	return (count * amount);
}

int main(void)
{
	map<string, list<std::pair<string, int> > >	bags;

	while (!cin.eof())
	{
		string buf;
		getline(cin, buf);
		get_info(bags, buf);
	}
	int total_bags = 0;
	for (auto it = bags.begin(); it != bags.end(); it++)
	{
		for (auto jt = it->second.begin(); jt != it->second.end(); jt++)
		total_bags += can_contain_bag(bags, it->first);
	}
	std::cout << bag_count(bags, "shiny gold", 1) - 1 << std::endl;
	return (0);
}
