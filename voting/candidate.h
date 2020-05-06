#ifndef CANDIDATE_H
#define CANDIDATE_H
using namespace std;

class Candidate
{
    private:

    string name;    //name of a candidate
    string party;   //party affiliation
    int votes;      //votes for a candidate

    public:

    //votes per age group
    int age1824,    //18-24
        age2529,    //25-29
        age3039,    //30-39
        age4049,    //40-49
        age5064,    //50-64
        age6590;    //65-90

    //votes per gender
    int male, female;

    //votes per race
    int white, black, asian, hispanic;
    
    //votes per education level
    int college, school, noedu;

    //votes per job level
    int wcollar, bcollar, nojob;

    //votes per policy
    int cj,     //criminal justice
        gc,     //gun control
        eco,    //economy
        fp,     //foreign policy
        edu,    //education
        env,    //environment
        tech,   //technology
        imm,    //immigration
        hc,     //healthcare
        ab;     //abortion
    
    /*constructor*/
    Candidate(string name, string party)
    {
        this->name = name;
        this->party = party;
       
        votes = 0;
        
        age1824 = 0;
        age2529 = 0;
        age3039 = 0;
        age4049 = 0;
        age5064 = 0;
        age6590 = 0;
        
        male = 0;
        female = 0;
        
        white = 0;
        black = 0;
        asian = 0;
        hispanic = 0;
        
        college = 0;
        school = 0;
        noedu = 0;
        
        wcollar = 0;
        bcollar = 0;
        nojob = 0;
        
        cj = 0;
        gc = 0;
        eco = 0;
        fp = 0;
        edu = 0;
        env = 0;
        tech = 0;
        imm = 0;
        hc = 0;
        ab = 0;
    }

    /*adds a vote for a candidate*/
    void Vote()
    {
        votes++;
    }

    /*returns the name of the candidate*/
    string Name()
    {
        return name;
    }

    /*returns the name of the party*/
    string Party()
    {
        return party;
    }

    /*returns the amount of votes for a candidate*/
    int Votes()
    {
        return votes;
    }
};

#endif
