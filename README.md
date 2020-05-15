# QPlayAllFiles
A Qt based program to play any bit stream from a file.

## Background
Several years ago I was interested in prime numbers. I wondered how the prime numbers would look like as a bitmap graphic. I wrote a program in C# do see this. As an input I created a binary file with a bit array. The position in the bit array represents the natural numbers. A helper program set the prime number to 1 and the other numbers to 0. My C# program translated the bit array in a bitmap graphic. One color for prime number, another color for the non prime numbers. 

![Prime Number Bitmap](https://moser-engineering.de/images/prime_bitmap_small.jpg)

The results made me curious how this would sound like. I decided to write a program which plays the content of the prime number bit array as MIDI notes.
Since this program can play any file as MIDI notes I called it QPlayAllFiles.
But the most interesting sound results from the prime_numbers.bin file.

## How it works
The input bit stream is divided into segments. These segments consists of individual channels (defined in Extras - Settings - Channels) which are mapped to the channel settings and sent to the MIDI output device. 
Each channel has a note, a MIDI channel, and a group value assigned. A bit value of 1 is interpreted as „note on“ and a bit value of 0 is interpreted as „note off“.

![Overview](https://moser-engineering.de/images/overview_small.jpg)

## Executables
You can find the Windows executable in ``windows_executables_release.zip``
Unpack this ZIP archive and the prime_numbers.zip archive.
Run QPlayAllFiles.exe

---
## New in Version 0.2
In version 0.2 there are the following enhancements:

In "Settings" the bar can defined in the form numerator/denominator,e.g., 3/4, 4/4, 6/8. With "Accent" it is possible to define which note in the bar is stressed. Furthermore it is possible to enable slightly varied interval timing and a metronome.

With slightly interval timing the result should sound more naturally. For this the intervals between two notes are changed with a small value applying the following algorithm:

When the number of notes in a segment is a prim number then change the interval by adding a random number N between "min" and "max".  "min" and "max" are configurable in the "Settings". Default values are min=5 and max=20ms. When "max" is bigger than 50ms it starts sounding strange. When a second random number between 0 and 2013 is also a prim number then negate the value of N. 

---
