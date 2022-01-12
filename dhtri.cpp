/**
                                        .-''-.
                                      .' .-.  )
                                     / .'  / /
    .-''` ''-.        .-''` ''-.    (_/   / /
  .'          '.    .'          '.       / /
 /              `  /              `     / /
'                ''                '   . '
|         .-.    ||         .-.    |  / /    _.-')
.        |   |   ..        |   |   ..' '  _.'.-''
 .       '._.'  /  .       '._.'  //  /.-'_.'
  '._         .'    '._         .'/    _.'
     '-....-'`         '-....-'` ( _.-'
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*_______________________________________MY CODE_____________________________________*/
// a(n) = (1678*n^3+3117*n^2+88*n-345*Mod[n,2]-320*Mod[n,3]-90*Mod[n,4]-288*Mod[n^3-n^2+n,5])/240. (Bill Daly)
// https://oeis.org/A210687
// https://www.math.uni-bielefeld.de/~sillke/SEQUENCES/grid-triangles?fbclid=IwAR07UkQTWgHc1c-y1w1JwF3Y5OsTri5a6MsjpYqSrvQJ0iQGaI3FIq17LYE
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    ll x = pow(n, 3) - pow(n, 2) + n;
    ll a = 1678 * pow(n, 3) + 3117 * pow(n, 2) + 88 * n - 345 * (n % 2) - 320 * (n % 3) - 90 * (n % 4) - 288 * (x % 5);
    cout << a / 240;
}