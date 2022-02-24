#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

int main() {
    std::ofstream outFile;
    outFile.open("data.txt");

    std::vector<int> v(32768);

    auto p = v;
    std::iota( p.begin(), p.end(), 0 );
    auto i = 0u;
    for ( ; i < v.size(); i+=2 )
    {
        auto const iPivot0 = i;
        auto const iPivot1 = ( i + v.size()-1 )/2;
        v[ p[ iPivot1 ] ] = i+1;
        v[ p[ iPivot0 ] ] = i;
        std::swap( p[ iPivot1 ], p[i+1] );
    }
    if ( v.size() > 0 && i == v.size() )
        v[ v.size()-1 ] = i-1;

    for ( auto x : v ) outFile << " " << x;

    outFile.close();
    return 0;
}
