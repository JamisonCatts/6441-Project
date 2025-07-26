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



    entry = readdir(dp);
    entry = readdir(dp);
    entry = readdir(dp);
    std::string path = path_start + entry->d_name + "/.config/";

    std::cout << path << std::endl;
    

    closedir(dp);
    return 0;
}