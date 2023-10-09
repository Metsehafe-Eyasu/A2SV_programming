#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string validIPAddress(string queryIP) {
        regex ipv4("(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])");
        regex ipv6("((([0-9a-fA-F]){1,4})\\:){7}([0-9a-fA-F]){1,4}");
        if (regex_match(queryIP, ipv4)) return "IPv4";
        else if (regex_match(queryIP, ipv6)) return "IPv6";
        return "Neither";
    }
};