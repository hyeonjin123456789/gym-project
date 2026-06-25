#include <Windows.h>
#include <time.h>

int machine_num = 26;
struct tm tm;

void excel();


int inf[27][2] = {0}; // 운동기구 번호 , [학번,시간]
int T[27][1] = {0}; // 운동기구 번호, [예약당시시간]


void gym()
{
    printf("------------------------------------------------------------------------------------------------------------------\n");
    printf("|                           (23)            (22)               (21)       (20)      (19)                         |\n");
    printf("|                            []             [[]]            [==[==]==]  [======]  [======]                       [\n");
    printf("|                            []             [||]              |    |       ||        ||                          [\n");
    printf("|                           //\\\\        [)--====--(]          |    |    [[====]]  [[====]]                       [\n");
    printf("|                          //  \\\\           [[]]              []  []    [      ]  [      ]            (18)       [\n");
    printf("|                        -()    ()-         [[]]            [[]]  [[]]  [      ]  [      ]       ()==[[[]]]==()  |\n");
    printf("|                                                                       [[=()=]]  [[=()=]]             ||        |\n");
    printf("|                             [=======]   [=======]   [=========]                                  [---||---]    |\n");
    printf("]                             (=======)    (=====)        [|]                                      [---||---]    |\n");
    printf("]                                [ ]         [ ]          [ ]                                          ||        |\n");
    printf("]                                [ ]         [ ]          [ ]                                    ()==[[[]]]==()  |\n");
    printf("]                              [=====]     [=====]      (=====)                                                  |\n");
    printf("]                               (26)        (25)         (24)                                        (]          |\n");
    printf("]                                                                                                (17) [== [[]]   |\n");
    printf("|                                                                                            (13)    (]    ||    |\n");
    printf("|   (1)     (2)     (3)     (4)     (5)     (6)     (7)     (8)     (9)   (10) (11)          {=}           ||    |\n");
    printf("| [[===]] [[===]] [[===]] [[===]] [[===]] [[===]] [[===]] [[===]] [[===]]  __  __            {=}      (16) ||    |\n");
    printf("| |     | |     | |     | |     | |     | |     | |     | |     | |     |  ||  ||            [=]     (]    ||    |\n");
    printf("| |     | |     | |     | |     | |     | |     | |     | |     | |     |  ||  ||    (12)    [=] (15) [== [[]]   |\n");
    printf("| |     | |     | |     | |     | |     | |     | |     | |     | |     |  ||  || []      [] {{=}}   (]          |\n");
    printf("| |     | |     | |     | |     | |     | |     | |     | |     | |     |  ||  || []======[] {{=}}        {{}}   |\n");
    printf("| [_____] [_____] [_____] [_____] [_____] [_____] [_____] [_____] [_____] []] []] []      [] [[=]]   (14) {{}}   |\n");
    printf("------------------------------------------------------------------------------------------------------------------\n");
}

void main_category()
{
    printf("[원하는 운동기구를 선택하시오] -0번은 예약 취소-\n>> ");
    scanf("%d",&machine_num);
    if(machine_num == 0){
        printf("[예약취소할 운동기구를 선택하시오]\n");
        scanf("%d", &machine_num);
        inf[machine_num][0] = 0;
        inf[machine_num][1] = 0;
        
        excel();
        printf("최소되었습니다.\n");
        main_category();
    }
}



void excel() {
    printf("----------------------------------------------\n");
    printf("| %-12s | %-12s | %-12s |\n", "machine_num", "classid", "time");
    printf("----------------------------------------------\n");

    for(int i = 1; i <= 26; i++) {

        if(inf[i][0] == 0) {
            printf("| %-12d | %-12s | %-12s |\n", i, "EMPTY", "EMPTY");
        } else {
            printf("| %-12d | %-12d | %d:%d ~ %d:%d |\n", i, inf[i][0], T[i][0] / 60, T[i][0] % 60, (T[i][0] + inf[i][1]) / 60, (T[i][0] + inf[i][1]) % 60);
        }

        printf("----------------------------------------------\n");
    }
}

void textcolor(int colorNum)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

void input_time()
{
    printf("[사용 시간을 입력하시오(단위:분)]\n>> ");
    scanf("%d", &inf[machine_num][1]);
}

enum ColorType{
BLACK,
darkBLUE,
DarkGreen,
darkSkyBlue,
DarkRed,
DarkPurple,
DarkYellow,
GRAY,
DarkGray,
BLUE,
GREEN,
SkyBlue,
RED,
PURPLE,
YELLOW,
WHITE
} COLOR;
void idreg(int machine_num){
    
    do{
        printf("학번을 입력해주세요. (예: 1101)\n");
        scanf("%d", &inf[machine_num][0]);
    }while(1000 > inf[machine_num][0] || inf[machine_num][0] > 4000);
    
}

void timenow(){
        time_t t = time(NULL);
        localtime_s(&tm, &t);
}

