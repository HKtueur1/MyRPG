/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** rpg_map
*/

#ifndef RPG_MAP_H_
#define RPG_MAP_H_

static const char *map_path[] = {
    "resources/map/Spawn.png",
    "resources/map/Map1.png",
    "resources/map/Map2.png",
    "resources/map/Map3.png",
};

static const char *spawn[] = {
    "xxxx  xxxx",
    "xxxx   xxx",
    "xxxxx   xx",
    "xxxxx   xx",
    "xxx      x",
    "xxx      x",
    "xxxxx    x",
    "xxxxx    x",
    "x+       x",
    "xxxxxxxxxx",
    "0",
    "0",
    "416",
};

static const char *map1[] = {
    "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
    "xxxx    xxxxx   xxxxxxx E xxxx",
    "xx      xx         xxx   xxxxx",
    "xx  xxxExx         xxx   xx xx",
    "xx  xxx    xxx     Exx   xx  x",
    "x   xx    xxx    xx xxxx     x",
    "xBBBBxx   xxx    xx xxxx    xx",
    "x    xxxx  xxxx  xx  +x+    xx",
    "       xx   E    xxx  +   xxxx",
    "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
    "-2940",
    "1760",
    "1696",
};

static const char *map2[] = {
    "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
    "xxxxxxxxx        xxxxx E    xx",
    "xx                 xx   xxx xx",
    "xx xxExxxxx        xxxx xxx xx",
    "x  xx xxxxxxxxxEEEExxxx  xx  x",
    "x     xxxxxxxxx    xx   xxx  x",
    "xBBBBxxxxxxxxxxxx       xxx  x",
    "x    xxxxxxxxxxxx       xxx+ x",
    "   xxxxxxxxxxxxxxxxxEEExxxx  x",
    "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
    "-2940",
    "1760",
    "1696",
};

static const char *map3[] = {
    "xxxxxxxxxxxxxxxxxxxxxxx",
    "xxxxxxxxxxxxEExxxxxxxxx",
    "xxx    xxxxxx    xxxxxx",
    " xxBBB  xxxxx  xE     x",
    "     B  xx   Exxx     x",
    "     B  xxx  xxx    x x",
    " xxBBB  xxx  xxx xx ++x",
    "xxx      xx  xxx  xx  x",
    "xxxxxxx E        xxxx x",
    "xxxxxxxxxxxxxxxxxxxxxxx",
    "-2044",
    "1312",
    "1248",
};


static const char **map[] = {
    spawn,
    map1,
    map2,
    map3,
};

#endif /* !RPG_MAP_H_ */
