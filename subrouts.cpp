#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>

void readtest(float **states_info, std::string fname)
{

    /**
     * Function that will read in a test file's info to array
     */
    std::string line;

    std::ifstream myfile(fname);
    std::string del = "=";
    float stateL_info[3];
    float stateR_info[3];
    float *pcurr_state = stateL_info;

    int pos = 0;
    std::string token;

    if (myfile.is_open())
    {
        for (int count = 0; count < 6; count++)
        {
            getline(myfile, line);
            while ((pos = line.find(del)) != std::string::npos)
            {
                token = line.substr(0, pos);
                line.erase(0, pos + del.length());
            }
            float curr_val = std::stof(line);
            pcurr_state[count % 3] = curr_val;

            if (count == 2)
            {
                pcurr_state = stateR_info;
            }
        }
        myfile.close();
    }
    else
    {
        std::cout << "Unable to open file";
    }

    states_info[0] = (stateL_info);
    states_info[1] = (stateR_info);
}