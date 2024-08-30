NAME        := push_swap

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#
# SRC_DIR   source directory
# OBJ_DIR   object directory
# SRCS      source files
# OBJS      object files
#
# CC        compiler
# CFLAGS    compiler flags
# CPPFLAGS  preprocessor flags

SRC_DIR     := srcs
OBJ_DIR     := obj
LIBFT_DIR   := srcs/libft
SRCS        := \
			main.c \
			check_arguments/single_argument.c \
			check_arguments/multiple_arguments.c \
			check_arguments/edge_cases.c \
			errors/ft_error_arguments.c \
			errors/ft_error_parsing.c \
			parsing_validation/process_arguments.c \
			parsing_validation/convert_to_int.c \
			parsing_validation/process_multi_argument_helper_functions.c \
			stacks/pushswap.c \
			stacks/operations/push.c \
			stacks/operations/swap.c \
			stacks/operations/reverse.c \
			stacks/operations/rotate.c \
			stacks/turk_algorithm/find_min_max_value.c \
			stacks/turk_algorithm/sorting_small_stack.c \
			stacks/turk_algorithm/utils.c \
			stacks/turk_algorithm/sort_bigger.c \
			stacks/turk_algorithm/set_stacks.c \
			stacks/turk_algorithm/sorting_loop.c \
			stacks/turk_algorithm/other_functions.c \
			stacks/turk_algorithm/calculate_move_cost.c \
			free_memory/free_array.c \
			free_memory/free_stacks.c \

SRCS        := $(SRCS:%=$(SRC_DIR)/%)
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIBFT       := $(LIBFT_DIR)/libft.a

CC          := cc
CFLAGS      := -Wall -Wextra -Werror
CPPFLAGS    := -I includes -I $(LIBFT_DIR)


#------------------------------------------------#
#   UTENSILS                                     #
#------------------------------------------------#
# RM        force remove
# MAKEFLAGS make flags
# DIR_DUP   duplicate directory tree

RM          := rm -f
MAKEFLAGS   += --no-print-directory
DIR_DUP     = mkdir -p $(@D)

RED		=	\033[91;1m
GREEN	=	\033[92;1m
YELLOW	=	\033[93;1m
BLUE	=	\033[94;1m
PINK	=	\033[95;1m
CLEAR	=	\033[0m

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#
# all       default goal
# $(NAME)   linking .o -> binary
# %.o       compilation .c -> .o
# clean     remove .o
# fclean    remove .o + binary
# re        remake default goal

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "$(BLUE)Make all$(CLEAR)\n$(PINK)Compiling push_swap.$(CLEAR)"
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	$(info CREATED $(NAME))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	@echo "$(BLUE)Make clean/fclean$(CLEAR)\n$(RED)Removing all compiled files.$(CLEAR)"
	@$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

#------------------------------------------------#
#   SPEC                                         #
#------------------------------------------------#

.PHONY: clean fclean re all
.SILENT:
