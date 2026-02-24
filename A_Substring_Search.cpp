#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> build_suffix_array(const string& s) {
    string str = s + "$";
    int n = str.size();
    vector<int> p(n), c(n);
    vector<pair<char, int>> a(n);
    for (int i = 0; i < n; ++i) a[i] = {str[i], i};
    sort(a.begin(), a.end());

    for (int i = 0; i < n; ++i) p[i] = a[i].second;
    c[p[0]] = 0;
    for (int i = 1; i < n; ++i) {
        c[p[i]] = c[p[i - 1]] + (a[i].first != a[i - 1].first);
    }

    int k = 0;
    while ((1 << k) < n) {
        for (int i = 0; i < n; ++i)
            p[i] = (p[i] - (1 << k) + n) % n;
        vector<int> cnt(n);
        for (int x : c) cnt[x]++;
        vector<int> pos(n);
        pos[0] = 0;
        for (int i = 1; i < n; ++i)
            pos[i] = pos[i - 1] + cnt[i - 1];
        vector<int> p_new(n);
        for (int x : p) {
            int i = c[x];
            p_new[pos[i]] = x;
            pos[i]++;
        }
        p = p_new;
        vector<int> c_new(n);
        c_new[p[0]] = 0;
        for (int i = 1; i < n; ++i) {
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
            pair<int, int> now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
            c_new[p[i]] = c_new[p[i - 1]] + (now != prev);
        }
        c = c_new;
        k++;
    }

    return p;
}

bool is_substring(const string& pattern, const string& text, const vector<int>& suffix_array) {
    int left = 0, right = suffix_array.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int pos = suffix_array[mid];
        string suffix = text.substr(pos, pattern.size());
        if (suffix == pattern) {
            return true;
        } else if (suffix < pattern) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string t;
    cin >> t;
    vector<int> suffix_array = build_suffix_array(t);

    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (is_substring(s, t + "$", suffix_array)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
