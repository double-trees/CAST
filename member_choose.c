#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NAMELENGTH 20

void sex(void);
void no_sex(void);

int main()
{
    char r;
    while (1)
    {
        printf("男女を分けますか？(y or n)\n");
        scanf("%1s", &r);
        if (r == 'y' || r == 'n')
        {
            break;
        }
    }
    if (r == 'y')
    {
        sex();
    }
    else if (r == 'n')
    {
        no_sex();
    }
    printf("当選おめでとうございます。\n");
    time_t T = time(NULL);
    printf("%s", ctime(&T));
}
void sex()
{

    int m, w, m0, w0, b0;
    char r0;
    printf("男子の人数を入力して下さい\n");
    scanf("%d", &m);

    printf("女子の人数を入力して下さい\n");
    scanf("%d", &w);

    printf("男子の当選人数を入力してください\n");
    scanf("%d", &m0);
    if (m < m0)
    {
        printf("当選人数エラーです。\n");
        exit(1);
    }

    printf("女子の当選人数を入力してください\n");
    scanf("%d", &w0);
    if (w < w0)
    {
        printf("当選人数エラーです。\n");
        exit(1);
    }
    printf("男女関係ない当選人数を入力してください\n");
    scanf("%d", &b0);
    if (m + w < b0 + m0 + w0)
    {
        printf("当選人数エラーです。\n");
        exit(1);
    }

    char men[m][NAMELENGTH];
    char women[w][NAMELENGTH];

    int men_win[m0];
    int women_win[w0];
    int bysex_win[b0];

    int i;
    for (i = 0; i < m; i++)
    {
        printf("%d人目の男子の名前を入力して下さい\n", i + 1);
        scanf("%s", men[i]);
    }

    for (i = 0; i < w; i++)
    {
        printf("%d人目の女子の名前を入力して下さい\n", i + 1);
        scanf("%s", women[i]);
    }

    printf("\nエントリー者\n男子枠\n");
    for (i = 0; i < m; i++)
    {
        printf("m%d:\t%s\n", i, men[i]);
    }

    printf("\n女子枠\n");
    for (i = 0; i < w; i++)
    {
        printf("w%d:\t%s\n", i, women[i]);
    }

    // r = 'p';

    while (1)
    {
        printf("これでいいですか？(y or n)\n");
        scanf("%1s", &r0);

        if (r0 == 'y' || r0 == 'n')
        {
            break;
        }
    }
    m0 = sizeof(men_win) / sizeof(int);
    w0 = sizeof(women_win) / sizeof(int);
    b0 = sizeof(bysex_win) / sizeof(int);

    if (r0 == 'n')
    {
        printf("エラーです。\n");
        exit(1);
    }
    else if (r0 == 'y')
    {

        int p, s, t;

        if (m0 != 0)
        {
            srand((unsigned)time(NULL));
            printf("\n\n当選者\n男子\n");
            i = 0;
            while (i < m0)
            {
                p = rand() % m;
                t = 0;
                for (s = 0; s < i; s++)
                {
                    if (p == men_win[s])
                    {
                        t = 1;
                        break;
                    }
                }
                if (t == 0)
                {
                    men_win[i] = p;
                    i++;
                    printf("m%d:\t%s\n", p, men[p]);
                }
            }
        }

        if (w0 != 0)
        {
            printf("\n女子\n");
            srand((unsigned)time(NULL));
            i = 0;
            while (i < w0)
            {
                p = rand() % w;
                t = 0;
                for (s = 0; s < i; s++)
                {
                    if (p == women_win[s])
                    {
                        t = 1;
                        break;
                    }
                }
                if (t == 0)
                {
                    women_win[i] = p;
                    i++;
                    printf("w%d:\t%s\n", p, women[p]);
                }
            }
        }
        if (b0 != 0)
        {
            printf("\n両性枠\n");
            srand((unsigned)time(NULL));
            i = 0;
            while (i < b0)
            {
                p = rand() % (w + m);
                t = 0;
                for (s = 0; s < i; s++)
                {
                    if (p == bysex_win[s])
                    {
                        t = 1;
                        break;
                    }
                }
                for (s = 0; s < m0 + w0; s++)
                {
                    if (p == men_win[s] || p == m + women_win[s])
                    {
                        t = 1;
                        break;
                    }
                }
                if (t == 0)
                {
                    bysex_win[i] = p;
                    i++;
                    if (p < m)
                    {
                        printf("m");
                        printf("%d:\t%s\n", p, men[p]);
                    }
                    else
                    {
                        printf("w");
                        printf("%d:\t%s\n", p - m, women[p - m]);
                    }
                }
            }
        }
    }
}

void no_sex()
{

    int m, m0;
    char r;
    printf("人数を入力して下さい\n");
    scanf("%d", &m);

    printf("当選人数を入力してください\n");
    scanf("%d", &m0);
    if (m < m0)
    {
        printf("当選人数エラーです。\n");
        exit(1);
    }

    char member[m][NAMELENGTH];
    int member_win[m0];

    int i;
    for (i = 0; i < m; i++)
    {
        printf("%d人目の名前を入力して下さい\n", i + 1);
        scanf("%s", member[i]);
    }

    printf("エントリー者\n");
    for (i = 0; i < m; i++)
    {
        printf("%d:\t%s\n", i, member[i]);
    }

    r = 'p';
    while (1)
    {
        printf("これでいいですか？(y or n)\n");
        scanf("%1s", &r);
        if (r == 'y' || r == 'n')
        {
            break;
        }
    }

    if (r == 'n')
    {
        printf("エラーです。\n");
        exit(1);
    }
    else if (r == 'y')
    {
        int p, s, t;
        srand((unsigned)time(NULL));

        printf("\n\n当選者\n");
        i = 0;
        while (i < m0)
        {
            p = rand() % m;
            t = 0;
            for (s = 0; s < i; s++)
            {
                if (p == member_win[s])
                {
                    t = 1;
                    break;
                }
            }
            if (t == 0)
            {
                member_win[i] = p;
                i++;
                printf("%d:\t%s\n", p, member[p]);
            }
        }
        }
}
