/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day9part1.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/09 07:54:59 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/12/09 08:26:45 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#ifndef PREAMBLE
# define PREAMBLE 25
#endif

using namespace std;

std::pair<int, int>	sum_contiguous(vector<int>& numbers, size_t start, int to_find)
{
	int sum = 0;

	size_t i = start;
	for (; i < numbers.size() && sum < to_find; i++)
		sum += numbers[i];
	return (std::pair<int, int>(i, sum));
}

std::pair<int, int>	find_weakness(vector<int>& numbers, int to_find)
{
	for (size_t i = 0; i < numbers.size(); i++)
	{
		std::pair<int, int>	tmp = sum_contiguous(numbers, i, to_find);
		if (tmp.second == to_find)
			return (std::pair<int, int>(i, tmp.first));
	}
	return (std::pair<int, int>(0, 0));
}

bool	find(vector<int>& numbers, int index, int to_find)
{
	size_t count = numbers.size();
	for (size_t i = count - PREAMBLE; i < count; i++)
	{
		if (i == index)
			continue ;
		if (numbers[index] + numbers[i] == to_find)
			return (true);
	}
	return (false);
}

std::pair<int, int>	smallest_and_largest(vector<int>& numbers, size_t start, size_t end)
{
	int smallest = 99999999;
	int biggest = 0;
	for (size_t i = start; i < end; i++)
	{
		std::cout << "checking: " << numbers[i] << std::endl;
		if (numbers[i] > biggest)
			biggest = numbers[i];
		if (numbers[i] < smallest)
			smallest = numbers[i];
	}
	std::cout << smallest << " | " << biggest << std::endl;
	return (std::pair<int, int>(smallest, biggest));
}

int main(void)
{
	vector<int>	numbers;

	size_t count = 0;
	int tmp;
	while (!cin.eof())
	{
		if (count < PREAMBLE)
		{
			numbers.push_back(int());
			cin >> numbers[count];
		}
		else
		{
			cin >> tmp;
			bool found = false;
			for (size_t i = count - PREAMBLE; i < count && !found; i++)
				found = find(numbers, i, tmp);
			if (!found)
			{
				std::pair<int, int>	range = find_weakness(numbers, tmp);
				std::cout << "range start: " << range.first << " | range end: " << range.second << std::endl;
				int sum = 0;
				for (size_t i = range.first; i < range.second; i++)
				{
					std::cout << sum << " + " << numbers[i] << " = " << sum + numbers[i] << std::endl;
					sum += numbers[i];
				}
				std::cout << sum << std::endl;
				std::pair<int, int> smallest_largest = smallest_and_largest(numbers, range.first, range.second);
				std::cout << smallest_largest.first + smallest_largest.second << std::endl;
				break ;
			}
			numbers.push_back(tmp);
		}
		count++;
	}
	std::cout << tmp << std::endl;
	return (0);
}
