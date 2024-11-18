CFLAGS =
CPPFLAGS =
LDFLAGS =
# CC = clang
MKFIFO = mkfifo
RM = rm -f

all: fifotest fifotest_p fifotest_c p2c c2p

fifotest: fifotest.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $^

fifotest_p: fifotest_p.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $^

fifotest_c: fifotest_c.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $^

p2c:
	$(MKFIFO) $@

c2p:
	$(MKFIFO) $@

clean:
	$(RM) fifotest fifotest_p fifotest_c p2c c2p

allclean: clean
	$(RM) *~
	$(RM) .DS_Store


