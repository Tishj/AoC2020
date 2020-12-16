/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day12part2.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/09 09:40:58 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/12/13 14:54:43 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cmath>

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
	coord(int x, int y) : x(x), y(y) {}
};

class ship
{
	private:
		int		direction;
		coord	pos;
		coord	offset;
		double	deg2rad(int degrees)
		{
			return (degrees * (M_PI / 180));
		}
		void	adjust_directions(char type, int amount)
		{
			if (type == 'L' || type == 'R')
			{
				coord newoffset;
				if ((type == 'L' && amount == 90) || (type == 'R' && amount == 270))
				{
					newoffset.x = -offset.y;
					newoffset.y = offset.x;
				}
				if ((type == 'L' && amount == 270) || (type == 'R' && amount == 90))
				{
					newoffset.x = offset.y;
					newoffset.y = -offset.x;
				}
				if (amount == 180)
				{
					newoffset.x = -offset.x;
					newoffset.y = -offset.y;
				}
				offset = newoffset;
			}
			else
			{
				if (type == 'N')
					offset.y += amount;
				if (type == 'E')
					offset.x += amount;
				if (type == 'S')
					offset.y -= amount;
				if (type == 'W')
					offset.x -= amount;
			}
		}
		void	adjust_pos(int amount)
		{
			pos.x += offset.x * amount;
			pos.y += offset.y * amount;
		}
	public:
		ship() : pos(0, 0), offset(10, 1) {}
		coord	get_pos()
		{
			return (this->pos);
		}
		coord	get_offset()
		{
			return (this->offset);
		}
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

	while (!ferry.move())
	{
		std::cout << ferry.get_pos().x << " " << ferry.get_pos().y << std::endl;
		std::cout << "offset: " << ferry.get_offset().x << " " << ferry.get_offset().y << std::endl;
	}
	coord	final_pos = ferry.get_pos();
	std::cout << abs(final_pos.x) + abs(final_pos.y) << std::endl;
	return (0);
}
