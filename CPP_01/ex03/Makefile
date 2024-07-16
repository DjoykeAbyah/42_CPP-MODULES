# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dreijans <dreijans@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/01/17 22:21:56 by dreijans      #+#    #+#                  #
#    Updated: 2024/06/04 18:07:34 by dreijans      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#executable
NAME 		= Violence

#compiler + flags
CC			= c++
CPPFLAGS	= -Wall -Wextra -g -fsanitize=address

#sources
SRC 		= 	main.cpp		\
				Weapon.cpp		\
				HumanA.cpp		\
				HumanB.cpp				

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
	@ echo "${YELLOW}Let's talk it out!${DONE}"

re:	fclean all

.PHONY: all clean fclean re