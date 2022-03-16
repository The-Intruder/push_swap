/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:36:02 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/21 09:42:49 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

void	print_stack_min(t_stack *stack_a)
{
	t_uint	i;
	t_node	*node;
	i = 0;
	node = stack_a->head;
	while (i++ < stack_a->size)
	{
		ft_printf("value: %5d\tvar_a: %5d\tvar_b: %5d\tvar_c: %5d\n", \
			node->value, node->var_a, node->var_b, node->var_c);
		node = node->next;
	}
}

/* -------------------------------------------------------------------------- */

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		err;

	reset_stack(&stack_a);
	reset_stack(&stack_b);
	err = init_stack(&stack_a, argc, argv);
	if (err)
		return (-1);
	if (!stack_b.size && stack_is_sorted(&stack_a))
		return (0);
	apply_lis_algo(&stack_a, &stack_b);
	sort_numbers(&stack_a, &stack_b);
	//print_stack_min(&stack_a);
	return (0);
}

/* -------------------------------------------------------------------------- */
