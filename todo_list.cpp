#include <iostream>
#include <queue>
#include <limits>

//Basically a program that allows you to add tasks at the end of the queue, and remove them from the front

void printq(std::queue<std::string> queue)
{

    std::cout << "Your tasks for the day from start to finish:" << "\n";
    while(!queue.empty())
    {
        std::cout << "- " << queue.front() << "\n";
        queue.pop();
    }
}
void menu(std::queue<std::string> &queue)
{
    std::string entry;
    
    while(true)
    {
        std::cout << "What tasks would you like to add for today, from first to last/morning to night? Press 'X' when you're done. ";
        std::cin >> entry;
        if(entry=="X" || entry == "x")
        {
            break;
        }
        queue.push(entry);

    
    }
    
}

void printq2(std::queue<std::string> q)
{
    while(!q.empty())
    {
        std::cout << "-" << q.front() << std::endl;
        q.pop();
    }
}

void mods(std::queue<std::string> &queue) //modifcations to the list
{
    int choice;

    while (!queue.empty())
    {
        std::cout << "\n" << "Would you like to remove the next task at the top of the queue?" << "\n";
        std::cout << "1. Yes" << "\n";
        std::cout << "2. No" << "\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch(choice)
        {
            case 1:
                std::cout << queue.front() << " removed." << "\n";
                queue.pop();
                break;

            case 2:
                std::cout << "Okay, task not removed." << "\n";
                printq2(queue); // Exit the function if user doesn't want to remove
                break;

            default:
                std::cout << "Invalid choice." << "\n";
                break;
        }
        
    }
    
    std::cout << "\nNo more tasks for the day.\n";

}

int main()
{
    std::queue <std::string> tasks;

    menu(tasks);
    printq(tasks);
    mods(tasks);
    
    std::cout << "\nPress Enter to Exit ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

}