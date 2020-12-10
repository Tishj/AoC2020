/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day1part1.ts                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 10:35:18 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/12/01 11:36:39 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
var readline = require('readline');
var rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});
var values = [];
rl.on('line', function (line) {
    values.push(parseInt(line));
});
rl.on('close', function () {
    console.log(values);
});
