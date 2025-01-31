cmake_minimum_required(VERSION 3.28)
project(piApproximation)

set(CMAKE_CXX_STANDARD 17)

include_directories(/msys64/mingw64/include)
link_directories(/msys64/mingw64/lib)

add_executable(piApproximation main.cpp
        src/PiApproximationAlgorithm.cpp
        include/PiApproximationAlgorithm.h
        src/MonteCarloApproximation.cpp
        include/MonteCarloApproximation.h
        src/MachinsFormulaPiApproximation.cpp
        include/MachinsFormulaPiApproximation.h)

target_link_libraries(piApproximation gmp gmpxx)
