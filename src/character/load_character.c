/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** load_character
*/

#include <stdlib.h>
#include "rpg_character.h"
#include "rpg_headers.h"
#include "ib.h"

void change_character(game_t *game)
{
    char *path = ib_strcpy(player_path[game->player->species]);

    game->player->spider = init_sprite(path, (sfIntRect){0, 0, 80, 64});
    game->player->spider->speed = 6;
    game->player->spider->size = (sfVector2f){1.5, 1.5};
    game->player->spider->pos.x = 192 - 48;
    game->player->spider->pos.y = 508 - 60;
    free(path);
}

bool load_character(game_t *game)
{
    ib_putstr("Loading player ...\n");
    game->player = malloc(sizeof(player_t));
    game->player->species = 0;
    game->player->clock = sfClock_create();
    game->player->time.microseconds = 0;
    change_character(game);
    ib_putstr("[SUCCESS]\n");
    return (true);
}