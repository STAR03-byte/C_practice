#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>

// 联合体：存储不同类型的数据（同一时间只能用其中一个成员）
typedef union {
	int int_value;
	float float_value;
	char* string_value;
}Data;

// 枚举：标记联合体中实际存储的数据类型
typedef enum {
	INT,
	FLOAT,
	STRING
}Datatype;

// 结构体：将数据类型和数据本身绑定，避免类型混淆
typedef struct {
	Datatype type;
	Data data;
}TypedData;


/**
 * @brief 打印 TypedData 类型的数据
 * @param typed_data 指向 TypedData 结构体的指针（避免拷贝，提升效率）
 */
void print_data(TypedData* typed_data) {
	switch (typed_data->type)
	{
	case INT:printf("Integer: %d\n", typed_data->data.int_value); break;
	case FLOAT:printf("Float: %.2f\n", typed_data->data.float_value); break;
	case STRING:printf("String :%s\n", typed_data->data.string_value); break;
	default:
		break;
	}
}

int main(void)
{
	//C89 就支持，编译器按结构体成员定义的顺序（先 type、后 data）赋值，优点是简短，缺点是如果结构体成员顺序变了，代码会出错。
	TypedData data1 = { INT,{.int_value = 10} };
	
	//两者结合
	TypedData data2 = { .type = FLOAT,{.float_value = 3.24} };

	//C99 新增特性，用 .成员名 = 值 明确指定赋值目标，顺序无关、可读性强，是现代 C 推荐的写法（优化后统一用这种）。
	TypedData data3 = { .data.string_value = "STAR",.type = STRING};

	print_data(&data1);

	print_data(&data2);

	print_data(&data3);

	return 0;
}