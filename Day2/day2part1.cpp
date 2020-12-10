/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day2part1.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 10:37:17 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/12/02 10:48:22 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
	string buf;

	int valid = 0;
	while (1)
	{
		int min, max, count;
		char id;
		string password;

		cin >> min; cin.ignore(); cin >> max >> id; cin.ignore(); cin >> password;
		std::cout << min << " " << max << " " << id << " " << password << std::endl;
		count = std::count(password.begin(), password.end(), id);
		if (count >= min && count <= max)
			valid++;
		if (cin.eof())
			break;
	}
	std::cout << valid << std::endl;
}
