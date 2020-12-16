/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_bs.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/13 17:14:58 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/12/13 17:20:44 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
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
	string test;
	getline(cin, test);
	vector<string>	split = split_on_char(test, ',');
	for (size_t i = 0; i < split.size(); i++)
		std::cout << split[i] << std::endl;
	return (0);
}
