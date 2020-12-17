/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day14part2.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/17 18:52:52 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/12/17 20:41:03 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdio.h>

using namespace std;

class	mask
{
	private:
		vector<bool>	setbits;
		vector<bool>	bits;
	public:
		void	update(string newMask)
		{
			vector<bool>	setbits(vector<bool>(36, false));
			vector<bool>	bits(vector<bool>(36, true));
			for (size_t i = 0; i < newMask.size(); i++)
			{
				if (newMask[i] != 'X')
				{
					setbits[i] = true;
					bits[i] = (newMask[i] == '1');
				}
			}
			this->setbits = setbits;
			this->bits = bits;
		}
		mask() : setbits(vector<bool>(36, false)), bits(vector<bool>(36, true)) {}
		void	apply_value(map<size_t, size_t>& memory, size_t value, size_t address, int i, size_t result)
		{
			if (i == 36)
			{
				dprintf(1, "memory[%ld] = %ld\n", result, value);
				memory[result] = value;
				return ;
			}
			int bit = (address >> (35 - i)) & 1;
			if (!setbits[i])
			{
				apply_value(memory, value, address, i + 1, (result * 2) + !bit);
				apply_value(memory, value, address, i + 1, (result * 2) + bit);
				return ;
			}
			if (setbits[i] && bits[i])
				bit = 1;
			apply_value(memory, value, address, i + 1, (result * 2) + bit);
		}
		size_t	apply(size_t raw)
		{
			size_t output = 0;
			for (int i = 0; i < 36; i++)
			{
				int bit = (raw >> (35 - i)) & 1;
				if (setbits[i] && ((bit && !bits[i]) || (!bit && bits[i])))
					bit = !bit;
				output = (output * 2) + bit;
			}
			return (output);
		}
};

int main(void)
{
	mask	bitmask;

	map<size_t, size_t>	memory;
	while (!cin.eof())
	{
		string tmp;
		getline(cin, tmp);
		if (tmp[1] == 'a')
			bitmask.update(tmp.substr(7, 36));
		else
		{
			string index_str = tmp.substr(4, tmp.find(']') - 4);
			size_t index = stoi(index_str);
			std::cout << "Index: " << index << std::endl;
			int start_of_num = tmp.find_last_of(' ');
			int value = stoi(tmp.substr(start_of_num, tmp.size() - start_of_num));
			std::cout << value << std::endl;
//			size_t applied = bitmask.apply(value);
			size_t applied = value;
			std::cout << "after mask: " << applied << std::endl;
//			memory[index] = applied;
			bitmask.apply_value(memory, applied, index, 0, 0);
		}
	}
	size_t result = 0;
	for (auto it = memory.begin(); it != memory.end(); it++)
		result += it->second;
	std::cout << result << std::endl;
	return (0);
}
