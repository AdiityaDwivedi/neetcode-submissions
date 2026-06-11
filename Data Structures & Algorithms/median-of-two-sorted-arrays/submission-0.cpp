class Solution {
public:
    vector<int> mergeSort(vector<int> &num1, vector<int> &num2) {
        vector<int> ans;
        int i = 0, j = 0;

        while(i < num1.size() && j < num2.size()) {
            if(num1[i] > num2[j]) {
                ans.push_back(num2[j++]);
            } else {
                ans.push_back(num1[i++]);
            }
        }

        while(i < num1.size()) {
            ans.push_back(num1[i++]);
        }

        while(j < num2.size()) {
            ans.push_back(num2[j++]);
        }

        return ans;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        ans = mergeSort(nums1, nums2);

        int n = ans.size();
        double k = 0;

        if(n % 2 == 0) {
            k = ((double)ans[n / 2 - 1] + ans[n / 2]) / 2.0;
        } else {
            k = ans[ans.size() / 2];
        }
        return k;
    }
};
