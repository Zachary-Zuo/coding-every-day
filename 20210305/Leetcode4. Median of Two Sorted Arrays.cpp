class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int l = nums1.size() + nums2.size();
        if (l % 2 == 1)
        {
            return getKth(nums1, nums2, (l + 1) / 2);
        }
        else
        {
            return (getKth(nums1, nums2, l / 2) + getKth(nums1, nums2, l / 2 + 1)) / 2.0;
        }
    }

    int getKth(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int lm = nums1.size();
        int ln = nums2.size();
        int i1 = 0, i2 = 0;
        while (true)
        {
            if (i1 == lm)
                return nums2[i2 + k - 1];
            if (i2 == ln)
                return nums1[i1 + k - 1];
            if (k == 1)
                return min(nums1[i1], nums2[i2]);
            int j1 = min(i1 + k / 2 - 1, lm - 1);
            int j2 = min(i2 + k / 2 - 1, ln - 1);

            if (nums1[j1] <= nums2[j2])
            {
                k -= j1 - i1 + 1;
                i1 = j1 + 1;
            }
            else
            {
                k -= j2 - i2 + 1;
                i2 = j2 + 1;
            }
        }
    }
};