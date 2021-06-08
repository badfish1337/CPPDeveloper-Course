#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // Print introduction statement and directive
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room... \nEnter the correct codes to continue...\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to terminal
    std::cout << "\n+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the player's guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** CODE MATCH FOUND: SERVER " << Difficulty << " ACCESS GRANTED... ***\nExtracting files...";
        return true;
    }
    else
    {
        std::cout << "\n*** CODE INVALID: CAUTION, SERVER " << Difficulty << " RESETTING... ***";
        return false;
    }
}


int main()
{
    srand(time(NULL)); // Create new random sequence based on time of day
    int LevelDifficulty = 1;
    const int MaxLevel = 10;

    while (LevelDifficulty <= MaxLevel) // Loop game until all levels completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    std::cout << "Congratulations, you are a master hacker.\nYou have been granted access to all secure servers!\nAll files extracted!";

    return 0;
}