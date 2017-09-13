##
## Makefile for <OCaml> in /home/barrau_a//ocaml/test
## 
## Made by adrien barrau
## Login   <barrau_a@epitech.net>
## 
## Started on  Sat Apr  2 00:50:18 2011 adrien barrau
## Last update Sun May 15 20:16:34 2011 adrien barrau
##

NAME		=	syscallGen

NAME_BYTE	=	$(NAME).byte

ML		=	main.ml

MLI		=

CMI		=	$(MLI:.mli=.cmi)

CMX		=	$(ML:.ml=.cmx)

CMO		=	$(ML:.ml=.cmo)

OCAMLFLAGS	=	-w Aelz -warn-error A

OCAMLC		=	ocamlc

OCAMLOPT	=	ocamlopt

RM		=	rm -f

all		:	$(CMI) $(NAME)

%.cmi		:	%.mli
			$(OCAMLC) -c $(OCAMLFLAGS) $< -o $@

%.cmx		:	%.ml
			$(OCAMLOPT) -c $(OCAMLFLAGS) $< -o $@

$(NAME)		:	$(CMX)
			$(OCAMLOPT) -o $(NAME) nums.cmxa $(CMX)

byte		:	$(CMI) $(NAME_BYTE)

%.cmo		:	%.ml
			$(OCAMLC) -c $(OCAMLFLAGS) $< -o $@

$(NAME_BYTE)	:	$(CMO)
			$(OCAMLC) -o $(NAME_BYTE) nums.cma $(CMO)

clean		:
			$(RM) *.cm*
			$(RM) *.o

fclean		:	clean
			$(RM) $(NAME)
			$(RM) $(NAME_BYTE)

re		:	fclean all

.PHONY		:	all byte clean fclean re
