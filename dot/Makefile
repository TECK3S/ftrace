##
## Makefile for  in /home/souman_a//Desktop/my_project/test_graph
## 
## Made by abd-el-moxine soumanou
## Login   <souman_a@epitech.net>
## 
## Started on  Wed Jun 29 12:42:24 2011 abd-el-moxine soumanou
## Last update Wed Jun 29 23:28:20 2011 arnaud1 tessa
##

OUTPUT=	graph

SRC=	main.c\
	allocate_code_str.c\
	build_code_str.c\
	fill_dot_str.c\
	build_code.c\
	print_file.c\
	build_and_print_file.c\
	build_level.c\
	build_dot.c\
	build_sub_levels.c\
	init_dot_file.c\
	close_dot_file.c\
	generate_dot_file.c

CFLAGS	+=	-W -Wall -Wextra -g

.O=		$(SRC:.c=.o)

$(OUTPUT):	$(.O)
		gcc $(.O) -o $(OUTPUT) -L. -llist

clean:
		rm -f $(.O)

fclean:		clean
		rm -f $(OUTPUT)

re:		fclean $(OUTPUT)
