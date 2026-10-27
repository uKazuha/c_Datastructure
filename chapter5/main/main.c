#include <stdio.h>
#include "mystr.h"


int main(void)
{
    char *s = "aaaabaaaaabcde";
    char *sub = "aaaaab";
    
    // locateSubstr(s,sub);
    puts("begin");
    int pos = KMP(s,sub);
    puts("after");
    printf("%d\n",pos);

    return 0;
}