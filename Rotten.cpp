#include <iostream>
#include <string>
#include <stdio.h>
#include <random>
#include <algorithm>
#include <sstream>


std::random_device seed;
std::minstd_rand rng(seed());

std::string shufflePhrase(const std::string& phrase)
{
    std::string shuffledPhrase;
    std::string underscores;
    std::stringstream ss(phrase);
    std::string word;

    while (ss >> word) {

        std::shuffle(word.begin(), word.end(), rng);
        shuffledPhrase += word + ' ';

        underscores += ' ';
    }

    return shuffledPhrase + underscores.substr(0, underscores.size() - 2);
}

std::string random_string()
{
    std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZqwertyuiopasdfghjklzxcvbnm!@#$%^&*()`~-_=+[{]}';:,<.>/?|");

    std::random_device rd;
    std::mt19937 generator(rd());

    std::shuffle(str.begin(), str.end(), generator);

    return str.substr(0, 100);            
}

int main()
{
    std::string base = random_string(); // get a basic 15 long string so we can work on it

    std::string ShuffledBase;

    for (int i = 0; i <= 50; i++)
        ShuffledBase = shufflePhrase(base); // shuffle it 50 times so we can get lucky

    std::cout << ShuffledBase << std::endl;
    
    system("pause");
    
	return 0;
}
