// ArrayJump.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int N = 0;
    int j = 0;
    int steps = 0;

    std::cout << "Enter the array size:" << std::endl;
    std::cin >> N;

    if (N < 1 || N > 10000)
    {
        std::cout << "Bad Limit set, limit should be between 1 - 10000" << std::endl;
        return 1;
    }

    int* arr = new int[N];

    std::cout << "Enter your elements" << std::endl;

    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
        std::cout << "your element: " << arr[i] << std::endl;
    }

    while (j < N)
    {
        int currentValue = arr[j];

        if (j == 0 && currentValue == 0)
        {
            currentValue = 1;
        }
        else if (currentValue == 0 && j == N - 1)
        {
            currentValue = 1;
            std::cout << "Final steps: " << steps << std::endl;
            return 1;
        }

        int currentIndex = j;

        j = j + currentValue;

        steps++;
    }

    std::cout << "Final steps: " << steps << std::endl;

    
}

