#include <bits/stdc++.h>
using namespace std;

// Hàm tính tổng các chữ số của một số nguyên
int tongphantu(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int l, r;
    cin >> l >> r;
    unordered_map<int, vector<int>> dem;
    
    for (int i = l; i <= r; i++)
    {
        int s = tongphantu(i);
        dem[s].push_back(i);
    }
    int maxhieu = 0;
    for (pair<int ,const vector<int>&> x : dem)
    {
        const vector<int> nums = x.second;
        if (nums.size() > 1)
        {
            int minn = *min_element(nums.begin(), nums.end());
            int maxn = *max_element(nums.begin(), nums.end());
            maxhieu = max(maxhieu, maxn - minn);
        }
    }
    cout << maxhieu;
    return 0;
}
