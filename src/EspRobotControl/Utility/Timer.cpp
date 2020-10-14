#include "EspRobotControl/Utility/Timer.hpp"

Timer::Timer(float period_, Print &printer_):
    period(period_),
    last_time_micros(0),
    current_time_micros(0),
    start_time_micros(0),
{
    period_micros = period*1000000.0;
}

Timer::~Timer()
{
}

void Timer::start(){
    start_time_micros = micros();
    last_time_micros = start_time_micros;
}

float Timer::wait(){
    bool waiting = true;
    while(waiting){
        current_time_micros;
        gettimeofday(&tv_now, NULL);
        int64_t current_time_micros = (int64_t)tv_now.tv_sec * 1000000L + (int64_t)tv_now.tv_usec;
        if ((current_time_micros - last_time_micros) > int(period_micros)){
            waiting = false;
            last_time_micros = current_time_micros;
        }
    }
    // int timer_in_loop_stop_micros = micros();
    // printer->print("timer in-function time: ");
    // printer->println(timer_in_loop_stop_micros - timer_in_loop_start_micros);
    return current_time_micros / 1000000.0;
}