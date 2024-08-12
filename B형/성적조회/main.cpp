#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init();
extern int add(int mId, int mGrade, char mGender[7], int mScore);
extern int remove(int mId);
extern int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore);

/////////////////////////////////////////////////////////////////////////

#define CMD_INIT 100
#define CMD_ADD 200
#define CMD_REMOVE 300
#define CMD_QUERY 400

static bool run() {
	int q;
	scanf("%d", &q);

	int id, grade, score;
	char gender[7];
	int cmd, ans, ret;
	bool okay = false;

	for (int i = 0; i < q; ++i) {
		scanf("%d", &cmd);
		switch (cmd) {
			case CMD_INIT:
				init();
				okay = true;
				break;
			case CMD_ADD:
				scanf("%d %d %s %d %d", &id, &grade, gender, &score, &ans);
				ret = add(id, grade, gender, score);
                //printf("add : %d\n",ret);
				if (ans != ret)
					okay = false;
				break;
			case CMD_REMOVE:
				scanf("%d %d", &id, &ans);
				ret = remove(id);
                //printf("remove : %d\n",ret);
				if (ans != ret)
					okay = false;
				break;
			case CMD_QUERY: {
				int gradeCnt, genderCnt;
				int gradeArr[3];
				char genderArr[2][7];
				scanf("%d", &gradeCnt);
				if (gradeCnt == 1) {
					scanf("%d %d", &gradeArr[0], &genderCnt);
				} else if (gradeCnt == 2) {
					scanf("%d %d %d", &gradeArr[0], &gradeArr[1], &genderCnt);
				} else {
					scanf("%d %d %d %d", &gradeArr[0], &gradeArr[1], &gradeArr[2], &genderCnt);
				}
				if (genderCnt == 1) {
					scanf("%s %d %d", genderArr[0], &score, &ans);
				} else {
					scanf("%s %s %d %d", genderArr[0], genderArr[1], &score, &ans);
				}
				ret = query(gradeCnt, gradeArr, genderCnt, genderArr, score);
                //printf("query : %d\n",ret);
				if (ans != ret)
					okay = false;
				break;
			}
			default:
				okay = false;
				break;
		}
	}
	return okay;
}

int main() {
	setbuf(stdout, NULL);
	freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++) {
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}
/*
1 100
18
100
200 500 1 male 1250 500
200 400 3 female 2900 400
200 900 2 female 2500 900
200 700 2 male 2500 700
200 600 1 female 1750 600
200 800 3 male 1000 800
200 300 2 female 2000 900
400 2 2 3 2 male female 2500 700
400 3 1 2 3 1 male 1100 500
200 100 2 female 2500 900
400 1 2 2 male female 2200 100
300 300 100
300 200 0
200 300 3 female 3000 300
400 2 1 3 1 female 1800 400
300 800 0
400 3 1 2 3 2 male female 1000 500
*/
/*
1 100
100
100
200 252957431 2 female 171173 252957431
200 342456213 1 male 221213 342456213
200 521708274 3 female 153613 521708274
200 709616947 2 female 171694 709616947
200 57687951 3 male 73693 57687951
200 773697866 1 female 240997 773697866
200 586152814 2 male 49428 586152814
200 250016477 1 female 254970 250016477
200 235145500 2 male 33832 586152814
200 709501141 2 male 159425 709501141
200 432968268 3 male 88462 432968268
200 946062933 3 male 7205 432968268
200 137169653 3 female 276685 137169653
200 524954935 1 female 54229 250016477
200 420437608 3 female 217486 137169653
200 416177924 1 male 294167 416177924
200 825458808 1 male 22351 416177924
200 574230010 2 female 87437 709616947
200 52999494 1 female 38509 250016477
200 32014096 2 male 42875 709501141
300 137169653 521708274
300 235145500 32014096
400 2 1 2 1 female 76157 574230010
400 1 2 2 male female 263733 0
400 3 1 2 3 1 female 70745 574230010
400 2 1 2 1 female 166280 252957431
300 252957431 574230010
300 524954935 52999494
400 1 3 1 male 135688 0
400 3 1 2 3 1 male 55659 57687951
300 709501141 32014096
300 946062933 57687951
400 1 3 1 female 116079 521708274
400 2 2 3 1 male 190434 0
400 2 2 3 2 male female 106189 521708274
400 2 1 2 2 male female 77849 574230010
400 1 2 1 female 203177 0
300 416177924 825458808
300 52999494 773697866
300 432968268 57687951
300 574230010 709616947
400 2 2 3 1 female 37320 521708274
400 3 1 2 3 1 female 8805 521708274
400 3 1 2 3 1 female 128393 521708274
400 2 1 3 1 male 194483 342456213
400 1 3 1 male 40986 57687951
300 521708274 420437608
400 2 1 3 1 male 218896 342456213
300 250016477 773697866
300 32014096 586152814
400 1 3 2 male female 198488 420437608
300 709616947 0
400 2 1 2 1 female 21499 773697866
400 3 1 2 3 2 male female 34584 586152814
300 342456213 825458808
400 3 1 2 3 1 male 245359 0
400 1 1 1 male 242821 0
400 1 1 1 female 37034 773697866
300 773697866 0
400 2 2 3 1 male 257737 0
400 2 1 2 1 female 81809 0
400 2 1 2 2 male female 6098 825458808
300 420437608 0
400 2 1 3 2 male female 160448 0
400 1 3 2 male female 267742 0
300 586152814 0
200 698970378 3 female 268273 698970378
300 698970378 0
300 57687951 0
200 761333949 2 female 217551 761333949
200 506261055 1 male 147295 506261055
400 1 3 1 male 236054 0
400 1 2 1 female 151816 761333949
400 2 2 3 1 male 32350 0
400 2 1 3 1 female 26190 0
400 2 1 3 1 male 106675 506261055
400 1 2 1 male 136234 0
400 3 1 2 3 2 male female 42826 506261055
400 1 1 2 male female 255710 0
300 761333949 0
400 2 1 2 2 male female 41717 506261055
400 1 2 1 female 68349 0
200 916222877 3 female 64025 916222877
400 1 2 1 male 5673 0
400 2 1 2 1 male 46772 506261055
400 1 2 1 female 12710 0
400 1 2 1 female 239902 0
300 995566058 0
400 2 1 3 1 male 194425 0
400 2 1 2 2 male female 26758 506261055
400 1 2 1 female 246370 0
400 3 1 2 3 1 male 105303 506261055
300 506261055 825458808
400 1 1 2 male female 20712 825458808
300 825458808 0
400 1 1 1 female 212392 0
400 1 1 2 male female 39993 0
400 1 3 1 male 55386 0
300 599588760 0
*/