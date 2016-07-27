hello : HelloWorldRT.o
	arm-linux-gnueabihf-gcc -o HelloRT HelloWorldRT.o
	
HelloWorld.o : HelloWorldRT.c
	arm-linux-gnueabihf-gcc -c HelloWorldRT.c

#.PHONY : clean
clean : 
	-rm -f *.o
