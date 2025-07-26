#include <iostream>
#include <dirent.h>

int main()
{
    struct dirent *entry;
    std::string path_start = "/home/";

    DIR *dp = opendir(path_start.c_str());

    if (dp == NULL)
    {
        perror("opendir");
        return 1;
    }

    while ((entry = readdir(dp)))
    {
        std::cout << entry->d_name << std::endl;
    }
    closedir(dp);
    return 0;
}