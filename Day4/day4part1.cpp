/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day4part1.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 08:45:20 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/12/04 11:36:12 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <limits>
#include <unistd.h>

using namespace std;

bool valid_entry(unordered_map<string, vector<string> >::iterator& it)
{
	if (it->first == "cid")
		return (false);
	if (it->first == "byr")
	{
		char *endptr;
		int number = strtol(it->second[0].c_str(), &endptr, 10);
		if (endptr == it->second[0].c_str() + it->second[0].size() && number >= 1920 && number <= 2002)
			return (true);
		return (false);
	}
	else if (it->first == "iyr")
	{
		char *endptr;
		int number = strtol(it->second[0].c_str(), &endptr, 10);
		if (endptr == it->second[0].c_str() + it->second[0].size() && number >= 2010 && number <= 2020)
			return (true);
		return (false);
	}
	else if (it->first == "eyr")
	{
		char *endptr;
		int number = strtol(it->second[0].c_str(), &endptr, 10);
		if (endptr == it->second[0].c_str() + it->second[0].size() && number >= 2020 && number <= 2030)
			return (true);
		return (false);
	}
	else if (it->first == "hgt")
	{
		char *endptr;
		int number = strtol(it->second[0].c_str(), &endptr, 10);
		size_t i = 0;
		for (; i < it->second[0].size() && it->second[0][i] >= '0' && it->second[0][i] <= '9'; i++) {}
		string id = it->second[0].substr(i, it->second[0].size());
		if ((id == "cm" && number >= 150 && number <= 193) || (id == "in" && number >= 59 && number <= 76))
			return (true);
		return (false);
	}
	else if (it->first == "hcl")
	{
		if (it->second[0][0] != '#')
			return (false);
		for (size_t i = 1; i < it->second[0].size(); i++)
		{
			if (!((it->second[0][i] >= '0' && it->second[0][i] <= '9') || (it->second[0][i] >= 'a' && it->second[0][i] <= 'f')))
				return (false);
			return (true);
		}
	}
	else if (it->first == "ecl")
	{
		string valid_colors[] = {
			"amb",
			"blu",
			"brn",
			"gry",
			"grn",
			"hzl",
			"oth",
		};
		for (size_t i = 0; i < 7; i++)
			if (valid_colors[i] == it->second[0])
				return (true);
		return (false);
	}
	else if (it->first == "pid")
	{
		size_t i = 0;
		for (; i < it->second[0].size() && it->second[0][i] >= '0' && it->second[0][i] <= '9'; i++) {}
		return (i == 9);
	}
	else
		return (false);
}

bool valid_passport(unordered_map<string, vector<string> >& passport)
{
	size_t fields = 0;
	for (auto it = passport.begin(); it != passport.end(); it++)
		fields += valid_entry(it);
	return (fields == 7);
}

vector<string>	split_on_char(string line, char c)
{
	vector<string>	split;
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
	unordered_map<string, vector<string> >	keyval;

	size_t passports = 0;
	while (!cin.eof())
	{
		string raw;
		getline(cin, raw);
		vector<string>	split = split_on_char(raw, ' ');
		for (size_t i = 0; i < split.size(); i++)
		{
			vector<string>	entry = split_on_char(split[i], ':');
			keyval[entry[0]].push_back(entry[1]);
		}
		if (raw.empty() || cin.eof())
		{
			if (valid_passport(keyval))
				passports++;
			keyval.clear();
		}
	}
	std::cout << passports << endl;
}
