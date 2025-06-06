# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dreijans <dreijans@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/01/17 22:21:56 by dreijans      #+#    #+#                  #
#    Updated: 2025/05/15 17:37:53 by djoyke        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#executable
NAME 		= btc

#compiler + flags
CC			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++11 -g -fsanitize=address -I $(HEADERDIR)
# CPPFLAGS	= -Wall -Wextra -Werror -std=c++11 -g -fsanitize=address -I

#sources
SRC 		= 	./src/main.cpp \
				./src/BitcoinExchange.cpp
				
#object files
OBJDIR 		= obj
OBJ			= $(addprefix $(OBJDIR)/, $(notdir $(SRC:.cpp=.o)))

# Header files
HEADERDIR	= ./header

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
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@ echo "${PURPLE}made!${DONE}"

$(OBJDIR)/%.o: ./src/%.cpp
	@ mkdir -p $(OBJDIR)
	$(CC) $(CPPFLAGS) -c -o $@ $^

#cleaning
clean:
	@ rm -rf $(OBJDIR)

fclean: clean
	@ rm -f $(NAME)
	@ echo "${YELLOW}Cleaning done${DONE}"

re:	fclean all

.PHONY: all clean fclean re
