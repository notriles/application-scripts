#include <iostream> // include iostream for console
#include <string> // include string for string variables

std::string getComputerChoice() // returns the computer's choice
{
    srand(time(NULL)); // sets the random seed for pure random gameplay
    int choice = rand() % 3; // gets number 0-3 to represent computer choice

    if (choice == 0) // choice 0 is rock
    {
        return "rock";
    }
    else if (choice == 1) // choice 1 is paper
    {
        return "paper";
    }
    else // choice 2 is scissors
    {
        return "scissors";
    }
}

std::string getUserChoice() // gets the user's choice from the console
{
    std::string choice; // create a variable to store the choice

    std::cout << "Please enter either rock, paper, or scissors." << std::endl; // prints instructions
    std::cin >> choice; // saves the user's input to the string variable

    if (choice == "rock" || choice == "paper" || choice == "scissors") // check if choice is valid
    {
        return choice;
    }
    else
    {
        std::cout << "Invalid choice." << std::endl;
        return getUserChoice(); // prompt user choice once more
    }
}

std::string determineWinner(std::string userChoice, std::string computerChoice) // determine winner from choices
{
    if (userChoice == computerChoice) // return "tie" if the choices are the same
    {
        return "tie";
    }

    bool didUserWin = false; // create avriable to represent if the user won

    if (userChoice == "rock")
    {
        didUserWin = computerChoice == "scissors"; // user wins if the computer chooses scissors
    }
    else if (userChoice == "paper")
    {
        didUserWin = computerChoice == "rock"; // user wins if the computer chooses rock
    }
    else if (userChoice == "scissors")
    {
        didUserWin = computerChoice == "paper"; // user wins if the computer chooses paper
    }

    return didUserWin ? "user" : "computer"; // ternary operator to return results
}

int main()
{
    std::string computerChoice = getComputerChoice(); // get the computer choice
    std::string userChoice = getUserChoice(); // get the user choice
    std::string outcome = determineWinner(userChoice, computerChoice); // determine the outcome of the game

    if (outcome == "tie")
    {
        std::cout << "It was a tie! You both chose " << userChoice; // tell the user that the game was a tie
    }
    else if (outcome == "user")
    {
        std::cout << "You won! You chose " << userChoice << " and the computer chose " << computerChoice; // let the user know that they won!
    }
    else
    {
        std::cout << "You lost! You chose " << userChoice << " and the computer chose " << computerChoice; // the user lost, better luck next time :c
    }

    return 0;
}
