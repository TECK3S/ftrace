##
## Makefile for <Ftrace> in /home/barrau_a//c_avancee/ftrace
## 
## Made by adrien barrau
## Login   <barrau_a@epitech.net>
## 
## Started on  Fri Jun 24 14:59:51 2011 adrien barrau
## Last update Sun Jul  3 22:55:25 2011 adrien barrau
##

NAME	=	ftrace

SRCS	=	main.c		\
		tracing.c	\
		sig_handler.c	\
		syscalls_mgr.c	\
		call_mgr.c	\
		display_graph.c	\
		symtab.c	\
		get_sym.c	\
		insert_node.c	\
		call_ff_mgr.c	\
		utilities1.c	\
		utilities2.c	\
		utilities3.c	\
		utilities4.c	\
                utilities5.c    \
                utilities6.c    \
                utilities7.c    \
                utilities8.c    \
                utilities9.c    \
                utilities10.c   \
                utilities11.c   \
                utilities12.c   \
                utilities13.c   \
                utilities14.c   \
                utilities15.c   \
		syscalls1.c     \
		syscalls2.c	\
		syscalls3.c	\
		syscalls4.c	\
		syscalls5.c	\
		syscalls6.c	\
		syscalls7.c	\
		syscalls8.c	\
		syscalls9.c	\
		syscalls10.c	\
		syscalls11.c	\
		syscalls12.c	\
		syscalls13.c	\
		syscalls14.c	\
		syscalls15.c	\
		syscalls16.c	\
		syscalls17.c	\
		syscalls18.c	\
		syscalls19.c	\
		syscalls20.c	\
		syscalls21.c	\
		syscalls22.c	\
		syscalls23.c	\
		syscalls24.c	\
		syscalls25.c	\
		syscalls26.c	\
		syscalls27.c	\
		syscalls28.c	\
		syscalls29.c	\
		syscalls30.c	\
		syscalls31.c	\
		syscalls32.c	\
		syscalls33.c	\
		syscalls34.c	\
		syscalls35.c	\
		syscalls36.c	\
		syscalls37.c	\
		syscalls38.c	\
		syscalls39.c	\
		syscalls40.c	\
		syscalls41.c	\
		syscalls42.c	\
		syscalls43.c	\
		syscalls44.c	\
		syscalls45.c	\
		syscalls46.c	\
		syscalls47.c	\
		syscalls48.c	\
		syscalls49.c	\
		syscalls50.c	\
		syscalls51.c	\
		syscalls52.c	\
		syscalls53.c	\
		syscalls54.c	\
		syscalls55.c	\
		syscalls56.c	\
		syscalls57.c	\
		syscalls58.c	\
		syscalls59.c	\
		syscalls60.c	\
		syscalls61.c	\
		syscalls62.c	\
		syscalls63.c	\
		syscalls64.c	\
		syscalls65.c	\
		syscalls66.c	\
		syscalls67.c	\
		dot2/build_code_str.c	\
		dot2/allocate_code_str.c	\
		dot2/fill_dot_str.c	\
		dot2/build_code.c	\
		dot2/print_file.c	\
		dot2/build_and_print_file.c	\
		dot2/build_dot.c	\
		dot2/build_level.c	\
		dot2/build_sub_levels.c	\
		dot2/init_dot_file.c	\
		dot2/generate_dot_file.c	\
		dot2/close_dot_file.c	\
		dot2/build_symbol_name.c	\
		dot2/int_to_str.c	\
		dot2/allocate_symbol_name.c	\
		dot2/fill_symbol_name.c	\
		dot2/build_declaration.c	\
		dot2/set_declaration_attributes.c	\
		dot2/build_declaration_code.c	\
		dot2/allocate_declaration.c	\
		dot2/set_symbol_name.c	\
		dot2/set_label.c	\
		dot2/set_shape.c	\
		dot2/set_color.c

OBJS	=	$(SRCS:.c=.o)

INC	=	includes/

LIB	=	lib/

ELF	=	elf
LIST	=	list

CFLAGS	+=	-W -Wall -Wextra -Werror -I $(INC)

LDFLAGS	=	-L$(LIB) -l$(ELF) -l$(LIST)

CC	=	gcc

RM	=	rm -rf

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
