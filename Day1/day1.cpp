/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day1.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 09:25:29 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/12/01 09:36:27 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
	string buf;
	map<int, int> entries;

	while (!getline(cin, buf).eof())
	{
		int entry = stoi(buf);
		entries[entry] = entry;
	}
	int nums[2] = {0};
	for (auto it = entries.begin(); it != entries.end(); it++)
	{
		int difference = 2020 - it->first;
		if (!entries.count(difference))
			continue ;
		nums[0] = it->first;
		nums[1] = difference;
		break ;
	}
	dprintf(2, "%d * %d = %d\n", nums[0], nums[1], nums[0] * nums[1]);
	return (0);
}
