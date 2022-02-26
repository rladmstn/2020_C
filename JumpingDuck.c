#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>

#define DUCK_Y 25
#define ROCK_Y 31
#define ROCK_X 45
#define SKY_Y 1
#define SKY_X 45
#define POINT_Y 15
#define POINT_X 52

//콘솔 창의 크기와 제목을 지정
void SetConsoleView()
{
    system("mode con:cols=125 lines=35");
    system("title <구글 오리 게임>\n <Google Duck>");
}

//커서 위치를 x, y로 이동하는 함수
void GotoXY(int x, int y)
{
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// 구름 그리기
void DrawSky(int skyX)
{
    GotoXY(skyX, SKY_Y);
    printf("                          aaaa    ");
    GotoXY(skyX, SKY_Y + 1);
    printf("               bbbbbbb  aaaaaaaaaa  ");
    GotoXY(skyX, SKY_Y + 2);
    printf("             bbbbbbbbbbbb  aa aaaaaaa ");
    GotoXY(skyX, SKY_Y + 3);
    printf("       bbbbbbbb aaaaaaaaaaaa aaaaaaaaaaaaaa                       aaaaaa bbbbbbbbb                 ");
    GotoXY(skyX, SKY_Y + 4);
    printf("                                                                    aaaaaaaaaaaa bbbbbbbbb               ");
    GotoXY(skyX, SKY_Y + 5);
    printf("                                                             bbbbbbbbb  aaaaaaaaaaa  bbbbbbbbbbbbb       ");
    GotoXY(skyX, SKY_Y + 6);
    printf("                                                     bbbbbbbbb aaaaaaaaaaaa    bbbbbbbbbb  sssssssss        ");
}

// 닿았을때 점수얻는 별 그리는 함수
void DrawPoint(int pointX)
{
    GotoXY(pointX, POINT_Y);
    printf("  ▲ ");
    GotoXY(pointX, POINT_Y + 1);
    printf("◀☆▶");
    GotoXY(pointX, POINT_Y + 2);
    printf("  ▼");
}

//돌 그리는 함수
void DrawRock(int rockX)
{
    GotoXY(rockX, ROCK_Y);
    printf("  /@/@@w@  ");
    GotoXY(rockX, ROCK_Y + 1);
    printf(" @w@@//@@w@ ");
    GotoXY(rockX, ROCK_Y + 2);
    printf(" @@//@w@@//@/@ ");
    GotoXY(rockX, ROCK_Y + 3);
    printf("@w@//@w@@w@//@@ ");
}


// 오리 그리는 함수
void DrawDuck(int duckY)
{
    GotoXY(0, duckY);
    static bool legFlag = true;
    printf("                 □□□     \n");
    printf("                □□◑□    \n");
    printf("               □□□□■■ \n");
    printf("  □           □□         \n");
    printf("  □□          □□□      \n");
    printf(" □□□□□□□□□□□     \n");
    printf(" □□□□□□□□□□□     \n");
    printf("   □□□□□□□□□       \n");
    printf("      □□□□□□          \n");

    // 다리 움직임 표현
    if (legFlag)
    {
        printf("        ㅁㅁ  ㅁ           \n");
        printf("              ㅁㅁ           ");
        legFlag = false;
    }
    else
    {
        printf("        ㅁ   ㅁㅁ         \n");
        printf("        ㅁㅁ                ");
        legFlag = true;
    }
}



// 충돌시 게임오버 그리는 함수
void DrawGameOver(const int score)
{
    system("cls");
    int x = 17;
    int y = 14;
    GotoXY(x, y);
    printf("+++++++++++++++++++++++++++++");
    GotoXY(x, y + 1);
    printf("|    [ G A M E O V E R ]    | ");
    GotoXY(x, y + 2);
    printf("+++++++++++++++++++++++++++++");
    GotoXY(x, y + 5);
    printf("SCORE : %d", score);

    printf("\n\n\n\n\n\n\n\n\n");
    system("pause");
}

//키보드 입력을 받고 입력된 키의 값을 반환하는 함수
int GetKeyDown()
{
    if (_kbhit() != 0)
    {
        return _getch();
    }
    return 0;
}


// 돌과 충돌시 true 아니면 false
bool isCollision(const int rockX, const int duckY)
{
    //돌의 X가 오리의 몸체쪽에 있을때와 오리 높이가 충분치 않을때

    if (rockX <= 11 && rockX >= 3 && duckY > 20)
    {
        return true;
    }
    return false;
}

// 포인트와 충돌시 true 아니면 false
bool isPlus(const int pointX, const int duckY)
{
    //포인트의 X가 오리의 몸체쪽에 있을때와 오리 높이가 충분치 않을때

    if (pointX <= 11 && pointX >= 3 && duckY < 20)
    {
        return true;
    }
    return false;
}

// 메인 함수 //
int main()
{
    SetConsoleView();

    while (true)
    {
        //게임 시작시 초기화
        bool isJumping = false;
        bool isBottom = true;
        const int gravity = 3;

        int duckY = DUCK_Y;
        int rockX = ROCK_X;
        int skyX = SKY_X;
        int pointX = POINT_X;

        int score = 0;
        clock_t start, curr;    //점수 변수 초기화
        start = clock();        //시작시간 초기화

        while (true)    //한 판 루프
        {
            // 충돌체크 돌의 x값과 오리의 y값으로 판단
            if (isCollision(rockX, duckY))
                break;

            // 포인트에 닿으면 점수 추가
            if (isPlus(pointX, duckY))
            {
                score = score + 5;
            }

            //a키가 눌렸을 때 점프
            if (GetKeyDown() == 'a' && isBottom)
            {
                isJumping = true;
                isBottom = false;
            }

            //점프중이라면 Y 감소, 점프가 끝났으면 Y 증가
            if (isJumping)
            {
                duckY -= gravity;
            }
            else
            {
                duckY += gravity;
            }

            //Y가 계속해서 증가하는걸 막기위해 바닥을 지정
            if (duckY >= DUCK_Y)
            {
                duckY = DUCK_Y;
                isBottom = true;
            }

            //돌이 왼쪽으로 가도록하고
            //돌의 위치가 왼쪽 끝으로가면 다시 오른쪽 끝으로 소환
            rockX -= 2;
            if (rockX <= 0)
            {
                rockX = ROCK_X;
            }

            // 구름도 돌과 같은 이동방식
            skyX -= 2;
            if (skyX <= 0)
            {
                skyX = SKY_X;
            }

            // 포인트도 돌과 같은 이동방식
            pointX -= 2;
            if (pointX <= 0)
            {
                pointX = POINT_X;
            }

            //점프하고 특정 맨 위를 찍으면 점프가 끝난 상황
            if (duckY <= 12)
            {
                isJumping = false;
            }

            DrawDuck(duckY);        //오리 그림 출력
            DrawRock(rockX);        //돌 그림 출력
            DrawSky(skyX);          //구름 그림 출력
            DrawPoint(pointX);      //별 그림 출력

            curr = clock(); // 현재시간
            if (((curr - start) / CLOCKS_PER_SEC) >= 1.3)  // 1.3초가 넘었을떄
            {
                score++;    //점수+
                start = clock();    //시작시간 초기화
            }

            Sleep(60);
            system("cls");

         
            printf("Score : %d ", score);    //점수 출력
        }
        // 게임 오버 화면
        DrawGameOver(score);
    }
    return 0;
}
