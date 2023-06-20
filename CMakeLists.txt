cmake_minimum_required(VERSION 3.23)
project(Leetcode)

set(CMAKE_CXX_STANDARD 14)

add_executable(Leetcode leetcode21.cpp,
        Leetcode leetcode649.cpp leetcode1456.cpp leetcode1498.cpp leetcode70.cpp contest_identifying_tea.cpp contest_shattered_cake.cpp contest_candle_box.cpp contest_crime.cpp contest_blink.cpp)
