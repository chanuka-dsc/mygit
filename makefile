CC=gcc
CFLAGS=-Wall -Wextra -O2
LDFLAGS=-lcrypto

SRC=src/main.c src/repo.c src/fs.c src/hash.c src/index.c src/commit.c
OUT=mygit

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

clean:
	rm -f $(OUT)
