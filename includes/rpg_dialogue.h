/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-mark.bekker
** File description:
** rpg_dialogue
*/

#ifndef RPG_DIALOGUE_H_
#define RPG_DIALOGUE_H_

static const char *dialogue_spawn[] = {
    "Well well well, what do we got here?",
    "It’s look like you choose the escape option...",
    "HHAHAHAHAHAHAHAHAHAHAHAHAHAH",
    "Your babies are waiting...",
    "So don’t be foolish and OBEY!",
};

static const char *dialogue_map_1[] = {
    "We meet again.",
    "...",
    "Do you really think that you can defeat someone in this cave?",
    "How sad, you only know how to bite.",
    "So don't think you can stand a chance against anyone!",
};

static const char *dialogue_map_2[] = {
    "Still alive?",
    "And you’ve learned a new skill ...",
    "It allows you to raise your defense by using your silk?",
    "I admit it, I'm kind of impressed.",
    "But you must surrender, as long as you still can.",
};

static const char *dialogue_map_3[] = {
    "H-How could you??",
    "You was’nt supposed to defeat them !!",
    "And now you’ve learned a new skill that allows you to sting ??",
    "Do you really think you can escape ??",
    "Well.. PREPARE TO DIE !!",
};

static const char **dialogue[] = {
    dialogue_spawn,
    dialogue_map_1,
    dialogue_map_2,
    dialogue_map_3,
};

#endif /* !RPG_DIALOGUE_H_ */
