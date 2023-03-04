NAME = philo
CFILES = exit.c grim_reaper.c init.c main.c output.c parsing.c philosopher.c time.c
OBJECTS = $(addprefix $(OBJDIR)/, $(CFILES:.c=.o))
# Define the object directory
OBJDIR = obj
CFLAGS = gcc -Wall -Wextra -Werror -g -pthread
$(NAME): $(OBJECTS)
	@echo "\033[0;32m ------CREATING----- $(NAME) \033[0m"
	$(CFLAGS) $(OBJECTS) -o $(NAME)
all: $(NAME)
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@echo " \033[0;33m---- Creating" [ $@ ] " ----- \033[0m"
	$(CFLAGS) -c $< -o $@
$(OBJDIR):
	mkdir $(OBJDIR)
clean:
	rm -rf $(NAME) $(OBJDIR)
fclean: clean
	rm -rf $(NAME)
re: clean all