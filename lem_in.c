/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 02:26:55 by gdanylov          #+#    #+#             */
/*   Updated: 2018/06/23 02:26:56 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft/includes/libft.h"

int				check_first(t_s *s, char *buff)
{
	t_list *one;

	while (get_next_line(0, &buff) > 0)
	{
		// ft_printf("\nbbbb1>>%s\n", buff);
		one = ft_lstnew(NULL, 0);
		one->content = buff;
		ft_lstadd(&s->print, one);
		if (check_start_end(buff) != 0)
		{
			// error_exit("First line is not a number of ants");
			error_exit("ERROR");
			return (1);
		}
		else if (check_comment(buff) == 1)
		{
			// ft_strdel(&buff);
			continue ;
		}
		else if (check_right(s, buff) == 1)
			break ;
		else
		{
			// error_exit("Not enough datas of ants or some other error");
			error_exit("ERROR");
			return (1);
		}
	}
	return (0);
}

void			check_second(t_s *s, char *buff)
{
	t_list *sec;

	while (get_next_line(0, &buff) > 0)
	{
		// ft_printf("\nbbbb2>>%s\n", buff);
		sec = ft_lstnew(NULL, 0);
		sec->content = buff;
		ft_lstadd(&s->print, sec);
		if (check_start_end(buff) == 1)
			check_double_start(s, buff);
		else if (check_start_end(buff) == 2)
			check_double_end(s, buff);
		else if (buff[0] != '#' && ft_strchr(buff, '-') != NULL)
		{
			if (check_connect(s, buff) == 0)
				check_other_coords(s, buff);
				// error_exit("Some errors with connections");
			else
			{
				free_m_connect(s);
				// ft_strdel(&buff);
			}
			// break ;
		}
		// ft_printf("")
		else if (buff[0] != '#')
			check_other_coords(s, buff);
		// else if (buff[0] == '#' && check_start_end(buff) == 0)
		// 	ft_strdel(&buff);
	}
	check_null_st_en(s);
}

int additional_verification(t_s *s)
{
	if (s->li->connect == NULL)
		return (0);
	else if (s->li_start->connect == NULL)
		return (0);
	else if (s->li_end->connect == NULL)
		return (0);
	else
		return (1);
}

void			check_third(t_s *s, char *buff)
{
	t_list *thi;

	while (get_next_line(0, &buff) > 0)
	{
		thi = ft_lstnew(NULL, 0);
		thi->content = buff;
		ft_lstadd(&s->print, thi);
		if (check_start_end(buff) == 1 || check_start_end(buff) == 2)
			// error_exit("error in check_third 1");
			error_exit("ERROR");
		else if (buff[0] != '#')
		{
			if (check_connect(s, buff) == 0)
			{
				// ft_strdel(&buff);
				// error_exit("error in check_connect 2");
				error_exit("ERROR");
			}
			// ft_strdel(&buff);
		}
		else if (additional_verification(s) == 0)
			error_exit("ERROR");
		// else if (buff[0] == '#' && check_start_end(buff) == 0)
		// 	ft_strdel(&buff);
	}
	// ft_strdel(&buff);
}

int				main(void)
{
	t_s			s;
	char		*buff;
	int			i;

	i = 0;
	buff = NULL;
	// s->print = ft_lstnew(NULL, 0);
	cle_s(&s);
	if (check_first(&s, buff) == 1)
		return (0);
	// func_print(s.print);
	check_second(&s, buff);
	check_third(&s, buff);
	func_print(s.print);
	// if (additional_verification(&s) == 1)
	// 	error_exit("ERROR");
		// error_exit("connects are no exist");
	create_queue(&s);
	from_end(&s);
	go_ants(&s);
	system("leaks lem-in");
}
