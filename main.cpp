#include <stdio.h>
#include <stdlib.h>

const int BLOCK_SIZE = 20;

typedef struct {
	int *array;
	int size;
} Array;
// ���������ﲻҪ��typedef struct {} *Array����Ϊ�����޷��������ر��������һ�������⡣

Array array_create(int init_size);

void array_free(Array *a);

int array_size(const Array *a);

int *array_at(Array *a, int index);

int array_get(const Array *a, int index);

void array_set(Array *a, int index, int num);

void array_flat(Array *a, int more_size);

Array array_create(int init_size) {
	Array a;
	a.array = (int *) malloc(init_size * sizeof(int));
	a.size = init_size;
	return a;
}

void array_free(Array *a) {
	free(a->array); // free(0)��free(NULL)���޺���
	a->array = NULL;
	a->size = 0;
}

// ��װ������ʵ��ϸ�ڣ��������Խ����������ظ���
int array_size(const Array *a) {
	return a->size;
}

// ���ﷵ��ָ���Ŀ���Ǻ���*array_at(&a, 0)��������ֵ����*array_at(&a, 0) = 10;
int *array_at(Array *a, int index) {

	if (index >= a->size) {
		array_flat(a, ((index / BLOCK_SIZE) + 1) * BLOCK_SIZE - a->size);
	}

	return a->array + index;
//	return &(a->array[index]);
}

int array_get(const Array *a, int index) {
	return a->array[index];
}

void array_set(Array *a, int index, int num) {
	a->array[index] = num;
}

void array_flat(Array *a, int more_size) {
	int *p = (int *) malloc(sizeof(int) * (a->size + more_size));

	for (int i = 0; i < a->size; i++) {
		p[i] = a->array[i];
	}
	free(a->array);
	a->size += more_size;
	a->array = p;
}

int main(int argc, char const *argv[]) {
	Array a = array_create(1);

//	printf("Array's size is %d\n", array_size(&a));
//
//	*array_at(&a, 0) = 10;
//	printf("array_at(0) is %d\n", *array_at(&a, 0));

//	printf("array_at(0) is %d\n", array_get(&a, 0));
//	array_set(&a, 0, 11);
//	printf("array_at(0) is %d\n", array_get(&a, 0));

	int number = 0;
	int cnt = 0;
	while (number != -1) {
		// a���Զ�����
//		scanf("%d", array_at(&a, cnt++));
		scanf("%d", &number);
		if (number != -1) {
			*array_at(&a, cnt++) = number;
		} else {
			break;
		}
		printf("Array's size is %d\n", array_size(&a));
	}

	array_free(&a);

	return 0;
}
