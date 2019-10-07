#include "fdf.h"

void	ft_display_coolstar(int x, int y, t_info *info)
{
	draw_segment(x, y, x, y - 40, info);
	draw_segment(x, y, x + 20, y - 40, info);
	draw_segment(x, y, x + 40, y - 40, info);
	draw_segment(x, y, x + 40, y - 20, info);
	draw_segment(x, y, x + 40, y, info);
	draw_segment(x, y, x + 40, y + 20, info);
	draw_segment(x, y, x + 40, y + 40, info);
	draw_segment(x, y, x + 20, y + 40, info);
	draw_segment(x, y, x, y + 40, info);
	draw_segment(x, y, x - 20, y + 40, info);
	draw_segment(x, y, x - 40, y + 40, info);
	draw_segment(x, y, x - 40, y + 20, info);
	draw_segment(x, y, x - 40, y, info);
	draw_segment(x, y, x - 40, y - 20, info);
	draw_segment(x, y, x - 40, y - 40, info);
	draw_segment(x, y, x - 20, y - 40, info);
}
