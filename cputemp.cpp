/*
 * This program is used to read the CPU temperature on a Raspberry Pi.
 * The Pi's temperature can be taken from the sysfs system, where it
 * is simply exposed as a text file.
 *
 * Author: Mike Dice
 * CreatedOn: October, 2020
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{
    ifstream tempFile("/sys/class/thermal/thermal_zone0/temp");
    if (tempFile.is_open())
    {
        string line;
        if (getline(tempFile, line))
        {
            int val = stoi(line);
            double degc = (double)val/1000.0;
            double degf = (degc * 9.0)/5.0 + 32.0;
            cout <<   degf << " F" << endl;
        }
        else
        {
            cout << "Did not read line from temperature file" << endl;
        }
        tempFile.close();
    }
    else
    {
        cout << "Temperature file did not open" << endl;
    }
}

