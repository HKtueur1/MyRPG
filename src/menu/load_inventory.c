/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** load_inventory
*/

#include "rpg_headers.h"


void param_inventory(inventory_sprite_t *inv, nb_inv_t *nb_inv)
{
    nb_inv->bite = false;
    nb_inv->sting = false;
    nb_inv->silk = false;
    inv->display = false;
    inv->sting->rect.left = 0;
    inv->silk->rect.left = 0;
    inv->bite->rect.left = 0;
    sfSprite_setTextureRect(inv->sting->sprite, inv->sting->rect);
    sfSprite_setTextureRect(inv->silk->sprite, inv->silk->rect);
    sfSprite_setTextureRect(inv->bite->sprite, inv->bite->rect);
}

void pos_sprite_inv(inventory_sprite_t *inv)
{
    inv->stinger->pos = (sfVector2f) {610, 480};
    inv->potion->pos = (sfVector2f) {620, 197};
    inv->cocoon->pos = (sfVector2f) {600, 340};
    inv->sting->pos = (sfVector2f) {250, 490};
    inv->silk->pos = (sfVector2f) {250, 350};
    inv->bite->pos = (sfVector2f) {250, 210};
    inv->bg->pos = (sfVector2f) {120, 90};
    sfSprite_setTextureRect(inv->stinger->sprite, inv->stinger->rect);
    sfSprite_setTextureRect(inv->potion->sprite, inv->potion->rect);
    sfSprite_setTextureRect(inv->cocoon->sprite, inv->cocoon->rect);
    sfSprite_setTextureRect(inv->sting->sprite, inv->sting->rect);
    sfSprite_setTextureRect(inv->bite->sprite, inv->bite->rect);
    sfSprite_setTextureRect(inv->silk->sprite, inv->silk->rect);
}

void create_inventory(game_t *game)
{
    game->menu->inv->bg = init_sprite("resources/menu/inv.png",\
        (sfIntRect){0, 0, 0, 0});
    game->menu->inv->potion = init_sprite("resources/menu/pts.png",\
        (sfIntRect){0, 0, 102, 117});
    game->menu->inv->cocoon = init_sprite("resources/menu/cocoon.png",\
        (sfIntRect){0, 0, 129, 111});
    game->menu->inv->stinger = init_sprite("resources/menu/dard.png",\
        (sfIntRect){0, 0, 111, 97});
    game->menu->inv->bite = init_sprite("resources/menu/ability1.png",\
        (sfIntRect){0, 0, 280, 107});
    game->menu->inv->silk = init_sprite("resources/menu/ability2.png",\
        (sfIntRect){0, 0, 280, 107});
    game->menu->inv->sting = init_sprite("resources/menu/ability3.png",\
        (sfIntRect){0, 0, 280, 107});
    pos_sprite_inv(game->menu->inv);
    param_inventory(game->menu->inv, game->menu->nb_inv);
}