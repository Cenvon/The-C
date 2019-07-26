class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        static int x=[](){
            std::ios::sync_with_stdio(false);
            cin.tie(NULL);
            return 0;
        }();
        // nums1.size() <= nums2.size()
        const int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        int l = 0, r = n1;
        // ��k�� left mid
        // (4 + 1) / 2 = 2
        // (3 + 1) / 2 = 2
        const int k = (n1 + n2 + 1) / 2;
        // [l, r]
        // min m1 s.t a[m1] >= a[m2-1]
        // m2 = k - m1,  max m2  a[m2] >= a[m1-1]
        while (l < r) {
            int m1 = l + (r - l) / 2;
            int m2  = k - m1;
            if (nums1[m1] > nums2[m2 - 1]) {
                r = m1;
            } else {
                l = m1 + 1;
            }
        }
        int m1 = l, m2 = k - l;
        int c1 = max(m1 == 0 ? INT_MIN : nums1[m1-1], m2 == 0 ? INT_MIN : nums2[m2-1]);
        if ((n1 + n2) % 2) return c1;
        int c2 = min(m1 >= n1 ? INT_MAX : nums1[m1], m2 >= n2 ? INT_MAX : nums2[m2]);
        return (c1 + c2) * 0.5;
    }
};