NAME	:= fdf
LIBFT	:= libft
MLX_DIR	:= MLX42/
MLX42	:= MLX42/build
OBJ_DIR	:= obj/
SRC_DIR	:= src/
INCLUDE	:= -I include -I libft/include -I $(MLX_DIR)include/MLX42
CC		:= cc

# Reset
NC		= \033[0m# 		Text Reset

# Regular Colors
BLACK	= \033[0;30m#	Black
RED		= \033[0;31m#	Red
GREEN	= \033[1;32m#	Green
YELLOW	= \033[1;33m#	Yellow
BLUE	= \033[1;34m#	Blue
PURPLE	= \033[0;35m#	Purple
BLD_PUR	= \033[1;35m#	Purple but bold
CYAN	= \033[1;36m#	Cyan
WHITE	= \033[1;37m#	White

ifeq ($(shell uname), Linux)
	MLXFM	:= -ldl -lglfw -pthread -lm
else
	MLXFM	:= -framework Cocoa -framework OpenGL -framework IOKit -lglfw3
endif

ifdef WITH_DEBUG
CFLAGS	:= -g -fsanitize=address
else
CFLAGS	:= -Wall -Werror -Wextra
endif

GRID_DIR	:= grid/
GRID_FILES	:= $(GRID_DIR)init_grid.c $(GRID_DIR)init_grid_utils.c $(GRID_DIR)center_grid.c $(GRID_DIR)grid_rotation.c

MISC_DIR	:= misc/
MISC_FILES	:= $(MISC_DIR)err.c $(MISC_DIR)put_functions.c $(MISC_DIR)operations.c $(MISC_DIR)color_utils.c

GNL_DIR		:= get_next_line/
GNL_FILES	:= $(GNL_DIR)get_next_line.c $(GNL_DIR)get_next_line_utils.c

BONUS_DIR	:= bonus/
BONUS_FILES	:= $(BONUS_DIR)ft_fdf_bonus.c $(BONUS_DIR)griddup_bonus.c $(BONUS_DIR)utils_bonus.c $(BONUS_DIR)hooks_bonus.c \
			   $(BONUS_DIR)put_instruction.c

ifdef WITH_BONUS
FILES		+= $(BONUS_FILES)
else
FILES		+= ft_fdf.c
MISC_FILES	+= $(MISC_DIR)hooks.c
endif

FILES 		+= $(GNL_FILES) $(GRID_FILES) $(MISC_FILES)
SRC_FILES	= $(addprefix $(SRC_DIR), $(FILES))
OBJ_FILES	= $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

all: $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(MLX42) $(OBJ_DIR)
	@echo "$(RED)compiling:$(NC)" "$(BLUE)$^$(NC)"
	@$(CC) $(INCLUDE) $(CFLAGS) $(NLXFM) -c $^ -o $@

$(MLX42):
	@cmake $(MLX_DIR) -B $@

$(OBJ_DIR):
	@echo "$(YELLOW)creating folders..."
	@mkdir -p $@
	@mkdir -p $(OBJ_DIR)$(GNL_DIR)
	@mkdir -p $(OBJ_DIR)$(GRID_DIR)
	@mkdir -p $(OBJ_DIR)$(MISC_DIR)
	@mkdir -p $(OBJ_DIR)$(BONUS_DIR)

$(NAME): $(OBJ_FILES)
	@echo "$(PURPLE)============================[$(NC)$(BLD_PUR)$(LIBFT)$(NC)$(PURPLE)]============================$(NC)"
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(MLX42)
	@echo "$(PURPLE)============================[$(NC)$(BLD_PUR)$(NAME)$(NC)$(PURPLE)]============================$(NC)"
	@echo "$(YELLOW)creating $@..."
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(MLX42)/libmlx42.a $(LIBFT)/libft.a  $(INCLUDE) $(MLXFM) -o  $@
	@echo "$(GREEN)done!$(NC)"

bonus:
	$(MAKE) WITH_BONUS=1 all

debug:
	$(MAKE) WITH_DEBUG=1 bonus

clean:
	@echo "$(CYAN)cleaning...$(NC)"
	@$(MAKE) clean -C $(LIBFT)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT)
	@$(MAKE) -C $(MLX42) clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus debug clean fclean re
