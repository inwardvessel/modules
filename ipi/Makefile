obj-m := mymod.o

all:
	make LLVM=1 M=$(PWD) -C $(HOME)/build/linux/native modules
	#make LLVM=1 ARCH=arm64 M=$(PWD) -C $(HOME)/build/linux/aarch64 modules

user:
	gcc -o user.out -static user.c

clean:
	rm -f *.o *.ko *.mod *.mod.c *.order *.symvers .*.cmd *.out
