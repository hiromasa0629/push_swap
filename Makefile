# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/01 15:24:00 by hyap              #+#    #+#              #
#    Updated: 2022/07/15 10:44:05 by hyap             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ${wildcard srcs/*.c}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

RM = rm -f

FTPRINTF = libftprintf.a

FSANITIZE = -fsanitize=address -g3

all: $(NAME)

$(NAME): ${SRCS}
	${CC} ${CFLAGS} -I includes ${SRCS} ${FTPRINTF} -o ${NAME}

clean:
	${RM} ${NAME}

run:
	@ \
	declare -a list; \
	dup="true"; \
	for i in $$(seq 1 $(NUM)); \
	do \
		dup="true"; \
		rand=$$(((RANDOM % 10000) + 1)); \
		while [[ $$dup == "true" ]]; \
		do \
			rand=$$(((RANDOM % 10000) + 1)); \
			dup="false"; \
			for j in $$(seq 1 $$i); \
			do \
				if [[ $${list[$$j]} == $$rand ]]; \
				then \
					dup="true"; \
					break; \
				fi \
			done; \
		done; \
		list[$$i]=$$rand; \
	done; \
	for k in $$(seq 1 $(NUM)); \
	do \
		str+="$${list[$$k]} "; \
	done; \
	str=$${str%?}; \
	./${NAME} $$str; \

check:
	@ \
	declare -a list; \
	dup="true"; \
	for i in $$(seq 1 $(NUM)); \
	do \
		dup="true"; \
		rand=$$(((RANDOM % 10000) + 1)); \
		while [[ $$dup == "true" ]]; \
		do \
			rand=$$(((RANDOM % 10000) + 1)); \
			dup="false"; \
			for j in $$(seq 1 $$i); \
			do \
				if [[ $${list[$$j]} == $$rand ]]; \
				then \
					dup="true"; \
					break; \
				fi \
			done; \
		done; \
		list[$$i]=$$rand; \
	done; \
	for k in $$(seq 1 $(NUM)); \
	do \
		str+="$${list[$$k]} "; \
	done; \
	str=$${str%?}; \
	./${NAME} $$str | ./checker_Mac $$str; \

sanitize:
	${CC} ${CFLAGS} ${FSANITIZE} -I includes ${SRCS} ${FTPRINTF} -o ${NAME}

re: clean all

.PHONY: all clean re