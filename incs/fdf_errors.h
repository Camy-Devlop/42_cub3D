/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_errors.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alephoen <alephoen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 11:56:50 by alephoen          #+#    #+#             */
/*   Updated: 2025/09/06 17:14:02 by alephoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_ERRORS_H
# define FDF_ERRORS_H

# define ERROR_PARSING_0	"Error Parsing! Syscall Fail!"
# define ERROR_N_PARSING_0	0

# define ERROR_PARSING_1	"Error Parsing Map is Empty!"
# define ERROR_N_PARSING_1	1

# define ERROR_PARSING_2	"Error Parsing Map has Empty Line"
# define ERROR_N_PARSING_2	2

# define ERROR_PARSING_3	"Error Parsing Map has invalid character"
# define ERROR_N_PARSING_3	3

# define ERROR_PARSING_4	"Error Parsing! Z is not an integer!"
# define ERROR_N_PARSING_4	4

# define ERROR_PARSING_5	"Error Parsing! Map's Width is not uniformed!"
# define ERROR_N_PARSING_5	5

// # define ERROR_PARSING_5	"Error Parsing! Map's Width Too Long!"
// # define ERROR_N_PARSING_5	5

// # define ERROR_PARSING_6	"Error Parsing! Map's Width Too Short!"
// # define ERROR_N_PARSING_6	6

# define ERROR_PARSING_7	"Error Parsing! Map is missing new line at eol!"
# define ERROR_N_PARSING_7	7

# define ERROR_SYS_CALL	"Error! Syscall Fail!"
# define ERROR_N_SYS_CALL	6

#endif
