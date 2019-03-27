#include <stdint.h>
#include "blink.h"

int main (void)
{

while(1){
blink_count(LED_GREEN, 10);  
blink_count(LED_ORANGE, 10);
blink_count(LED_RED, 10);
blink_count(LED_BLUE, 10);
//blink(LED_BLUE);
}
    
}
