#ifndef VOTER_H
#define VOTER_H
using namespace std;

class Voter
{
    private:

    int id;             //voter ID
    string password;    //voter password
    string age;         //voter age
    string gender;      //voter gender
    string race;        //voter race
    string education;   //voter education
    string job;         //voter job
    string voted;       //vote status
    string candidate;   //candidate choice 
    string policy;      //most important policy
    

    public:

    /*constructor*/
    Voter()
    {
        load(0,
             "None", "None", "None",
             "None", "None", "None", 
             "No", "None", "None");
    }

    /*loads database information for a voter*/
    void load(int id,
              string password, string age, string gender,
              string race, string education, string job, 
              string voted, string candidate, string policy)
    {
        this->id = id;
        this->password = password;
        this->age = age;
        this->gender = gender;
        this->race = race;
        this->education = education;
        this->job = job;
        this->voted = voted;
        this->candidate = candidate;
        this->policy = policy;
    }

    /*sets voted to true if a voter has voted*/
    void Voted(string voted)
    {
        this->voted = voted;
    }

    /*sets the candidate choice for a voter*/
    void Candidate(string candidate)
    {
        this->candidate = candidate;
    }

    /*sets the most important policy for a voter*/
    void Policy(string policy)
    {
        this->policy = policy;
    }

    /*returns the voter ID*/
    int ID()
    {
        return id;
    }

    /*returns the voter password*/
    string Password()
    {
        return password;
    }

    /*returns the voter age*/
    string Age()
    {
        return age;
    }

    /*returns the voter gender*/
    string Gender()
    {
        return gender;
    }

    /*returns the voter race*/
    string Race()
    {
        return race;
    }

    /*returns the voter education*/
    string Education()
    {
        return education;
    }

    /*returns the voter job*/
    string Job()
    {
        return job;
    }

    /*returns the vote status for a voter*/
    string Voted()
    {
        return voted;
    }

    /*returns the candidate choice for a voter*/
    string Candidate()
    {
        return candidate;
    }

    /*returns the most important policy for a voter*/
    string Policy()
    {
        return policy;
    }
};

#endif