#include<bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        k = n-k;
        int ws=0;
        int sum=0;
        int minSum=INT_MAX;
        int totSum=0;

        for(int we=0;we<n;we++){
            sum += cardPoints[we];
            if(we>=k-1){
                minSum = min(minSum,sum);
                sum-=cardPoints[ws];
                ws++;
            }
            totSum += cardPoints[we];
        }
        //cout<<totSum<<" "<<minSum<<endl;
        return (k==0)?totSum:totSum-minSum;
}

int main()
{
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    int k = 3;
    cout<<maxScore(cardPoints,k);
}