int main() {
    TEST {
        int N, K;
        cin >> N >> K;
        ll MOD = 998244353;
        vvll dp(K + 3, vll(2, 0));
        dp[1][0] = dp[2][1] = 2;
        REP(i, N - 1) {
            vvll dp2(K + 3, vll(2, 0));
            REP1(j, 1, K + 1) {
                dp2[j][0] += dp[j][0] + 2 * dp[j][1];
                dp2[j + 1][0] += dp[j][0];
                dp2[j][1] += dp[j][1];
                dp2[j + 1][1] += 2 * dp[j][0];
                dp2[j + 2][1] += dp[j][1];
            }
            swap(dp, dp2);
            REP1(j, 1, K + 3) dp[j][0] %= MOD, dp[j][1] %= MOD;
        }
        printf("%lld\n", (dp[K][0] + dp[K][1]) % MOD);
    }
    
    
    return 0;
}
