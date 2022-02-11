BPF_INC = ./include
CC = clang

all: example.bpf.o

example.bpf.o: example.bpf.c
	@$(CC) -I $(BPF_INC) -O2 -g -target bpf -c $< -o $@

example.o: example.c
	@$(CC) -I $(BPF_INC) -O2 -g -c $< -o $@

example: example.o
	@$(CC) $< deps/libbpf.a -lelf -lz -o example

.PHONY: clean
clean:
	@rm *.o