// Problem: Most Frequent Prime
// Difficulty: medium
// Runtime: 11 ms
// Memory: 31.3 MB

class Solution {
public: 
    bool isPossible(int x,int y,int row,int col){
        if(x>=0 && x<row && y>=0 && y<col) return true;
        
        return false;
    } 
    bool isPrime(int n){
        if(n<2) return false;
        
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        
        return true;
    }
    
    int mostFrequentPrime(vector<vector<int>>& mat) {
        unordered_map<int,int> pf; 
        
        int row=mat.size(); 
        int col=mat[0].size(); 

        int d1[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int d2[8] = {-1, 0, 1, -1, 1, -1, 0, 1};


        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                for(int k=0;k<8;k++){
                    int digit = mat[i][j];
                    int x = i+d1[k];
                    int y = j+d2[k];
                    while(isPossible(x,y,row,col)){
                        digit = digit*10+mat[x][y];
                        if(digit>10 && isPrime(digit)){
                            pf[digit]++;
                        }
                        x+=d1[k];
                        y+=d2[k];
                    }

                }
            }
        }


        int mxf=0; 
        int mxp=-1; 
        for(auto it:pf){
            int p=it.first; 
            int freq=it.second; 
            if(freq> mxf || (freq==mxf && p>mxp)){
                mxf=freq;
                mxp=p;
            }
        }
        
        return mxp;
        
    }
};