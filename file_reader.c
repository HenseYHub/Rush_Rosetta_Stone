#include <unistd.h>
#include <fcntl.h>

int main(void)
{
int by_read;
int file_dec;
char buff[100];

// O_RDONLY == Open Read Only
file_dec = open("numbers.dict", O_RDONLY);

// open() returns a file desciptor >= 0 its good)
// open() return -1 if file not open(error)

if (file_dec == -1)
{
    write(1, "Dict Error\n", 11);
    return (1);
}

// read == write (read(from where, to where, how much))
by_read = read(file_dec, buff, 100);

while(by_read > 0)
{

// stdout/terminal --- what? data ---- how much? how many by_read read
write(1, buff, by_read);
by_read = read(file_dec, buff, 100);
}
// Close the file because we opened it before
close(file_dec);
return (0);
}