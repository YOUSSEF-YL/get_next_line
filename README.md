# get_next_line
This project is about programming a function that returns a line read from a file descriptor.

***Mandatory part***

• Repeated calls (e.g., using a loop) to your get_next_line() function should let
you read the text file pointed to by the file descriptor, one line at a time.
• Your function should return the line that was read.
If there is nothing else to read or if an error occurred, it should return NULL.
• Make sure that your function works as expected both when reading a file and when
reading from the standard input.
• Please note that the returned line should include the terminating \n character,
except if the end of file was reached and does not end with a \n character.
• Your header file get_next_line.h must at least contain the prototype of the
get_next_line() function.
• Add all the helper functions you need in the get_next_line_utils.c file.
A good start would be to know what a static variable is.

***Bonus part***

This project is straightforward and doesn’t allow complex bonuses. However, we trust
your creativity. If you completed the mandatory part, give a try to this bonus part.
Here are the bonus part requirements:
• Develop get_next_line() using only one static variable.
• Your get_next_line() can manage multiple file descriptors at the same time.
For example, if you can read from the file descriptors 3, 4 and 5, you should be
able to read from a different fd per call without losing the reading thread of each
file descriptor or returning a line from another fd.
It means that you should be able to call get_next_line() to read from fd 3, then
fd 4, then 5, then once again 3, once again 4, and so forth.
Append the _bonus.[c\h] suffix to the bonus part files.
It means that, in addition to the mandatory part files, you will turn in the 3 following
files:
• get_next_line_bonus.c
• get_next_line_bonus.h
• get_next_line_utils_bonus.c


***things to know***

**What is the File Descriptor?**

File descriptor is integer that uniquely identifies an open file of the process.

**File Descriptor table**
File descriptor table is the collection of integer array indices that are file descriptors in which elements are pointers to file table entries. One unique file descriptors table is provided in operating system for each process.

**File Table Entry:**
 File table entries is a structure In-memory surrogate for an open file, which is created when process request to opens file and these entries maintains file position.

**Standard File Descriptors**
When any process starts, then that process file descriptors table’s fd(file descriptor) 0, 1, 2 open automatically, (By default) each of these 3 fd references file table entry for a file

**Returns: How many bytes were actually read()**

- return Number of bytes read on success
- return 0 on reaching end of file
- return -1 on error
- return -1 on signal interrupt

```
 File Decsriptors, Open File Table, Inode Table
	-- each PCB has a table of file descriptor pointers
	-- each file descriptor pointer points to an open file table
	   entry containing
		-- reference count
		-- offset
		-- inode table index
	-- each inode for an open file is stored in an "in-core" inode table
	   entry with a reference count

```

![https://web.archive.org/web/20160422100533im_/http://www.cs.ucsb.edu/~rich/class/cs170/notes/FileSystem/filetable.rich.jpg](https://web.archive.org/web/20160422100533im_/http://www.cs.ucsb.edu/~rich/class/cs170/notes/FileSystem/filetable.rich.jpg)

## **Overview**

When a [process](https://www.computerhope.com/jargon/p/process.htm) makes a successful request to open a file, the kernel [returns](https://www.computerhope.com/jargon/r/return.htm) a file descriptor which points to an entry in the kernel's global file table. The file table entry contains information such as the [inode](https://www.computerhope.com/jargon/i/inode.htm) of the file, byte [offset](https://www.computerhope.com/jargon/o/offset.htm), and the access restrictions for that [data stream](https://www.computerhope.com/jargon/d/datastre.htm) ([read-only](https://www.computerhope.com/jargon/r/readonly.htm), write-only, etc.).