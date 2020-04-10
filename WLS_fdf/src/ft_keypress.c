#include "../inc/fdf.h"

int		keypress(int keycode, void *ptr)
{
	t_info	*info;
	info = (t_info *)ptr;
	ft_putstr("<((!))> Keycode: ");
	ft_putnbr(keycode);
	ft_putstr("\n");
	if (keycode == 65307)
	{
		ft_free_map(info);
		exit(0);
	}
	if (keycode == ' ')
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
	if (keycode == 'x')
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		if (info->projection == 0 || info->projection == 1)
			info->projection = 3;
		else
			info->projection = 0;
		ft_draw_projection(info);
	}
	if (keycode == 'z')
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->zdx += 1;
		info->zdy += 1 ;
		ft_draw_projection(info);
	}
	if (keycode == 's')
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->zdx -= 1;
		info->zdy -= 1 ;
		ft_draw_projection(info);
	}
	if (keycode == 'e')
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->dd->angle_x -= 1.0;
		info->dd->angle_y -= 1.0;
		info->dd->angle_z -= 1.0;
		ft_draw_projection(info);
	}
	if (keycode == 'd')
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->dd->angle_x += 1.0;
		info->dd->angle_y += 1.0;
		info->dd->angle_z += 1.0;
		ft_draw_projection(info);
	}
	if (keycode == 65430) // <<
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->x_first -= 50;
		ft_draw_projection(info);
	}
	if (keycode == 65361) // <
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->x_first -= 5;
		ft_draw_projection(info);
	}
	if (keycode == 65431) // ^^
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->y_first -= 50;
		ft_draw_projection(info);
	}
	if (keycode == 65362) // ^
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->y_first -= 5;
		ft_draw_projection(info);
	}
	if (keycode == 65432) // >>
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->x_first += 50;
		ft_draw_projection(info);
	}
	if (keycode == 65363) // >
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->x_first += 5;
		ft_draw_projection(info);
	}
	if (keycode == 65433) // vv
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->y_first += 50;
		ft_draw_projection(info);
	}
	if (keycode == 65364) // v
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->y_first += 5;
		ft_draw_projection(info);
	}
	if (keycode == 'p')
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->zoom++;
		ft_draw_projection(info);
	}
	if (keycode == 'm')
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
		info->zoom--;
		ft_draw_projection(info);
	}
	if (keycode == 'q')
	{
		info->color = 0x000000;
		ft_draw_projection(info);
		info->color = 0xFFFFFF;
	}
	if (keycode == 'm')
	{
  		mlx_string_put(info->mlx_ptr,info->window,50,20,0xFF99FF,"String output");
 		mlx_string_put(info->mlx_ptr,info->window,150,40,0x00FFFF,"MinilibX test");
	}
	return (0);
}
