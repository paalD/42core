/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 16:47:21 by dpaal             #+#    #+#             */
/*   Updated: 2021/09/23 11:59:58 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	char	*ret;
	int		i;

	i = 0;
	c = (char)c;
	ret = (char *)str;
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
		ret++;
	}
	if (str[i] == c)
		return (ret);
	else
		return (0);
}
