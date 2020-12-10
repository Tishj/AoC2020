/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day1part2.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 09:25:29 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/12/01 10:15:07 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct sum
{
	sum(int a, int b, int c) : a(a), b(b), c(c), combined(a + b + c) {}
	int a, b, c;
	int combined;
};

int main(void)
{
	string buf;
	vector<int>	entries;
	vector<sum>	sums;

	while (!getline(cin, buf).eof())
	{
		int entry = stoi(buf);
		entries.push_back(entry);
	}
	int nums[2] = {0};
	for (size_t i = 0; i + 2 < entries.size(); i++)
	{
		for (size_t j = i + 1; j + 1 < entries.size(); j++)
			for (size_t k = j + 1; k < entries.size(); k++)
				sums.push_back(sum(entries[i], entries[j], entries[k]));
	}
	for (size_t i = 0; i < sums.size(); i++)
	{
		if (sums[i].combined == 2020)
		{
			dprintf(2, "%d * %d * %d = %d\n", sums[i].a, sums[i].b, sums[i].c, sums[i].a * sums[i].b * sums[i].c);
			break ;
		}
	}
	return (0);
}
