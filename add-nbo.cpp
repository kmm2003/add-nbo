#include<stdint.h>
#include<stddef.h>
#include<stdio.h>
#include<netinet/in.h>

uint32_t write_32bit(char *name) {
	FILE* fp=fopen(name,"rb");
	uint8_t data[4];
	fread(data,sizeof(int),4,fp);
	uint8_t network_buffer[] = { data[0], data[1], data[2], data[3] };
	uint32_t* p = reinterpret_cast<uint32_t*>(network_buffer);
	uint32_t n = ntohl(*p); // TODO
	printf("%d(0x%x) ",n,n);
	return n;
}

int main(){
	uint32_t num1=write_32bit("thousand.bin");
	printf("+ ");
	uint32_t num2=write_32bit("five-hundred.bin");
	printf("= %d(0x%x)\n",num1+num2,num1+num2);
	return 0;
}
