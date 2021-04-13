#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

ll symbol_value(char symbol)
{
    switch (symbol)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
}

ll roman_to_decimal(string roman)
{

    ll value = 0;

    int length = roman.length();
    for (int i = 0; i < length; i++)
    {
        ll symbol = symbol_value(roman[i]);

        if (symbol == 0)
        {
            //Invalid symbol. Not a valid roman number
            return -1;
        }

        //Check next symbol for subtractive notation
        if (i + 1 < length)
        {
            long next = symbol_value(roman[i + 1]);
            if (symbol < next)
            {
                //Using subtractive notation
                symbol = next - symbol;

                //Skip next symbol
                i++;
            }
        }
        value += symbol;
    }

    return value;
}

int main()
{
    OJ;
    string input;
    cin >> input;
    // cout << input;
    vector<string> tokens;
    vector<ll> nums;
    stringstream check1(input);
    string intermediate;

    while (getline(check1, intermediate, ','))
    {
        tokens.push_back(intermediate);
    }

    for (auto x : tokens)
    {
        cout << x << " : " << roman_to_decimal(x) << "\n";
    }

    return 0;
}