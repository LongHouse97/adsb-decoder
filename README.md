# adsb-decoder

## Description
ADS-B decoder

## Dependencies

* (On Ubuntu) Make sure everything is up-to-date:
```
    :~$ sudo apt update
    :~$ sudo apt upgrade
```

## Install

### Download

Go to your development directory and clone the repository from github:

```
    :~$ git clone https://github.com/LongHouse97/adsb-decoder.git
```

### Build and Install

Build the executable from source:

```
    :~$ cd ./adsb-decoder
    :~$ mkdir build
    :~$ cd build
    :~$ cmake ..
    :~$ make
```

## Execute

Start the ROS master node

```
    :~$ ./src/adsb-decoder
```

Now you can start to enter ADS-B messages through the console.

## Authors

* Arian Ghoddousi
    * Contact: arian.ghoddousi@aviware.net

## Version History

* 1.0.0
    * Decoding of aircraft identification

## License

Copyright (C) Aviware 2022