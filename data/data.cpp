#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

//voter data file

const unsigned short int VOTERS = 1000;       //amount of voters

int main()
{
    char characters[] = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*";
    char password[16];   //16 character password
    const int l = 70;    //length of characters array

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
        cout << "\nGenerating data.." << endl;

        //generate all voters with 5-digit ID's starting with 11
        for (int i = 0; i < VOTERS; i++)
        {
            cout.precision(3);
            cout << "\r" << (i * 100.0) / VOTERS << "%   ";     //display progress

            //generate random password
            for (int j = 0; j < 16; j++)
                password[j] = characters[rand() % l];

            string pass;

            //convert password to string
            for (int k = 0; k < 16; k++)
                pass += password[k];

            a = rand() % (90 - 18 + 1) + 18;        //age: 18-90
            age = to_string(a);
            
            g = rand() % 2;
            r = rand() % 4;
            e = rand() % 3;
            j = rand() % 3;
            
            f << to_string(11000 + i) << " "
              << pass << " "
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

        cout << "\r100%   " << endl;
    }
    else
    {
        cout << "Unable to generate data file." << endl;
        while (1);
    }

    f.close();

    cout << "\nData successfully generated: data.txt" << endl
         << "\nData file is ready for use in the election.";

    while (1);

    return 0;
}