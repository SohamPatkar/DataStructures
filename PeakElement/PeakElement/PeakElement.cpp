// PeakElement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

int main()
{
    int N;

    std::cout << "Enter the array size:" << std::endl;
    std::cin >> N;

    std::vector<int> arr(N);

    std::cout << "Enter your elements" << std::endl;

    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
        std::cout << "your element: "<< arr[i] << std::endl;
    }

    std::cout << "Peak elements are:" << std::endl;

    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            if (arr[i] > arr[i + 1])
            {
                std::cout << i << std::endl;
            }
        }
        else if (i == N - 1)
        {
            if (arr[i] > arr[i - 1])
            {
                std::cout << i << std::endl;
            }
        }
        else
        {
            if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1])
            {
                std::cout << i << std::endl;
            }
        }
    }
}

