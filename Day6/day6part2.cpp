/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day6part2.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/06 11:19:36 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/12/06 11:31:55 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <set>
#include <iostream>
#include <map>

using namespace std;

int main(void)
{
	int sum = 0;
	map<char, int>	answers;
	int groupsize = 0;

	while (!cin.eof())
	{
		string line;

		getline(cin, line);
		for (size_t i = 0; i < line.size(); i++)
			answers[line[i]]++;
		if (line.empty() || cin.eof())
		{
			if (cin.eof())
				groupsize++;
			for (auto it = answers.begin(); it != answers.end(); it++)
				if (it->second == groupsize)
					sum++;
			answers.clear();
			groupsize = 0;
		}
		else
			groupsize++;
	}
	std::cout << sum << std::endl;
	return (0);
}
