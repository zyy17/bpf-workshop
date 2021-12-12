BPF_INC = ./include
CC = clang

all: example.bpf.o

example.bpf.o: example.bpf.c
	@$(CC) -I $(BPF_INC) -O2 -g -target bpf -c $< -o $@

.PHONY: clean
clean:
	@rm *.bpf.o