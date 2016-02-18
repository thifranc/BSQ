/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 14:52:21 by thifranc          #+#    #+#             */
/*   Updated: 2016/02/16 17:23:28 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALL_H
# define FT_ALL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct	s_struct
{
	int			length;
	int			x_pos;
	int			y_pos;
}				t_sqr;

char			*g_char_buf;
int				*g_int_tab;
int				g_line_len;
int				g_fd;
int				g_nb_line;
char			g_code[3];
t_sqr			g_sqr;

void			ft_opt_bsq(void);
int				ft_atoi(char *str, int pos);
void			find_sqr2(char *str);
char			*ft_go_beg2(char *str);
char			*ft_strncpy(char *str, char *g_char_buf);
void			first_line2(void);
int				ft_wild_cases2(char *s, int i);
int				ft_data_line2(char *str);
int				ft_line_len2(char *str);
char			*ft_get_file(void);
char			*ft_strdup(char *s, int ct, int flag);
int				ft_strlen(char *s);
void			ft_bsq_opt(void);
void			print_sqr2(char *str);
int				ft_wild_cases(char *str);
int				ft_data_line(char *str, int nb2);
int				ft_error(void);
int				char_test(void);
int				ft_line_len(char *str);
void			get_new_block(void);
int				find_max(int i, int nb);
int				test_gauche(int i, int nb);
int				test_droit(int i, int nb);
int				main(int ac, char **av);
void			print_sqr(char *str);
void			first_line(void);
void			find_sqr(char *str);
void			print_next_line(int i);

#endif
