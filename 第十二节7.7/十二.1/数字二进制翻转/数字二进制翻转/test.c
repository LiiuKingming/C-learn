#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>


unsigned int reverse_bit(unsigned int value){
	int i = 0;
	unsigned int num = 0;
	for (i = 31; i >= 0; --i){
		unsigned int tmp = (value >> i) & 1;
		if (tmp == 1){
			num = (tmp << (31 - i)) + num;
		}
	}
	printf("%u\n", num);
	value = num;
	return value;
}

#if 0
unsigned int reverse_bit(unsigned int value){
	int bit = 0;
	int ret = 0;
	for (int i = 0; i < 32; i++){
		ret = ret << 1;
		bit = value & 1;
		value = value >> 1;
		ret = bit | ret;
	}
	return ret;
}
#endif

int main(){
	unsigned int value = 0;
	reverse_bit(25);
	system("pause");
	return 0;
}