class TreeAncestor {
public:
    vector<vector<int>> up;
    int LOG;
    TreeAncestor(int n, vector<int>& parent) {
        LOG =20;
        up.assign(LOG,vector<int>(n));
        for(int i=0;i<n;i++)
            up[0][i] = parent[i];
        for(int j=1;j<LOG;j++){
            for(int i=0;i<n;i++){
                if(up[j-1][i] == -1)
                    up[j][i] = -1;
                else
                    up[j][i] = up[j-1][up[j-1][i]];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int j=0;j<LOG;j++){
            if(k&(1<<j)){
                node = up[j][node];
                if(node == -1){
                    return -1;
                }
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */