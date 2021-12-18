# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antheven <antheven@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/24 19:16:38 by antheven          #+#    #+#              #
#    Updated: 2021/12/18 02:41:58 by antheven         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR	= src
OUT_DIR	= src
SRC		= \
			main.c \
			util/ft_strlen.c \
			util/append.c \
			util/error.c \
			display/screen.c \
			game/loading.c \
			game/keyboard.c \
			game/texture.c \
			game/player.c \
			game/extras.c \
			game/level.c \
			game/loop.c \

OUT		= $(SRC:.c=.o)
BIN		= so_long
SRCS	= $(addprefix $(SRC_DIR)/, $(SRC))
OUTS	= $(addprefix $(OUT_DIR)/, $(OUT))
INC_DIR	= include -I minilibx-linux
LIBS	= -L minilibx-linux -lmlx -lX11 -lXext
FLAGS	= -Wall -Wextra -Werror

all: $(BIN)

$(BIN): $(OUTS)
	@printf "Packing out files.."
	@gcc -o $(BIN) $(OUTS) $(LIBS) $(FLAGS) -g3
#-fsanitize=address
	@echo "OK"

.c.o:
#	@echo "$(SRC_DIR)/$*.c => $(OUT_DIR)/$*.o"
	@echo "$< => $@"
	@$(CC) -I $(INC_DIR) -c -o $@ $< $(FLAGS) -g3
#	@mkdir -p $(OUT_DIR)/$*.o
#	@rm  -rf $(OUT_DIR)/$*.o
#	@$(CC) -I $(INC_DIR) -c -o $(OUT_DIR)/$*.o $(SRC_DIR)/$*.c $(CFLAGS)
#	printf " - OK%c" 10

clean:
	$(RM) $(OUTS)

fclean: clean
	$(RM) $(BIN)

re: fclean all