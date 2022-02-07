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

## Example Messages

'''
    8d3b756b251811b4c39e6082017d
    8d4d21c8230d8271e14460b21522
    8d4a1b41232d2439c30c60c0a9c5
    8d5083c92305527708382090690c
'''