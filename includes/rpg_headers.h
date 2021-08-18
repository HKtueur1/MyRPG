/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** rpg_headers
*/

#ifndef RPG_HEADERS_H_
#define RPG_HEADERS_H_

#include "rpg_structures.h"
#include <stdlib.h>

int error_handler(int ac, char const * const av[]);

void end_game(game_t *game);
bool init_game(game_t *game);
bool launch_game(game_t *game);
void check_event(game_t *game);

bool load_menu(game_t *game);
bool load_world(game_t *game);
bool load_combat(game_t *game);
bool load_dialogue(game_t *game);
bool load_character(game_t *game);
enemy_t *load_enemy_c(enemy_t *enemy, int i);

void manage_menu(game_t *game);
void manage_world(game_t *game);
void manage_combat(game_t *game);
void manage_fight(game_t *game);
void manage_dialogue(game_t *game);
void manage_action(game_t *game);

void display_menu(game_t *game);
void display_world(game_t *game);
void display_combat(game_t *game);
void display_dialogue(game_t *game);
void display_character(game_t *game);

bool animate_player(game_t *game);
bool move_z(game_t *game);
bool move_d(game_t *game);
bool move_s(game_t *game);
bool move_q(game_t *game);

//manage_menu
void mouse_on_settings(game_t *game);
void click_on_settings(game_t *game);
void create_inventory(game_t *game);
void display_setting(game_t *game);
void first_cutscene(game_t *game);
void check_cutscene(game_t *game);
void load_settings(game_t *game);
void load_cutscene(game_t *game);
void check_pause(game_t *pause);
void create_pause(game_t *game);
void check_choice(game_t *game);
void display_inv(game_t *game);
void display_inv(game_t *game);
void check_inv(game_t *game);
void mouse_on_settings(game_t *game);
void click_on_settings(game_t *game);
void first_cutscene(game_t *game);
void load_cutscene(game_t *game);
void check_cutscene(game_t *game);
void display_cutscene(game_t *game);
void display_endcutscene(game_t *game);
void check_endcutscene(game_t *game);
//

//music
void free_music(game_t *game);
void music(game_t *game);
//

void change_character(game_t *game);
bool load_next_level(game_t *game);
#endif /* !RPG_HEADERS_H_ */