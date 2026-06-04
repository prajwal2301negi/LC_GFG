// Problem: Block Placement Queries
// Difficulty: hard
// Runtime: 771 ms
// Memory: 372.5 MB

class segtree {
    const int N = 1e5+7;
    int size;
    vector<int> count;

public:
    segtree(){
        size=1;
        while(size<N) size*=2;
        count.resize(2*size, 0);
    }

    void insert(int i,int val,int x,int lx,int rx){
        if(rx-lx==1){
            count[x]=val;
            return;
        }
        int mid = lx+(rx-lx)/2;
        if(i<mid) insert(i, val, 2*x+1, lx, mid);
        else insert(i, val, 2*x+2, mid, rx);

        count[x]=max(count[2*x+1], count[2*x+2]);
    }

    void insert(int i,int val){
        insert(i, val, 0, 0, size);
    }

    int calc(int l,int r,int x,int lx,int rx){
        if(l>=rx || lx>=r) return 0;
        if(l<=lx && rx<=r) return count[x];

        int mid = lx+(rx-lx)/2;
        return max(calc(l,r,2*x+1,lx,mid), calc(l,r,2*x+2,mid,rx));
    }

    int calc(int l,int r){
        return calc(l,r,0, 0,size);
    }
};

class Solution {
public:
    const int N = 1e5+7;

    vector<bool> getResults(vector<vector<int>>& queries) {
        segtree st;
        st.insert(0, N);

        vector<bool> res;
        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(N);

        for(auto &q : queries){
            int op = q[0];

            if(op==1){
                int x = q[1];

                if(obstacles.count(x)) continue;

                auto it = obstacles.upper_bound(x);
                st.insert(x, *it - x);

                it--;
                st.insert(*it, x - *it);

                obstacles.insert(x);
            }
            else {
                int x = q[1];
                int sz = q[2];

                int mx = 0;
                auto it = obstacles.lower_bound(x);

                if(*it == x){
                    it--;
                    mx = max(mx, st.calc(0, *it+1));
                }
                else {
                    it--;
                    mx = max(mx, x - *it);

                    if(it != obstacles.begin()){
                        it--;
                        mx = max(mx, st.calc(0, *it+1));
                    }
                }

                res.push_back(mx >= sz);
            }
        }

        return res;
    }
};