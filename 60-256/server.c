/*
Name:	Kolby Sarson
ID:		104232327
Due:	November 26, 2017
Item:	Assignement 5
*/
#include <stdio.h>
#include <string.h>    
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <unistd.h>   
#include <signal.h>
#include <sys/stat.h>
int main(int argc, char *argv[]){
    int socket_desc, client_sock, c, read_size;
    struct sockaddr_in server, client;
    char client_message[2000];
    //Create socket and prepare the sockaddr_in structure
    socket_desc=socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=INADDR_ANY;
    server.sin_port=htons(8888);
    //Bind
    if(bind(socket_desc, (struct sockaddr*)&server, sizeof(server))<0){
        perror("Bind Failed. Error");
        return 1;
    }
    //Listen
    listen(socket_desc, 3);
    while(1){ 
	    printf("Waiting for incoming connections...\n");
	    c=sizeof(struct sockaddr_in);
	    //Accept connection from an incoming client
	    client_sock=accept(socket_desc, (struct sockaddr*)&client, (socklen_t*)&c);
	    if (client_sock < 0)
	        return 1;
	    printf("Connection Accepted.\n");
	    //Receive a message from client
	    while((read_size=recv(client_sock, client_message, 2000, 0))>0){
	        client_message[read_size]='\0';	//Making sure previous messages don't show up
	        printf("Received Command: %s\n", client_message);
	        //Executing command and sending back to client
	        if (fork()==0){
	           	//Instead of the command being executed to STDOUT, it is sent to the client
	        	dup2(client_sock, STDOUT_FILENO); 
	        	execlp(client_message, client_message, NULL);
	        }  
	    }
	    if(read_size==0){
	        printf("Client Disconnected\n");
	        fflush(stdout);
	    }
	}
    return 0;
}