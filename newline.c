/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 18:45:32 by thifranc          #+#    #+#             */
/*   Updated: 2016/02/16 17:35:52 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_all.h"

int		test_droit(int i, int nb)
{
	int back;

	back = i;
	while (i < g_line_len && i < back + nb && g_int_tab[i] >= nb - 1)
		i++;
	if (i == back + nb)
		return (1);
	else
		return (0);
}

int		test_gauche(int i, int nb)
{
	if (i == 0)
		return (0);
	if (g_int_tab[i - 1] == nb)
		return (1);
	else
		return (0);
}

int		find_max(int i, int nb)
{
	if (test_droit(i, nb) == 1 || test_gauche(i, nb) == 1)
		return (nb);
	else
		return (find_max(i, nb - 1));
}

void	print_next_line(int cur_line)
{
	int i;

	i = 0;
	while (i < g_line_len)
	{
		if (g_int_tab[i] == 0 || g_int_tab[i] == -1)
			g_int_tab[i]++;
		else
			g_int_tab[i] = find_max(i, g_int_tab[i] + 1);
		if (g_int_tab[i] > g_sqr.length)
		{
			g_sqr.length = g_int_tab[i];
			g_sqr.x_pos = i;
			g_sqr.y_pos = cur_line;
		}
		i++;
	}
}

void	get_new_block(void)
{
	int i;

	i = 0;
	while (i < g_line_len)
	{
		if (g_char_buf[i] == g_code[1])
			g_int_tab[i] = -1;
		i++;
	}
}
