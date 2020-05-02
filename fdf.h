/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <quegonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 03:34:26 by quegonza          #+#    #+#             */
/*   Updated: 2020/04/30 03:53:40 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define WIN_W 1000
# define WIN_H 600
# define READ_BUFFSIZE 5000
# define PI 3.14159265

typedef struct	s_info
{
	void		*mlx_ptr;
	void		*window;
	int			**map;
	int			y_map_size;
	int			x_map_size;
	int			projection;
	int			flag;
	int			color;
	int			zoom;
	int			zdim;
	int			xdx;
	int			xdy;
	int			ydx;
	int			ydy;
	int			zdx;
	int			zdy;
	int			x_first;
	int			y_first;
	double		angle_x;
	double		angle_y;
	double		angle_z;
	double		pi;
	int			x1;
	int			x2;
	int			y1;
	int			y2;
}				t_info;

int				ft_parse_input(char *file, t_info *info);
int				ft_check_input(char *str, t_info *info);
int				ft_check_input_loop(int *i1, int *xt, char *str, t_info *info);
char			*ft_open_read(char *file);
char			*ft_read(int fd);

int				ft_keypress(int keycode, void *ptr);
void			ft_keypress_help(int keycode, t_info *info);
void			ft_keypress_left(int keycode, t_info *info);
void			ft_keypress_up(int keycode, t_info *info);
void			ft_keypress_right(int keycode, t_info *info);
void			ft_keypress_down(int keycode, t_info *info);
void			ft_keypress_rotate(int keycode, t_info *info);
void			ft_keypress_switch(int keycode, t_info *info);
void			ft_keypress_zoom(int keycode, t_info *info);
void			ft_keypress_depth(int keycode, t_info *info);

void			draw_seg(t_info *info);
void			draw_segment_q1(t_info *info);
void			draw_segment_q2(t_info *info);
void			draw_segment_q3(t_info *info);
void			draw_segment_q4(t_info *info);
void			draw_segment_q5(t_info *info);
void			draw_segment_q6(t_info *info);
void			draw_segment_q7(t_info *info);
void			draw_segment_q8(t_info *info);

void			ft_xlines(t_info *w);
void			ft_ylines(t_info *w);

void			ft_iso_project(t_info *w);
void			ft_para_project(t_info *w);

void			ft_free_map(t_info *info);
void			ft_draw_projection(t_info *info);
void			ft_error(char *fonction, void *ptr);

#endif
