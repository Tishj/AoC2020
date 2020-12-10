/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day1part1.ts                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 10:35:18 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/12/01 11:37:59 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

var values: number[] = [];
rl.on('line', function(line)
	{
		values.push(parseInt(line));
	}
);

rl.on('close');

