/* hostent host entry */

#include <netdb.h>
#include <stdio.h>


int main()
{
    struct hostent *ht;

    ht = gethostent();

    printf("%s\n", ht->h_name);
}
