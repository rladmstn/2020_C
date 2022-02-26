#include<stdio.h>

int main(void)
{
	int num , ch1, ch2, n;
	double percent = 0, percent2 = 0, solute  = 0, solvent = 0, solution = 0;
	printf("계산할 용액의 농도 종류를 선택하세요.\n");
	printf("1. 퍼센트농도\n2. ppm농도\n3. 몰농도 \n4. 몰랄농도\n");
	scanf_s("%d", &num);

	//1. 퍼센트농도
	if (num == 1)
	{
		for (n = 1; n <= 2; n++)
		{
			printf("입력할 정보를 선택하세요.\n");
			printf("1. 용질의 질량\n2. 용매의 질량\n3. 용액의 질량\n");
			scanf("%d", ch1);

			if (ch1 == 1)
			{
				printf("용질의 질량을 입력하세요(g).\n");
				scanf_s("%lf", &solute);
			}

			if (ch1 == 2)
			{
				printf("용매의 질량을 입력하세요(g).\n");
				scanf_s("%lf", &solvent);
			}

			if (ch1 == 3)
			{
				printf("용액의 질량을 입력하세요(g).\n");
				scanf_s("%lf", &solution);
			}
		} 
	    
		if (solute == 0 && solvent != 0 && solution != 0)
		{
			percent = ((solution - solvent) / solution) * 100;
		}


		if (solvent == 0 && solute != 0 && solution != 0)
		{
			percent = (solute / solution) * 100;
		}

		if (solution == 0 && solute != 0 && solvent != 0)
		{
			percent = (solute / (solvent + solute)) * 100;
		}

		printf("용액의 퍼센트 농도는 %.2f %% 입니다.", percent);
	}

	//2. ppm농도
	if (num == 2)
	{
		for (n = 1; n <= 2; n++)
		{
			printf("입력할 정보를 선택하세요.\n");
			printf("1. 용질의 질량(g)\n2. 용매의 질량(g)\n3. 용액의 질량(g)\n");
			scanf_s("%d", &ch1);

			if (ch1 == 1)
			{
				printf("용질의 질량을 입력하세요.\n");
				scanf_s("%lf", &solute);
			}

			if (ch1 == 2)
			{
				printf("용매의 질량을 입력하세요.\n");
				scanf_s("%lf", &solvent);
			}

			if (ch1 == 3)
			{
				printf("용액의 질량을 입력하세요.\n");
				scanf_s("%lf", &solution);
			}
		}

		if (solute == 0 && solvent != 0 && solution != 0)
		{
			percent = ((solution - solvent) / solution) * 100;
		}


		if (solvent == 0 && solute != 0 && solution != 0)
		{
			percent = (solute / solution) * 100;
		}

		if (solution == 0 && solute != 0 && solvent != 0)
		{
			percent = (solute / (solvent + solute)) * 100;
		}

		printf("용액의 퍼센트 농도는 %.2f %% 입니다.", percent);
	}



    //3. 몰농도
	if (num == 3)
	{
		for (n = 1; n <= 2; n++)
		{
			printf("입력할 정보를 선택하세요.\n1. 용질의 양(mol) \n2. 용액의 부피(L)\n");
			scanf_s("%d", &ch2);

			if (ch2 == 1)
			{
				printf("용질의 양을 입력해 주세요.\n");
				scanf_s("%lf", &solute);
			}
			
			if (ch2 == 2)
			{
				printf("용액의 부피를 입력해주세요.\n");
				scanf_s("%lf",&solution);
			}
		}
		percent = solute / solution;

		printf("용액의 몰 농도는 %.2f M 입니다.", percent);
	}

	//4. 몰랄농도
	if (num == 4)
	{
		for (n = 1; n <= 2; n++)
		{
			printf("입력할 정보를 선택하세요.\n1. 용질의 양(mol) \n2. 용매의 질량(kg)\n");
			scanf_s("%d", &ch2);

			if (ch2 == 1)
			{
				printf("용질의 양을 입력해 주세요.\n");
				scanf_s("%lf", &solute);
			}

			if (ch2 == 2)
			{
				printf("용매의 질량을 입력해주세요.\n");
				scanf_s("%lf", &solvent);
			}
		}
		percent = solute / solvent;

		printf("용액의 몰 농도는 %.2f m 입니다.", percent);
	}


	return 0;
}