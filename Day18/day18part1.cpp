/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day18part1.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/18 12:14:44 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/12/19 19:09:15 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>

using namespace std;

unsigned long		result(string expression, int& i);

unsigned long		value(string expression, int &i)
{
	unsigned long res;
	for (; expression[i] == ' '; i++) {}
	if (expression[i] == '(')
	{
		res = result(expression, ++i);
		i++;
		return (res);
	}
	size_t len = 0;
	for (; expression[i + len] >= '0' && expression[i + len] <= '9'; len++) {}
	string raw = expression.substr(i, len);
	i += len;
	res = stoi(raw);
	return (res);
}

unsigned long		result(string expression, int& i)
{
	int start = i;
	unsigned long res = value(expression, i);
	for (;i < expression.size() && expression[i] != ')';)
	{
		if (expression[i] == ' ')
			i++;
		else if (expression[i] == '+')
			res += value(expression, ++i);
		else if (expression[i] == '*')
			res *= value(expression, ++i);
	}
	return (res);
}

int main(void)
{
	unsigned long total = 0;
	while (!cin.eof())
	{
		int index = 0;
		string tmp;
		getline(cin, tmp);
		std::cout << "EXPRESSION: " << tmp << std::endl;
		unsigned long res = result(tmp, index);
		std::cout << res << std::endl;
		total += res;
	}
	std::cout << "TOTAL: " << total << std::endl;
	return (0);
}
