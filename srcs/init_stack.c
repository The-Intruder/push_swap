/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:36:02 by mnaimi            #+#    #+#             */
/*   Updated: 2022/02/21 09:42:49 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* -------------------------------------------------------------------------- */

static char	**get_patched_argv(int argc, char **argv)
{
	int		i;
	char	*argv_concat;
	void	*dummy_ptr;
	char	**new_argv;

	i = 1;
	argv_concat = (char *)ft_calloc(1, sizeof(char));
	while (i < argc)
	{
		if (!argv[i][0] || !arg_is_valid(argv[i]))
			return (p_err(""), free(argv_concat), exit(-1), NULL);
		dummy_ptr = argv_concat;
		argv_concat = ft_strjoin(argv_concat, argv[i++]);
		free(dummy_ptr);
		dummy_ptr = argv_concat;
		argv_concat = ft_strjoin(argv_concat, " ");
		free(dummy_ptr);
	}
	new_argv = ft_split(argv_concat, ' ');
	if (trim_unwanted_chars(new_argv))
		return (free_newly_created_argv(new_argv), free(argv_concat), NULL);
	return (free(argv_concat), new_argv);
}

/* -------------------------------------------------------------------------- */

static t_node	*init_stack_node(char *asci_nbr)
{
	t_node	*node;

	node = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node->prev = NULL;
	node->value = ft_atoi(asci_nbr);
	node->var_a = 1;
	node->var_b = -1;
	node->var_c = 1;
	node->next = NULL;
	return (node);
}

/* -------------------------------------------------------------------------- */

static int	link_stack_nodes(t_stack *stack, char **argv)
{
	t_node	*node;
	int		i;

	i = 0;
	node = NULL;
	while (argv[i])
	{
		node = init_stack_node(argv[i]);
		if (!node)
			return (free_exit(stack, NULL), 0);
		if (stack->tail)
		{
			stack->tail->next = node;
			node->prev = stack->tail;
			node->next = stack->head;
		}
		else if (i == 0)
			stack->head = node;
		stack->tail = node;
		++i;
	}
	stack->size = i;
	return (0);
}

/* -------------------------------------------------------------------------- */

int	handle_exeptions(t_stack *stack)
{
	t_node	*node;
	int		i;

	i = 0;
	node = get_lowest_value_node(stack);
	while (i++ <= 3)
	{
		if (stack_is_sorted_from_node(node, stack->size))
			push_lowest_to_head(stack, NULL);
		else
			check_exec_op(SA, stack, NULL, 1);
	}
	return (0);
}

/* -------------------------------------------------------------------------- */

int	init_stack(t_stack	*stack, int argc, char **argv)
{
	char	**new_argv;
	int		err;

	err = 0;
	new_argv = get_patched_argv(argc, argv);
	if (!new_argv || handle_err(argc, new_argv))
		return (-1);
	err = link_stack_nodes(stack, new_argv);
	if (err)
		return (-1);
	patch_stack(stack);
	free_newly_created_argv(new_argv);
	return (0);
}

/* -------------------------------------------------------------------------- */
