/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sqr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 12:56:00 by thifranc          #+#    #+#             */
/*   Updated: 2016/02/16 17:37:40 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_all.h"

void	ft_go_beg(char *str)
{
	char	tmp;
	int		red;

	g_fd = open(str, O_RDONLY);
	red = read(g_fd, &tmp, 1);
	while (tmp != '\n' && red != 0 && red != -1)
		red = read(g_fd, &tmp, 1);
}

void	find_sqr(char *str)
{
	int		i;

	i = 0;
	ft_go_beg(str);
	while (i < g_nb_line)
	{
		read(g_fd, g_char_buf, g_line_len + 1);
		if (i == 0)
			first_line();
		else
		{
			get_new_block();
			print_next_line(i);
		}
		i++;
	}
	close(g_fd);
}

void	print_sqr(char *str)
{
	int x;
	int y;

	y = 0;
	ft_go_beg(str);
	while (y < g_nb_line)
	{
		read(g_fd, g_char_buf, g_line_len + 1);
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
	close(g_fd);
}

int		main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac == 1)
		ft_opt_bsq();
	while (i < ac)
	{
		if (ft_wild_cases(av[i]) == 1)
		{
			g_sqr.length = 0;
			find_sqr(av[i]);
			g_sqr.y_pos -= (g_sqr.length - 1);
			print_sqr(av[i]);
			free(g_char_buf);
			free(g_int_tab);
			printf("%d | %d | %d\n", g_sqr.length, g_sqr.x_pos, g_sqr.y_pos);
		}
		i++;
	}
	return (0);
}
