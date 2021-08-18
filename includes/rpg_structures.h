/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** rpg_structures
*/

#ifndef RPG_STRUCTURES_H_
#define RPG_STRUCTURES_H_

#include "oli.h"

//PLAYER
typedef struct player_s {
    sprite_t *health_bar;
    sprite_t *spider;
    sfClock *clock;
    sfTime time;
    int species;
    int hp_max;
    int lv_up;
    int atk;
    int def;
    int hp;
    int xp;
} player_t;

//WORLD
typedef struct world_s {
    sfVector2i pos;
    sprite_t *map;
    bool speaking;
    bool dialogue;
    bool boss;
    int level;
    int *eve;
} world_t;

//COMBAT
typedef struct enemy_s {
    sprite_t *sprite;
    sprite_t *health;
    int move_rect;
    int rect_end;
    int atk;
    int hp;
    int hp_max;
    int xp;
} enemy_t;

//COMBAT
typedef struct scene_c_s {
    sprite_t *background;
    sprite_t **attack;
    sprite_t *b_fight;
    sprite_t *b_bag;
    sprite_t *b_run;
    sprite_t *yellow;
    sprite_t *red;
    bool fight;
    bool run;
    bool bag;
} scene_c_t;

//COMBAT
typedef struct combat_s {
    int mode;
    sfTime wait;
    scene_c_t *scene;
    enemy_t *enemy;
    sfClock *clock;
    sfTime time;
    bool boss;
    int cycle;
} combat_t;

//MENU
enum enum_map {
    settings,
    play,
    exit_g,
    htp,
};

//MENU
typedef struct spd_sprite_s {
    sprite_t *violet;
    sprite_t *white;
    sprite_t *blue;
} spd_sprite_t;

//MENU
typedef struct bg_sprite_s {
    sprite_t *background;
    sprite_t *settings;
    sprite_t *play;
    sprite_t *exit;
    sprite_t *htp;
    sprite_t *how;
    bool how_isopen;
} bg_sprite_t;

//MENU
typedef struct choose_sprite_s {
    sprite_t *bg_button1;
    sprite_t *bg_button2;
    sprite_t *bg_button3;
    sprite_t *bg;
} choose_sprite_t;

//INVENTORY
typedef struct inventory_sprite_s {
    sprite_t *stinger;
    sprite_t *potion;
    sprite_t *cocoon;
    sprite_t *sting;
    sprite_t *bite;
    sprite_t *silk;
    sprite_t *bg;
    bool display;
} inventory_sprite_t;

typedef struct pause_menu_s {
    sprite_t *bg;
    sprite_t *b_menu;
    sprite_t *b_exit;
    int prev_mode;
} pause_menu_t;

//MENU
typedef struct nb_inv_s {
    int stinger;
    int potion;
    int cocoon;
    bool sting;
    bool silk;
    bool bite;
} nb_inv_t;

typedef struct cutscene_s {
    sprite_t *cut;
    sprite_t *end;
    bool is_open;
    sfClock *clock;
    sfTime time;
} cutscene_t;

//MENU

typedef struct diag_s {
    sprite_t *bg;
    sfText *text;
    sfFont *font;
} diag_t;

typedef struct settings_s {
    sprite_t *buttonm;
    sprite_t *buttonp;
    sprite_t *bg;
    bool is_open;
} settings_t;

typedef struct menu_s {
    inventory_sprite_t *inv;
    cutscene_t *cutscene;
    pause_menu_t *pause;
    choose_sprite_t *ch;
    settings_t *setting;
    nb_inv_t *nb_inv;
    int current_menu;
    bg_sprite_t *bg;
    diag_t *diag;
} menu_t;

//MUSIC
typedef struct music_s {
    sfMusic *combat;
    sfMusic *main;
    int vol;
} music_t;

//GAME
typedef struct game_s {
    sfRenderWindow *window;
    spd_sprite_t *color;
    player_t *player;
    combat_t *combat;
    world_t *world;
    music_t *music;
    sfEvent event;
    int game_mode;
    int dialogue;
    menu_t *menu;
} game_t;

#endif /* !RPG_STRUCTURES_H_ */
