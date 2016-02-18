/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:32:19 by thifranc          #+#    #+#             */
/*   Updated: 2016/02/16 17:35:23 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_all.h"

int		ft_line_len2(char *str)
{
	int		ct;
	int		i;

	ct = 0;
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	i++;
	while (str[i] != '\n' && str[i])
	{
		ct++;
		i++;
	}
	if (str[i] == '\n')
		return (ct);
	else
		return (0);
}

void	first_line2(void)
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

char	*ft_strncpy(char *str, char *g_char_buf)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i])
	{
		g_char_buf[i] = str[i];
		i++;
	}
	g_char_buf[i] = '\n';
	return (str + i + 1);
}

void	find_sqr2(char *str)
{
	int		y;

	str = ft_go_beg2(str);
	y = 0;
	while (y < g_nb_line)
	{
		str = ft_strncpy(str, g_char_buf);
		if (y == 0)
			first_line();
		else
		{
			get_new_block();
			print_next_line(y);
		}
		y++;
	}
}

void	ft_opt_bsq(void)
{
	char	*str;

	str = ft_get_file();
	if (ft_wild_cases2(str, 0) == 1)
	{
		g_sqr.length = 0;
		find_sqr2(str);
		g_sqr.y_pos -= (g_sqr.length - 1);
		print_sqr2(str);
	}
}
