CC=gcc
CFLAGS=-Wall -Wextra -O2
LDFLAGS=-lcrypto

SRCS = src/main.c src/repo.c src/fs.c src/hash.c src/index.c src/commit.c src/object.c src/cmd_hash_object.c src/cmd_cat_file.c
OUT=mygit

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(OUT) $(LDFLAGS)

clean:
	rm -f $(OUT)
