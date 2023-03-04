/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:19:27 by elevy             #+#    #+#             */
/*   Updated: 2022/12/26 10:54:11 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_strlen(char *str);
int		ft_strlen_nl(char *str);
int		ft_get_nl(char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*read_file(char *buffer, int fd);
char	*get_new_buffer(char *buffer);
char	*get_line(char *buffer);
char	*get_next_line(int fd);
#endif
