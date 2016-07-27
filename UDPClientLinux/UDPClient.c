/*
    Simple udp client
    Silver Moon (m00n.silv3r@gmail.com)
*/
#include<stdio.h> //printf
#include<string.h> //memset
#include<stdlib.h> //exit(0);
#include<arpa/inet.h>
#include<sys/socket.h>
 
#define SERVER "192.168.0.11"
#define BUFLEN 512  //Max length of buffer
#define PORT 5000   //The port on which to send data
 
void die(char *s)
{
    perror(s);
    exit(1); 
}
 
int main(void)
{
    struct sockaddr_in si_other;
    int s, i, slen=sizeof(si_other);
    char buf[BUFLEN];
    char message[BUFLEN];
	
	printf("Sending message : ");
	
    if ( (s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    {
        die("socket");
    }
 
    memset((char *) &si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(PORT);
     
    if (inet_aton(SERVER , &si_other.sin_addr) == 0) 
    {
        fprintf(stderr, "inet_aton() failed\n");
        exit(1);
    }

	strcpy(message, "Ehsan");
	message[strlen(message)] = '\0';
			
    while(1)
    {
        // printf("Enter message : ");
        // gets(message);
        
		printf("%s\n", message);
		
        //send the message
        if (sendto(s, message, strlen(message) , 0 , (struct sockaddr *) &si_other, slen)==-1)
        {
            die("sendto()");
        }
        
		sleep(2);
		
		
        // //receive a reply and print it
        // //clear the buffer by filling null, it might have previously received data
        // memset(buf,'\0', BUFLEN);
        // //try to receive some data, this is a blocking call
        // if (recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen) == -1)
        // {
            // die("recvfrom()");
        // }
         
        // puts(buf);
    }
 
    close(s);
    return 0;
}