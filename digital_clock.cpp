#include <iostream>
#include <iomanip>
#include <ctime>
#ifdef _WIN32
#include <windows.h>   // For Sleep() on Windows
#else
#include <unistd.h>    // For sleep() on Linux/macOS
#endif

using namespace std;

// Clears the screen using ANSI escape codes (works on Linux, macOS, Windows 10+)
void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

// Cross-platform 1-second delay
void delayOneSecond() {
#ifdef _WIN32
    Sleep(1000);   // Windows Sleep takes milliseconds
#else
    sleep(1);      // Linux/macOS sleep takes seconds
#endif
}

void displayDigitalClock(bool use12HourFormat = false) {
    while (true) {
        clearScreen();
        
        // Get current time
        time_t current_time = time(nullptr);
        tm* local_time = localtime(&current_time);

        // Display header
        cout << "==========================\n";
        cout << "      DIGITAL CLOCK       \n";
        cout << "==========================\n\n";

        // Handle 12-hour / 24-hour format
        int hour = local_time->tm_hour;
        string am_pm = "";
        if (use12HourFormat) {
            am_pm = " AM";
            if (hour >= 12) {
                am_pm = " PM";
                if (hour > 12) hour -= 12;
            }
            if (hour == 0) hour = 12;
        }

        // Display Date
        cout << "Date: " 
             << setw(2) << setfill('0') << local_time->tm_mday << "/"
             << setw(2) << (local_time->tm_mon + 1) << "/"
             << (1900 + local_time->tm_year) << "\n";

        // Display Time
        cout << "Time: " 
             << setw(2) << setfill('0') << hour << ":"
             << setw(2) << local_time->tm_min << ":"
             << setw(2) << local_time->tm_sec 
             << am_pm << "\n\n";

        cout << "==========================\n";
        cout << "Press Ctrl+C to exit...\n";

        // Wait 1 second before refreshing
        delayOneSecond();
    }
}

int main() {
    try {
        // Pass true for 12-hour format, false for 24-hour format
        displayDigitalClock(true);  
    } catch (...) {
        cout << "Clock stopped." << endl;
    }
    return 0;
}
