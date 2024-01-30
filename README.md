# riemann_solver

This is a C++ implementation of the Riemann Problem using Toro's _Riemann Solvers and Numerical Methods for Fluid Dynamics_ Section 4.9. I essentially translate their Fortran version to C++ and implement with my style.


There are 4 cpp files:

- `riemann_solver.cpp`
  - holds `main` function that solves the problem
- `subrouts.cpp`
  - holds a subroutine that reads in test riemann states from txt files that are of the form (DU=left density) for all three primitive variables (density, velocity, pressure) in left and right
- `riemann_state.cpp`
  - Holds information that defines a state (density, velocity, pressure, sound speed)
  - I implemented this using a class, but it could have been a struct instead. Just felt like flexing my cpp muscles and gain more practice with classes
- `riemann_problem.cpp`
  - Holds information that defines a riemann problem (initial states in left and right, as well as adiabatic index)
  - Holds 5 different "setting" functions that define a problem. A user can either provide the left and right states in `main`, create a text file with initial conditions, or use one of the pre-set tests
  - Solving a Riemann problem requires 4 pieces of information (apart from adiabatic inde): domain length, number of cells, position of discontinuity, and the time of sampling. To solve my implementation, an output file path is also required to write the solution

To use this program, I compile with the `g++`

```
g++ -o main subrouts.cpp riemann_state.cpp riemann_solver.cpp riemann_problem.cpp
```

and just run the output executable

```
./main
```

The test directory holds example solution outputs as well as visualizations using a jupyter notebook.

Currently, the equation of state is just a simple caloric $$e=e(\rho,P)=P/(\rho (\gamma - 1))$$ and fluid is an ideal gas. Also, this program solves the Rimeann Problem for the _time-dependent_, _one-dimensional_ Euler equations.

## TODO

There are four main things I want to add onto this program before I feel finished

1. Test for memory leaks. I have done this before on Linux devices for my CS152 course. However, I used Valgrind to check for memory issues, which is not available on macOS (which is where I'm developing this code).
2. Create a Make file. I believe compilation can occur by calling a makefile, which I would like to get familiarity with.
3. Validate that a Riemann problem is "set". In the solve function of the RiemannProblem class, I would like to validate that the left and right states have been set with some values. Not 100% sure how I would like to implement this yet.
4. I am not sure how to deal with exiting criteria when either 1) pressure positivity fails or 2) Newton-Raphson iteration diverges when solving for pressure
