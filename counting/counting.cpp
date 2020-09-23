#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cmath>
#include "candidate.h"
using namespace std;

bool counting;                 //counting open or closed

const unsigned short int CANDIDATES = 4;      //amount of candidates
const unsigned short int VOTERS = 1000;       //amount of voters

int votes = 0;                 //amount of votes

string id,
       password, age, gender,
       race, education, job,
       voted, candidate, policy;

int democratic = 0;
int republican = 0;

int age1824 = 0;
int age2529 = 0;
int age3039 = 0;
int age4049 = 0;
int age5064 = 0;
int age6590 = 0;

int male = 0;
int female = 0;

int white = 0;
int black = 0;
int asian = 0;
int hispanic = 0;

int college = 0;
int school = 0;
int noedu = 0;
    
int wcollar = 0;
int bcollar = 0;
int nojob = 0;

int cj = 0;
int gc = 0;
int eco = 0;
int fp = 0;
int edu = 0;
int env = 0;
int tech = 0;
int imm = 0;
int hc = 0;
int ab = 0;

Candidate c[CANDIDATES] =
{
    {"Trump", "Republican"},
    {"Biden", "Democratic"},
    {"Sanders", "Democratic"},
    {"Warren", "Democratic"}
};

double generalPercentage(int x)
{
    return (x * 100.0) / votes;
}

/*calculate and display election results*/
bool generalResults()
{
    cout.precision(4);
    cout << "Election Results: \n" << endl;

    if (votes == 0)
    {
        cout << "No votes have been cast." << endl;
        return false;
    }

    //tally votes
    for (int i = 0; i < CANDIDATES; i++)
    {
        cout << c[i].Name() << ": "
             << (c[i].Votes() * 100.0) / votes << "%"
             << " - " << c[i].Votes()
             << endl;
    }

    cout << "\n\nGeneral election statistics: " << endl;
    
    cout << "\nVotes: " << votes << endl
         << "Turnout: " << (votes * 1.0 / VOTERS) * 100 << "%" << endl;

    cout << "\nRepublican Party: " << generalPercentage(republican)
         << "%" << endl
         << "Democratic Party: " << generalPercentage(democratic)
         << "%" << endl;

    cout << "\nAge groups: " << endl
         << "18-24: " << generalPercentage(age1824) << "%" << endl
         << "25-29: " << generalPercentage(age2529) << "%" << endl
         << "30-39: " << generalPercentage(age3039) << "%" << endl
         << "40-49: " << generalPercentage(age4049) << "%" << endl
         << "50-64: " << generalPercentage(age5064) << "%" << endl
         << "65-90: " << generalPercentage(age6590) << "%" << endl;

    cout << "\nGender: " << endl
         << "Male: "   << generalPercentage(male) << "%" << endl
         << "Female: " << generalPercentage(female) << "%" << endl;
    
    cout << "\nRace: " << endl
         << "White: "    << generalPercentage(white) << "%" << endl
         << "Black: "    << generalPercentage(black) << "%" << endl
         << "Asian: "    << generalPercentage(asian) << "%" << endl
         << "Hispanic: " << generalPercentage(hispanic) << "%" << endl;

    cout << "\nEducation: " << endl
         << "College: " << generalPercentage(college) << "%" << endl
         << "School: "  << generalPercentage(school) << "%" << endl
         << "None: "    << generalPercentage(noedu) << "%" << endl;
    
    cout << "\nJob: " << endl
         << "White-collar: " << generalPercentage(wcollar) << "%" << endl
         << "Blue-collar: "  << generalPercentage(bcollar) << "%" << endl
         << "None: "         << generalPercentage(nojob) << "%" << endl;

    cout << "\nPolicy: " << endl
         << "Criminal Justice: " << generalPercentage(cj) << "%" << endl
         << "Gun Control: "      << generalPercentage(gc) << "%" << endl
         << "Economy: "          << generalPercentage(eco) << "%" << endl
         << "Foreign Policy: "   << generalPercentage(fp) << "%" << endl
         << "Education: "        << generalPercentage(edu) << "%" << endl
         << "Environment: "      << generalPercentage(env) << "%" << endl
         << "Technology: "       << generalPercentage(tech) << "%" << endl
         << "Immigration: "      << generalPercentage(imm) << "%" << endl
         << "Healthcare: "       << generalPercentage(hc) << "%" << endl
         << "Abortion: "         << generalPercentage(ab) << "%" << endl;

    return true;
}

