# HexDump

This is a command line hex dump for visualizing files in hexadecimal and ASCII code. 

### Usage

Usage is very simple with a single command `hexdump` that only requires a file path. For example: `hexdump doc.txt`.

Adding the executable to your environmental path for use across your system is encouraged. 

### Example Output

<pre>
0x00000010  A2  FF  9A  A9  FF  8D  02  7D  |  20  F5  80  A9  28  20  CF  80  .......}  ...( ..
0x00000020  A9  01  20  CF  80  A9  02  20  |  CF  80  A9  0F  20  CF  80  A9  .. ....  .... ...
0x00000030  00  8D  04  02  AD  86  80  8D  |  00  02  AD  87  80  8D  01  02  ........ ........
0x00000040  A9  00  8D  02  02  8D  03  02  |  18  A2  10  2E  00  02  2E  01  ........ ........
0x00000050  02  2E  02  02  2E  03  02  38  |  AD  02  02  E9  0A  A8  AD  03  .......8 ........
0x00000060  02  E9  00  90  06  8C  02  02  |  8D  03  02  CA  D0  DD  2E  00  ........ ........
0x00000070  02  2E  01  02  AD  02  02  18  |  69  30  20  88  80  AD  00  02  ........ i0 .....
0x00000080  0D  01  02  D0  BB  A2  00  BD  |  04  02  F0  07  20  05  81  E8  ........ .... ...
0x00000090  4C  77  80  4C  83  80  C1  06  |  48  A0  00  B9  04  02  AA  68  Lw.L.... H......h
0x000000A0  99  04  02  C8  8A  48  D0  F3  |  68  99  04  02  60  48  A9  F0  .....H.. h...`H..
0x000000B0  8D  02  7D  A9  20  8D  00  7D  |  09  40  8D  00  7D  AD  00  7D  ..}. ..} .@..}..}
0x000000C0  48  A9  20  8D  00  7D  09  40  |  8D  00  7D  AD  00  7D  68  29  H. ..}.@ ..}..}h)
0x000000D0  08  D0  E0  A9  00  8D  00  7D  |  A9  FF  8D  02  7D  68  60  20  .......} ....}h`
0x000000E0  9D  80  48  4A  4A  4A  4A  8D  |  00  7D  09  40  8D  00  7D  49  ..HJJJJ. .}.@..}I
0x000000F0  40  8D  00  7D  68  29  0F  8D  |  00  7D  09  40  8D  00  7D  49  @..}h).. .}.@..}I
0x00000100  40  8D  00  7D  60  A9  02  8D  |  00  7D  09  40  8D  00  7D  29  @..}`... .}.@..})
0x00000110  0F  8D  00  7D  60  20  9D  80  |  48  4A  4A  4A  4A  09  10  8D  ...}` .. HJJJJ...
0x00000120  00  7D  09  40  8D  00  7D  49  |  40  8D  00  7D  68  29  0F  09  .}.@..}I @..}h)..
0x00000130  10  8D  00  7D  09  40  8D  00  |  7D  49  40  8D  00  7D  60  00  ...}.@.. }I@..}`.
0x00000140  00  00  00  00  00  00  00  00  |  00  00  00  00  00  00  00  00  ........ ........
*
0x00008000  00  00  00  00  00  00  00  00  |  00  00  00  00  00  80  00  00  ........ ........
</pre>

The `*` implies that the line directly above it is repeated untill the following lines data is different.

### Compile Source

Currently the only binary release is for windows (.exe). However, this project can be compiled from source
using cmake for specific build systems and operating systems.
