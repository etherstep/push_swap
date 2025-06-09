# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/24 16:41:49 by jpelline          #+#    #+#              #
#    Updated: 2025/05/26 21:57:34 by jpelline         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors and formatting
BOLD		:= $(shell tput bold)
GREEN		:= $(shell tput setaf 2)
YELLOW		:= $(shell tput setaf 3)
BLUE		:= $(shell tput setaf 4)
MAGENTA		:= $(shell tput setaf 5)
CYAN		:= $(shell tput setaf 6)
WHITE		:= $(shell tput setaf 7)
RESET		:= $(shell tput sgr0)

# Program name
NAME		:=	push_swap

# Compiler flags
CC			:=	cc
CFLAGS		:=	-Wextra -Wall -Werror
OPTFLAGS	:=	-O2
DEBUG_FLAGS	:=	-g3 -fsanitize=address -fsanitize=undefined

# Directories
OBJ_DIR		:= obj
SRC_DIR		:= src

# Dependencies tracking
DEP_DIR		:= $(OBJ_DIR)/.deps
DEPFLAGS	= -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d

# Libraries
LIBFT_DIR	:=	./libft
LIBFT		:=	$(LIBFT_DIR)/libft.a

# Additional flags
LDFLAGS		:=	-L$(LIBFT_DIR) -lft

# Include paths
INC			:= -I./include -I$(LIBFT_DIR)

# Sources
SRCS		:=	push_swap.c parsing.c utils.c swap.c \
				sort.c radix_sort.c push.c rotate.c reverse.c

OBJS		:=	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

# Calculating SRCS amount
TOTAL_SRCS	:=	$(words $(SRCS))

# Create progress file for tracking compilation
PROGRESS_FILE := $(OBJ_DIR)/.progress

# Default target
all:
	@if [ -f $(NAME) ] && $(MAKE) -q $(NAME); then \
		echo "$(BOLD)$(YELLOW)🔄 $(NAME) is already up to date.$(RESET)"; \
	else \
		echo "$(BOLD)$(WHITE)🌀 Starting to build $(NAME)...$(RESET)"; \
		$(MAKE) $(NAME) --no-print-directory; \
		echo "$(BOLD)$(GREEN)✅ All components built successfully!$(RESET)"; \
	fi

# Debug target
debug: CFLAGS += $(DEBUG_FLAGS)
debug: OPTFLAGS := -O0
debug: clean $(NAME)
	@echo "$(BOLD)$(CYAN)🐛 Debug build completed!$(RESET)"

# Main executable target - links all objects and libraries
$(NAME): $(OBJS) $(LIBFT)
	@echo "$(BOLD)$(GREEN)🔗 Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(OPTFLAGS)
	@echo "$(BOLD)$(GREEN)✅ $(NAME) successfully compiled!$(RESET)"
	@rm -f $(PROGRESS_FILE)

# Create necessary directories if they don't exist
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "0" > $(PROGRESS_FILE)

$(DEP_DIR): | $(OBJ_DIR)
	@mkdir -p $@

# Compilation rule for each source file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(DEP_DIR)
	@if [ -f $(PROGRESS_FILE) ]; then \
		CURRENT=$$(cat $(PROGRESS_FILE)); \
		NEXT=$$((CURRENT + 1)); \
		echo "$$NEXT" > $(PROGRESS_FILE); \
		printf "🔧 [%3d%%] $(BOLD)$(BLUE)Compiling $<...$(RESET)\n" \
			$$((NEXT*100/$(TOTAL_SRCS))); \
	fi
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(OPTFLAGS) -c $< -o $@ $(INC)

# Include auto-generated dependency files
-include $(wildcard $(DEP_DIR)/*.d)

# build libft if needed
$(LIBFT):
	@echo "$(MAGENTA)📚 Building libft library...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIR) --no-print-directory

# Remove object files and dependency files
clean:
	@echo "$(YELLOW)🧹 Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -sC $(LIBFT_DIR) clean --no-print-directory
	@echo "$(YELLOW)✅ Object files cleaned!$(RESET)"

# Remove everything including the executable
fclean: clean
	@echo "$(YELLOW)🧹 Removing $(NAME)...$(RESET)"
	@rm -rf $(NAME)
	@$(MAKE) -sC $(LIBFT_DIR) fclean --no-print-directory
	@echo "$(YELLOW)✅ $(NAME) removed!$(RESET)"

# Full rebuild from scratch
re: fclean
	@echo "$(BOLD)$(WHITE)🔄 Rebuilding from scratch...$(RESET)"
	@$(MAKE) -s all

# Additional useful targets
help:
	@echo "$(BOLD)$(CYAN)Available targets:$(RESET)"
	@echo "  $(GREEN)all$(RESET)     - Build the project (default)"
	@echo "  $(GREEN)debug$(RESET)   - Build with debug flags and sanitizers"
	@echo "  $(GREEN)clean$(RESET)   - Remove object files"
	@echo "  $(GREEN)fclean$(RESET)  - Remove all generated files"
	@echo "  $(GREEN)re$(RESET)      - Rebuild from scratch"
	@echo "  $(GREEN)help$(RESET)    - Show this help message"

# Prevent intermediate files from being deleted
.SECONDARY: $(OBJS)
.PHONY: all debug clean fclean re help
