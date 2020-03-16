class Solution {
public:
    bool arePartner(int a, int b) {
        if(a % 2)
            return b == a - 1;
        else
            return b == a + 1;
    }
    
    int minSwapsCouples(vector<int>& s) {
        int swaps = 0;
        
        for(int i=0; i<s.size(); i = i+2) {
            if(!arePartner(s[i], s[i+1])) {
                int partner;
                
                if(s[i]%2)
                    partner = find(s.begin()+i+1, s.end(), s[i]-1) - s.begin();
                else
                    partner = find(s.begin()+i+1, s.end(), s[i]+1) - s.begin();
                
                //swap
                s[i+1] += s[partner];
                s[partner] = s[i+1] - s[partner];
                s[i+1] -= s[partner];
                swaps++;
            }
            
            // for(int i: s)
            //     cout << i << " ";
            // cout << "\n";
        }
        
        return swaps;
    }
};
