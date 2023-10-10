/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:15:47 by jkoupy            #+#    #+#             */
/*   Updated: 2023/10/10 13:03:22 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

int	intlen(int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		len++;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char	*result;
	int		i;

	i = intlen(nbr);
	result = malloc((i + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[i] = '\0';
	if (nbr == INT_MIN)
	{
		result[1] = '2';
		nbr = -147483648;
	}
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	while (nbr != 0)
	{
		i--;
		result[i] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (result);
}


int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("\n");
		return (0);
	}
	printf("%s", ft_itoa(atoi(argv[1])));
	return (0);
}

/* Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
 */
