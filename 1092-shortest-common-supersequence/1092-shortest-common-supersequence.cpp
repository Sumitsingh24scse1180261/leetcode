class Solution {
public:
string a,b;
vector<vector<int>> dp;

int solve(int i,int j){
if(i==a.size()) return b.size()-j;
if(j==b.size()) return a.size()-i;

if(dp[i][j]!=-1) return dp[i][j];

if(a[i]==b[j])
return dp[i][j]=1+solve(i+1,j+1);

return dp[i][j]=1+min(solve(i+1,j),solve(i,j+1));
}

string shortestCommonSupersequence(string str1,string str2){
a=str1;
b=str2;

int n=a.size();
int m=b.size();

dp.assign(n,vector<int>(m,-1));

solve(0,0);

string ans;
int i=0,j=0;

while(i<n&&j<m){
if(a[i]==b[j]){
ans+=a[i];
i++;
j++;
}
else if(solve(i+1,j)<=solve(i,j+1)){
ans+=a[i];
i++;
}
else{
ans+=b[j];
j++;
}
}

while(i<n){
ans+=a[i];
i++;
}

while(j<m){
ans+=b[j];
j++;
}

return ans;
}
};