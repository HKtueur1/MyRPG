/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** load_world
*/

#include <stdlib.h>
#include "ib.h"
#include "rpg_map.h"
#include "rpg_headers.h"

bool load_map(game_t *game)
{
    int pos_x = ib_atoi(map[game->world->level][10]);
    char *path = ib_strcpy(map_path[game->world->level]);

    game->world->map = init_sprite(path, (sfIntRect){});
    game->world->map->pos = (sfVector2f){pos_x, -576};
    game->world->map->size = (sfVector2f){2, 2};
    game->world->map->speed = 6;
    free(path);
    if (game->world->map->texture == NULL)
        return (false);
    return (true);
}

bool load_world(game_t *game)
{
    ib_putstr("Loading world ...\n");
    game->world = malloc(sizeof(world_t));
    game->world->pos = (sfVector2i){96, 544};
    game->world->eve = malloc(sizeof(int) * 4);
    game->world->level = 0;
    game->world->eve[0] = 1;
    game->world->eve[1] = 3;
    game->world->eve[2] = 4;
    game->world->eve[3] = 8;
    game->world->boss = false;
    game->world->dialogue = true;
    if (!load_map(game))
        return (false);
    ib_putstr("[SUCCESS]\n");
    return (true);
}

bool load_next_level(game_t *game)
{
    int pos_x;
    
    if (game->world->level == 3) {
        game->game_mode = 0;
        game->menu->current_menu = 4;
        return;
    }
    pos_x = ib_atoi(map[game->world->level + 1][11]);
    destroy_sprite(game->world->map);
    game->dialogue = 0;
    game->world->pos = (sfVector2i){pos_x, 476};
    game->world->level++;
    game->world->boss = true;
    game->world->dialogue = true;
    game->player->spider->pos = (sfVector2f){529, 329};
    sfSprite_setPosition(game->player->spider->sprite,\
        game->player->spider->pos);
    if (!load_map(game))
        return (false);
    return (true);
}