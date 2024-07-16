# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: djoyke <djoyke@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2024/01/13 22:49:01 by djoyke        #+#    #+#                  #
#    Updated: 2024/05/28 20:42:42 by dreijans      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#executable
NAME 		= PhoneBook

#compiler + flags
CC			= c++
CPPFLAGS	= -Wall -Wextra -g -fsanitize=address

#sources
SRC 		= 	PhoneBook.cpp	\
				Contact.cpp		\
				UI.cpp			\
				main.cpp		\

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
	@ echo "${YELLOW}Phonebook thrown in the trash!${DONE}"

re:	fclean all

.PHONY: all clean fclean re