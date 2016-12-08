#include <algorithm>
#include <iostream>
#include <vector>
#include <time.h>

static constexpr int NUMBER_OF_EXPERIMENTS = 1000000;
static const std::vector<int> ALL_DOORS = {1, 2, 3};
static constexpr bool CHANGE_DOOR = true;

// Choose random element from the set
int chooseRandom(std::vector<int> numbers)
{
    int n = rand() % numbers.size();
    return numbers[n];
}

// Remove choosen element from the set
// for example: exclude({1, 2, 3}, 2) == {1, 3}
std::vector<int> exclude(std::vector<int> numbers, int number)
{
    auto p = std::find(std::begin(numbers), std::end(numbers), number);
    if (p != std::end(numbers))
        numbers.erase(p);
    return numbers;
}

int main()
{
    srand(time(0));
    int numberOfWins = 0;
    for (int i = 0; i < NUMBER_OF_EXPERIMENTS; ++ i)
    {
        int prizeDoor = chooseRandom(ALL_DOORS);
        int choosenDoor = chooseRandom(ALL_DOORS);
        int openedDoor = chooseRandom(exclude(exclude(ALL_DOORS, prizeDoor), choosenDoor));
        if (CHANGE_DOOR)
            choosenDoor = chooseRandom(exclude(exclude(ALL_DOORS, choosenDoor), openedDoor));
        if (choosenDoor == prizeDoor)
            ++ numberOfWins;
    }
    std::cout << numberOfWins << " / " << NUMBER_OF_EXPERIMENTS << " = " <<
                 (static_cast<double>(numberOfWins) /
                  static_cast<double>(NUMBER_OF_EXPERIMENTS)) << std::endl;
    return 0;
}
