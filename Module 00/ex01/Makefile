NAME = my_awesome_phone_book
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp PhoneBook.class.cpp Contact.class.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all