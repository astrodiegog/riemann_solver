# Test

This directory holds tests for the Riemann Problem from Toro's _Riemann Solvers and Numerical Methods for Fluid Dynamics_ section 4.3.3

Specifically, the starting states and ending time for each test are

| Test | $$\rho_{\mathrm{L}}$$ | $$u_{\mathrm{L}}$$ | $$P_{\mathrm{L}}$$ | $$\rho_{\mathrm{R}}$$ | $$u_{\mathrm{R}}$$ | $$P_{\mathrm{R}}$$ | Timeout (s) |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 1 (sod) | 1.0 | 0.0 | 1.0 | 0.125 | 0.0 | 0.1 | 0.25 |
| 2 (123) | 1.0 | -2.0 | 0.4 | 1.0 | 2.0 | 0.4 | 0.15 |
| 3 (strong shock) | 1.0 | 0.0 | 1000.0 | 1.0 | 2.0 | 0.4 | 0.012 |
| 4 (two shocks) | 5.99924 | 19.5975 | 460.894 | 5.99242 | -6.19633 | 46.0950 | 0.035 |

The `.txt` files are solutions using a domain length from 0 to 1, 100 cells, discontinuity at 0.5, and a $\gamma = 1.4$

The jupyter notebook `viz.ipynb` shows the starting and timeout states for each test.

`sod_test_readin.txt` is an example txt file that can be used to input some initial starting states.
