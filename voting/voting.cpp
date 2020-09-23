#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "candidate.h"
#include "voter.h"
using namespace std;

bool voting;                   //voting open or closed

const unsigned short int CANDIDATES = 4;      //amount of candidates
const unsigned short int VOTERS = 1000;       //amount of voters
const unsigned short int POLICIES = 10;       //amount of policies

//define candidates
Candidate c[CANDIDATES] =
{
    {"Trump", "Republican"},
    {"Biden", "Democratic"},
    {"Sanders", "Democratic"},
    {"Warren", "Democratic"}
};

//define voters
Voter v[VOTERS];

//define policies
string p[POLICIES] =
{
    "CriminalJustice",
    "GunControl",
    "Economy",
    "ForeignPolicy",
    "Education",
    "Environment",
    "Technology",
    "Immigration",
    "Healthcare",
    "Abortion"
};

//allocate memory
string m[VOTERS][10];

/*check if an ID is eligible*/
bool eligible(int id, string password)
{
    //check voter database
    for (int i = 0; i < VOTERS; i++)
    {
        //check if ID is in database
        if (v[i].ID() == id)
        {
            //check if password is correct
            if (v[i].Password() == password)
            {
                //check if voted
                if (v[i].Voted() == "Yes")
                {
                    cout << "You have already cast your vote.\n" << endl;
                    return false;
                }

                return true;
            }
            else
            {
                cout << "Password is incorrect.\n" << endl;
                return false;
            }
        }
    }

    cout << "You are not eligible for voting.\n" << endl;
    return false;
}

/*enter an ID*/
int enter(int id)
{
    cout << "\nEnter your ID: ";
    cin >> id;

    return id;
}

/*enter a password*/
string enter(string password)
{
    cout << "Enter your password: ";
    cin >> password;

    return password;
}

/*select a candidate*/
int selectCandidate()
{
    cout << "\nSelect your candidate: " << endl;

    for (int i = 0; i < CANDIDATES; i++)
    cout << i + 1 << ". " << c[i].Name() << endl;
    
    int n;
    cin >> n;

    while (n < 1 || n > CANDIDATES)
    {
        cout << "Please select one of the four candidates." << endl;
        cin >> n;
    }
    
    return n;
}

/*select a policy*/
int selectPolicy()
{
    cout << "\nWhat policy was the most important factor in your vote?" << endl
         << "1. Criminal Justice" << endl
         << "2. Gun Control" << endl
         << "3. Economy" << endl
         << "4. Foreign Policy" << endl
         << "5. Education" << endl
         << "6. Environment" << endl
         << "7. Technology" << endl
         << "8. Immigration" << endl
         << "9. Healthcare" << endl
         << "10. Abortion" << endl;

    int n;
    cin >> n;

    while (n < 1 || n > POLICIES)
    {
        cout << "Please select one of the ten policies." << endl;
        cin >> n;
    }

    return n;
}

/*confirm a vote*/
bool confirm(int candidate, int policy)
{
    char conf;

    cout << "\nYour choices: " << endl
         << "Candidate: " << c[candidate].Name() << endl
         << "Policy: " << p[policy] << endl
         << "\nAre you sure you wish to submit your vote?" << endl;
    
    do
    {
        cout << "Enter Y to confirm or N to cancel: ";
        
        cin >> conf;
        conf = toupper(conf);
        
        if (conf == 'Y')
        return true;
        else if (conf == 'N')
        return false;

    } while (conf != 'Y' && conf != 'N');

    return false;
}

/*submit a vote*/
void submit(int voter, int candidate, int policy)
{
    //set voter as voted and update memory
    v[voter].Voted("Yes");
    m[voter][7] = v[voter].Voted();
    
    //set voter candidate choice and update memory
    v[voter].Candidate(c[candidate].Name());
    m[voter][8] = v[voter].Candidate();
    
    //set voter policy choice and update memory
    v[voter].Policy(p[policy]);
    m[voter][9] = v[voter].Policy();
}

/*print a vote*/
void print(int voter)
{
    cout << "\nYour ballot: " << endl
         << "ID: " << v[voter].ID() << endl
         << "Candidate: " << v[voter].Candidate() << endl
         << "\nYour vote has been submitted. Thank you for voting.\n"
         << endl;  
}

int main()
{
    voting = true;             //voting is open

    ifstream r;                //read from data
    ofstream w;                //write to data

    r.open("data.txt");        //read data from storage

    if (r.is_open())
    {
        //read data from storage into memory
        for (int i = 0; i < VOTERS; i++)
        {
            for (int j = 0; j < 10; j++)
            r >> m[i][j];
        }
    }
    else
    {
        cout << "Unable to open and read from data file." << endl
             << "Please make sure the file is in the folder.";
        while (1);
    }

    r.close();

    //load data from memory to voter objects
    for (int i = 0; i < VOTERS; i++)
    {
        v[i].load(stoi(m[i][0]),
                       m[i][1], m[i][2], m[i][3],
                       m[i][4], m[i][5], m[i][6],
                       m[i][7], m[i][8], m[i][9]);
    }

    cout << "Welcome to the 2020 Election." << endl;

    while (voting)
    {
        int id = 0;                     //voter ID
        string password;                //voter password
        int voter, candidate, policy;

        do
        {
            //enter ID and password
            id = enter(id);
            password = enter(password);

            //check voter eligibility
            while (!eligible(id, password))
            {
                id = enter(id);
                password = enter(password);
            }

            voter = id - 11000;
        
            candidate = selectCandidate() - 1;
            policy    = selectPolicy() - 1;
            
          //verify and confirm choices
        } while(!confirm(candidate, policy));

        //submit ballot
        submit(voter, candidate, policy);
        
        w.open("data.txt");        //write data to storage
        
        if (w.is_open())
        {
            //write data from memory into storage
             for (int i = 0; i < VOTERS; i++)
             {
                 for (int j = 0; j < 10; j++)
                 w << m[i][j] << " ";
                
                w << endl;
             }
        }
        else
        {
            cout << "Unable to open and write to data file." << endl
                 << "Please make sure the file is in the folder.";
            while (1);
        }
        
        w.close();

        //print ballot
        print(voter);   
    }

    voting = false;

    cout << "Voting is closed." << endl;

    return 0;
}