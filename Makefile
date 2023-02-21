NAME = philo
CFILES = init_phios.c init.c main.c philo.c routine.c time.c utils.c 
OBJECTS = $(addprefix $(OBJDIR)/, $(CFILES:.c=.o))
# Define the object directory
OBJDIR = obj
CFLAGS = gcc -Wall -Wextra -Werror -g -pthread
$(NAME): $(OBJECTS)
	@echo "\033[0;32m ------CREATING----- \033[0m" $(NAME)
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
