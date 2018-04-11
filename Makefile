# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/17 17:46:02 by rmaury            #+#    #+#              #
#    Updated: 2018/04/11 12:00:21 by rmaury           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMES = server client
CCLIB = 
CCFLAGS = -Wall -Werror -Wextra -g
SRCDIR = src
OBJDIR = obj
INCDIR = includes/
LIBDIR = Libft/libft.a

S_SRC +=	server.c
S_SRC +=	get_next_line.c

C_SRC +=	client.c
C_SRC +=	get_next_line.c

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
S_OBJS = $(addprefix $(OBJDIR)/, $(S_SRC:.c=.o))
C_OBJS = $(addprefix $(OBJDIR)/, $(C_SRC:.c=.o))
INCS = $(addprefix -I , $(INCDIR))

all: $(NAMES)

server: build $(S_OBJS)
	@make -C Libft
	@gcc $(CCLIB) $(CCFLAGS) -o server $(S_OBJS) $(INCS) $(LIBDIR)
	@echo "Server built!"

client: build $(C_OBJS)
	@make -C Libft
	@gcc $(CCLIB) $(CCFLAGS) -o client $(C_OBJS) $(INCS) $(LIBDIR)
	@echo "Client built!"

build:
	@mkdir -p $(OBJDIR)

clean:
	@make -C Libft clean
	@rm -f $(OBJS)

fclean: clean
	@make -C Libft fclean
	@rm -f $(NAME)
	@rm -rf obj

re: fclean all

dev : all
	@./$(NAME)

.PHONY: clean fclean all

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@gcc -c $(CCFLAGS) $(INCS) -I Libft/includes -o $@ $<