/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 11:16:44 by exam              #+#    #+#             */
/*   Updated: 2019/06/11 18:51:55 by lolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "brackets.h"

void ft_process(char *str)
{
	int err = 0;
	int i = 0;
	int j = 0;
	char c[4096];

		while (!err && str[i] != '\0')
		{
			if (IS_OPEN(str[i]))
				c[++j] = str[i];
			else if (IS_CLOSE(str[i]))
			{
				if ((str[i] == ')' && c[j] != '(') ||
					(str[i] == '}' && c[j] != '{') ||
					(str[i] == ']' && c[j] != '[')) 
					err = 1;
				else
				{
					c[j] = ' ';
					j--;
				}
			}	
		i++;
		}
		if (err)
	   		write(1, "Error\n", 6);		
		else
	   		write(1, "OK\n", 3);
}

int main(int argc, char *argv[])
{
	int i = 0;

	if (argc == 1)
		write(1, "\n", 1);
	else
	{
		while (++i < argc)
			ft_process(argv[i]);
	}
	return (0);
}
