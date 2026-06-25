#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include "my-header.h"
int main(int argc, char const *argv[])
{

    while (1)
    {
        textcolor(GRAY);
        gym();
        excel();
        textcolor(WHITE);
        main_category();
        timenow();
        
        if(inf[machine_num][0] != 0 && tm.tm_hour * 60 + tm.tm_min <= T[machine_num][0]+inf[machine_num][1]){
            printf("이미 사용 중 입니다. 다시 입력해주세요.\n");
            timenow();
            continue;
        }

        idreg(machine_num);

        do
        {
            input_time();
        } while(inf[machine_num][1] < 1);

        T[machine_num][0] = tm.tm_hour * 60 + tm.tm_min;
        printf("%d님 \n", inf[machine_num][1]);
        printf("| %d:%d ~ %d:%d %d번 예약되었습니다 |\n", T[machine_num][0] / 60, T[machine_num][0] % 60, (T[machine_num][0] + inf[machine_num][1]) / 60, (T[machine_num][0] + inf[machine_num][1]) % 60, machine_num);
    }
    return 0;
}