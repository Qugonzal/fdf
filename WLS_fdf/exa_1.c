#include "fdf.h"
#include <math.h>
#include <stdlib.h>
#include <mlx.h>
#include <X11/Xlib.h>

/*
int	abs(int a)
{
	return (a > 0 ? a : -a);
}
*/
/*
void SDL_PutPixel32(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
	Uint8 *p;
	if (x<0 || y<0 || x>surface->w-1 || y>surface->h-1)
		return;
	p = (Uint8*)surface->pixels + y * surface->pitch + x * 4;
	*(Uint32*)p = pixel;
}
*/
void Line(t_info *info,int x1,int y1, int x2,int y2,long long couleur)  // Bresenham
{
	int x,y;
	int Dx,Dy;
	int xincr,yincr;
	int erreur;
	int i;
	Dx = abs(x2-x1);
	Dy = abs(y2-y1);
	if(x1<x2)
		xincr = 1;
	else
		xincr = -1;
	if(y1<y2)
		yincr = 1;
	else
		yincr = -1;
	x = x1;
	y = y1;
	if(Dx>Dy)
	{
		erreur = Dx/2;
		for(i=0;i<Dx;i++)
		{
			x += xincr;
			erreur += Dy;
			if(erreur>Dx)
			{
				erreur -= Dx;
				y += yincr;
			}
			mlx_pixel_put(info->mlx_ptr, info->window,x1,y1,couleur);
			//SDL_PutPixel32(info,x, y,couleur);
		}
	}
	else
	{
		erreur = Dy/2;
		for(i=0;i<Dy;i++)
		{
			y += yincr;
			erreur += Dx;
			if(erreur>Dy)
			{
				erreur -= Dy;
				x += xincr;
			}
			mlx_pixel_put(info->mlx_ptr, info->window,x1,y1,couleur);
		}
	}
	mlx_pixel_put(info->mlx_ptr, info->window,x1,y1,couleur);
	mlx_pixel_put(info->mlx_ptr, info->window,x2,y2,couleur);
}
/*
int KeyHit()
{
	SDL_Event e;
	if (SDL_PollEvent(&e))
		if (e.type == SDL_KEYDOWN)
			return 1;
	return 0;
}
*/
void Positionne(int i,int j,int alt,int* outx,int* outy)
{
	int startx,starty;
	int pas = 10;
	startx = 10;
	starty = 300;
	*outx = startx + i*pas + j*pas;
	*outy = starty + i*pas/2 - j*pas/2 - alt;
}

int GetAlt(int i,int j)
{
	if (i>25)
		return (int)(10*cos(i*1.0/3)+10*sin(j*1.0/3));

	if ((i-25)*(i-25) + (j-25)*(j-25)<380)
		return 20;
	return 0;
}

void Segment(t_info *info,int imin,int jmin,int imax,int jmax)
{
	int xmin,ymin,xmax,ymax;
	int alt = 0;
	Positionne(imin,jmin,GetAlt(imin,jmin),&xmin,&ymin);
	Positionne(imax,jmax,GetAlt(imax,jmax),&xmax,&ymax);
	Line(info,xmin,ymin,xmax,ymax,0x00007700);
}

int main(int argc,char** argv)
{
	void	*param;
	t_info	info;
	int i,j;

	param = 0;
	if (!(info.mlx_ptr = mlx_init()))
	{
		exit(1);
	}
	if (!(info.window = mlx_new_window(info.mlx_ptr, 500, 500, "it's a TITLE")))
	{
		exit(1);
	}
/*	SDL_Surface* screen;
	int i,j;
	SDL_Init(SDL_INIT_VIDEO);
	screen=SDL_SetVideoMode(1000,600,32,SDL_SWSURFACE|SDL_DOUBLEBUF);
*/
	for(i=0;i<50;i++)
	{
		for(j=0;j<50;j++)
		{
			if (i!=49)
				Segment(&info,i,j,i+1,j);
			if (j!=49)
				Segment(&info,i,j,i,j+1);
		}
	}
/*	SDL_Flip(screen);
	while(!KeyHit()){}
	SDL_Quit();
*/
	return 0;
}
