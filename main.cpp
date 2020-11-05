#include <bits/stdc++.h>
using namespace std;

vector <string> v;

int odp_a()
{
    int ans = 0;
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i][0] == v[i][v[i].size()-1])
            ans++;
    }
    return ans;
}

int oct2dec(string osemkowa)
{
	int dziesietna = strtol(osemkowa.c_str(), NULL, 8);
	return dziesietna;
}

int odp_b()
{
    int ans = 0;
    for(int i = 0; i < v.size(); i++)
    {
        string x = to_string(oct2dec(v[i]));
        if(x[0] == x[x.size()-1])
            ans++;
    }
    return ans;
}

void odp_c()
{
    int ans = 0;
    int minn = INT_MAX, maxx = INT_MIN;
    string s_minn, s_maxx;
    for(int i = 0; i < v.size(); i++)
    {
        bool ok = true;
        for(int j = 1; j < v[i].size(); j++)
        {
            if(v[i][j] < v[i][j-1])
                ok = false;
        }
        if(ok)
        {
            ans++;
            int x = oct2dec(v[i]);
            if(x > maxx)
            {
                maxx = x;
                s_maxx = v[i];
            }
            if(x < minn)
            {
                minn = x;
                s_minn = v[i];
            }
        }
    }
    cout << "liczba: " << ans << "\n";
    cout << "min: " << s_minn << "\n";
    cout << "max: " << s_maxx;

}

int main()
{
    ifstream file1("dane.txt");
    if (file1.good())
    {
        string x;
        while(file1 >> x)
            v.push_back(x);

        cout << "6a " << odp_a() << "\n";
        cout << "6b " << odp_b() << "\n";
        cout << "6c\n";
        odp_c();
    }

    return 0;
}
