#include <fmt/core.h>
#include <fmt/chrono.h>
#include <chrono>

int main() {
    fmt::print("🧠 Pi: {:.3f}\n", 3.14159);
    fmt::print("🕒 Time now: {:%Y-%m-%d %H:%M:%S}\n", std::chrono::system_clock::now());
    return 0;
}
