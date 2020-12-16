/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day16part1.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 19:26:03 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/12/16 20:39:53 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <locale>

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
	vector<vector<bool> >	field_column(fields.size(), vector<bool>(my_ticket.size()));
	for (size_t i = 0; i < tickets.size(); i++)
	{
//		std::cout << "Ticket " << i << " : ";
		for (size_t j = 0; j < tickets[i].size(); j++)
		{
//			std::cout << tickets[i][j] << ((j + 1 < tickets[i].size()) ? "," : "\n");
			size_t x = 0;
			for (; x < fields.size(); x++)
				if (is_in_range(tickets[i][j], fields[x][0]) || is_in_range(tickets[i][j], fields[x][1]))
					break ;
			if (x == fields.size())
				field_error += tickets[i][j];
		}
	}
	std::cout << field_error << std::endl;
	return (0);
}
