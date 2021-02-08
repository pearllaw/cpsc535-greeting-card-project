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

string greeting_card_generator(string s, vector<pair<string, string>> ls, 
    int char_count, int pair_count)
{
    // return original string if no words/pairs
    if (char_count <= 0 || pair_count <= 0)
    {
        return s;
    }
    
    // initialize iss as s
    istringstream iss(s);
    string word;
    s.clear();

    while (iss >> wormv
    {
        for (unsigned int i = 0; i < pair_count; i++)
        {
            if (word == ls[i].first)
            {
                s += ls[i].second + ' ';
                break;
            }
        }
        s += word + ' ';
    }     
  
    // for (unsigned int i = 0; i < pair_count; i++)
    // {
    //     size_t found = s.find(ls[i].first, 0);
    //     size_t word_len = ls[i].first.length();
    //     string replacement = ls[i].second;
    //     if (found == string::npos) break;
    //     s.replace(found, word_len, replacement);
    //     found += replacement.length();
    // }

    return s;
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
    
    // number of characters in s
    int n = s.length();
    
    // count number of pairs in ls
    int m = ls.size();

    // output new greeting
    cout << greeting_card_generator(s, ls, n, m);
    
    return 0;
}


