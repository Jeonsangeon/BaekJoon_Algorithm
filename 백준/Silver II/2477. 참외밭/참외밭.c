#include <stdio.h>

int main() {
    int number_per_area;
    scanf("%d", &number_per_area);

    int max_x = 0;
    int max_y = 0;
    int loc[6][2];
    int cnt[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i < 6; ++i) {
        scanf("%d %d", &loc[i][0], &loc[i][1]);
        cnt[loc[i][0]]++;
        if (loc[i][0] == 1 || loc[i][0] == 2) {
            if (loc[i][1] > max_x)
                max_x = loc[i][1];
        } else {
            if (loc[i][1] > max_y)
                max_y = loc[i][1];
        }
    }
    int large = max_x * max_y;
    int small = 0;
    for(int i = 0; i < 6; ++i){
        if(loc[i][0]==3 && loc[(i+1)%6][0]==1 && loc[(i+2)%6][0] == 3){
            small = loc[(i+1)%6][1] * loc[(i+2)%6][1];
            break;
        }
        else if(loc[i][0]==3 && loc[(i+1)%6][0]==2 && loc[(i+2)%6][0] == 3){
            small = loc[i%6][1] * loc[(i+1)%6][1];
            break;
        }
        else if(loc[i][0]==4 && loc[(i+1)%6][0]==1 && loc[(i+2)%6][0] == 4){
            small = loc[i%6][1] * loc[(i+1)%6][1];
            break;
        }
        else if(loc[i][0]==4 && loc[(i+1)%6][0]==2 && loc[(i+2)%6][0] == 4){
            small = loc[(i+1)%6][1] * loc[(i+2)%6][1];
            break;
        }
    }

    printf("%d", (large - small) * number_per_area);

    return 0;
}