/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliot <ncolliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:22:27 by ncolliot          #+#    #+#             */
/*   Updated: 2022/11/01 04:27:25 by ncolliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

int	found_newline(t_list *stash)
{
	int	i;
	t_list	*current;

	if (stash == NULL)
		return (0);
	current = ft_lst_get_last(stash);
    i = 0;
    while (current->content[i])
    {
        if (current->content[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

t_list  *ft_lst_get_last(t_list *stash)
{
    t_list  *current;
    
    current = stash;
    while (current && current->next)
        current = current->next;
    return (current);
}

void    generate_line(char **line, t_list *stash)
{
    int i;
    int len;

    len = 0;
    while (stash)
    {
        i = 0;
        while (stash->content[i])
        {
            if (stash->content[i] == '\n')
            {
                len++;
                break;
            }
            len++;
            i++;
        }
        stash = stash->next;
    }
    *line = malloc(sizeof(char) * (len + 1));
}

void    free_stash(t_list *stash)
{
    t_list  *current;
    t_list *next;
    
    current = stash;
    while (current)
    {
        free(current->content);
        next = current->next;
        free(current);
        current = next;
    }
}