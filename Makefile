CFLAGS = -Wall -O3 -march=native
LIBS =

app: main.c
	gcc $(CFLAGS) main.c -o app $(LIBS)

clean:
	rm -f app