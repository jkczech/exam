/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:53:09 by jkoupy            #+#    #+#             */
/*   Updated: 2023/10/09 15:05:06 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

void	fill(char **tab, t_point size, t_point begin, char to_fill)
{
	if (begin.x < 0 || begin.x >= size.x || begin.y < 0 || begin.y >= size.y)
		return ;
	if (tab[begin.y][begin.x] == to_fill)
		tab[begin.y][begin.x] = 'F';
	else
		return ;
	fill(tab, size, (t_point){begin.x - 1, begin.y}, to_fill);
	fill(tab, size, (t_point){begin.x + 1, begin.y}, to_fill);
	fill(tab, size, (t_point){begin.x, begin.y - 1}, to_fill);
	fill(tab, size, (t_point){begin.x, begin.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

void	print_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab && tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			printf("%c ", tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

char **make_area(char *zone[]) {
    int i;
    char **area = (char **)malloc(sizeof(char *) * (5 + 1)); // 5 rows + 1 for NULL terminator

    if (area == NULL) {
        perror("Failed to allocate memory for area");
        exit(1);
    }

    for (i = 0; i < 5; i++) {
        area[i] = (char *)malloc(strlen(zone[i]) + 1); // +1 for the null terminator

        if (area[i] == NULL) {
            perror("Failed to allocate memory for area row");
            exit(1);
        }

        strcpy(area[i], zone[i]);
    }

    area[5] = NULL; // NULL-terminate the array of strings

    return area;
}

int main(void)
{
    char **area;
    t_point size = { 8, 5 };
    t_point begin = { 0, 0 };
    char *zone[] = {
        "11111111",
        "10001001",
        "10010001",
        "10110001",
        "11100001"
    };
    area = make_area(zone);
    print_tab(area);
    flood_fill(area, size, begin);
    printf("\n");
    print_tab(area);
    return (0);
}


/*
Assignment name  : flood_fill
Expected files   : *.c, *.h
Allowed functions: -
--------------------------------------------------------------------------
Write a function that takes a char ** as a 2-dimensional array of char, a
t_point as the dimensions of this array and a t_point as the starting point.
Starting from the given 'begin' t_point, this function 'colors' an entire
by replacing characters inside by the character 'F'. A zone is an ensemble of
zone the same character delimitated horizontally and vertically
by other characters. The flood_fill function won't 'color' in diagonal.
The flood_fill function will be prototyped like this:

The t_point structure is available inside the "t_point.h" file attached
to this assignment. We will use our "t_point.h" for graduation.
Example :
$> cat test_main.c
#include "test_functions.h"
#include "flood_fill.h"
int main(void)
{
    char **area;
    t_point size = { 8, 5 };
    t_point begin = { 2, 2 };
    char *zone[] = {
        "11111111",
        "10001001",
        "10010001",
        "10110001",
        "11100001"
    };
    area = make_area(zone);
    print_tab(area);
    flood_fill(area, size, begin);
    putc('\n');
    print_tab(area);
    return (0);
}
$> gcc flood_fill.c test_main.c test_functions.c -o flood_fill ; ./flood_fill
1 1 1 1 1 1 1 1
1 0 0 0 1 0 0 1
1 0 0 1 0 0 0 1
1 0 1 1 0 0 0 1
1 1 1 0 0 0 0 1
1 1 1 1 1 1 1 1
1 F F F 1 0 0 1
1 F F 1 0 0 0 1
1 F 1 1 0 0 0 1
1 1 1 0 0 0 0 1
$>
*/
