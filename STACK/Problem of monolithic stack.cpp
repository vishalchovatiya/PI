/*
Helpers:
https://medium.com/@vishnuvardhan623/monotonic-stack-e9dcc4fa8c3e
https://www.hackerrank.com/challenges/find-maximum-index-product/problem

Q. Index product = left(i) * right(i)
left(i) = closest index j such that j < i and a[j] > a[i]. If no such j exists then  = 0. 
right(i) = closest index k such that k < i and a[k] > a[i]. If no such k exists then  = 0.

Simple input: 
5
5 4 3 4 5

Sample output:
8

Explanation:
IndexProduct(1) = 0 
IndexProduct(2) = 1 x 5 = 5
IndexProduct(3) = 2 x 4 = 8
IndexProduct(4) = 1 x 5 = 5
IndexProduct(5) = 0 
*/

#include <bits/stdc++.h>

using namespace std;
#define DEBUG(X)    std::cout<<#X<<" = "<<X<<std::endl;
#define PRINT(C,WAY)    do\
                        {\
                            cout<<setw(10)<<#C<<" : ";\
                            for(auto&& i : C) {\
                                WAY;\
                            }\
                            cout<<endl;\
                        } while (0);

vector<string> split_string(string);

// Complete the solve function below.
int solve(vector<int> arr) {

    long maxInnerPro = 0;
    long size = arr.size();

    PRINT(arr,cout<<i<<" ")

    long rightMax[size] = {0};
    stack<long> rS;
    for (long i = size-1; i >= 0; --i)
    {
        while(!rS.empty() && arr[i] >= arr[rS.top()]){
            rS.pop();
        }
        
        if(rS.empty()) rightMax[i] = 0;
        else rightMax[i] = rS.top()+1;
        rS.push(i);
    }
    PRINT(rightMax,cout<<i<<" ")



    long leftMax[size] = {0};
    stack<long> lS;
    for (long i = 0; i < size; ++i)
    {
        while(!lS.empty() && arr[i] >= arr[lS.top()]){
            lS.pop();
        }
        
        if(lS.empty()) leftMax[i] = 0;
        else leftMax[i] = lS.top()+1;
        lS.push(i);
    }
    PRINT(leftMax,cout<<i<<" ")


    for (long i = 0; i < size; ++i)
    {
        maxInnerPro = max(leftMax[i] * rightMax[i], maxInnerPro);
    }

    DEBUG(maxInnerPro);
    return maxInnerPro;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int arr_count;
    cin >> arr_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(arr_count);

    for (int arr_itr = 0; arr_itr < arr_count; arr_itr++) {
        int arr_item = stoi(arr_temp[arr_itr]);

        arr[arr_itr] = arr_item;
    }

    int result = solve(arr);

    fout << result << "\n";
    cout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
