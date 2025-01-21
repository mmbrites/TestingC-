#include <iostream>
#include <thread>

static bool s_Finished = false;

void doWork()
{
    using namespace std::literals::chrono_literals;
    std::cout << "Started thread ID = " << std::this_thread::get_id() << std::endl;
    while(!s_Finished)
    {
        std::cout << "Working...\n";
        std::this_thread::sleep_for(1s); // Current thread sleeps for 1 second
    }
}

int main() 
{
    std::thread worker(doWork); // Starts another thread called 'worker', which executes the 'doWork' function
    
    std::cin.get();
    s_Finished = true;
    
    worker.join(); // Waits for the 'worker' thread to finish its work. In other programming languages, it is often named 'wait'.
    std::cout << "Finished." << std::endl;
    std::cout << "Started thread ID = " << std::this_thread::get_id() << std::endl;
    
    std::cin.get();
}