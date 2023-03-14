#pragma once

#include <chrono>
#include <concepts>

namespace Albedo{
namespace time
{

    template<typename T>
    concept real_number = std::integral<T> || std::floating_point<T>;

    template<real_number Precision>
    class Duration
    {
    public:
        Precision nanoseconds() { return m_time_stamp.count(); }
        Precision microseconds() { return std::chrono::duration_cast<std::chrono::microseconds>(m_time_stamp).count(); }
        Precision milliseconds() { return std::chrono::duration_cast<std::chrono::milliseconds>(m_time_stamp).count(); }
        Precision seconds() { return std::chrono::duration_cast<std::chrono::seconds>(m_time_stamp).count(); }
        Precision minutes() { return std::chrono::duration_cast<std::chrono::minutes>(m_time_stamp).count(); }
        Precision hours() { return std::chrono::duration_cast<std::chrono::hours>(m_time_stamp).count(); }
        Precision days() { return std::chrono::duration_cast<std::chrono::days>(m_time_stamp).count(); }
    public:
        Duration() = delete;
        Duration(const std::chrono::steady_clock::duration& time_stamp) :m_time_stamp{ time_stamp } {}
        Duration(std::chrono::steady_clock::duration&& time_stamp) :m_time_stamp{ time_stamp } {}
        Duration& operator=(const std::chrono::steady_clock::duration& time_stamp) { m_time_stamp = time_stamp; }
        Duration& operator=(std::chrono::steady_clock::duration&& time_stamp){ m_time_stamp = time_stamp; }
    private:
        std::chrono::steady_clock::duration m_time_stamp;
    };

    template<real_number Precision = double>
    class StopWatch
    {
    public:
        void start()
        {
            m_current_time = std::chrono::high_resolution_clock::now();
        }

        Duration<Precision> split(bool reset = true)
        { 
            auto split_time_stamp = std::chrono::high_resolution_clock::now();
            auto time_duration = split_time_stamp - m_current_time;
            if (reset) m_current_time = std::move(split_time_stamp);
            return time_duration;
        }

    public:
        StopWatch() :m_current_time{ std::chrono::high_resolution_clock::now() } {};

    private:
        std::chrono::steady_clock::time_point m_current_time;
    };

}} // namespace Albedo::time