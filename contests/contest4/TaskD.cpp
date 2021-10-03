//
// Created by padjal on 30.09.21 г..
// Timer
// Idea: Convert all times to seconds. Add interval to current time. Convert back to time.
//

#include <iostream>
#include <string>

int64_t parseCurrentTime(std::string time) {
    // Format is: HH:MM:SS (with leading zeros).
    // Examples: 23:60:60, 05:05:05

    int64_t seconds = 0;

    seconds += std::stol(time.substr(6, 2));
    seconds += std::stol(time.substr(3, 2)) * 60;
    seconds += std::stol(time.substr(0, 2)) * 60 * 60;

    return seconds;
}

int countColons(std::string str) {
    int colons = 0;

    for (char i : str) {
        if (i == ':') {
            colons++;
        }
    }

    return colons;
}

int64_t parseInterval(std::string time) {
    // Format is: H:M:S (with leading zeros).
    // Examples: 0, 5:1

    int64_t seconds = 0;
    int colons = countColons(time);

    if (colons == 2) {
        int count = 0;
        std::string number;
        for (int i = 0 ; i < time.length() ; ++i) {
            if (time.at(i) == ':') {
                int64_t temp = std::stol(number);
                switch (count) {
                    case 0:
                        seconds += std::stol(number) * 60 * 60;
                        count++;
                        break;
                    case 1:
                        seconds += std::stol(number) * 60;
                        count++;
                        break;
                }
                number = "";
            } else {
                number += time.at(i);

                // Check if is last.
                if (i + 1 == time.length()) {
                    seconds += std::stol(number);
                }
            }
        }
    } else if (colons == 1) {
        int count = 0;
        std::string number;
        for (int i = 0 ; i < time.length() ; ++i) {
            if (time.at(i) == ':') {
                switch (count) {
                    case 0:
                        seconds += std::stol(number) * 60;
                        count++;
                        break;
                }
                number = "";
            } else {
                number += time.at(i);

                // Check if is last.
                if (i + 1 == time.length()) {
                    seconds += std::stol(number);
                }
            }
        }
    } else {
        seconds += std::stol(time);
    }

    return seconds;
}

std::string intToTime(int64_t seconds) {
    std::string result;

    for (int i : {0, 1, 2}) {
        int64_t rem;

        if (i != 2) {
            rem = seconds % 60;
            seconds /= 60;
        } else {
            rem = seconds;
        }

        std::string remString = rem < 10 ?
                                std::string("0").append(std::to_string(rem)) :
                                std::to_string(rem);

        if (i == 0) {
            result += remString;
        } else if (i == 1) {
            result = remString.append(":").append(result);
        } else {
            if (std::stol(remString) >= 24) {
                int64_t days = std::stol(remString) / 24;

                remString = std::to_string(std::stol(remString) % 24).length() == 1 ?
                            std::string("0").append(std::to_string(std::stol(remString) % 24)) :
                            std::to_string(std::stol(remString) % 24);

                std::string addition = "+" + std::to_string(days) + " days";
                result = remString.append(":").append(result).append(addition);
                break;
            }
            result = remString.append(":").append(result);
        }
    }

    return result;
}

void testRun(const std::string &currentTimeString, const std::string &intervalString) {
    std::cout << "Test with values " << currentTimeString << ", " << intervalString << std::endl;

    // Parse current time
    int64_t currentTime = parseCurrentTime(currentTimeString);

    // Parse interval
    int64_t interval = parseInterval(intervalString);

    std::cout << intToTime(currentTime + interval) << std::endl;
}

int main() {
    std::string currentTimeString, intervalString;

    getline(std::cin, currentTimeString);
    getline(std::cin, intervalString);

    // Parse current time
    int64_t currentTime = parseCurrentTime(currentTimeString);

    // Parse interval
    int64_t interval = parseInterval(intervalString);

    std::cout << intToTime(currentTime + interval);

    /*testRun("23:60:60", "0");
    testRun("05:05:05", "5:1");
    testRun("00:05:05", "5:1");
    testRun("10:00:00", "24:15:20");
    testRun("24:00:00", "48:15:20");
    testRun("00:00:00", "24:15:20");
    testRun("23:59:00", "600:600");  // WA5
    testRun("00:00:00", "1000000:1000000:1000000"); // WA6*/

    return 0;
}

