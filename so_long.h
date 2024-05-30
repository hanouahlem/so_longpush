/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbey <ahbey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:17:48 by ahbey             #+#    #+#             */
/*   Updated: 2024/05/30 20:20:54 by ahbey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "printf/ft_printf.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>

enum				e_DIR
{
	HAUT,
	BAS,
	DROITE,
	GAUCHE,
};

typedef struct s_game
{
	void			*mlx;
	void			*win;
	char			**map;
	void			*texture[16];
	void			*numeros[10];
	int				nb_line;
	int				len_line;
	int				map_height;
	int				exit;
	int				playerx;
	int				playery;
	int				item;
	int				image;
	int				nb_steps;
	int				direction;
	void			*mohaimage[4];
	struct s_game	*next;
}					t_game;

int					ft_so_strlen(char *str);
char				*ft_strdup(char *s);
int					touch_key(int keycode, t_game *game);
int					count_line(char *str);
char				**stock_map(t_game *game, char *str);
void				make_image(t_game *game);
int					check_name_map(char *str);
int					ft_strlen_name(char *str);
int					check_first_and_last_line(t_game *game);
int					check_border_map(t_game *game);
int					check_map_all(t_game *game, char *str);
int					free_map(char **str);
void				init_data_game(t_game *game);
int					strlen_tab(char **str);
int					check_map_rectangle(t_game *game);
int					check_interior(t_game *game);
int					validate_counts(int count_exit, int count_playeur,
						int count_collect);
int					check_line_content(char *line, int *count_exit,
						int *count_playeur, int *count_collect);
int					start_game(t_game *game);
int					close_window(void *param);
char				*ft_itoa(int n);
void				destroyimages(t_game *game, int error);
void				load_moha_image(t_game *game);
void				load_texture(t_game *game);
int					flood_fill(int x, int y, char **map);
int					map_dup(t_game *game);
int					check_flood_fill(char **map_dup);
void	posplayer(t_game *game);

#endif
