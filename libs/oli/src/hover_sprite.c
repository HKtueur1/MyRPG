/*
** EPITECH PROJECT, 2021
** lib-csfml
** File description:
** sprite_is_hovered
*/

#include "../../includes/oli_struct.h"

bool sprite_hover(sprite_t *sprite, sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfFloatRect zone = sfSprite_getGlobalBounds(sprite->sprite);

    if (sfFloatRect_contains(&zone, mouse.x, mouse.y))
        return (true);
    return (false);
}