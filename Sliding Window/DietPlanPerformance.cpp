#include<bits/stdc++.h>
using namespace std;

int dietPlanPerformance(vector<int>& calories,int k,int lower,int upper)
{
    int ws = 0;
    int sum = 0;
    int res = 0;
    int n = calories.size();

    for (int we=0;we<n;we++)
    {
        sum += calories[we];
        if (we>=k-1)
        {
            if (sum<lower)
            {
                res-=1;
            }
            else if (sum>upper)
            {
                res+=1;
            }
            sum -= calories[ws];
            ws++;
        }
    }
    return res;
}

int main()
{
    vector<int> calories = {0,0,0};
    int k=3;
    int lower=2;
    int upper=4;
    cout<<dietPlanPerformance(calories,k,lower,upper);
}