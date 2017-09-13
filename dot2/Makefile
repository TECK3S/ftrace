##
## Makefile for  in /home/souman_a//Desktop/my_project/test_graph
## 
## Made by abd-el-moxine soumanou
## Login   <souman_a@epitech.net>
## 
## Started on  Wed Jun 29 12:42:24 2011 abd-el-moxine soumanou
## Last update Sun Jul  3 19:59:36 2011 arnaud1 tessa
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
	generate_dot_file.c\
	allocate_declaration.c\
	build_declaration.c\
	set_declaration_attributes.c\
	set_symbol_name.c\
	build_symbol_name.c\
	int_to_str.c\
	fill_symbol_name.c\
	allocate_symbol_name.c\
	set_label.c\
	set_shape.c\
	set_color.c\
	build_declaration_code.c

CFLAGS	+=	-W -Wall -Wextra -g

.O=		$(SRC:.c=.o)

$(OUTPUT):	$(.O)
		gcc $(.O) -o $(OUTPUT) -L. -llist

clean:
		rm -f $(.O)

fclean:		clean
		rm -f $(OUTPUT)

re:		fclean $(OUTPUT)
