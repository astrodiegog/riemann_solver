#ifndef REIMANN_STATE_H
#define REIMANN_STATE_H

class State
{
private:
    float U, D, P;
    float C;

public:
    void get_state();
    void set_state(float *arr_info);

    float get_density();
    float get_velocity();
    float get_pressure();

    void set_sound(float gamma);
    float get_sound();
};

#endif