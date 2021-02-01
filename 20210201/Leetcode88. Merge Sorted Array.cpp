class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> result(n + m);
        int i = 0, j = 0;
        int t = 0;
        while (true)
        {
            if (i >= m)
                break;
            if (j >= n)
                break;
            if (nums1[i] < nums2[j])
            {
                result[t] = nums1[i];
                i++;
                t++;
            }
            else
            {
                result[t] = nums2[j];
                j++;
                t++;
            }
        }
        while (i < m)
        {
            result[t] = nums1[i];
            i++;
            t++;
        }
        while (j < n)
        {
            result[t] = nums2[j];
            j++;
            t++;
        }
        swap(result, nums1);
    }
};

/*Note:
// 0. Create an empty vector v0
std::vector<int> v0;

// 1. Create a vector v1 with 3 elements of default value 0
std::vector<int> v1(3);

// 2. Create a vector v2 with 5 elements of value 2
std::vector<int> v2(5, 2);

// 3. Create a vector v3 with 3 elements of value 1 and with the allocator of vector v2
std::vector<int> v3(3, 1, v2.get_allocator());

// 4. Create a copy, vector v4, of vector v2
std::vector<int> v4(v2);

// 5. Create a vector v5 by copying the range v4[_First, _Last)
std::vector<int> v5(v4.begin() + 1, v4.begin() + 3);
*/
