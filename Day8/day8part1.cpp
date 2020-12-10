/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day8part1.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/08 07:21:56 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/12/08 15:17:26 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class	console
{
	private:
		int				pointer;
		int				value;
		map<int, int>	count;
		vector<string>	instructions;
		int	amount()
		{
			int pos = instructions[pointer].find_last_of("+-");
			string raw = instructions[pointer].substr(pos + 1, instructions[pointer].size() - (pos + 1));
			return (stoi(raw) * ((instructions[pointer][pos] == '+') ? 1 : -1));
		}
		void	nop()
		{
			pointer++;
		}
		void	acc()
		{
			value += amount();
			pointer++;
		}
		void	jump()
		{
			pointer += amount();
		}
	public:
		console(vector<string>& instructions) : pointer(0), value(0), instructions(instructions) {}
		console(const console& other) : pointer(other.pointer), value(other.value), instructions(other.instructions), count(other.count) {}
		console(const console& other, vector<string>& instructions) : pointer(other.pointer), value(other.value), instructions(instructions), count(other.count) {}
		int getpos()
		{
			return (this->pointer);
		}
		int getvalue()
		{
			return (this->value);
		}
		int run(bool original)
		{
			bool finite = true;
			while (pointer < instructions.size() && finite)
			{
				if (count[pointer]++ != 0)
				{
					finite = false;
					break;
				}
				string type = instructions[pointer].substr(0, 3);
				if (type == "acc")
					acc();
				else if (type == "nop")
				{
					if (original) //try to swap the instruction and run it
					{
						vector<string> dup(this->instructions);
						dup[pointer][0] = 'j';
						dup[pointer][1] = 'm';
						dup[pointer][2] = 'p';
						console attempt(*this, dup);
						attempt.count[pointer]--;
						int res = attempt.run(false);
						if (res != -1)
						{
							std::cout << "changed pointer: " << pointer << std::endl;
							return (res);
						}
					}
					nop();
				}
				else if (type == "jmp")
				{
					if (original)
					{
						vector<string> dup(this->instructions);
						dup[pointer][0] = 'n';
						dup[pointer][1] = 'o';
						dup[pointer][2] = 'p';
						console attempt(*this, dup);
						attempt.count[pointer]--;
						int res = attempt.run(false);
						if (res != -1)
						{
							std::cout << "changed pointer: " << pointer << std::endl;
							return (res);
						}
					}
					jump();
				}
			}
			return ((finite) ? this->value : -1);
		}
};

int main(void)
{
	vector<string>	instructions;

	map<int, int>	instruction_count;
	while (!cin.eof())
	{
		instructions.push_back(std::string());
		getline(cin, instructions[instructions.size() - 1]);
	}
	console			handheld(instructions);
	std::cout << handheld.run(true) << std::endl;
	return (0);
}
