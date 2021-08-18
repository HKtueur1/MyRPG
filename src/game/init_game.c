/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** init_game
*/

#include <stdlib.h>
#include "ib.h"
#include "rpg_errors.h"
#include "rpg_headers.h"

bool init_game(game_t *game)
{
    bool (*load_module[6])(game_t *game) = \
    {load_menu, load_character, load_world, load_combat, load_dialogue};
    char *name = "SAH - Le monde du plaisir";
    sfVideoMode mode = {900, 700, 32};

    game->game_mode = 0;
    for (int i = 0; i < 5; i++)
        if (!(*load_module[i])(game))
            return (ib_puterr(error[5 + i], false));
    game->window = sfRenderWindow_create(mode, name, sfClose, NULL);
    if (game->window == NULL)
        return (ib_puterr(error[4], false));
    sfRenderWindow_setFramerateLimit(game->window, 60);
    return (true);
}