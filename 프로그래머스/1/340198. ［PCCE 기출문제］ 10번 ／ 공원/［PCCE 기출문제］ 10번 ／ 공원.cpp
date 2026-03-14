#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park){
    int answer = 0;
    sort(mats.begin(), mats.end(), greater<int>());
    int max_side = 0;
    vector<vector<int>> dp(park.size()+1, vector<int>(park[0].size()+1, 0));
    for(int i = 0; i < park.size(); i++){
        for(int j = 0; j < park[0].size(); j++){
            if(park[i][j] == "-1"){
                dp[i+1][j+1] = min({dp[i+1][j], dp[i][j+1], dp[i][j]})+1;
                max_side = max({dp[i+1][j+1], max_side});
            }
        }
    }
    for(int i = 0; i < mats.size(); i++){
        if(mats[i] <= max_side){
            return mats[i];
        }
    }
    return -1;
}