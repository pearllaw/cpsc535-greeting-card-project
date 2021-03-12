#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <sstream>

using namespace std;

pair <string, string> list_pair(string first, string second);

pair <string, string> list_pair(string first, string second)
{
    pair<string, string> pairs = {first, second};
    return pairs;
}

string greeting_card_generator(string s, vector<pair<string, string>> ls)
{
     string ne{ s };
    string result = "";
   
    vector<int> vec;
    for (int i = 1;i <= ne.length()-1;i++) {
        vec.push_back(-1);
    }
    for (unsigned int i = 0; i < ne.length() ; i++)
    {    
        for (unsigned int j = 0; j < ls.size() ; j++)
        {
            size_t found = ne.find(ls[j].first);
            if (found != string::npos)  // match found
            {
                vec[found] = j;
            }
        }
    }

    for (unsigned int i = 0; i < ne.length(); i++)
    {
        if (vec[i] == -1)
        {
            result += ne.substr(i, 1);
        }
        else
        {
            for (unsigned int j = 0; j < ls.size(); j++) 
            {
                if (vec[i] == j) {
                    result += ls[j].second;
                    i = i + ls[j].first.length();
                }
            }
        }
    }
    return result;
}
 
int main(int argc, char** argv)
{
    // check arguments
    if (argc < 3)
    {
        cerr << "Usage: " << argv[0] << " filename1.txt filename2.txt" << endl;
        return EXIT_FAILURE;
    }

    ifstream infile(argv[1]);   // file containing string input
    ifstream infile2(argv[2]);  // file containing list of pairs

    // failed to open file
    if (infile.fail())
    {
        cout << "Unable to open " << argv[1] << endl;
        return 1;
    }
    if (infile2.fail())
    {
        cout << "Unable to open " << argv[2] << endl;
        return 1;
    }

    char c;
    string s, line;
    vector <pair<string, string>> ls;

    // assign input string into s
    infile >> noskipws; // prevent loss of spaces
    while (infile >> c) 
    {
        s += c;   
    }
    infile.close();

    // assign list of pairs into ls
    while (getline(infile2, line))
    {
        stringstream ss(line);
        string first, second;
        getline(ss, first, ',');
        getline(ss, second, ',');

        ls.push_back(list_pair(first, second));
    }
    infile2.close();
    
    // output new greeting
    cout << greeting_card_generator(s, ls) << endl;
    
    return 0;
}


