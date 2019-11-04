/*
Name:   Kolby Sarson
ID:     104232327
Due:    November 26, 2017
Item:   Assignement 5
*/
#include <stdio.h> 
#include <string.h>    
#include <sys/socket.h>    
#include <arpa/inet.h> 
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
int main(int argc , char *argv[]){
    int sock;
    struct sockaddr_in server;
    //Create socket
    sock=socket(AF_INET , SOCK_STREAM , 0);
    int n;  //Size of the incomming message
    //Check if the user gave a specific IP address, else use local host
    if(argc==1)
    	server.sin_addr.s_addr=inet_addr("127.0.0.1");
    else
    	server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);
    //Connect to server
    if(connect(sock, (struct sockaddr*)&server, sizeof(server))<0)
        return 0;     
    //Keep communicating with server
    while(1){
        char message[255], server_reply[255];
        printf("Enter a command: ");
        scanf("%s", message);
        //Send data
        if(send(sock, message, strlen(message), 0)<0)
            return 0;
        //Receive a reply from the server
        if((n = recv(sock, server_reply, 255, 0)) < 0){
            printf("recv failed\n");
            break;
        }
        server_reply[n]='\0';   //Making sure old message does not appear
        printf("Server reply :\n%s", server_reply);
        if(n==0)   //The server disconnected 
            break;
    }
    close(sock);
    return 0;
}