# BadUSB

## Building

1. Install compiler 
	Download compiler from [arm developer](https://developer.arm.com/downloads/-/gnu-rm)
	```bash
	tar -xvjf gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2
	sudo mv gcc-arm-none-eabi-10.3-2021.10 /opt
	export PATH=/opt/gcc-arm-none-eabi-10.3-2021.10/bin:$PATH
	```
2. Install st-link
	```bash
	sudo pacman -S stlink
	```
3. Build and flash the firmware
	`make`
