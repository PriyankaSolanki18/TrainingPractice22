CC = gcc
CFLAGS = -Wall -pthread
INCLUDE_DIR = include
SRC_DIR = src
LIB_DIR = lib
TARGET_SERVER = server
TARGET_CLIENT = client

all: $(TARGET_SERVER) $(TARGET_CLIENT)

$(TARGET_SERVER): $(SRC_DIR)/server.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $@ $^

$(TARGET_CLIENT): $(SRC_DIR)/client.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $@ $^

clean:
	rm -f $(TARGET_SERVER) $(TARGET_CLIENT)

