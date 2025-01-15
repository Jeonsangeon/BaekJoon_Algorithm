#include <iostream>
#include <algorithm>
#include <cstdlib>

#define X first
#define Y second
#define MAX_N 10
#define MAX_INT 2147483647

using namespace std;

int N;
pair<int, int> home, company, customer[MAX_N];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	int test_case, T;
	cin >> T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N;
        cin >> home.X >> home.Y;
        cin >> company.X >> company.Y;
        for(int i = 0; i < N; ++i)
            cin >> customer[i].X >> customer[i].Y;
        sort(customer, customer+N);
        int dist, min_dist = MAX_INT;
        do{
            dist = 0;
            dist += (abs(home.X-customer[0].X) + abs(home.Y-customer[0].Y));
            for(int i = 1; i < N; ++i){
                dist += (abs(customer[i].X-customer[i-1].X) + abs(customer[i].Y-customer[i-1].Y));
                if(min_dist < dist)
                    break;
            }
            if(min_dist < dist)
                continue;
            dist += (abs(company.X-customer[N-1].X) + abs(company.Y-customer[N-1].Y));
            min_dist = min(min_dist, dist);
        } while(next_permutation(customer, customer + N));
        cout << "#" << test_case << ' ' << min_dist << "\n";
	}

	return 0;
}