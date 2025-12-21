/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_signal_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 03:44:47 by alephoen          #+#    #+#             */
/*   Updated: 2025/11/24 19:47:38 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <signal_handler.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Static flag variable visible only within this source file
static volatile sig_atomic_t	g_is_sigint = 0;

// this must have this signature that's why I do (void)sig;
void	set_sig_int(int sig)
{
	(void) sig;
	g_is_sigint = 1;
}

bool	get_is_sigint(void)
{
	return (g_is_sigint);
}

void	reset_is_sigint(void)
{
	g_is_sigint = 0;
}

// Setup the signal handler;
// void	set_sigint_handler(void)
// {

// }

void	set_sigint_handler(void)
{
	signal(SIGINT, set_sig_int);
}
*/
