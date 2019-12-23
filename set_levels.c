/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_levels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:03:15 by tmelia            #+#    #+#             */
/*   Updated: 2019/12/23 17:03:18 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		clear_stack(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp && (tmp)->next)
	{
		tmp = tmp->next;
		free(stack);
		stack = tmp;
	}
	if (stack)
		free(stack);
}

t_stack		*copy_stack(t_stack *stack)
{
	t_stack *tmp;
	t_stack *a;

	a = stack;
	tmp = NULL;
	if (!stack)
		return (NULL);
	if (a)
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		tmp->next = NULL;
		tmp->head = tmp;
	}
	while (a && a->next)
	{
		tmp->x = a->x;
		tmp->next = (t_stack *)malloc(sizeof(t_stack));
		tmp->head = tmp->head;
		tmp->next->head = tmp->head;
		tmp = tmp->next;
		tmp->next = NULL;
		a = a->next;
	}
	tmp->x = a->x;
	return (tmp->head);
}

t_stack		*set_one_level(t_stack *tmp, t_stack *stack,
		int mas[3], t_room *rooms)
{
	int		q;

	while ((q = get_next_room(rooms, tmp->x, mas[1])) >= 0)
	{
		rooms[q].visit = mas[1];
		rooms[q].lvl = mas[0];
		if (q != mas[2])
			stack = lst_create(stack, q);
	}
	return (stack);
}

void		set_levels(t_room *rooms, int visit, t_str *lem)
{
	t_stack			*stack;
	t_stack			*tmp;
	int				mas[3];

	stack = lst_create(NULL, lem->start);
	tmp = copy_stack(stack);
	clear_stack((stack)->head);
	stack = NULL;
	mas[0] = 1;
	while (tmp)
	{
		mas[1] = visit;
		mas[2] = lem->end;
		stack = set_one_level(tmp, stack, mas, rooms);
		tmp->next ? tmp = tmp->next : 0;
		if (!tmp->next)
		{
			mas[0]++;
			stack = set_one_level(tmp, stack, mas, rooms);
			clear_stack((tmp)->head);
			tmp = copy_stack(stack);
			stack ? clear_stack((stack)->head) : 0;
			stack = NULL;
		}
	}
}
