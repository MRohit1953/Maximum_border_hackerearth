#include <iostream>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int num;
	cin >> num;		
	for(int cae=0; cae < num; ++cae) 
	{
        int dong, cot, ans{0};
        cin >> dong >> cot;
        char table[dong][cot];
		for (int i=0; i<dong; ++i) {
            for (int j=0; j<cot; ++j) {
                cin >> table[i][j];
            }
        }
		//find left --> right
		for(int i=0; i<dong; ++i) {
			int tmp{0}, flag1{0}, flag2{0}, a{0}, b{0};//flag to know where to end the border
			for(int j=0; j<cot; ++j) {
				if (table[i][j] == '#' && (i-1<0 || i+1 == dong) )
					++tmp;
				else if (table[i][j] == '#' && (table[i-1][j]=='.' || table[i+1][j]=='.')) {	
					if (table[i-1][j]=='#')
						++flag1;
					if (table[i+1][j]=='#')
						++flag2;
					if(flag1 && flag2) {
						/*
						...#......
						..########
						......#...
						it will like this.
						*/
						a = b;
						b = j;
						ans = max(ans, tmp);
						tmp = b - a;
						if (table[i-1][j] == '#')
							flag2 = 0;
						else flag1 = 0;
					}
					b = j;	
					++tmp;
				}
				else {//reset the temp border and get the new ans
					ans = max(ans, tmp);
					tmp = 0;
					flag1 = 0;
					flag2 = 0;
				}		
			}
		}
		//find top --> botton same as above.
		for(int j=0; j<cot; ++j) {
			int tmp{0}, flag1{0}, flag2{0}, a{0}, b{0};
			for (int i=0; i<dong; ++i) {
				if (table[i][j] == '#' && (j == 0 || j == cot - 1))
					++tmp;
				else if (table[i][j] == '#' && (table[i][j-1]=='.' || table[i][j+1]=='.')) {			
					if (table[i][j-1]=='#')
						++flag1;
					if (table[i][j+1]=='#')
						++flag2;
					if(flag1 && flag2) {
						a = b;
						b = i;
						ans = max(ans, tmp);
						tmp = b - a;
						if (table[i][j-1] == '#')
							flag2 = 0;
						else flag1 = 0;
					}
					b = i;
					++tmp;
				}
				else {
					ans = max(ans, tmp);
					tmp = 0;
					flag1 = 0;
					flag2 = 0;
				}		
			}
		}
		//	
		cout << ans << endl;
	}
	return 0;
}