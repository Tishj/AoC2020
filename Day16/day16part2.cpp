/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day16part2.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 19:26:03 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/12/17 00:23:47 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <locale>
#include <set>
#include <stdio.h>
#include <algorithm>

using namespace std;

bool	is_in_range(int num, pair<int, int> range)
{
	return (num >= range.first && num <= range.second);
}

int main(void)
{
	vector<vector<pair<int, int>>>	fields;

	while (!cin.eof()) //parse fields
	{
		string tmp;
		getline(cin, tmp);
		if (tmp.empty())
			break ;
		vector<pair<int, int>>	ranges(2);
		size_t colon = tmp.find(':', 0);
		colon++;
		size_t sep = tmp.find('-', colon);
		ranges[0].first = stoi(tmp.substr(colon + 1, sep - (colon + 1)));
		colon = sep;
		sep = tmp.find(' ', sep);
		ranges[0].second = stoi(tmp.substr(colon + 1, (sep - 1) - colon));
		colon = tmp.find_last_of(' ');
		sep = tmp.find('-', colon);
		ranges[1].first = stoi(tmp.substr(colon, colon - sep));
		ranges[1].second = stoi(tmp.substr(sep + 1, tmp.size() - (sep + 1)));
		fields.push_back(ranges);
	}
	for (size_t i = 0; i < fields.size(); i++)
		std::cout << "range1: " << fields[i][0].first << "-" << fields[i][0].second << " | range2: " << fields[i][1].first << "-" << fields[i][1].second << std::endl;

	string tmp;
	getline(cin, tmp);
	vector<int>	my_ticket;

	while (!cin.eof())
	{
		char c;

		int num;
		cin >> num;
		my_ticket.push_back(num);
		c = cin.get();
		if (c == '\n')
			break ;
	}
	std::cout << "My ticket: ";
	for (size_t i = 0; i < my_ticket.size(); i++)
		std::cout << my_ticket[i] << ((i + 1 < my_ticket.size()) ? "," : "\n");

	getline(cin, tmp);
	getline(cin, tmp);
	vector<vector<int> >	tickets;
	while (!cin.eof())
	{
		vector<int>	ticket;
		while (!cin.eof())
		{
			int num;
			char c;
			cin >> num;
			ticket.push_back(num);
			c = cin.get();
			if (c == '\n')
				break ;
		}
		tickets.push_back(ticket);
	}
	set<size_t>	invalid_tickets;
	for (size_t i = 0; i < tickets.size(); i++) //remove all invalid fields
	{
		for (size_t j = 0; j < tickets[i].size(); j++) //columns
		{
			size_t x = 0;
			for (; x < fields.size(); x++) //loop over all fields
				if (is_in_range(tickets[i][j], fields[x][0]) || is_in_range(tickets[i][j], fields[x][1]))
					break ;
			if (x == fields.size())
			{
				invalid_tickets.insert(i);
				break ;
			}
		}
	}

	std::cout << "Invalid tickets: ";
	for (auto it = invalid_tickets.begin(); it != invalid_tickets.end();)
		std::cout << *it << ((++it == invalid_tickets.end()) ? "\n" : ",");

	vector<vector<bool> >	field_column(fields.size(), vector<bool>(my_ticket.size(), true));
	for (size_t i = 0; i < fields.size(); i++) //fields
	{
		for (size_t j = 0; j < my_ticket.size(); j++) //column
		{
			for (size_t x = 0; x < tickets.size(); x++) //tickets
			{
				if (invalid_tickets.find(x) != invalid_tickets.end())
					continue ;
				if (!is_in_range(tickets[x][j], fields[i][0]) && !is_in_range(tickets[x][j], fields[i][1]))
				{
					field_column[i][j] = false;
					break ;
				}
			}
		}
	}
	size_t check = 0;
	set<size_t>	singles;
	for (;true;)
	{
		for (size_t i = 0; i < fields.size() && true; i++)
		{
			if (count(field_column[i].begin(), field_column[i].end(), true) == 1 && singles.find(i) == singles.end())
			{
				singles.insert(i);
				size_t index = find(field_column[i].begin(), field_column[i].end(), true) - field_column[i].begin();
				for (size_t j = 0; j < field_column.size(); j++)
				{
					if (j == i)
						continue ;
					field_column[j][index] = false;
				}
				check = 0;
			}
			check++;
		}
		if (check + 1 >= fields.size())
			break ;
	}
	dprintf(2, "            ");
	for (size_t i = 0; i < my_ticket.size(); i++)
		dprintf(2, "%2ld ", i);
	std::cout << std::endl;
	for (size_t i = 0; i < fields.size(); i++)
	{
		dprintf(2, "FIELD[%2ld] : ", i);
		for (size_t j = 0; j < my_ticket.size(); j++)
			std::cout << "[" << ((field_column[i][j]) ? "X" : " ") << "]";
		std::cout << std::endl;
	}
	unsigned long prod = 1;
	for (size_t i = 0; i < 6; i++)
	{
		size_t index = find(field_column[i].begin(), field_column[i].end(), true) - field_column[i].begin();
		prod *= my_ticket[index];
	}
	std::cout << prod << std::endl;
	return (0);
}
