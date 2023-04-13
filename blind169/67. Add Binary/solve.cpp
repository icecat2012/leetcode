class Solution {
public:
    string addBinary(string a, string b) {
        char aa, bb, inc=0, t;
        string c;
        int i=0;
        while(i<a.size() || i<b.size() || inc)
        {
            if ((int)a.size()-1-i>=0)
                aa=a[a.size()-1-i]-'0';
            else
                aa=0;

            if ((int)b.size()-1-i>=0)
                bb=b[b.size()-1-i]-'0';
            else
                bb=0;

            t = aa+bb+inc;
            inc = t/2;
            c = to_string(t%2) + c;
            ++i;
            cout<<'#'<<c<<endl;
        }
        return c;
    }
};