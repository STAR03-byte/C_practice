#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>

//匿名结构体
typedef struct {
	char name[50];
	uint16_t id;
	float score;
}Student;

void print_stu(Student stu);

void update_score_by_value(Student stu, float new_score);
void update_score_by_reference(Student* stu, float new_score);

int main(void)
{
	Student stu = { "John Doe",123,89.8 };

	puts("Before update :");

	print_stu(stu);

	update_score_by_value(stu, 100);

	puts("After update by value :\n");

	print_stu(stu);

	update_score_by_reference(&stu, 100);

	puts("After update by reference :\n");

	print_stu(stu);

	return 0;
}

void print_stu(Student stu) {
	printf("name: %s\n", stu.name);
	printf("id: %" PRIu16 "\n", stu.id);
	printf("name: %.2f\n", stu.score);
}

void update_score_by_value(Student stu, float new_score) {
	stu.score = new_score;
}

void update_score_by_reference(Student* stu, float new_score) {
	stu->score = new_score;
}