/*calculate and display election results*/
void candidateResults()
{
    cout.precision(4);

    cout << "\n\nCandidate statistics: " << endl;

    for (int i = 0; i < CANDIDATES; i++)
    {
        if (c[i].Votes() == 0)
        {
            continue;
        }

        cout << "\n------ " << c[i].Name() << " ------" << endl;

        cout << "\nAge groups: " << endl
             << "18-24: " << (c[i].age1824 * 100.0) / c[i].Votes() << "%" << endl
             << "25-29: " << (c[i].age2529 * 100.0) / c[i].Votes() << "%" << endl
             << "30-39: " << (c[i].age3039 * 100.0) / c[i].Votes() << "%" << endl
             << "40-49: " << (c[i].age4049 * 100.0) / c[i].Votes() << "%" << endl
             << "50-64: " << (c[i].age5064 * 100.0) / c[i].Votes() << "%" << endl
             << "65-90: " << (c[i].age6590 * 100.0) / c[i].Votes() << "%" << endl;

        cout << "\nGender: " << endl
             << "Male: "   << (c[i].male * 100.0) / c[i].Votes() << "%" << endl
             << "Female: " << (c[i].female * 100.0) / c[i].Votes() << "%" << endl;
    
        cout << "\nRace: " << endl
             << "White: "    << (c[i].white * 100.0) / c[i].Votes() << "%" << endl
             << "Black: "    << (c[i].black * 100.0) / c[i].Votes() << "%" << endl
             << "Asian: "    << (c[i].asian * 100.0) / c[i].Votes() << "%" << endl
             << "Hispanic: " << (c[i].hispanic * 100.0) / c[i].Votes() << "%" << endl;

        cout << "\nEducation: " << endl
             << "College: " << (c[i].college * 100.0) / c[i].Votes() << "%" << endl
             << "School: "  << (c[i].school * 100.0) / c[i].Votes() << "%" << endl
             << "None: "    << (c[i].noedu * 100.0) / c[i].Votes() << "%" << endl;
    
        cout << "\nJob: " << endl
             << "White-collar: " << (c[i].wcollar * 100.0) / c[i].Votes() << "%" << endl
             << "Blue-collar: "  << (c[i].bcollar * 100.0) / c[i].Votes() << "%" << endl
             << "None: "         << (c[i].nojob * 100.0) / c[i].Votes() << "%" << endl;

        cout << "\nPolicy: " << endl
             << "Criminal Justice: " << (c[i].cj * 100.0) / c[i].Votes() << "%" << endl
             << "Gun Control: "      << (c[i].gc * 100.0) / c[i].Votes() << "%" << endl
             << "Economy: "          << (c[i].eco * 100.0) / c[i].Votes() << "%" << endl
             << "Foreign Policy: "   << (c[i].fp * 100.0) / c[i].Votes() << "%" << endl
             << "Education: "        << (c[i].edu * 100.0) / c[i].Votes() << "%" << endl
             << "Environment: "      << (c[i].env * 100.0) / c[i].Votes() << "%" << endl
             << "Technology: "       << (c[i].tech * 100.0) / c[i].Votes() << "%" << endl
             << "Immigration: "      << (c[i].imm * 100.0) / c[i].Votes() << "%" << endl
             << "Healthcare: "       << (c[i].hc * 100.0) / c[i].Votes() << "%" << endl
             << "Abortion: "         << (c[i].ab * 100.0) / c[i].Votes() << "%" << endl;
    }
}

