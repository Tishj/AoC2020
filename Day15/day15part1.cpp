/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day15part1.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/15 13:12:08 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/12/15 13:28:24 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <unistd.h>

using namespace std;

int main(void)
{
	map<int, int>	numbers;

	size_t turn = 1;
	while (!cin.eof())
	{
		int tmp;
		cin >> tmp;
		numbers[tmp] = turn++;
		std::cout << tmp << std::endl;
	}
	int next = 0;
	for (; turn < 2020; turn++)
	{
		std::cout << next << std::endl;
		int old = numbers[next];
		numbers[next] = turn;
		if (old)
			next = turn - old;
		else
			next = 0;
//		sleep(1);
	}
	std::cout << next << std::endl;
	return (0);
}
