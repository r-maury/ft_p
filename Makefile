# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/17 17:46:02 by rmaury            #+#    #+#              #
#    Updated: 2018/01/17 17:50:44 by rmaury           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_p
CCLIB = 
CCFLAGS = -Wall -Werror -Wextra -g
SRCDIR = src/
OBJDIR = obj/
INCDIR = includes/
LIBDIR = 

SRC +=		main.c

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
	@gcc -c $(CCFLAGS) $(INCS) -I Libft/includes -I mlx -I /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.10.sdk/System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/ -o $@ $<