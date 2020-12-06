using namespace std;
#include <iostream>
#include <fstream>
#include <string>

int main() {

    // the ans string will represent each person in a group.
    string ans;
    // the input file.
    ifstream responses;
    responses.open("input.txt");
    // since there are 26 questions labeled a-z, we make and initialize a size 26 array.
    int uniqueAnswers[26] = {0};
    // variable to keep track of the total number of questions answered yes.
    int totalCount = 0;
    // variable to track how large a group is to ensure everyone answers a question
    int groupSize = 0;

    // read in each line from the file for each person.
    while(getline(responses, ans)) {
         // if we reach this, then we are finished reading in a group and can calculate the responses.
        if(ans == "") {
            for(int i = 0; i < 26; i++) {
                // increase the totalCount if everyone in a group answered yes.
                if(uniqueAnswers[i] == groupSize) {
                    totalCount++;
                    
                }
                // reset the answer for the next group.
                uniqueAnswers[i] = 0;
            }
            // once we are done reading the responses, set groupSize to 0 for the next group.
            groupSize = 0;
        }
        else {
            // loop through the line and increment in the array the respective index for the question.
            for(size_t i = 0; i < ans.size(); i++) {
                uniqueAnswers[ans[i] - 'a'] += 1; 
            }
            // increment the groupSize once we read in a member.
            groupSize++;
        }
    }

    cout << "The sum of the counts is: " << totalCount << "\n";

    // close your files!
    responses.close();

    return 0;
}