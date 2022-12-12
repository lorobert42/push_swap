# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 14:40:57 by lorobert          #+#    #+#              #
#    Updated: 2022/11/25 10:58:05 by lorobert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	push_swap
NAMEB	:=	checker

SRCS_BASE	:=	ft_sort.c \
			ft_sort_small.c \
			ft_sort_large.c \
			ft_basic_operations.c \
			ft_advanced_operations.c \
			ft_stack_init.c \
			ft_stack.c \
			ft_tab.c \
			ft_chunk.c \
			ft_math.c \
			ft_strslen.c \
			ft_error.c \
			ft_parse_arg.c
SRCS	:=	push_swap.c \
			$(SRCS_BASE)
OBJS	:=	$(SRCS:.c=.o)
SRCSB	:=	ft_checker.c \
			get_next_line.c \
			$(SRCS_BASE)
OBJSB	:=	$(SRCSB:.c=.o)

LIBS	:=	ft
LIBS_TARGET	:=	libft/libft.a

INCS	:=	libft

CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror -g
CPPFLAGS	:=	$(addprefix -I, $(INCS)) -MMD -MP
LDFLAGS	:=	$(addprefix -L, $(dir $(LIBS_TARGET)))
LDLIBS	:=	$(addprefix -l, $(LIBS))

RM		:=	rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)

$(LIBS_TARGET):
	make bonus -C $(@D)

bonus: $(NAME) $(OBJSB) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJSB) $(LDLIBS) -o $(NAMEB)

clean:
	for f in $(dir $(LIBS_TARGET)); do make -C $$f clean; done
	$(RM) $(OBJS)

fclean: clean
	for f in $(dir $(LIBS_TARGET)); do make -C $$f fclean; done
	$(RM) $(NAME)

re:	fclean all

.PHONY: all bonus clean fclean re
