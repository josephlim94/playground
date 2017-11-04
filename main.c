#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_LEN 512

void print_log(unsigned char* buffer, unsigned int buff_length)
{
	unsigned char temp[3] = "as";
	unsigned char* temp_buffer;
	unsigned int i;

	unsigned int temp_buff_len = (buff_length*2)+1;

	temp_buffer = malloc(temp_buff_len);
	memset(temp_buffer, '\0', temp_buff_len);
	for (i = 0; i < buff_length; i++)
	{
		sprintf(temp, "%02X", buffer[i]);
		temp_buffer[i*2] = temp[0];
		temp_buffer[(i*2)+1] = temp[1];
	}
	printf("%s", temp_buffer);
	printf("\n");
	free(temp_buffer);
}

void main()
{
	unsigned char buffer[BUFF_LEN];
	int i;

	for (i = 0; i < BUFF_LEN; i++)
	{
		buffer[i] = i;
	}

	printf("Hello world!\n");

	print_log(buffer, BUFF_LEN);
}
