/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp_save_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:34:22 by hhoummad          #+#    #+#             */
/*   Updated: 2021/01/19 19:15:45 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		check_save(char *str)
{
	if (ft_memcmp(str, "--save\0", 7) != 0)
	{
		ft_putstr_fd("Error\nYou've Inserted A Wrong Option\n", 2);
		exit(1);
	}
}

static int	round_four(int width)
{
	return (width % 4 == 0 ? width : width - width % 4 + 4);
}

static void	fill_colors(char **bmp_data, int bmp_size, int pad_width)
{
	int		index;
	int		x;
	int		y;
	int		color;

	index = -1;
	while (++index < bmp_size)
		bmp_data[0][index] = (char)0;
	y = -1;
	while (++y < g_data.h)
	{
		x = -1;
		while (++x < g_data.w)
		{
			color = g_d_addr[y * g_data.w + x];
			index = (g_data.h - 1 - y) * pad_width + x * 3;
			bmp_data[0][index++] = color & 0x000000FF;
			bmp_data[0][index++] = (color & 0x0000FF00) >> 8;
			bmp_data[0][index] = (color & 0x00FF0000) >> 16;
		}
	}
}

static int	*fill_header(void)
{
	int		*header;

	if (!(header = (int *)malloc(13 * sizeof(int))))
		puterror("Error\nFailed to alloc memory for BMP Header!\n", NULL);
	header[0] = 0;
	header[1] = 0;
	header[2] = 0x36;
	header[3] = 0x28;
	header[4] = g_data.w;
	header[5] = g_data.h;
	header[6] = 0x180001;
	header[7] = 0;
	header[8] = 0;
	header[9] = 0;
	header[10] = 0;
	header[11] = 0;
	header[12] = 0;
	return (header);
}

void		export_bmp(int width, int height)
{
	char		*bmp_data;
	int			*header;
	int			fd;
	int			bitmap_size;
	const char	tag[] = "BM";

	bitmap_size = height * round_four(width * 3) * 3;
	header = fill_header();
	if (!(bmp_data = (char *)malloc(bitmap_size * sizeof(char))))
		puterror("Error\nFailed to allocate memory for BMP!\n", NULL);
	fill_colors(&bmp_data, bitmap_size, round_four(width * 3));
	header[0] = sizeof(tag) + sizeof(header) + bitmap_size;
	if (!(fd = open("save.bmp", O_RDWR | O_CREAT | O_TRUNC, 0777)))
		puterror("Error\nFailed to access BMP file!\n", NULL);
	write(fd, tag, 2 * sizeof(char));
	write(fd, header, 13 * sizeof(int));
	write(fd, bmp_data, bitmap_size * sizeof(char));
	close(fd);
	exit(0);
}
