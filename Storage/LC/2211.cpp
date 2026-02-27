#include <iostream>
#include <vector>
#include <string>

using namespace std;
int countCollisions(string directions)
{
    int n = directions.size();
    int left = 0, right = n - 1;

    while (left < n && directions[left] == 'L')
        left++;
    while (right >= 0 && directions[right] == 'R')
        right--;

    int collisions = 0;
    for (int i = left; i <= right; i++)
    {
        if (directions[i] != 'S')
            collisions++;
    }

    return collisions;
}

int main()
{
    return 0;
}