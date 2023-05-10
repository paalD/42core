/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 18:00:45 by dpaal             #+#    #+#             */
/*   Updated: 2021/09/23 15:15:45 by dpaal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char *)str;
	c = (char)c;
	while (str[i] != '\0')
	{
		i++;
		ret++;
	}
	while (i > 0 && str[i] != c)
	{
		i--;
		ret--;
	}
	if (str[i] == c)
		return (ret);
	else
		return (0);
}
