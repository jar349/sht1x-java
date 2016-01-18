Java support for C Library for SHT1x sensors
--
Licensed under MIT

Depends on the [C Library for SHT1x sensors connected to bcm2835 via GPIO ports](https://github.com/jar349/sht1x).  Follow the link and install it before installing this library.

##Install instructions
####1.  Clone the repository
```bash
$ git clone https://github.com/jar349/sht1x-java.git
```
####2. Compile and install the library: 
```bash
./autogen.sh
./configure
make
sudo make install
```

The library should be installed in /usr/local/lib and headers in /usr/local/include