#include <iostream>
#include <chrono>
#include <thread>

// To simplify benchmarking :) - The Timer struct uses the object lifetime concept to its advantage
struct Timer
{
    std::chrono::_V2::system_clock::time_point start, end;
    std::chrono::duration<float> duration;

    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float ms = duration.count() * 1000.0f; // Changes timer to miliseconds
        std::cout << "Timer took " << ms << "ms\n"; // std::endl seems to be quite slow for some reason
    }
};

void function()
{
    Timer timer; // Times this function
    for (int i = 0; i < 100; i++)
        std::cout << "Hello" << std::endl;
} 

int main()
{
    /*
        Timing in C++:
            using namespace std::literals::chrono_literals; // To obtain the '1s' literal
            auto start = std::chrono::high_resolution_clock::now(); // Fetches current time
            std::this_thread::sleep_for(1s); // Pauses execution for 1 second (Not guaranteed that it will be exactly 1 second)
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<float> duration = end - start; // Calculate duration - std::chrono::duration is a complex library, be sure to check it out
            std::cout << duration.count() << " seconds" << std::endl;
    */
   function();
}