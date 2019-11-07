/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 13:48:22 by ede-thom          #+#    #+#             */
/*   Updated: 2019/08/20 10:47:05 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# define DEFAULT_DICT "numbers.dict"
# include <stdio.h>

typedef	struct		s_dict
{
	char	**num;
	char	**name;
	int		size;
}					t_dict;

typedef	struct		s_file
{
	int		fd;
	int		size;
	int		parse_ok;
}					t_file;

int		ft_atoi(const char *str);
int		error_message(int erro_number);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		index_of(char to_find, char *str);
int		is_space(char c);
char	**ft_split(char *str, char *charset);
int		parsing_itot(char *path, char *number);
void	ft_putstr(char *str);
int		ft_numcmp(char *s1, char *s2);
char	*ft_substract(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strjoin(int size, char **strs, char *sep);
int		count_zero(char *num);
char	*num_is_valid(char *num);
int		tab_size(char **tab);
char	*test_find_value(t_dict dict, char *nb);
char	*ft_add(const char *a, const char *b);
void	ft_show_tab(t_dict dict);
int		int_to_text(char *num, t_dict dict, int offset);

#endif
