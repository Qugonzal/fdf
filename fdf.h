
typedef struct	s_info
{
	void	*mlx_ptr;
	void	*window;
}		t_info;

void	draw_segment_q1(int x1, int y1, int x2, int y2, t_info *info);
void	draw_segment_q2(int x1, int y1, int x2, int y2, t_info *info);
void	draw_segment_q3(int x1, int y1, int x2, int y2, t_info *info);
void	draw_segment_q4(int x1, int y1, int x2, int y2, t_info *info);
void	draw_segment_q5(int x1, int y1, int x2, int y2, t_info *info);
void	draw_segment_q6(int x1, int y1, int x2, int y2, t_info *info);
void	draw_segment_q7(int x1, int y1, int x2, int y2, t_info *info);
void	draw_segment_q8(int x1, int y1, int x2, int y2, t_info *info);

void	draw_segment(int x1, int y1, int x2, int y2, t_info *info);
