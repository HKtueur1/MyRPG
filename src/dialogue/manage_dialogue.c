/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** manage_dialogue
*/

#include "rpg_dialogue.h"
#include "rpg_headers.h"

void manage_dialogue(game_t *game)
{
    static sfTime time;

    time.microseconds = 200000; 
    sfText_setString(game->menu->diag->text,\
        dialogue[game->world->level][game->dialogue]);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        game->dialogue++;
        sfSleep(time);
    }
    if (game->dialogue > 4) {
        game->world->dialogue = false;
        game->world->speaking = false;
    }
}