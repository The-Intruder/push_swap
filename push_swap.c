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

/* -------------------------------------------------------------------------- */

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		err;

	reset_stack(&stack_a);
	reset_stack(&stack_b);
	system("clear");
	err = init_stack(&stack_a, argc, argv);
	if (err)
		return (-1);
	apply_lis_algo(&stack_a);
	exec_print_op(0, &stack_a, &stack_b);
	push_non_lis_node_to_stackb(&stack_a, &stack_b);
	exec_print_op(0, &stack_a, &stack_b);
	return (0);
}

/* -------------------------------------------------------------------------- */
