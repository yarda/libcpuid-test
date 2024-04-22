NAME = libcpuid-test

GCC = gcc

LIBCPUID_CFLAGS = $(shell pkg-config --cflags libcpuid)
LIBCPUID_LIBS = $(shell pkg-config --libs libcpuid || echo -lcpuid)

.PHONY: all clean

all: $(NAME)

$(NAME).o: libcpuid-test.c
	$(GCC) -c -o $(NAME).o $(LIBCPUID_CFLAGS) $(CFLAGS) libcpuid-test.c

$(NAME): $(NAME).o
	$(GCC) -o $(NAME) $(LIBCPUID_LIBS) $(LIBS) $(LDFLAGS) $(NAME).o

clean:
	rm -f $(NAME) $(NAME).o
