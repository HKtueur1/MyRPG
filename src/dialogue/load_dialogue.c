/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** load_dialogue
*/

#include "ib.h"
#include "rpg_headers.h"

bool load_dialogue(game_t *game)
{
    ib_putstr("Loading dialogues ...\n");
    game->dialogue = 0;
    game->menu->diag = malloc(sizeof(diag_t));
    game->menu->diag->bg = init_sprite("resources/menu/parlermdr.png",\
        (sfIntRect){0, 0, 900, 700});
    game->menu->diag->text = sfText_create();
    game->menu->diag->font =\
        sfFont_createFromFile("resources/combat/angel.ttf");
    sfText_setFont(game->menu->diag->text, game->menu->diag->font);
    sfText_setColor(game->menu->diag->text, sfBlack);
    sfText_setString(game->menu->diag->text, "caca");
    sfText_setPosition(game->menu->diag->text, (sfVector2f){200, 590});
    ib_putstr("[SUCCESS]\n");
    return (true);
}