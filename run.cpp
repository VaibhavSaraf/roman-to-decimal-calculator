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

ll sum(vector<ll> &nums)
{
    return accumulate(nums.begin(), nums.end(), 0);
}

ll substract(vector<ll> &nums)
{
    ll x = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        x = x - nums[i];
    }
    return x;
}
ll multiply(vector<ll> &nums)
{
    ll ans = 1;
    for (auto x : nums)
    {
        ans *= x;
    }
    return ans;
}
ll divide(vector<ll> &nums)
{
    ll ans = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        ans = ans / nums[i];
    }
    return ans;
}

int main()
{
    // OJ;

    int opt;
    string input;
    cout << "1. Convert to decimal number \n2. Add \n3. Subtract \n4. Multiply \n5. Divide";
    cout << "Enter the option: ";
    cin >> opt;
    cout << endl;
    cout << "Enter numbers: ";
    cin >> input;
    cout << endl;

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
        nums.push_back(roman_to_decimal(x));
    }

    if (opt == 1)
    {
        for (auto x : nums)
            cout << x << " ";
        cout << "\n";
    }
    else if (opt == 2)
    {
        cout << sum(nums) << "\n";
    }
    else if (opt == 3)
    {
        cout << substract(nums) << "\n";
    }
    else if (opt == 4)
    {
        cout << multiply(nums) << "\n";
    }
    else if (opt == 5)
    {
        cout << divide(nums) << "\n";
    }
    else
    {
        cout << "Wrong Option\n";
    }

    return 0;
}