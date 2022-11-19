// Reference https://www.geeksforgeeks.org/aho-corasick-algorithm-pattern-searching/

using namespace std;
#include <bits/stdc++.h>

const int MAXS = 500;
const int MAXC = 26;
 
int out[MAXS];
int f[MAXS];
int g[MAXS][MAXC];
 
int buildMatchingMachine(string arr[], int k) {
    memset(out, 0, sizeof out);
    memset(g, -1, sizeof g);

    int states = 1;
 
    for (int i = 0; i < k; ++i) {
        const string &word = arr[i];
        int currentState = 0;
 
        for (int j = 0; j < word.size(); ++j)
        {
            int ch = word[j] - 'a';
            if (g[currentState][ch] == -1)
                g[currentState][ch] = states++;
 
            currentState = g[currentState][ch];
        }

        out[currentState] |= (1 << i);
        cout << "I: " << i << " " << (1 << i) << '\n';
    }
 
    for (int ch = 0; ch < MAXC; ++ch)
        if (g[0][ch] == -1)
            g[0][ch] = 0;
 
    memset(f, -1, sizeof f);

    queue<int> q;
 
    for (int ch = 0; ch < MAXC; ++ch) {
        if (g[0][ch] != 0) {
            f[g[0][ch]] = 0;
            q.push(g[0][ch]);
        }
    }

    while (q.size()) {
        int state = q.front();
        q.pop();
        for (int ch = 0; ch <= MAXC; ++ch) {
            if (g[state][ch] != -1) {
                // Find failure state of removed state
                int failure = f[state];
                while (g[failure][ch] == -1)
                      failure = f[failure];
 
                failure = g[failure][ch];
                f[g[state][ch]] = failure;
                out[g[state][ch]] |= out[failure];
 
                q.push(g[state][ch]);
            }
        }
    }
 
    return states;
}
 
int findNextState(int currentState, char nextInput)
{
    int answer = currentState;
    int ch = nextInput - 'a';
 
    // If goto is not defined, use failure function
    while (g[answer][ch] == -1)
        answer = f[answer];
 
    return g[answer][ch];
}
 
void searchWords(string arr[], int k, string text) {
    buildMatchingMachine(arr, k);
    int currentState = 0;
 
    for (int i = 0; i < text.size(); ++i)
    {
        currentState = findNextState(currentState, text[i]);

        if (out[currentState] == 0)
             continue;

        for (int j = 0; j < k; ++j)
        {
            if (out[currentState] & (1 << j))
            {
                cout << "Word " << arr[j] << " appears from "
                     << i - arr[j].size() + 1 << " to " << i << endl;
            }
        }
    }
}
// Preprocessing should be an O(m * k) algorithm
// Driver program to test above
int main()
{
    string arr[] = {"sting", "sti", "ng"};
    string text = "sting";
    //k should be between 0 and 62 (inclusive)
    int k = sizeof(arr)/sizeof(arr[0]);
 
    searchWords(arr, k, text);
 
    return 0;
}