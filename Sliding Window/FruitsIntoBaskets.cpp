#include<bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> freq;
        int ws = 0;
        int maxLen = 0;

        for (int we=0;we<fruits.size();we++)
        {
                freq[fruits[we]]++;
                while (freq.size()>2)
                {
                        freq[fruits[ws]]--;
                        if (freq[fruits[ws]]==0) freq.erase(fruits[ws]);
                        ws++;
                }
                maxLen = max(maxLen,we-ws+1);
        }
        return maxLen;
}

int main()
{
        vector<int> fruits = {1,2,3,2,2};
        cout<<totalFruit(fruits);
}