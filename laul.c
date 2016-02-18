/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   laul.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:28:27 by thifranc          #+#    #+#             */
/*   Updated: 2016/02/16 17:37:30 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_all.h"

void	first_line(void)
{
	int i;

	i = 0;
	while (i < g_line_len)
	{
		if (g_char_buf[i] == g_code[1])
			g_int_tab[i] = 0;
		else
		{
			if (g_char_buf[i] == g_code[0] && g_sqr.length == 0)
			{
				g_sqr.length = 1;
				g_sqr.x_pos = i;
				g_sqr.y_pos = 0;
			}
			g_int_tab[i] = 1;
		}
		i++;
	}
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_go_beg2(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (str + i + 1);
}

int		ft_error(void)
{
	write(1, "map error\n", 10);
	return (0);
}
