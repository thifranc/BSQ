/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 13:49:21 by thifranc          #+#    #+#             */
/*   Updated: 2016/02/16 17:32:46 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_all.h"

void	print_sqr2(char *str)
{
	int x;
	int y;

	y = 0;
	str = ft_go_beg2(str);
	while (y < g_nb_line)
	{
		str = ft_strncpy(str, g_char_buf);
		x = 0;
		if (y >= g_sqr.y_pos && y < g_sqr.y_pos + g_sqr.length)
			while (x < g_sqr.length)
			{
				g_char_buf[g_sqr.x_pos + x] = g_code[2];
				x++;
			}
		write(1, g_char_buf, g_line_len);
		write(1, "\n", 1);
		y++;
	}
}

char	*ft_strdup(char *s, int ct, int flag)
{
	int		i;
	char	*s2;

	i = 0;
	if (flag == 1)
		ct += 10;
	if (!(s2 = (char*)malloc(sizeof(char) * (ct))))
		return (NULL);
	while (i < ct && s[i])
	{
		s2[i] = s[i];
		i++;
	}
	if (s[i] == '\0')
		s2[i] = '\0';
	return (s2);
}

char	*ft_get_file(void)
{
	char	*lol;
	char	*lol2;
	int		ct;
	int		red;

	ct = 10;
	if (!(lol = (char*)malloc(sizeof(char) * (ct))))
		return (NULL);
	red = read(0, lol, 10);
	while (red != 0 && red != -1 && red == 10)
	{
		lol2 = ft_strdup(lol, ct, 1);
		red = read(0, lol2 + ct, 10);
		ct += 10;
		lol = ft_strdup(lol2, ct, 0);
	}
	return (lol);
}

int		ft_data_line2(char *str)
{
	char	*str2;
	int		y;
	int		nb2;

	if (!(str2 = (char*)malloc(sizeof(char) * 10)))
		return (0);
	y = 0;
	nb2 = 0;
	while (str[y] != '\n')
	{
		str2[y] = str[y];
		y++;
	}
	if (y >= 3)
	{
		g_code[2] = str2[y - 1];
		g_code[1] = str2[y - 2];
		g_code[0] = str2[y - 3];
		nb2 = ft_atoi(str2, y - 3);
	}
	if (nb2 <= 0)
		return (0);
	return (nb2);
}

int		ft_wild_cases2(char *s, int i)
{
	int		ct;

	if (ft_data_line2(s) == 0 || ft_line_len2(s) == 0)
		return (ft_error());
	g_nb_line = ft_data_line2(s);
	g_line_len = ft_line_len2(s);
	if (!(g_char_buf = (char*)malloc(sizeof(char) * g_line_len + 1)))
		return (0);
	if (!(g_int_tab = (int*)malloc(sizeof(int) * g_line_len)))
		return (0);
	s = ft_go_beg2(s);
	ct = 0;
	while (s[i] && (s[i] == g_code[0] || s[i] == g_code[1] || s[i] == '\n'))
	{
		if (s[i] == '\n' && ct % g_line_len == 0)
			i++;
		if (s[i] == '\n' && ct % g_line_len != 0)
			return (ft_error());
		ct++;
		i++;
	}
	if (ct / g_line_len == g_nb_line || g_nb_line == 1 || g_line_len == 1)
		return (1);
	else
		return (ft_error());
}
