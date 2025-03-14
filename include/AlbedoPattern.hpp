#pragma once

#include <exception>

namespace Albedo{
namespace pattern
{

    template<typename T>
    class Singleton
    {
    protected:
        Singleton() = default;
        virtual ~Singleton() noexcept = default;

    public:
        static T& instance() noexcept(std::is_nothrow_constructible<T>::value)
        {
            static T singleton;
            return singleton;
        }
    protected:
        Singleton(const Singleton&) = delete;
        Singleton(Singleton&&) = delete;
        Singleton& operator=(const Singleton&) = delete;
        Singleton& operator=(Singleton&&) = delete;
    };

    class Command
    {
    public:
        virtual void execute() = 0;
    };

}} // namespace Albedo::pattern