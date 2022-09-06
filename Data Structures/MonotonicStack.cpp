#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;


int main() {
    int arr[5] = {1,4,3,2,5};
    vector<int> assign(5, -1);
    int n = 5;
    //pair consists of two integers <height of element, index of element>
    stack<pair<int, int>> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty()) {
            //checks if the element at the top is less than the current element in the arr 
            //(Can also be less than or equal to depending on the problem)
            if (stk.top().first < arr[i]) {
                //assign the index of the cur elem since it is the closest element with a greater height
                assign[stk.top().second] = i;
                stk.pop();
            } else {break;}
        }
        //inserting a new element into the stack
        stk.push(make_pair(arr[i], i));
    }
    for (int i = 0; i < n; i++) {
        cout << assign[i] << " ";
    }
    cout << '\n';
}
