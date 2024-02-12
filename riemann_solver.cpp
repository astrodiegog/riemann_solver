#include <iostream>
#include <sstream>
#include <cmath>
#include <fstream>
#include <string>
#include <cmath>

#include "riemann_state.h"
#include "riemann_problem.h"
#include "subrouts.h"

int main()
{
    int CELLS;
    float GAMMA, MPA;
    float DIAPH, DOMLEN, TIMEOUT;

    /**
     * DOMLEN - Domain length
     * DIAPH - initial discontinuity position
     * CELLS - number of computing cells
     * GAMMA - Ratio of specific heats
     * TIMEOUT - Output time
     * MPA - normalizing constant
     */
    GAMMA = 1.4;
    MPA = 1.0;

    DOMLEN = 1.;
    CELLS = 100;
    DIAPH = 0.5;
    TIMEOUT = 0.035;

    int readin = 0;

    // create riemann problem
    RiemannProblem riemannprob;
    char soln_fname[] = "test/twoshock_soln.txt";

    if (readin)
    {
        // create states
        float **states_info = (float **)malloc(2 * sizeof(float *));
        std::string test_fname = "test/sod_test_readin.txt";
        readtest(states_info, test_fname);
        State stateL, stateR;
        stateL.set_state(states_info[0]);
        stateR.set_state(states_info[1]);
        riemannprob.set_prob(stateL, stateR, GAMMA, MPA);
    }
    else
    {
        riemannprob.set_test4(GAMMA, MPA);
    }

    riemannprob.get_prob();
    riemannprob.solve(DOMLEN, CELLS, DIAPH, TIMEOUT, soln_fname);

    std::cout << "hello world ! done riemann solvin" << std::endl;
}
