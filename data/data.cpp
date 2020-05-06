#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

//voter data file

const int VOTERS = 1000;       //amount of voters

int main()
{
    int a,
        g,
        r,
        e,
        j;

    string age;
    string gender[2] = {"Male", "Female"};
    string race[4] = {"White", "Black", "Asian", "Hispanic"};
    string education[3] = {"College", "School", "None"};
    string job[3] = {"White-collar", "Blue-collar", "None"};
    string voted = "No";
    string choice = "None";
    string policy = "None";

    srand(time(NULL));

    ofstream f;
    f.open("data.txt");

    if (f.is_open())
    {
        //generate all voters with 5-digit ID's starting with 11
        for (int i = 0; i < VOTERS; i++)
        {
            a = rand() % (90 - 18 + 1) + 18;        //age: 18-90
            age = to_string(a);
            
            g = rand() % 2;
            r = rand() % 4;
            e = rand() % 3;
            j = rand() % 3;
            
            f << 11000 + i << " "
              << age << " "
              << gender[g] << " "
              << race[r] << " "
              << education[e] << " "
              << job[j] << " "
              << voted << " "
              << choice << " "
              << policy << " "
              << endl;
        }
    }
    else
    {
        cout << "Database error." << endl;
        exit(1);
    }

    f.close();

    cout << "Data generated." << endl;

    return 0;
}