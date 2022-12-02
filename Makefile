# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 14:02:39 by lgenevey          #+#    #+#              #
#    Updated: 2022/12/02 05:24:11 by hrolle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

# SRCS	=	main.c \
# 			srcs/binaries/build_absolute_path.c \
# 			srcs/binaries/execute_non_builtins.c \
# 			srcs/builtins/ft_env.c \
# 			srcs/builtins/ft_export.c \
# 			srcs/builtins/ft_unset.c \
# 			srcs/builtins/ft_exit.c \
# 			srcs/builtins/ft_pwd.c \
# 			srcs/builtins/ft_echo.c \
# 			srcs/execution/is_builtin.c \
# 			srcs/init/list_utils.c \
# 			srcs/init/init_env.c \
# 			srcs/init/init_export.c \
# 			srcs/init/init_shell.c \
# 			srcs/parsing/get_cmds.c \
# 			srcs/parsing/print_cmdli.c \
# 			srcs/parsing/heredoc.c \
# 			srcs/signals/sig_handler.c

#SRCS	=	$(wildcard srcs/*/*.c *.c)

SRCS	=	main.c                                   srcs/execution/no_cmd.c                  srcs/init/ft_prompt_utils.c              srcs/parsing/create_cmdli.c		\
			srcs/builtins/builtins_utils.c           srcs/execution/set_redirection.c         srcs/init/init_env.c                     srcs/parsing/error_cmdli.c		\
			srcs/builtins/ft_cd.c                    srcs/images/image_10_12.c                srcs/init/init_export.c                  srcs/parsing/free_cmdli.c		\
			srcs/builtins/ft_echo.c                  srcs/images/image_13_15.c                srcs/init/init_shell.c                   srcs/parsing/free_tab.c			\
			srcs/builtins/ft_env.c                   srcs/images/image_16_18.c                srcs/init/list_utils.c                   srcs/parsing/get_cmds.c			\
			srcs/builtins/ft_exit.c                  srcs/images/image_19_20.c                srcs/parsing/add_andor.c                 srcs/parsing/heredoc.c			\
			srcs/builtins/ft_export.c                srcs/images/image_1_2.c                  srcs/parsing/add_arg.c                   srcs/parsing/print_cmdli.c		\
			srcs/builtins/ft_export_utils.c          srcs/images/image_3_4.c                  srcs/parsing/add_cmd.c                   srcs/parsing/print_tab.c			\
			srcs/builtins/ft_pwd.c                   srcs/images/image_5_6.c                  srcs/parsing/add_dquote.c                srcs/parsing/split_cmd.c			\
			srcs/builtins/ft_unset.c                 srcs/images/image_7_9.c                  srcs/parsing/add_file.c                  srcs/parsing/token_buff.c		\
			srcs/execution/builtin_set_file.c        srcs/init/ft_get_env.c                   srcs/parsing/add_pipe.c                  srcs/parsing/type_and_set.c		\
			srcs/execution/exec_cmd.c                srcs/init/ft_get_export.c                srcs/parsing/add_quote.c                 srcs/secure/error.c				\
			srcs/execution/get_absolute_path.c       srcs/init/ft_get_shell.c                 srcs/parsing/add_var.c                   srcs/secure/free_tab_null.c		\
			srcs/execution/get_absolute_path_utils.c srcs/init/ft_get_str_env.c               srcs/parsing/add_wildcard.c              srcs/secure/ft_say.c				\
			srcs/execution/get_path_utils.c          srcs/init/ft_get_var.c                   srcs/parsing/cmdli_first.c               srcs/secure/print_minishell.c	\
			srcs/execution/is_builtin.c              srcs/init/ft_prompt.c                    srcs/parsing/cmdli_utils.c               srcs/signals/sig_handler.c

INC_FLAGS := -Ilibs/libft/incs -Iincs
LIBS := -Llibft -lft -lreadline

INC_FLAGS += -I$(HOME)/.brew/opt/readline/include
LIBS += -L$(HOME)/.brew/opt/readline/lib

OBJS	=	$(SRCS:.c=.o)
CC		=	gcc
RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

ifeq ($(DEBUG), 1)
	CFLAGS += -fsanitize=address -g3
endif

BLUE	= \033[0;34m
VIOLET	= \033[0;36m
GREEN	= \033[0;32m
RED		= \033[0;31m
YELLOW	= \033[0;33m
NONE	= \033[0m

all:	$(NAME)

%.o: %.c
	@printf "Compiling %-43s \r" $<
	@$(CC) -c $< -o $@

$(NAME)	: $(OBJS)
	@echo "$(BLUE)Making libft and bonuses... $(NONE)"
	@$(MAKE) -C printfd
	@$(MAKE) -C libft
	@$(MAKE) -C libft bonus
	@$(CC) $(CFLAGS) $(INC_FLAGS) $(OBJS) $(LIBS) printfd/libftprintfd.a -o $(NAME)
	@printf "$(GREEN) $(NAME) ready.\n$(NONE)"

norm:
	@echo "$(VIOLET)[NORM - START]$(NONE)"
	@norminette srcs/*/*.*
	@echo "$(VIOLET)[NORM - END]$(NONE)"

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C libft clean
	@$(MAKE) -C printfd clean
	@printf "$(GREEN) OBJS removed.\n$(NONE)"

fclean:	clean
	@$(RM) $(NAME)
	@$(RM) printfd/libftprintfd.a
	@$(RM) libft/libft.a
	@printf "$(GREEN) libft.a removed.\n$(NONE)"
	@printf "$(GREEN) $(NAME) removed.\n$(NONE)"

re: fclean all

.PHONY:	all clean fclean re
.SILENT: $(NAME) bonus clean fclean re
