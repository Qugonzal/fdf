#include "mlx.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
//#include <X11/Xlib.h>
#include <fcntl.h>
#include <math.h>

# define WIN_W 1000
# define WIN_H 800
# define PI 3.14159265

typedef struct	s_doubles
{
	double		angle_x;
	double		angle_y;
	double		angle_z;
	double		pi;
}				t_doubles;

typedef struct	s_info
{
	void		*mlx_ptr;
	void		*window;
	int			**map;
//	int		**colors;
	int			y_map_size;
	int			x_map_size;
	int			projection;
	int			color;
	int			zoom;
	int			xdx;
	int			xdy;
	int			ydx;
	int			ydy;
	int			zdx;
	int			zdy;
	int			x_first;
	int			y_first;
	t_doubles	*dd;
}				t_info;

typedef struct	s_coor
{
	int x1;
	int x2;
	int y1;
	int y2;
}				t_coor;

void	draw_segment_q1(int x1, int y1, int x2, int y2, t_info *info);
void	draw_segment_q2(int x1, int y1, int x2, int y2, t_info *info);
void	draw_segment_q3(int x1, int y1, int x2, int y2, t_info *info);
void	draw_segment_q4(int x1, int y1, int x2, int y2, t_info *info);
void	draw_segment_q5(int x1, int y1, int x2, int y2, t_info *info);
void	draw_segment_q6(int x1, int y1, int x2, int y2, t_info *info);
void	draw_segment_q7(int x1, int y1, int x2, int y2, t_info *info);
void	draw_segment_q8(int x1, int y1, int x2, int y2, t_info *info);

void	ft_iso_project(t_info *w);
void	ft_para_project(t_info *w);

void	draw_seg(int x1, int y1, int x2, int y2, t_info *info);
int		keypress(int keycode, void *ptr);
void	ft_display_coolstar(int x, int y, t_info *info);
void	ft_free_map(t_info *info);
int		**ft_parse_input(char *file, t_info *info);
void	ft_draw_projection(t_info *info);
void	ft_displaymap_simple(t_info *info);
void	ft_error(char *fonction, void *ptr);
