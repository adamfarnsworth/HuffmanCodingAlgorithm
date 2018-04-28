# HuffmanCodingAlgorithm
encode and decode using pipes and files

1. frequencies – prints a table of the occurrence frequencies of characters in data read
from stdin.  

2. huffman – reads a frequency table from stdin, calculates and prints a table of Huffman
codes for each character.  

3. encode – using a table of Huffman codes (as generated by huffman), translates data
from stdin to the corresponding binary encoded data and prints it to stdout.  

4. decode – using a table of Huffman codes (as generated by huffman), translates encoded
data from stdin back to the original data and prints it to stdout.  

## frequencies

The frequencies program takes a sample text as input and outputs a table of character
frequencies when the input is done. It handles arbitrary (possibly binary) input and
it outputs the table with one line per character, containing the ASCII code for the
character followed by some whitespace and then the number of occurrences
of the character in the input, formatted as a human-readable number. Characters which don’t
occur are not be listed. Other than reordering of the lines and padding numbers with
zeros, the correct table of frequencies for a given sample input is unique. For example, the
following segment of output:  
100 21  
101 32  
102 6  
103 23  
104 9  

indicates that the ASCII characters 100 through 104 (d through h) occurred in the input text
with respective frequencies of 21, 32, 6, 23 and 9.

## huffman

The huffman program implements the algorithm which generates Huffman codes. It takes as
input (from stdin), a table of frequencies, as generated by the frequencies program, and
does two things:  

• Create a file codewords.txt in the current directory that contains a table of encodings.
The table of encodings has the same format as the table of frequencies except that
instead of an occurrence count, the second entry on each line should be the encoding of
the corresponding character as a string of ASCII 0’s and 1’s. For example, a section of
this file might look like this:  
115 11000  
100 11001  
110 1101  
97 1110  
This means that ASCII characters 115 (s), 100 (d), 110 (n) and 97 (a) are to be encoded
as the binary sequences 11000, 11001, 1101, and 1110 respectively.  

• Calculate the compressed file size to stdout.  

Keep in mind that for a given table of character frequencies, there are many possible
correct code tables. Not only are there different ways to assign 0’s and 1’s to the edges of the
Huffman code tree, but in most cases, there are even different trees which are correct.  

## encode
The encode program implements the data encoding process. It takes as its only command-line
argument a file containing a code table, as generated by the huffman program. It reads an
arbitrary input stream from stdin and prints the encoded version to stdout. Note that the
encoded version is packed binary, not ASCII 0’s and 1’s. Using the encoding example from
2
the previous section, this means that if the input file begins with the characters sad, then the
encoded version will begin with this sequence of bits: 11000 1110 11001. Since codewords
generally have lengths which are not multiples of 8, you will have to do some bit manipulation
to ’pack’ the codewords into a stream of bytes.  Testing can be done by entering:  

$ cat input | ./encode codewords.txt | ./decode codewords.txt > output  

## decode
The decode program implements the data decoding process. It works like encode but in
reverse. That is, it takes as its only command-line argument a file containing a code table,
reads encoded data from stdin, decodes it and writes the decoded data to stdout. Note
however, that since any encoded file is a possible valid input, it should be able to handle arbitrary input, not just actual encoded data.
As stated in the previous section, decode program must work as the inverse of your
encode program.
Like the encode program, the decode program must process its input as a stream. The
program must produce output incrementally. It may not read the entire input and then
process it in memory. Ideally, it should produce output as soon as it possibly can.


