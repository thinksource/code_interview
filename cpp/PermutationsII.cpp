class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        if(num.size()==0) {
            return vector<vector<int> >();
        }
        vector<vector<int> > vs = permute(num, (int)num.size()-1);
        set<vector<int> > se(vs.begin(), vs.end());
        return vector<vector<int>>(se.begin(), se.end());
    }

    vector<vector<int> > permute(vector<int> &num, int n) {
        vector<vector<int> > res;
        if(n==0) {
            res.push_back(vector<int>{num[0]});
            return res;
        }
        vector<vector<int> > ps = permute(num, n-1);
        for(int i=0;i<ps.size();i++) {
            for(int j=0;j<=n;j++){
                if(j!=n) {
                    if(ps[i][j]==num[n]) {
                        continue;
                    }
                }
                vector<int> t(ps[i].begin(), ps[i].end());
                t.insert(t.begin()+j,num[n]);
                res.push_back(t);
            }
        }
        return res;
    }
};
