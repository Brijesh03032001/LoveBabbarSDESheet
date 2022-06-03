// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    string dir="RLDU";
    void sol(int r ,int c, vector<vector<int>> &m , int n , vector<string>&ans, string mo,vector<vector<int>>&vis, vector<int>&dx, vector<int>&dy)
    {
        if(r==n-1 && c==n-1)
        {
            ans.push_back(mo);
            return ;
        }
        for(int i=0;i<4;i++){
            int nx= r + dx[i];
            int ny= c + dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<n && m[nx][ny]==1 && vis[nx][ny]==0)
            {
                vis[r][c]=1;
                sol(nx,ny,m,n,ans,mo+dir[i],vis,dx,dy);
                vis[r][c]=0;
                
            }
        }
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
       vector<string>ans;
       vector<vector<int>>vis(n,vector<int>(n,0));
       vector<int>dx{0,0,1,-1};
       vector<int>dy{1,-1,0,0};
       string a="";
       if(m[0][0]==0)
       {
           return ans;
       }
       else
       {
           sol(0,0,m,n,ans,a,vis,dx,dy);
           //return ans;
       }
       
       return ans;
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends