#include <netdb.h>

int main()
{
    struct addrinfo info, *result;

    getaddrinfo(0, "30", &info, &result);
}
