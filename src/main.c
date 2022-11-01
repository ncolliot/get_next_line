/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliot <ncolliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:22:38 by ncolliot          #+#    #+#             */
/*   Updated: 2022/11/01 06:46:05 by ncolliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>

int main()
{
    int fd;
    char *line;

    fd = open("test/text", O_RDONLY); // fd va prendre les donnés du fichier
    while (1)
    {
        line = get_next_line(fd);
        printf("%s", line);
        if (line == NULL)
            break;
        free(line);
    }
    return (0);
}