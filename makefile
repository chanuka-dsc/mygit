CC=gcc
CFLAGS=-Wall -Wextra -O2

SRC=src/main.c src/repo.c src/fs.c src/hash.c src/index.c src/commit.c
OUT=mygit

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
