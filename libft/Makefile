# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/31 11:42:48 by thakala           #+#    #+#              #
#    Updated: 2021/12/22 18:54:18 by thakala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FUNCTIONS = \
	ft_strlen \
	ft_strcpy \
	ft_strcat \

SRCS = $(foreach src, $(FUNCTIONS), $(addsuffix .c, $(src)))

OBJS = $(foreach obj, $(FUNCTIONS), $(addsuffix .o, $(obj)))

INCLUDES = -I./includes

CC = clang

COMP_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(COMP_FLAGS) $(INCLUDES) -c $(SRCS)
	ar rcs $(NAME) $(OBJS)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
