#include <bits/stdc++.h>
using namespace std;

int convert_to_24hrs(int hr, int min, char meridiem)
{
    int time = 0;
    if (meridiem == 'A' && hr == 12)
    {
        hr = 0;
    }
    else if (meridiem == 'P' && hr != 12)
    {
        hr += 12;
    }
    time = hr * 100 + min;
    return time;
}

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        // your code goes here
        int p_hr, p_min, p_time, n;
        char p_meridiem;
        scanf("%d:%d %cM", &p_hr, &p_min, &p_meridiem);
        p_time = convert_to_24hrs(p_hr, p_min, p_meridiem);
        // cout << p_time << endl;
        cin >> n;
        while (n--)
        {
            int l_hr, l_min, l_time, r_hr, r_min, r_time;
            char l_meridiem, r_meridiem;
            scanf("%d:%d %cM %d:%d %cM", &l_hr, &l_min, &l_meridiem, &r_hr, &r_min, &r_meridiem);
            
            l_time = convert_to_24hrs(l_hr, l_min, l_meridiem);
            r_time = convert_to_24hrs(r_hr, r_min, r_meridiem);

            if (p_time >= l_time && p_time <= r_time)
            {
                cout << "1";
            }
            else
            {
                cout << "0";
            }
            // cout << l_time << " " << p_time << " " << r_time << endl;
        }
        cout << "\n";
    }
    return 0;
}
