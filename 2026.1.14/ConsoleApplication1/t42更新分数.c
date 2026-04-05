#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<stdbool.h>

void update_score(int32_t* score, int32_t points);
int32_t* compare_score(int32_t* score1, int32_t* score2);

int main(void)
{
	int32_t play1_score = 100;

	int32_t play2_score = 890;

	update_score(&play1_score, 70);

	int32_t* high_score = compare_score(&play1_score, &play2_score);

	printf("较高的分数:%" PRId32 "\n", *high_score);

	return 0;
}

void update_score(int32_t* score, int32_t points) {
	*score += points;
	printf("增加后的分数：%" PRId32 "\n", *score);
}

int32_t* compare_score(int32_t* score1, int32_t* score2) {
	return(*score1 > *score2) ? score1 : score2;
}