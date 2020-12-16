/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day12part1.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/09 09:40:58 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/12/12 08:55:53 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

enum	direction
{
	NORTH,
	EAST,
	SOUTH,
	WEST,
};

struct coord
{
	int x;
	int y;
	coord() : x(0), y(0) {}
};

class ship
{
	private:
		int		direction;
		coord	pos;
		void	adjust_directions(char type, int amount)
		{
			if (type == 'L')
				amount = 360 - amount;
			if (type == 'L' || type == 'R')
				direction = (direction + (amount / 90)) % 4;
			else
			{
				if (type == 'N')
					pos.y += amount;
				if (type == 'E')
					pos.x += amount;
				if (type == 'S')
					pos.y -= amount;
				if (type == 'W')
					pos.x -= amount;
			}
		}
		void	adjust_pos(int amount)
		{
			if (direction == NORTH)
				pos.y += amount;
			if (direction == EAST)
				pos.x += amount;
			if (direction == SOUTH)
				pos.y -= amount;
			if (direction == WEST)
				pos.x -= amount;
		}
	public:
		coord	get_pos()
		{
			return (this->pos);
		}
		ship() : direction(EAST) {}
		bool	move()
		{
			char	tmp;
			int		amount;

			cin >> tmp >> amount;
			if (tmp != 'F')
				adjust_directions(tmp, amount);
			else
				adjust_pos(amount);
			if (cin.eof())
				return (true);
			return (false);
		}
};

int main(void)
{
	ship	ferry;

	while (!ferry.move()) {}
	coord	final_pos = ferry.get_pos();
	std::cout << abs(final_pos.x) + abs(final_pos.y) << std::endl;
	return (0);
}
