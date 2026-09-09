class Solution {
public:
  int removeDuplicates(vector<int> &v)// 1 1 2 2 2 3 3 3 3 5
{
    if (v.empty())return 0;

    int j = 0; // last unique index
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] != v[j])
        {
            j++;
            v[j] = v[i];
        }
    }
    return j + 1;
}};