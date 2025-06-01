# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: djoyke <djoyke@student.42.fr>                +#+                      #
#                                                    +#+                       #
#    Created: 2024/01/13 18:33:13 by djoyke        #+#    #+#                  #
#    Updated: 2024/01/13 20:46:24 by djoyke        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#executable
NAME 		= megaphone

#compiler + flags
CC			= c++
CPPFLAGS	= -Wall -Wextra -Werror

#sources
SRC 		= megaphone.cpp

#object files
OBJDIR 		= obj
OBJ			= $(addprefix $(OBJDIR)/, $(notdir $(SRC:.cpp=.o)))

#colours
DONE		:= \033[0m
RED			:= \033[1;91m
GREEN		:= \033[1;92m
YELLOW		:= \033[1;93m
BLUE		:= \033[1;94m
PURPLE		:= \033[1;95m
CYAN		:= \033[1;96m
WHITE		:= \033[1;97m
BLACK		:= \033[1;90m


#targets
all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CPPFLAGS) -o $(NAME)
	@ echo "${PURPLE}made!${DONE}"

$(OBJDIR)/%.o: %.cpp
	@ mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $^

#cleaning
clean:
	@ rm -rf $(OBJDIR)

fclean: clean
	@ rm -f $(NAME)
	@ echo "${YELLOW}megaphone stowed away!${DONE}"

re:	fclean all

.PHONY: all clean fclean re norminette run flags thread-flags
