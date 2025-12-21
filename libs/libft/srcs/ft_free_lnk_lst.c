/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lnk_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:11:09 by alephoen          #+#    #+#             */
/*   Updated: 2025/12/06 16:37:46 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stddef.h>

// typedef t_free_fun;

// typedef struct s_node
// {
// 	void			*nod;
// 	struct s_node	*nxt;
// 	struct s_node	*prv;
// }	t_node;

// // void	*free_linked_lst(t_node **lst, t_free_fun free_data)
// void	*free_linked_lst(t_node **lst, void *(*free_data)(t_node *))
// {
// 	t_node	*crt;
// 	t_node	*nxt;

// 	if (!lst)
// 		return (NULL);
// 	crt = *lst;
// 	while (crt)
// 	{
// 		nxt = crt->nxt;
// 		if (free_data)
// 			free_data(crt);
// 		free(crt);
// 		crt = nxt;
// 	}
// 	*lst = NULL;
// 	return (NULL);
// }
