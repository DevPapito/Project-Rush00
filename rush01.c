void	ft_putchar(char c);

static void	init_chars(char *chars)
{
	chars[0] = '/';
	chars[1] = '*';
	chars[2] = '\\';
	chars[3] = ' ';
}

static int is_corner(int angle, int index)
{
	return (angle == 0 || angle == index - 1);
}

static int is_last_line(int angle1, int index1, int angle2, int index2)
{
	return (is_corner(angle1, index1) && angle2 == index2 - 1);
}

static void fill(int row, int x, int line, int y, int mode, char *chars)
{
	while (row < x)
	{
		if (mode == 1)
		{
			if (is_last_line(row, x, line, y))
			{
				if (row == x - 1)
					ft_putchar(chars[0]);
				else
					ft_putchar(chars[2]);
			}
			else if (is_corner(row, x))
			{
				if (row == x - 1)
					ft_putchar(chars[2]);
				else
					ft_putchar(chars[0]);
			}
			else
				ft_putchar(chars[1]);
		}
		else
		{
			if (is_corner(row, x))
				ft_putchar(chars[1]);
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
			fill(row, x, line, y, 1, chars);
		else
			fill(row, x, line, y, 2, chars);
		ft_putchar('\n');
		line++;
	}
}
