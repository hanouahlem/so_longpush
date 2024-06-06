/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbey <ahbey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:10:17 by ahbey             #+#    #+#             */
/*   Updated: 2024/06/03 21:42:16 by ahbey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moveto(int dir[2], t_game *game)
{
	if (game->map[game->playery + dir[0]][game->playerx + dir[1]] == '1')
		return ;
	if (game->map[game->playery + dir[0]][game->playerx + dir[1]] == 'E'
		&& game->item != 0)
		return ;
	game->map[game->playery][game->playerx] = '0';
	if (game->map[game->playery + dir[0]][game->playerx + dir[1]] == 'C')
	{
		game->item--;
		game->image++;
		game->map[game->playery + dir[0]][game->playerx + dir[1]] = '0';
	}
	ft_printf(" MOVE %d \r\033[0m", game->nb_steps++);
	if (game->map[game->playery + dir[0]][game->playerx + dir[1]] == 'E'
		&& game->item == 0)
	{
		ft_printf("bien jouer t'as bien harbat en %d move\n", game->nb_steps);
		mlx_loop_end(game->mlx);
	}
	game->map[game->playery + dir[0]][game->playerx + dir[1]] = 'P';
	game->playery += dir[0];
	game->playerx += dir[1];
}

int	touch_key(int keycode, t_game *game)
{
	static int	directions[4][2] = {
	{-1, 0},
	{1, 0},
	{0, 1},
	{0, -1}};

	if (keycode == 65307)
		mlx_loop_end(game->mlx);
	if (keycode == 'w' || keycode == 's' || keycode == 'd' || keycode == 'a')
	{
		if (keycode == 'w')
			game->direction = HAUT;
		else if (keycode == 's')
			game->direction = BAS;
		else if (keycode == 'd')
			game->direction = DROITE;
		else if (keycode == 'a')
			game->direction = GAUCHE;
		moveto(directions[game->direction], game);
	}
	start_game(game);
	return (0);
}

int	close_window(void *param)
{
	mlx_loop_end(param);
	return (1);
}
