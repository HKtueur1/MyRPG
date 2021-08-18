/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** rpg_errors
*/

#ifndef RPG_ERRORS_H_
#define RPG_ERRORS_H_

static const char *error[] = {
//          ERROR 0
    "Usage: ./my_rpg [path]\n\n"
    "   [path]: the path to the file contaigning the map\n",
//          ERROR 1
    "Error: invalid arguments given\n"
    "       try './my_rpg -h' to see usage\n",
//          ERROR 2
    "Error: too many arguments\n"
    "       try './my_rpg -h' to see usage\n",
//          ERROR 3
    "' no such file or directory\n",
//          ERROR 4
    "Error: failed to create a window\n",
//          ERROR 5
    "Error: failed to load menu\n",
//          ERROR 6
    "Error: failed to load world\n",
//          ERROR 7
    "Error: failed to load combat\n",
//          ERROR 8
    "Error: failed to load dialogue\n",
//          ERROR 9
    "Error: failed to load player\n",
};

#endif /* !RPG_ERRORS_H_ */