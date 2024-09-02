/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:05:46 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/08/12 00:15:29 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii_new(int c)
{
	if (c == 34)
		return (1);
	else if (c >= 0 && c <= 127)
		return (0);
	else
		return (-1);
}