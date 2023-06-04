#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

void runMainForInput(const std::string &mainFileName, const std::string &inputFileName, const std::string &outputFileName)
{
    std::ifstream inputFile(inputFileName);
    std::ofstream outputFile(outputFileName);

    // Save the current standard input/output streambufs
    auto cinBuf = std::cin.rdbuf();
    auto coutBuf = std::cout.rdbuf();

    // Redirect standard input to inputFile and standard output to outputFile
    std::cin.rdbuf(inputFile.rdbuf());
    std::cout.rdbuf(outputFile.rdbuf());

    // Compile and run the main file code
    system(("g++ " + mainFileName + " && ./a.out").c_str());

    // Restore the original standard input/output streambufs
    std::cin.rdbuf(cinBuf);
    std::cout.rdbuf(coutBuf);
}

int main()
{
    DIR *dp;
    int i = 0;
    struct dirent *ep;
    dp = opendir("./small/in");

    if (dp != NULL)
    {
        while (ep = readdir(dp))
            i++;

        (void)closedir(dp);
    }
    else
        perror("Couldn't open the directory");

    printf("There's %d test cases in the current directory.\n", i - 2);

    const int numFiles = i - 2;

    for (int i = 1; i <= numFiles; ++i)
    {
        std::string mainFileName = "main.cpp"; // Replace with the actual filename of your main file
        std::string inputFileName = "small/in/input" + std::to_string(i) + ".txt";
        std::string outputFileName = "myOutput/output" + std::to_string(i) + ".txt";
        runMainForInput(mainFileName, inputFileName, outputFileName);
    }

    return 0;
}
