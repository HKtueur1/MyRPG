/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** load_combat
*/

#include "ib.h"
#include "rpg_headers.h"
#include "rpg_combat.h"
#include <stdlib.h>

sprite_t **load_attacks(sprite_t **attack)
{
    sfIntRect rect = (sfIntRect){0, 0, 221, 106};
    for (int i = 0; i < 4; i++) {
        attack[i] = malloc(sizeof(sprite_t));
    }
    attack[0] = init_sprite("resources/combat/ability_bite.png", rect);
    attack[1] = init_sprite("resources/combat/ability_silk.png", rect);
    attack[2] = init_sprite("resources/combat/ability_sting.png", rect);
    attack[3] = NULL;
    attack[1]->pos = (sfVector2f){ 330, 580 };
    attack[0]->pos = (sfVector2f){  50, 580 };
    attack[2]->pos = (sfVector2f){ 630, 580 };
    sfSprite_setTextureRect(attack[0]->sprite, attack[0]->rect);
    sfSprite_setTextureRect(attack[1]->sprite, attack[1]->rect);
    sfSprite_setTextureRect(attack[2]->sprite, attack[2]->rect);
    return (attack);
}

scene_c_t *load_scene_c(scene_c_t *scene)
{
    sfIntRect rect = (sfIntRect){0, 0, 900, 700};

    scene->attack = malloc(sizeof(sprite_t *) * 4);
    scene->background = init_sprite("resources/combat/bg_combat.png", rect);
    rect = (sfIntRect){0, 0, 500, 130};
    scene->attack = load_attacks(scene->attack);
    scene->b_bag = init_sprite("resources/combat/buttonbag.png", rect);
    scene->b_fight = init_sprite("resources/combat/buttonfight.png", rect);
    scene->b_run = init_sprite("resources/combat/buttonrun.png", rect);
    scene->red = init_sprite("resources/combat/red.png", rect);
    scene->yellow = init_sprite("resources/combat/yellow.png", rect);
    scene->b_bag->pos = (sfVector2f){ 180, 580 };
    scene->b_fight->pos = (sfVector2f){ -100, 580 };
    scene->b_run->pos = (sfVector2f){ 480, 580 };
    sfSprite_setTextureRect(scene->b_bag->sprite, scene->b_bag->rect);
    sfSprite_setTextureRect(scene->b_fight->sprite, scene->b_fight->rect);
    sfSprite_setTextureRect(scene->b_run->sprite, scene->b_run->rect);
    sfSprite_setScale(scene->b_run->sprite, (sfVector2f){20, 20});
    return (scene);
}

enemy_t *load_enemy_c(enemy_t *enemy, int i)
{
    enemy = malloc(sizeof(enemy_t));
    enemy->sprite = init_sprite(ib_strcpy(png_enemy[i]),\
        (sfIntRect){0, 0, ib_atoi(size[i]), ib_atoi(size[i])});
    enemy->health = init_sprite("resources/combat/life.png",\
        (sfIntRect){0, 0, 300, 11});
    sfSprite_setTextureRect(enemy->health->sprite, enemy->health->rect);
    enemy->health->pos = (sfVector2f){50, 150};
    enemy->sprite->pos = (sfVector2f){650, 200};
    enemy->atk = ib_atoi(atk[i]);
    enemy->hp = ib_atoi(hp[i]);
    enemy->hp_max = ib_atoi(hp[i]);
    enemy->xp = ib_atoi(xp[i]);
    enemy->move_rect = ib_atoi(size[i]);
    enemy->rect_end = ib_atoi(end[i]);
    sfSprite_setPosition(enemy->sprite->sprite, enemy->sprite->pos);
    sfSprite_setTextureRect(enemy->sprite->sprite, enemy->sprite->rect);
    return (enemy);
}

void load_healthbar(player_t *player)
{
    player->health_bar = init_sprite("resources/combat/life.png",\
        (sfIntRect){0, 0, 300, 11});
    sfSprite_setTextureRect(player->health_bar->sprite,\
        player->health_bar->rect);
    player->health_bar->pos = (sfVector2f){550, 425};
    player->hp_max = 100;
    player->hp = 100;
    player->lv_up = 10;
    player->def = 0;
    player->atk = 20;
    player->xp = 0;
}

bool load_combat(game_t *game)
{
    ib_putstr("Loading combat scenes ...\n");
    game->combat = malloc(sizeof(combat_t));
    game->combat->scene = malloc(sizeof(scene_c_t));
    game->combat->enemy = malloc(sizeof(enemy_t *) * 10);
    game->combat->scene = load_scene_c(game->combat->scene);
    load_healthbar(game->player);
    game->combat->scene->fight = false;
    game->combat->scene->bag = false;
    game->combat->scene->run = false;
    game->combat->boss = false;
    game->combat->cycle = 0;
    game->combat->mode = 1;
    game->combat->wait.microseconds = 100000;
    game->combat->clock = sfClock_create();
    game->combat->time.microseconds = 0;
    ib_putstr("[SUCCESS]\n");
    return (true);
}