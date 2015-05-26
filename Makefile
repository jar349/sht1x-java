CC=gcc
INCLUDE=-I. -I/usr/local/include -I/usr/java/default/include -I/usr/java/default/include/linux
LINKS=-L/usr/local/lib
LIBS=-lbcm2835 -lm -lsht1x
CFLAGS=$(INCLUDE) $(LINKS) $(LIBS)

Sht1xSensor: Sht1xSensor.c
	$(CC) -fPIC -c Sht1xSensor.c $(CFLAGS)
	$(CC) Sht1xSensor.o -shared -o libsht1x-java.so -Wl,-soname,sht1x-java

clean:
	rm -f *.o *.so
