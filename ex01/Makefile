CC = c++

CFLAGS = -Wall -Wextra -Werror -g -std=c++98

NAME = form

DIR_SRCS	=	.
DIR_OBJS	=	.objs

LST_SRCS =	main.cpp\
			Form.cpp \
			Bureaucrat.cpp \

LST_OBJS = $(LST_SRCS:.cpp=.o)

SRCS		=	$(addprefix $(DIR_SRCS)/, $(LST_SRCS))
OBJS		=	$(addprefix $(DIR_OBJS)/, $(LST_OBJS))

ERASE		=	\033[2K\r
BLUE		=	\033[34m
YELLOW		=	\033[33m
GREEN		=	\033[32m
END			=	\033[0m

all : $(NAME)

$(DIR_OBJS)/%.o : $(DIR_SRCS)/%.cpp
	@mkdir -p .objs
	@$(CC) $(CFLAGS) -o $@ -c $<
	@printf "$(BLUE) > Compilation :$(END) $<\n"


$(NAME) :   $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
	@printf "$(ERASE)$(GREEN)$(NAME) made !\n$(END)"

clean   :
	@printf "$(YELLOW)$(DIR_OBJS) removed$(END)\n"
	@rm -rdf $(DIR_OBJS)

fclean  :   clean
	@printf "$(YELLOW)$(NAME) removed$(END)\n"
	@rm -f $(NAME)

re      :   fclean all
