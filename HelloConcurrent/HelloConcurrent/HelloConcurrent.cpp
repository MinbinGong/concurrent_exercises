// HelloConcurrent.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <thread>

void hello()
{
    std::cout << "Hello Concurrent World\n";
}

int main()
{
    std::thread t(hello);
    t.join();
}
