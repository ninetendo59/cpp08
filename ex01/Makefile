#milb: mommy, i'd like to bureaucrap
NAME = span
# HEADER = inc
# TEMPLATE = template
CXX = c++
# added template but only if with sources
# CXXFLAGS = -std=c++98 -I$(HEADER) -I$(TEMPLATE) -Wall -Wextra -Werror
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
# SOURCE = src
# SRC_PATHS = $(addprefix $(SOURCE)/,main.cpp second.cpp) \
#				$(addprefix $(SOURCE2)/,file1.cpp file2.cpp)
SRCS = main.cpp Span.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
