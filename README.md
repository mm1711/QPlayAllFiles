# QPlayAllFiles
A Qt based program to play any bit stream from a file.

## Background
Several years ago I was interested in prime numbers. I wondered how the prime numbers would look like as a bitmap graphic. I wrote a program in C# do see this. As an input I created a binary file with a bit array. The position in the bit array represents the natural numbers. A helper program set the prime number to 1 and the other numbers to 0. My C# program translated the bit array in a bitmap graphic. One color for prime number, another color for the non prime numbers. 

![Prime Number Bitmap] (images/prime_bitmap_small.jpg)

The results made me curious how this would sound like. I decided to write a program which plays the content of the prime number bit array as MIDI notes.
Since this program can play any file as MIDI notes I called it QPlayAllFiles.
But the most interesting sound results from the prime_numbers.bin file.

## How it works
The input bit stream is divided into segments. These segments consists of individual channels (defined in Extras - Settings - Channels) which are mapped to the channel settings and sent to the MIDI output device. 
Each channel has a note, a MIDI channel, and a group value assigned. A bit value of 1 is interpreted as „note on“ and a bit value of 0 is interpreted as „note off“.

![Overview] (images/overview_small.jpg)



