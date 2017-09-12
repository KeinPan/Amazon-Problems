// Manacher's Algorithm
int countSubstrings(string s) {
        // step1
        string t = "@#";
        for(char &c: s) {t += c; t += "#";}
        t += "$";
    
        // step2
        int mx = 0, id = 0;
        vector<int> p(t.size(), 0);
        for(int i = 0; i < p.size(); ++i){
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            while (t[i + p[i]] == t[i - p[i]]) ++p[i];
            if (mx < i + p[i]) {
                mx = i + p[i];
                id = i;
            }
        }
        int res = 0;
        for(int &i : p) res += i/2;
        return res;
    }
