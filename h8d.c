/*

H8D (HATED)
A hexadecimal / visible ASCII byte dumper


Copyright 2018 BRIAN PUTHUFF

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include <stdio.h>

#define PAD_LIMIT 8

void clearArray(unsigned char* byte_array, unsigned int size_of_array);
void process(unsigned char* hd, unsigned char* byte_array, unsigned int size_of_byte_array, FILE* output_file);

int main(int argc, char* argv[]) {
	unsigned int i;
	FILE* input_fp;
	FILE* output_fp;
	unsigned char HEXDIGITS[16] = { "0123456789ABCDEF" };
	unsigned char pad[PAD_LIMIT];
	unsigned char c;
	clearArray(pad, PAD_LIMIT);

	if(argc > 1) {
		input_fp = fopen(argv[1], "rb");
		output_fp = fopen("dump.txt", "w");
		if(input_fp != NULL && output_fp != NULL) {
			i = 0;
			do {
				c = fgetc(input_fp);
				if(feof(input_fp)) {
					break;
				}
				pad[i] = c;
				++i;
				if(i == PAD_LIMIT) {
					process(HEXDIGITS, pad, PAD_LIMIT, output_fp);
					clearArray(pad, PAD_LIMIT);
					i = 0;
				}
			} while(1);
			if(i > 0) {
				process(HEXDIGITS, pad, PAD_LIMIT, output_fp);
				clearArray(pad, PAD_LIMIT);
			}
			fclose(input_fp);
			fclose(output_fp);
		}
	}

	return 0;
}

/* initialize pad buffer elements to zero */
void clearArray(unsigned char* byte_array, unsigned int size_of_array) {
	unsigned int i;
	for(i = 0; i < size_of_array; ++i) {
		byte_array[i] = 0;
	}
}


/* dump hex and visible ASCII to output file */
void process(unsigned char* hd, unsigned char* byte_array, unsigned int size_of_byte_array, FILE* output_file) {
	unsigned int i;
	unsigned char nibble;

	/* hex dump */
	for(i = 0; i < size_of_byte_array; ++i) {
		nibble = byte_array[i] & 0xf0;
		nibble = nibble >> 4;	
		fputc(hd[nibble], output_file);
		nibble = byte_array[i] & 0x0f;
		fputc(hd[nibble], output_file);
		fputc(' ', output_file);
	}

	/* pad additional spaces between HEX dump and readible ASCII dump */
	for(i = 0; i < 4; ++i) {	
		fputc(' ', output_file);
	}

	/* readible ASCII dump */
	for(i = 0; i < size_of_byte_array; ++i) {
		if(byte_array[i] < 32) {
			fputc('.', output_file);
		}
		else if(byte_array[i] > 126) {
			fputc('.', output_file);
		}
		else {
			fputc(byte_array[i], output_file);
		}
		if(i == size_of_byte_array - 1) {
			fputc('\n', output_file);
		}
		else {
			fputc(' ', output_file);
		}
	}
}
