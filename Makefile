# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/17 17:46:02 by rmaury            #+#    #+#              #
#    Updated: 2018/01/18 14:23:47 by rmaury           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
CCLIB = 
CCFLAGS = -Wall -Werror -Wextra -g
SRCDIR = src/
OBJDIR = obj/
INCDIR = includes/
LIBDIR = Libft/libft.a

SRC +=	server.c

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INCS = $(addprefix -I , $(INCDIR))

all: $(NAME)
$(NAME): build $(OBJS)
	@make -C Libft
	@gcc $(CCLIB) $(CCFLAGS) -o $(NAME) $(OBJS) $(INCS) $(LIBDIR)
	@echo "All done!"
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