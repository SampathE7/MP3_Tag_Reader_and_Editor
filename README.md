# MP3_Tag_Reader_and_Editor
This project is a simple command-line MP3 tag reader and editor written in C.It allows you to view and modify ID3v2 metadata such as:
- Title
- Artist
- Album
- Year
- Contents
- comments

The program demonstrates how media players store and manage metadata inside MP3 headers and uses several key C programming concepts including:
- File handling (binary file I/O)
- String manipulation
- Byte-level operations
- Endianness conversion
- Pointers and arrays
- Error handling
- Command-line arguments

Features:

1.View MP3 tag information (-v)
 Displays all available metadata from an MP3 file:
 - ./a.out -v song.mp3
2.Edit MP3 tag fields (-e)
        -t      Modifies Title 
        -a      Modifies Artist
        -A      Modifies Album 
        -y      Modifies Year 
        -c      Modifies Content 
        -C      Modifies Comment
  - Ex: ./a.out -e -t "New Title" song.mp3

3.File validation
 - Verifies the MP3 file contains the ID3 header.
 - Handles missing/invalid files gracefully.

4.Byte-level tag processing
 Reads and writes tag data directly from the MP3 header (ID3v2), including:
 - Tag name (TIT2, TPE1, etc.)
 - Frame size
 - Flag bytes
 - Content bytes


Internal Program Flow:

1. View Mode (mp3_view)

 - Opens file in read mode
 - Checks for “ID3” header
 - Reads tag frames sequentially
 - Converts tag sizes from big-endian to little-endian
 - Prints extracted metadata

2. Edit Mode (mp3_edit)
 - Opens original MP3 and a temporary output file
 - Copies the header and all tag frames
 - When the target frame is found:
    -> Replaces content with new user input
    -> Recalculates tag size
 - Writes updated data to temporary file
 - Replaces the original MP3 file

3. Error Handling
 - Invalid arguments trigger usage messages
 - Missing files produce clear error outputs
 - Non-MP3 files are rejected


Technologies & Concepts Used:
- Binary File I/O (fread, fwrite, fseek)
- Endianness conversion
- Command-line utility design
- String handling & pointers
- ID3v2 tag structure parsing
