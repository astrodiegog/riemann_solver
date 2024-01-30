#ifndef REIMANN_PROB_H
#define REIMANN_PROB_H

#include "riemann_state.h"

class RiemannProblem
{
private:
    State stateL, stateR;
    float gamma, mpa;
    float G1, G2, G3, G4, G5, G6, G7, G8;

    void set_gams(float gamma);
    void set_sounds();

    void test_presspos();
    void StarPU(float *P, float *U);
    void GuessPM(float *PM);
    void prefun(float *F, float *FD, float P, float DK, float PK, float CK);
    void sample(float PM, float UM, float S, float *D, float *U, float *P);

public:
    void get_prob();
    void set_prob(State stateLeft, State stateRight, float gamma_in, float mpa_in);
    void set_test1(float gamma_in, float mpa_in);
    void set_test2(float gamma_in, float mpa_in);
    void set_test3(float gamma_in, float mpa_in);
    void set_test4(float gamma_in, float mpa_in);

    void solve(float DOMLEN, int CELLS, float DIAPH, float TIMEOUT, char *soln_fname);
};

#endif