#include <iostream>
#include <chrono>
#include <ctime>
//class godzina
class Czas {
private:
    std::chrono::high_resolution_clock::time_point m_startTime;
    std::chrono::high_resolution_clock::time_point m_endTime;
public:
    void start()
    {
        m_startTime = std::chrono::high_resolution_clock::now();
    }
    void stop()
    {
        m_endTime = std::chrono::high_resolution_clock::now();
    }
    double full_time()
    {
        return std::chrono::duration<double>(m_endTime - m_startTime).count();
    }

};

int main()
{
    Czas timer;
    timer.start();
    int input;
    std::cin>>input;
    auto str = std::to_string(input);
    std::cout << str << std:: endl;
    timer.stop();
    const auto full_time = timer.full_time();
    std::cout << "Full time(in seconds): " << full_time << std::endl;

    return 0;
}
