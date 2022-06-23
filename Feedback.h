#ifndef FEEDBACK_H
#define FEEDBACK_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Feedback
{
private:
    string feedback;
    int rating;

public:
    Feedback();
    ~Feedback();
    string GetFeed() const
    {
        return feedback;
    }

    void SetFeed(string feedback)
    {
        this->feedback = feedback;
    }
    // Store Feedback in File
    void storeFeedback(string did, string pid)
    {
        ofstream feedbackFile;
        feedbackFile.open("feedbacks.txt", ios::app);
        feedbackFile << did << " " << pid << " " << feedback << " " << rating << endl;
        feedbackFile.close();
    }
    void readFeedback(string did, string pid)
    {
        ifstream feedbackFile;
        feedbackFile.open("feedbacks.txt");
        string temp;
        while (feedbackFile >> temp)
        {
            if (temp == did && feedbackFile >> temp && temp == pid)
            {
                feedbackFile >> feedback >> rating;
                break;
            }
        }
        feedbackFile.close();
    }
    int GetRating() const
    {
        return rating;
    }

    void SetRating(int rating)
    {
        this->rating = rating;
    }
};

Feedback::Feedback()
{
    feedback = "\0";
    rating = 0;
}

Feedback::~Feedback()
{
}
#endif