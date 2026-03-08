SRCS := src/errno.c src/fcntl.c src/ioctl.c src/mman.c src/stdio.c src/stdlib.c src/string.c src/unistd.c src/wrap.c src/utsname.c src/stat.c src/resource.c src/signal.c src/socket.c src/time.c src/wait.c
OBJECTS := src/errno.o src/fcntl.o src/ioctl.o src/mman.o src/stdio.o src/stdlib.o src/string.o src/unistd.o src/wrap.o src/utsname.o src/stat.o src/resource.c src/signal.o src/socket.o src/time.o src/wait.o
STATIC_LIB := lib/libc.a
SHARED_LIB := lib/libc.so
CFLAGS := -nostdlib -ffreestanding -Iinclude -O2
LDFLAGS := -shared -fno-builtin -nostdlib -ffreestanding

CC := gcc
LD := ld
AR := ar
NASM := nasm

all: lib $(STATIC_LIB) $(SHARED_LIB) build_crt0 build_crt1

lib:
	mkdir -p lib

$(SHARED_LIB): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

$(STATIC_LIB): $(OBJECTS)
	$(AR) rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

build_crt0:
	$(NASM) -f elf64 src/crt0.asm -o lib/crt0.o

build_crt1:
	$(CC) $(CFLAGS) -c src/crt1.c -o lib/crt1.o

clean:
	rm -f src/*.o lib/*.a lib/*.o lib/*.so
