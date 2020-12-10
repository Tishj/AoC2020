/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day6part1.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/06 11:19:36 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/12/06 11:31:26 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <set>
#include <iostream>
#include <set>

using namespace std;

int main(void)
{
	int sum = 0;
	set<char>	answers;

	while (!cin.eof())
	{
		string line;

		getline(cin, line);
		for (size_t i = 0; i < line.size(); i++)
			answers.insert(line[i]);
		if (line.empty() || cin.eof())
		{
			sum += answers.size();
			answers.clear();
		}
	}
	std::cout << sum << std::endl;
	return (0);
}
