/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** end_game
*/

#include <stdlib.h>
#include "rpg_headers.h"

void end_game(game_t *game)
{
    sfRenderWindow_destroy(game->window);
}