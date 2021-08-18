/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** init_music
*/

#include "rpg_headers.h"
#include <stdlib.h>

void music(game_t *game)
{
    game->music = malloc(sizeof(music_t));
    game->music->main = sfMusic_createFromFile("resources/menu/main.ogg");
    game->music->combat = sfMusic_createFromFile("resources/menu/combat.ogg");
    sfMusic_setVolume(game->music->main, 50);
    sfMusic_setVolume(game->music->combat, 50);
    sfMusic_setLoop(game->music->main, sfTrue);
    sfMusic_setLoop(game->music->combat, sfTrue);
    game->music->vol = 50;
    sfMusic_play(game->music->main);
}

void free_music(game_t *game)
{
    sfMusic_destroy(game->music->main);
    sfMusic_destroy(game->music->combat);
}