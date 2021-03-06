/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_ants.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 04:28:02 by gdanylov          #+#    #+#             */
/*   Updated: 2018/08/14 04:28:03 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft/includes/libft.h"

t_list			*get_end_room(t_s *s)
{
	t_list *tmp;

	tmp = s->shortest;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void			func(t_list *ants, int current_ants)
{
	if (ants == NULL)
		return ;
	func(ants->next, ants->content_size);
	if (current_ants != 0)
		ft_printf("L%d-%s", current_ants, ((t_li*)ants->content)->name);
	ants->content_size = current_ants;
}

void func_print(t_list *p)
{
	if (p == NULL)
		return ;
	func_print(p->next);
	ft_printf("%s\n", p->content);
}

void			go_ants(t_s *s)
{
	t_list			*ants;
	t_list			*tmp;
	int				current_ants;
	t_list *shor;

	current_ants = 1;
	ants = s->shortest;
	tmp = get_end_room(s);
	// func_print(s->print);
	ft_printf("\n");
	while (tmp->content_size != (size_t)s->number_of_ants)
	{
		if (current_ants <= s->number_of_ants)
		{
			func(ants, current_ants);
		}
		else
			func(ants, 0);
		current_ants++;
		ft_printf("\n");
	}
	while (s->shortest != NULL)
	{
		shor = s->shortest->next;
		ft_strdel((void*)s->shortest->content);
		free(s->shortest);
		s->shortest = shor;
	}
}
