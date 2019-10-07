#include "fdf.h"

int		keypress(int keycode, void *ptr)
{
	t_info	*info;
	info = (t_info *)ptr;
	ft_putstr("<((!))> Keycode: ");
	ft_putnbr(keycode);
	ft_putstr("\n");

	if (keycode == 53)
	{
		ft_free_map(info);
		exit(0);
	}
	if (keycode == 49)
	{
		if (info->color == 0x000000)
		{
			info->color = 0xFFFFFF;
			ft_display_coolstar(50, 50, info);
			mlx_string_put(info->mlx_ptr,info->window,5,20,info->color,"String output");
			mlx_string_put(info->mlx_ptr,info->window,15,40,info->color,"MinilibX test");
		}
		else
		{
			info->color = info->color;
			ft_display_coolstar(50, 50, info);
			mlx_string_put(info->mlx_ptr,info->window,5,20,info->color,"String output");
			mlx_string_put(info->mlx_ptr,info->window,15,40,info->color,"MinilibX test");
		}
	}
	if (keycode == 2) // d
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->angle -= 1;
		ft_draw_projection(info);
	}
	if (keycode == 14) // e
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->angle += 1;
		ft_draw_projection(info);
	}
	if (keycode == 123) // <
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->x_first -= 5;
		ft_draw_projection(info);
	}
	if (keycode == 126) // ^
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->y_first -= 5;
		ft_draw_projection(info);
	}
	if (keycode == 124) // >
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->x_first += 5;
		ft_draw_projection(info);
	}
	if (keycode == 125) // v
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->y_first += 5;
		ft_draw_projection(info);
	}
	if (keycode == 35) // p
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->zoom++;
		ft_draw_projection(info);
	}
	if (keycode == 37) // l
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->zoom--;
		ft_draw_projection(info);
	}
	return (0);
}
