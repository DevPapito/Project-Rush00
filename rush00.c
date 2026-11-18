void	ft_putchar(char c);

static void	init_chars(char *chars)
{
	chars[0] = 'o';
	chars[1] = '-';
	chars[2] = '|';
	chars[3] = ' ';
}

static int is_corner(int angle, int index)
{
	return (angle == 0 || angle == index - 1);
}

static void fill(int row, int x, int mode, char *chars)
{
	while (row < x)
	{
		if (mode == 1)
		{
			if (is_corner(row, x))
				ft_putchar(chars[0]);
			else
				ft_putchar(chars[1]);
		}
		else
		{
			if (is_corner(row, x))
				ft_putchar(chars[2]);
			else
				ft_putchar(chars[3]);
		}
		row++;
	}
}

void	rush(int x, int y)
{
	char	chars[4];
	int		line;
	int		row;

	line = 0;
	init_chars(chars);
	while (line < y)
	{
		row = 0;
		if (is_corner(line, y))
			fill(row, x, 1, chars);
		else
			fill(row, x, 2, chars);
		ft_putchar('\n');
		line++;
	}
}
