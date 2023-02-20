#include <iostream>
#include <algorithm>
#include <random>
#include <string>
#include <time.h>
#include <fstream>
#include <vector>

std::string generatePassword(const int NUM_DIGITS){
    std::string password;

    password.push_back(char(std::rand() % 14 + 33));
    password.push_back(char(std::rand() % 25 + 65));
    password.push_back(char(std::rand() % 25 + 97));
    for(int i = 3; i < NUM_DIGITS; i++){
        int charClass = std::rand() % 5;
        int character;

        switch(charClass){
            case 0:
                character = std::rand() % 14 + 33;
                break;
            case 1:
                character = std::rand() % 10 + 48;
                break;
            case 2:
                character = std::rand() % 6 + 58;
                break;
            case 3:
                character = std::rand() % 25 + 65;
                break;
            case 4:
                character = std::rand() % 5 + 91;
                break;
            case 5:
                character = std::rand() % 25 + 97;
                break;
        }
        password.push_back(char(character));
    }

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(password.begin(),password.end(),std::default_random_engine(seed));

    return password;
}

int main(int argc, char* argv[]){
    const int NUM_DIGITS = 15; srand(time(0));
    std::string platform, password, line;
    std::vector<std::string> newFile;

    if(argc == 1){
        std::cout << "What are you generating a password for?: ";
        std::cin >> platform;
    }
    else
        platform = argv[1];
    password = generatePassword(NUM_DIGITS);
    std::cout << password << std::endl;

    std::ifstream infile; infile.open("/Users/tate-minch/Documents/misc/Passwords/passwordGenerator/Passwords.txt");
    while (getline(infile, line)){
        if(line.find(platform) == std::string::npos)
            newFile.push_back(line);
    }
    infile.close();

    std::ofstream outfile; outfile.open("/Users/tate-minch/Documents/misc/Passwords/passwordGenerator/Passwords.txt", std::ios::trunc);
    outfile << platform + " - " << password << std::endl;
    for(int i = 0; i < newFile.size();i++){
        outfile << newFile[i] + "\n";
    }
    outfile.close();


    return 0;
}
