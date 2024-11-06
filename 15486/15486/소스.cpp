//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
#define MAX 1500001

int DP[MAX] = { 0, };

int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<pair<int, int>> vec;

    vec.push_back({ 0, 0 });
    int day, cost;
    for (int i = 0; i < N; i++) {
        cin >> day >> cost;
        vec.push_back({ day, cost });
    }

    int currentMax = 0;
    for (int i = 1; i < N + 1; i++) {
        currentMax = DP[i];
        if (i + vec[i].first > N + 1) continue;
        DP[i + vec[i].first] = max(DP[i + vec[i].first], currentMax + vec[i].second);
    }

    cout << DP[N];

    return 0;
}