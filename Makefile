##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makesfiles
##

NAME 	=	my_rpg

CC		=	gcc

SRC		=	src/main/error_handler.c			\
			src/main/main.c						\
			src/game/window_event.c				\
			src/game/launch_game.c				\
			src/game/init_game.c				\
			src/game/end_game.c					\
			src/character/display_character.c	\
			src/character/manage_character.c	\
			src/character/load_character.c		\
			src/dialogue/display_dialogue.c		\
			src/dialogue/manage_dialogue.c		\
			src/dialogue/load_dialogue.c		\
			src/combat/display_combat.c			\
			src/combat/manage_combat.c			\
			src/combat/manage_fight.c			\
			src/combat/manage_action.c			\
			src/combat/load_combat.c			\
			src/world/display_world.c			\
			src/world/manage_world.c			\
			src/world/load_world.c				\
			src/menu/display_menu.c				\
			src/menu/load_inventory.c 			\
			src/menu/load_menu.c				\
			src/menu/load_pause.c				\
			src/menu/manage_choice.c 			\
			src/menu/manage_inventory.c			\
			src/menu/manage_menu.c				\
			src/menu/manage_pause.c				\
			src/menu/init_music.c				\
			src/menu/load_settings.c 			\
			src/menu/display_settings.c 		\
			src/menu/cut_scene.c  				\

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -W

CPPFLAGS	=	-Iincludes

CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

LIB		=	-L libs -lib -loli -lm

all:	$(NAME)

build_libs:
	make -C libs/oli
	make -C libs/ib
	scp libs/includes/ib.h includes/
	scp libs/includes/oli.h includes/
	scp libs/includes/oli_struct.h includes/

$(NAME):	build_libs	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CSFML) $(LIB)

clean:
	make -C libs/oli clean
	make -C libs/ib clean
	rm -f $(OBJ)

fclean:	clean
	make -C libs/oli fclean
	make -C libs/ib fclean
	rm -f $(NAME)
	rm -f includes/ib.h
	rm -f includes/oli.h
	rm -f includes/oli_struct.h

re: 	fclean all
