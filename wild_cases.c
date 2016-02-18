/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wild_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 12:58:39 by thifranc          #+#    #+#             */
/*   Updated: 2016/02/16 17:33:04 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_all.h"

int		ft_line_len(char *str)
{
	int		red;
	int		ct;
	int		fd;
	char	buf;

	ct = 0;
	fd = open(str, O_RDONLY);
	red = read(fd, &buf, 1);
	while (buf != '\n' && red != 0 && red != -1 && fd != -1)
		red = read(fd, &buf, 1);
	red = read(fd, &buf, 1);
	while (red != 0 && red != -1 && fd != -1 && buf != '\n')
	{
		ct++;
		red = read(fd, &buf, 1);
	}
	close(fd);
	if (buf == '\n')
		return (ct);
	else
		return (0);
}

int		ft_atoi(char *str, int pos)
{
	int i;
	int nb1;
	int nb2;

	i = 0;
	nb2 = 0;
	while ('0' <= str[i] && str[i] <= '9' && i < pos)
	{
		nb1 = str[i] - 48;
		nb2 = nb2 * 10 + nb1;
		i++;
	}
	if (i != pos)
		return (-1);
	else
		return (nb2);
}

int		ft_data_line(char *str, int nb2)
{
	char	*tmp;
	int		red;
	int		y;

	if (!(tmp = (char*)malloc(sizeof(char) * 10)))
		return (0);
	g_fd = open(str, O_RDONLY);
	red = read(g_fd, tmp, 1);
	y = 0;
	while (tmp[y] != '\n' && red != 0 && red != -1 && g_fd != -1)
	{
		y++;
		red = read(g_fd, tmp + y, 1);
	}
	if (y >= 3)
	{
		g_code[2] = tmp[y - 1];
		g_code[1] = tmp[y - 2];
		g_code[0] = tmp[y - 3];
		nb2 = ft_atoi(tmp, y - 3);
	}
	if (nb2 <= 0)
		return (0);
	return (nb2);
}

int		char_test(void)
{
	int i;

	i = 0;
	while (i <= g_line_len &&
			(g_char_buf[i] == g_code[0] || g_char_buf[i] == g_code[1]))
		i++;
	if (i == g_line_len)
		return (1);
	else
		return (0);
}

int		ft_wild_cases(char *str)
{
	int		i;
	int		red;

	if (ft_data_line(str, 0) == 0 || ft_line_len(str) == 0)
		return (ft_error());
	g_nb_line = ft_data_line(str, 0);
	g_line_len = ft_line_len(str);
	if (!(g_char_buf = (char*)malloc(sizeof(char) * g_line_len + 1)))
		return (0);
	if (!(g_int_tab = (int*)malloc(sizeof(int) * g_line_len)))
		return (0);
	red = read(g_fd, g_char_buf, g_line_len + 1);
	i = 0;
	while (i < g_nb_line && red == (g_line_len + 1) && char_test() == 1)
	{
		red = read(g_fd, g_char_buf, g_line_len + 1);
		i++;
	}
	close(g_fd);
	if (i == g_nb_line || g_nb_line == 1 || g_line_len == 1)
		return (1);
	else
		return (ft_error());
}
