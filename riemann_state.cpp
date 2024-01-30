#include "riemann_state.h"
#include <iostream>
#include <fstream>

void State::get_state()
{
    /**
     * Get a state's full information
     */
    std::cout << "State density is: " << D << "\n";
    std::cout << "State velocity is: " << U << "\n";
    std::cout << "State pressure is: " << P << "\n";
}
void State::set_state(float *arr_info)
{
    /**
     * Set a state's information with an array of 3 floats
     * In order: density, velocity, pressure
     */
    D = (arr_info[0]);
    U = (arr_info[1]);
    P = (arr_info[2]);
}

/**
 * Get functions that return a state's information
 */
float State::get_density()
{
    return D;
}
float State::get_velocity()
{
    return U;
}
float State::get_pressure()
{
    return P;
}

void State::set_sound(float gamma)
{
    /**
     * Set the sound speed for a state
     */
    C = sqrt(gamma * P / D);
}

float State::get_sound()
{
    return C;
}