#include <bits/stdc++.h>
#include <iostream>
#define int long long
#define ll long long
#define float double
#define endl "\n"
#define forp(i, x, t) for (int i = x; i < t; i++)
#define forn(i, t) for (int i = t; i >= 0; i--)
#define all(x) x.begin(), x.end()
#define rev(x) x.rbegin(), x.rend()
#define veci vector<int>
#define pb(x) push_back(x)
const int mod = 1e9 + 7;

using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> vp;
    int suml = 0, sumr = 0;
    forp(i,0,n) {
        int x, y;
        cin >> x >> y;
        vp.push_back({x, y});
        suml += x;
        sumr += y;
    }

    if (suml > 0 || sumr < 0) {
        cout << "No";
        return 0;
    }

    veci result(n);
    int curSum = 0;
    forp(i,0,n) {
        result[i] = vp[i].first;
        curSum += result[i];
    }

    forp(i,0,n) {
        if (curSum == 0) {
            break;
        }

        int maxIncrease = vp[i].second - vp[i].first;
        int required = 0 - curSum;
        int kitnaKreFir = min(maxIncrease, required);
        result[i] += kitnaKreFir;
        curSum += kitnaKreFir;
    }

    if (curSum == 0) {
        cout << "Yes\n";
        forp(i,0,n) cout << result[i] << ' '; 
    } else {
        cout << "No\n";
    }

    return 0;
}