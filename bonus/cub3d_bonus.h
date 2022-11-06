/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 22:22:12 by hhoummad          #+#    #+#             */
/*   Updated: 2021/01/21 17:33:08 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <string.h>
# include <math.h>
# include "mlx.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# define TITLE "cub3D"
# define MS 13
# define RS 5
# define RADIN 0.01745329251
# define FOV 60
# define SQ 64
# define A 0
# define S 1
# define D 2
# define W 13
# define RT sqrtf
# define G g_data
# define T g_tex
# define ADDR g_d_addr

typedef	struct	s_data
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	char		*t;
	char		**map;
	int			w;
	int			h;
	int			c;
	int			f;
}				t_data;

typedef	struct	s_player
{
	float		angle;
	float		x;
	float		y;
}				t_player;

typedef	struct	s_ray
{
	float		loop_ang;
	float		x;
	float		y;
}				t_ray;

typedef	struct	s_wall
{
	float		dist;
	float		x;
	float		y;
	int			der;
}				t_wall;

typedef struct	s_tex
{
	int			*no;
	int			*so;
	int			*we;
	int			*ea;
	int			*s;
	int			*t;
	int			w[6];
	int			h[6];
}				t_tex;

typedef struct	s_spr
{
	int			x;
	int			y;
	float		dis;
	float		dis2;
	int			tp;
}				t_spr;

typedef struct	s_prt
{
	int			h;
	int			y_star;
	int			y_end;
	int			x_star;
	int			x_end;
}				t_prt;

typedef struct	s_hud
{
	int			a;
	int			b;
	int			c;
	int			d;
	int			y_a;
	int			y_b;
	int			y_c;
}				t_hud;

typedef struct	s_vie
{
	int			s_x;
	int			e_x;
	int			s_y;
	int			e_y;
	int			e_vie;
}				t_vie;

t_data			g_data;
t_player		g_player;
t_ray			g_ray;
t_wall			g_wall;
t_tex			g_tex;
t_tex			g_tex2;
t_spr			*g_sprites;
t_prt			g_prt;
t_hud			g_hud;
t_vie			g_vie;
float			*g_wall_distance;
int				g_save;
int				g_som_spr;
int				g_check;
int				g_h;
int				*g_w;
int				g_ck_m;
int				g_ply;
void			*g_mlx_ptr;
void			*g_win_ptr;
void			*g_nimage;
int				*g_d_addr;
int				g_bits_per_pixel;
int				g_s_line;
int				g_endian;
float			g_r_x;
float			g_r_y;
float			g_r_ang;
float			g_dis_pp;
int				g_vital;
int				g_trap;
int				g_vue;
int				g_fd;
float			g_hold;
int				g_op_h;

void			init_data(char *fname);
void			check_save(char *str);
void			readf(int fd);
int				tablen(char **tab);
void			freedata(void *p);
void			free_2d(char **tab);
void			puterror(char *str, void *p);
void			check_r(char *line);
int				checkatoi(char *str);
void			check_path(char *line, char *dir);
void			check_color(char *line, char *pos);
void			check_map(char *line, int fd);
char			*joinmap(char *line, int fd);
void			wh_map(void);
void			isvalid(int i, int j);
void			start_visuals(void);
void			init_scene(void);
void			player_pos(int a, int b);
int				update(int key);
void			up_pos(int key, float wanted_x, float wanted_y);
void			is_a_wall(float x_inter, float y_inter);
int				is_wall_ray(float x_inter, float y_inter);
int				check_more(int x, int y, int lax, int lay);
void			star_ray(void);
void			wallxy(float x, float y, int i);
float			norm_anglef(float angle);
int				norm_angle(int angle);
void			draw_wall(int x, float a, float b, float i);
void			set_cf(int x, int y);
void			remp_g_r(float x, float y, float angle);
float			cal_step_v(float wanted, float angle);
float			cal_step_h(float wanted, float angle);
float			y_angle_h(int *a, float *wanted, int *j);
float			y_angle_v(int *a, float *wanted, int *j);
float			pmsq_h(float wanted);
float			pmsq_v(float wanted);
void			init_sprite(int i);
void			star_sprite(void);
void			dis_sprite(void);
void			sort_sprite(void);
void			export_bmp(int width, int height);
void			star_hv(void);
void			data_hud_vie(void);
char			*cus_split(char *line, char *dir);
int				check_more2(int x, int y, int lax, int lay);
void			check_sp(char *line, int i);

#endif
