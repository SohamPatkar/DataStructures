#include <iostream>

int main()
{
    int N = 0;

    std::cout << "Enter the array size:" << std::endl;
    std::cin >> N;

    int* arr = new int[N];

    std::cout << "Enter your elements" << std::endl;

    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
        std::cout << "your element: " << arr[i] << std::endl;
    }

    std::cout << "Element to remove:" << std::endl;

    int toRemove;
    std::cin >> toRemove;

    for (int i = 0; i < N; i++)
    {
        if (arr[i] == toRemove)
        {
            for (int j = i; j < N - 1; j++)
            {
                arr[i] = arr[i + 1];
            }
        }
    }

    N--;

    std::cout << "The updated array is" << std::endl;

    for (int i = 0; i < N; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

