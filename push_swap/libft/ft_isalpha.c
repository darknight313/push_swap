/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:44:19 by ashirzad          #+#    #+#             */
/*   Updated: 2023/10/29 01:44:24 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int a)
{
	int	result;

	result = 0;
	if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
	{
		result = 1;
	}
	return (result);
}
