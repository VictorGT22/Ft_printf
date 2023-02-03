# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 23:08:02 by efrre-m           #+#    #+#              #
#    Updated: 2023/02/03 04:10:19 by victgonz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER = includes/include/
NAME = libftprintf.a

SRCS =	src/ft_printf.c 				\
			src/func_ptr.c				\
			src/func_putnbr.c 			\
			src/utils_1.c					\
			src/utils_2.c					\
			src/std_func.c 				\
			src/func_conv/func_s_c.c 		\
			src/func_conv/func_e_f.c		\
			src/func_conv/func_p.c		\
			src/func_conv/func_u.c		\
			src/func_conv/func_x.c		\
			src/func_conv/func_o.c		\
			src/func_conv/func_d_i.c		\
			src/func_conv/func_b.c		\
			src/func_conv/func_g.c		\
			src/func_conv/func_n.c		\
			src/get_info/get_info.c	 	\
			src/get_info/get_info_2.c		\
			src/free_info/free_1.c

LIBS_DIR = lib/my

CC = gcc
RM = rm -f
CFLAGS = 

OBJS = ${SRCS:.c=.o}

OBJBONUS = $(SRCS:.c=.o)

%.o: %.c  $(HEADER)
	$(CC) $(CFLAGS) -I $(HEADER) -c -o $@ $<

all: 		make_libs ${NAME}

make_libs:
			@make -C $(LIBS_DIR)
			
${NAME}:	${OBJS} lib/my/libft.a
			cp lib/my/libft.a ${NAME}
			ar rcs ${NAME} ${OBJS} 
			ranlib ${NAME}

bonus: $(BONUS)

$(BONUS) : $(OBJSBONUS) lib/my/libft.a
			cp lib/my/libft.a ${NAME}
			ar rcs ${NAME} ${OBJSBONUS} 
			ranlib ${NAME}
			
clean: 		
			${RM} ${OBJS} ${OBJSBONUS} 
			make clean -C $(LIBS_DIR)

fclean: 	clean
			${RM} ${NAME}
			make fclean -C $(LIBS_DIR)

re:			fclean all

.PHONY: all clean fclean re