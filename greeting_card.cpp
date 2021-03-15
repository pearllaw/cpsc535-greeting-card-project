#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <sstream>
#include <string>

using namespace std;

pair <string, string> list_pair(string first, string second);

pair <string, string> list_pair(string first, string second)
{
    pair<string, string> pairs = {first, second};
    return pairs;
}

string greeting_card_generator(string s, vector<pair<string, string>> ls)
{
    // return original string if empty string/no list pairs
    string ne{ s };
    string result;
    vector<int> vec;
    for (int i = 1;i <= ne.length();i++) {
        vec.push_back(-1);
    }
    for (unsigned int j = 0; j < ls.size(); j++)
    {    
        for (unsigned int i = 0; i < ne.length(); i++)
        {
            size_t found = ne.find(ls[j].first);
            while (found != string::npos)  // match found
            {
                vec[found] = j;
                found = ne.find(ls[j].first, found+ls[j].first.length());
            }
        }
    }
    for (unsigned int i = 0; i < ne.length(); i++)
    {
        if (vec[i] == -1)
        {
            string nm = ne.substr(i, 1);
            result += nm;
        }
        else
        {
            for (unsigned int j = 0; j < ls.size(); j++) 
            {
               // cout << "54  " << j <<endl;
                if (vec[i] == j) {
                    string m = ls[j].second;
                    result += m;
                    i = i + ls[j].first.length() -1; 
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
        cout << first << "  &  " << second << endl;

        ls.push_back(list_pair(first, second));
    }
    infile2.close();
    
    // output new greeting
    cout << s << endl;
    cout << greeting_card_generator(s, ls) << endl;
    
    return 0;
}

