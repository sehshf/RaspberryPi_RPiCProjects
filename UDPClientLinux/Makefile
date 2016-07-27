UDPSend : UDPClient.o
	arm-linux-gnueabihf-gcc -o UDPSend UDPClient.o
	
UDPClient.o : UDPClient.c
	arm-linux-gnueabihf-gcc -c UDPClient.c

#.PHONY : clean
clean : 
	-rm -f *.o
