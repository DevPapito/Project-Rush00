/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DevPapito <pietroeziosuzano@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 22:12:48 by DevPapito         #+#    #+#             */
/*   Updated: 2026/11/18 22:12:48 by DevPapito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

static void	init_chars(char *chars)
{
	chars[0] = 'A';
	chars[1] = 'C';
	chars[2] = 'B';
	chars[3] = ' ';
}

static int	is_corner(int angle, int index)
{
	return (angle == 0 || angle == index - 1);
}

static int	top_index(int row, int x, int line, int y)
{
	if (is_corner(row, x) && line == y - 1)
		return (1);
	if (is_corner(row, x))
		return (0);
	return (2);
}

static void	fill(int x, int line, int y, char *chars)
{
	int	row;

	row = 0;
	while (row < x)
	{
		if (is_corner(line, y))
			ft_putchar(chars[top_index(row, x, line, y)]);
		else if (is_corner(row, x))
			ft_putchar(chars[2]);
		else
			ft_putchar(chars[3]);
		row++;
	}
}

void	rush(int x, int y)
{
	char	chars[4];
	int		line;

	line = 0;
	init_chars(chars);
	while (line < y)
	{
		fill(x, line, y, chars);
		ft_putchar('\n');
		line++;
	}
}
