/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prime_factorial.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:15:49 by jkoupy            #+#    #+#             */
/*   Updated: 2023/10/10 09:59:24 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	isprime(int num)
{
	int	i;

	i = 2;
	while (i <= num / 2)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	next_prime(int num)
{
	if (num == 2)
		return (3);
	num += 2;
	while (!isprime(num))
	{
		num += 2;
	}
	return (num);
}

void	fprime(int num)
{
	int	prime;

	prime = 2;
	if (isprime(num))
	{
		printf("%d", num);
		return ;
	}
	while (num > 1)
	{
		if (num % prime == 0)
		{
			printf("%d", prime);
			num /= prime;
			if (num > 1)
			{
				printf("*");
				continue ;
			}
			break ;
		}
		prime = next_prime(prime);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("\n");
		return (0);
	}
	fprime(atoi(argv[1]));
	return (0);
}

/*
Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there is one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$
 */


