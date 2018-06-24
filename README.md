## H8D (HATED)

H8D is a tool that reads from an input file and generates a text dump of the file's byte contents (in hexadecimal notation) along with any visible ASCII artifacts (i.e. text) from that hex data.

### Building
A makefile is included in this repository to compile the executable.

### Running
Run the executable with the name of the file to be read as the first argument.

Example:

`./h8d bios.sms`

The program will generate a `dump.txt` file with the output.

Sample of output file:

```
...
0C 01 80 00 CD C2 0C C3     . . . . . . . .
6C 03 43 4F 4E 47 52 41     l . C O N G R A
54 55 4C 41 54 49 4F 4E     T U L A T I O N
53 21 79 CD 2E 04 10 FA     S ! y . . . . .
C9 3A 31 C2 3D 57 87 82     . : 1 . = W . .
5F AF CB 1A 1F 83 5F 21     _ . . . . . _ !
B9 19 19 7E 32 08 C4 23     . . . ~ 2 . . #
7E 32 48 C4 23 7E 32 47     ~ 2 H . # ~ 2 G
C4 23 11 00 CA 06 80 C5     . # . . . . . .
06 04 4E 79 3C E6 03 C6     . . N y < . . .
04 12 13 AF 12 13 CB 19     . . . . . . . .
CB 19 10 EF 23 C1 10 E7     . . . . # . . .
21 3E CA 01 74 10 11 40     ! > . . t . . @
00 71 19 10 FC 3E FF 32     . q . . . > . 2
44 C2 11 36 80 E7 3E 08     D . . 6 . . > .
CD 2E 04 3A 44 C2 B7 20     . . . : D . .  
F5 11 06 80 E7 11 FF 8A     . . . . . . . .
E7 C9 11 00 88 E7 11 37     . . . . . . . 7
8A E7 21 25 C2 7E 35 20     . . ! % . ~ 5  
05 AF 32 44 C2 C9 ED 44     . . 2 D . . . D
5F E6 07 C0 7B 0F 0F C6     _ . . . { . . .
C0 5F 16 79 6F 26 C9 06     . _ . y o & . .
11 C5 7E CF 01 40 00 09     . . ~ . . @ . .
EB 09 EB C1 10 F3 C9 21     . . . . . . . !
32 C2 35 F0 36 3B 23 7E     2 . 5 . 6 ; # ~
D6 01 27 77 11 7A 79 20     . . ' w . z y  
05 3D 32 35 C2 3C E7 7E     . = 2 5 . < . ~
1F 1F 1F 1F E6 0F 28 02     . . . . . . ( .
F6 30 CD 92 0D 7E E6 0F     . 0 . . . ~ . .
F6 30 D3 BE F5 F1 3E 08     . 0 . . . . > .
D3 BE C9 01 01 00 61 54     . . . . . . a T
49 4D 45 20 55 50 52 44     I M E   U P R D
20 20 20 20 54 49 4D 45             T I M E
30 35 25 35 35 30 35 35     0 5 % 5 5 0 5 5
...
```

Note: this is only a sample of a single section of the total output file.

### License (BSD2)

Copyright 2018 BRIAN PUTHUFF

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

