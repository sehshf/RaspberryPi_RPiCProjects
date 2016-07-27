hello : HelloWorld.o
	arm-linux-gnueabihf-gcc -o hello HelloWorld.o
	
HelloWorld.o : HelloWorld.c
	arm-linux-gnueabihf-gcc -c HelloWorld.c

#.PHONY : clean
clean : 
	-rm -f *.o
