/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 13:59:57 by seli              #+#    #+#             */
/*   Updated: 2018/09/23 17:19:22 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_putchar_x(char c, int times);
void	pl(int w, int fw, int d, int door_style);
int		ds(int h, int d, int tier, int size);
int		ft_cal_full_width(int size);

void	sastantua(int size)
{
	int fw;
	int d;
	int w;
	int tier;
	int h;

	fw = ft_cal_full_width(size);
	tier = 1;
	w = -3;
	d = 2 * ((size - 1) / 2) + 1;
	while (tier <= size)
	{
		w += 2 * (tier / 2 + 2) - 2;
		h = tier + 2;
		while (h > 0)
		{
			w += 2;
			pl(w, fw, d, ds(h, d, tier, size));
			h--;
		}
		tier++;
	}
}

int		ds(int h, int d, int tier, int size)
{
	if(tier == size && d >= 5 && h * 2 == d + 1)
		return (2);
	else
		return (tier == size && h <= d);
}

void	pl(int w, int fw, int d, int door_style)
{
	ft_putchar_x(' ', (fw - w) / 2);
	ft_putchar('/');
	if (door_style == 0)
		ft_putchar_x('*', w);
	else
	{
		ft_putchar_x('*', (w - d) / 2);
		if (door_style == 1)
			ft_putchar_x('|', d);
		if (door_style == 2)
		{
			ft_putchar_x('|', d - 2);
			ft_putchar('$');
			ft_putchar('|');
		}
		ft_putchar_x('*', (w - d) / 2);
	}
	ft_putchar('\\');
	ft_putchar('\n');
}

int		ft_cal_full_width(int size)
{
	int tier;
	int w;

	if (size == 0)
		return (0);
	tier = 1;
	w = -3;
	while (tier <= size)
	{
		w += 2 * (tier / 2 + 2 + tier + 1);
		tier++;
	}
	return (w);
}

void	ft_putchar_x(char c, int times)
{
	while (times > 0)
	{
		ft_putchar(c);
		times--;
	}
}