int main()
{
    counting = true;

    while(counting)
    {
        ifstream r;             

        r.open("data.txt");     //read data from storage

        if (r.is_open())
        {
            while (r >> id >> password >> age >> gender
                 >> race >> education >> job
                 >> voted >> candidate >> policy)
            {
                //check votes
                for (int i = 0; i < CANDIDATES; i++)
                {
                    //add vote for a candidate if found
                    if (c[i].Name() == candidate)
                    {
                        c[i].Vote();
                        votes++;

                        if      (c[i].Party() == "Republican")
                        republican++;
                        else if (c[i].Party() == "Democratic")
                        democratic++;

                        if      (stoi(age) < 25)
                        {
                            age1824++;
                            c[i].age1824++;
                        }
                        else if (stoi(age) < 30)
                        {
                            age2529++;
                            c[i].age2529++;
                        }
                        else if (stoi(age) < 40)
                        {
                            age3039++;
                            c[i].age3039++;
                        }
                        else if (stoi(age) < 50)
                        {
                            age4049++;
                            c[i].age4049++;
                        }
                        else if (stoi(age) < 65)
                        {
                            age5064++;
                            c[i].age5064++;
                        }
                        else if (stoi(age) <= 90)
                        {
                            age6590++;
                            c[i].age6590++;
                        }

                        if      (gender == "Male")
                        {
                            male++;
                            c[i].male++;
                        }
                        else if (gender == "Female")
                        {
                            female++;
                            c[i].female++;
                        }

                        if      (race == "White")
                        {
                            white++;
                            c[i].white++;
                        }
                        else if (race == "Black")
                        {
                            black++;
                            c[i].black++;
                        }
                        else if (race == "Asian")
                        {
                            asian++;
                            c[i].asian++;
                        }
                        else if (race == "Hispanic")
                        {
                            hispanic++;
                            c[i].hispanic++;
                        }
                        
                        if      (education == "College")
                        {
                            college++;
                            c[i].college++;
                        }
                        else if (education == "School")
                        {
                            school++;
                            c[i].school++;
                        }
                        else if (education == "None")
                        {
                            noedu++;
                            c[i].noedu++;
                        }

                        if      (job == "White-collar")
                        {
                            wcollar++;
                            c[i].wcollar++;
                        }
                        else if (job == "Blue-collar")
                        {
                            bcollar++;
                            c[i].bcollar++;
                        }
                        else if (job == "None")
                        {
                            nojob++;
                            c[i].nojob++;
                        }

                        if      (policy == "CriminalJustice")
                        {
                            cj++;
                            c[i].cj++;
                        }
                        else if (policy == "GunControl")
                        {
                            gc++;
                            c[i].gc++;
                        }
                        else if (policy == "Economy")
                        {
                            eco++;
                            c[i].eco++;
                        }
                        else if (policy == "ForeignPolicy")
                        {
                            fp++;
                            c[i].fp++;
                        }
                        else if (policy == "Education")
                        {
                            edu++;
                            c[i].edu++;
                        }
                        else if (policy == "Environment")
                        {
                            env++;
                            c[i].env++;
                        }
                        else if (policy == "Technology")
                        {
                            tech++;
                            c[i].tech++;
                        }
                        else if (policy == "Immigration")
                        {
                            imm++;
                            c[i].imm++;
                        }
                        else if (policy == "Healthcare")
                        {
                            hc++;
                            c[i].hc++;
                        }
                        else if (policy == "Abortion")
                        {
                            ab++;
                            c[i].ab++;
                        }
                    }
                }
            }
        }
        else
        {
            cout << "Unable to open and read from data file." << endl
                 << "Please make sure the file is in the project.";
            while (1);
        }

        r.close();

        if (generalResults())
            candidateResults();

        counting = false;
    }

    while (1);

    return 0;
}