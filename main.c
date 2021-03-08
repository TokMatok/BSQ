/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:33:37 by msteak            #+#    #+#             */
/*   Updated: 2021/03/08 11:33:39 by msteak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	**ft_create_matrix(int n, int m)
{
	int i, j, count;
	srand(time(0));
	char **matrix = (char**) malloc(n * sizeof(char*) + n * m * sizeof(char));
	matrix[0] = (char*)(matrix + n);
	for (i = 0; i < n; i++) {
		matrix[i] = matrix[0] + i * m;
		count = 0;
		for (j = 0; j < m; j++) {
			if (rand() % 2 == 1 && count < 10)
			{
				matrix[i][j] = 'o';
				count++;
			}
			else
				matrix[i][j] = '.'; 
		}
	}

	return (matrix);
}

void	ft_print_matrix(char **matrix, int n, int m)
{
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%c ", matrix[i][j]);
		}
		printf("\n");
	}
}

// void	ft_init_get_matrix()

void	ft_vector_d(int **d, char **matrix, int i, int m, char *symbols)
{
	int j;

	j = 0;
	if (ft_strlen(symbols) == 0)
	{
		while (i < m)
		{
			(*d)[i] = -1;
			i++;
		}
	}
	else 
	{
		while (j < m)
		{
			if (matrix[i][j] == symbols[0])
				(*d)[j] = i;
			j++;
		}
	}
}

void	ft_vector_d1(int **d, int **d1, int m)
{
	int j;
	int top;
	int	*st;

	j = 0;
	top = -1;
	st = malloc(sizeof(int) * m);
	while (j < m)
	{
		while (top != -1 && (*d)[st[top]] <= (*d)[j])
			top--;
		(*d1)[j] = top == -1 ? -1 : st[top];
		st[++top] = j;
		j++;
	}
	free(st);
}

void	ft_vector_d2(int **d, int **d2, int m)
{
	int j;
	int top;
	int	*st;

	top = -1;
	j = m - 1;
	st = malloc(sizeof(int) * m);
	while (j >= 0) 
	{
		while (top != -1 && (*d)[st[top]] <= (*d)[j])
			top--;
		(*d2)[j] = top == -1 ? m : st[top];
		st[++top] = j;
		j--;
	}
	free(st);
}

int 	*ft_limits_submatrix(int max, int top, int bottom, int left, int rigth)
{
	static int limits[5];
	
	if (max > limits[0])
	{
		limits[0] = max;
		limits[1] = top;
		limits[2] = bottom;
		limits[3] = left;
		limits[4] = rigth;
	}
	return (limits);
}

char	**ft_get_matrix(char **matrix, char *symbols, int n, int m)
{
	int	i;
	int	j;
	int	*d;
	int	*d1;
	int	*d2;
	int	max;

	d = malloc(sizeof(int) * m);
	d1 = malloc(sizeof(int) * m);
	d2 = malloc(sizeof(int) * m);
	i = 0;
	max = 0;
	ft_vector_d(&d, matrix, 0, m, "");
	while (i < n)
	{
		ft_vector_d(&d, matrix, i, m, symbols);
		ft_vector_d1(&d, &d1, m);
		ft_vector_d2(&d, &d2, m);
		j = 0;
		while (j < m)
		{
			ft_limits_submatrix((i - d[j]) * (d2[j] - d1[j] - 1), d[j] + 1, i, d1[j] + 1, d2[j] - 1);
			j++;
		}
		i++;
	}
	return (matrix);
}

int main(void)
{
	char **matrix = ft_create_matrix(30, 30);
	ft_print_matrix(matrix, 30, 30);
	ft_get_matrix(matrix, "oX", 30, 30);
	int *lim = ft_limits_submatrix(-1, 0, 0, 0, 0);
	printf("\n");
	printf("max = %d\n", lim[0]);
	printf("top = %d\n", lim[1]);
	printf("bottom = %d\n", lim[2]);
	printf("left = %d\n", lim[3]);
	printf("right = %d\n", lim[4]);
}

