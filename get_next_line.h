/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 00:12:59 by wleite            #+#    #+#             */
/*   Updated: 2022/11/22 13:37:12 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/**
 * @brief Reads a line from a file descriptor
 *
 * @param fd File descriptor to read.
 * @return Return a string including \\n if is a line. In case of the file
 * dont have \\n return a string without \\n, NULL if the file is empty
 * or error occurred.
 */
char	*get_next_line(int fd);

#endif
