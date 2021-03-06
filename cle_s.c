/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cle_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 16:35:32 by gdanylov          #+#    #+#             */
/*   Updated: 2018/06/23 16:35:34 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		cle_s(t_s *s)
{
	s->number_of_ants = 0;
	s->number_of_room_start = NULL;
	s->two_hash = 0;
	s->check_number = NULL;
	s->check = 0;
	s->spaces_start = 0;
	s->spaces_end = 0;
	s->spaces_other = 0;
	s->hyphen = 0;
	s->start_x = 0;
	s->start_y = 0;
	s->number_of_room_end = NULL;
	s->end_x = 0;
	s->end_y = 0;
	s->other_x = 0;
	s->other_y = 0;
	s->li = NULL;
	s->li_queue_tail = NULL;
	s->li_queue_head = NULL;
	s->li_start = NULL;
	s->li_end = NULL;
	s->connect = NULL;
	s->start = 0;
	s->end = 0;
	s->print = NULL;
}

void		cle_m(t_s *s)
{
	int i;

	i = 0;
	while (s->m[i])
	{
		s->m[i] = NULL;
		i++;
	}
}
