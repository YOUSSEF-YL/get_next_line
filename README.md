# get_next_line
This project is about programming a function that returns a line read from a file descriptor.




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