///  (Medium)  3355. Zero Array Transformation I

////////////////////////////////////////////////////////////////////////////    TC  O(Q+n)      ///  SC  O(n+n)


class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>diff(n,0);
        
      //////////////////////////////////////////////////////////             // STEP 1 => Make a difference array
        for(auto &query:queries){
            int start=query[0];
            int end=query[1];
            int x=1;

            diff[start]+=x;
            if(end+1<n){
                diff[end+1]-=x;
            }
        }

      //////////////////////////////////////////////////////////////////////  // STEP2 => find cummulative sum

        vector<int>ans(n,0);
        int cumSum=0;

        for(int i=0;i<n;i++){
            cumSum+=diff[i];
            ans[i]=cumSum;
        }


        // Check Condition in Question

        for(int i=0;i<n;i++){
            if(ans[i]<nums[i]){   // 0 nhi ho paya
                return false;
            }
        }

       return true;
    }
};
