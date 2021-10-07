#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


int main()
{
    string line, word;
    ifstream rFile;

    map<string, int> WordM = { {"Mother", 47}, {"Father", 47}, {"Brother", 19}, {"Wife", 25} };
    map<string, int>::iterator it, itMax;

    rFile.open("input.txt");

    if (rFile.is_open()) 
    {
        while (getline(rFile, line))
        {
            istringstream ss(line);

            while (ss >> word)
            {
                it = WordM.find(word);
                if (it != WordM.end())
                {
                    it->second += 1;
                }
                else
                {
                    WordM.insert(pair < string, int>(word, 1));
                }
            }

        }
    }
    rFile.close();

    ofstream wFile("result.txt");
    itMax = WordM.begin();
    for (it = WordM.begin(); it != WordM.end(); ++it)
    {
        if (itMax->second < it->second)
        {
            itMax = it;
        }

        cout << it->first << ":" << it->second << endl;
        wFile << it->first << ":" << it->second << endl;
    }
    wFile << "This word is frequerency word: " << itMax->first << " : " << itMax->second << endl;

    WordM.clear();

    wFile.close();

    return 0;
}

