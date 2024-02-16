#include "string_util.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"

static const uint8_t digit_char[10]={'0','1','2','3','4','5','6','7','8','9'};
static const uint8_t hex_digit[] ={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

void string_swap(const char* p_buffer,char* p_msg,const uint8_t len){
    uint8_t i=0;
    for(i=0;i<len;i++){
        p_msg[i]=p_buffer[len-i-1];
    }
}

int long_to_string(const uint32_t data,char* s){
    uint32_t remain=data;
    uint8_t digit=0;
    uint8_t index=0;
    char buffer[16]= {0};
    while(remain >=10){
        digit = (uint8_t)(remain%10);
        buffer[index]=(char)digit_char[digit];
        index++;
        remain =(uint32_t)(remain/10);
    }
    buffer[index]=(char)digit_char[remain];
        string_swap(buffer,s,index+1);
    s[index+1]='\0';
    return (index+1);
}

int slong_to_string(const int32_t data,char* s){
    int32_t temp;
    if(data >=0){
        return (long_to_string((uint32_t)data,s));
    }

    temp=-data;
    *s='-';
    return (long_to_string((uint32_t)temp,s+1)+1);
}

void byte_to_hex_ascii(const uint8_t s,char* hex){
    uint8_t low_digit= s & 0x0f;
    uint8_t high_digit=(s & 0xf0)>>4;
    hex[0] = (char)hex_digit[low_digit];
    hex[1]= (char)hex_digit[high_digit];
}

uint16_t slen(const char *str) {

    const char *char_ptr;
    const uint32_t *longword_ptr;
    uint32_t longword;
    uint32_t lomagic;
    uint32_t himagic;

    /* Handle the first few characters by reading one character at a time.
     Do this until CHAR_PTR is aligned on a longword boundary.  */
    for (char_ptr = str; ((unsigned long int) char_ptr & 3) != 0; ++char_ptr){
        if (*char_ptr == '\0'){
            return (uint16_t)(char_ptr - str);
        }
    }

    longword_ptr = (uint32_t*) char_ptr;

    /* Bits 31, 24, 16, and 8 of this number are zero.  Call these bits
     the "holes."  Note that there is a hole just to the left of
     each byte, with an extra at the end:

     bits:  01111110 11111110 11111110 11111111
     bytes: AAAAAAAA BBBBBBBB CCCCCCCC DDDDDDDD

     The 1-bits make sure that carries propagate to the next 0-bit.
     The 0-bits provide holes for carries to fall into.  */
    himagic = 0x80808080L;
    lomagic = 0x01010101L;

    for (;;) {
        longword = *longword_ptr++;

        if (((longword - lomagic) & ~longword & himagic) != 0) {
            /* Which of the bytes was the zero?  If none of them were, it was
             a misfire; continue the search.  */

            const char *cp = (const char*) (longword_ptr - 1);

            if (cp[0] == 0)
                return (uint16_t)(cp - str);
            if (cp[1] == 0)
                return (uint16_t)(cp - str + 1);
            if (cp[2] == 0)
                return (uint16_t)(cp - str + 2);
            if (cp[3] == 0)
                return (uint16_t)(cp - str + 3);
        }
    }
    return (0);
}

uint8_t str_contain(const char* dst,const char* str){

        const char* match= str;
        const char* source=dst;
    while(*match){
        if((*source)!= (*match)) return (0);
        if(*source=='\0') return (0);
        source++;
        match++;
    }
    return (1);
}

uint16_t string_copy(char* dst,const char*src){
    uint16_t index = 0;
        while(*src){
                *dst++=*src++;
                index++;
        }
        *dst++='\0';
        return index;
}

uint16_t string_package(char* dst, const char* src){
    *dst++='"';
    dst+=string_copy(dst, src);
    *dst++='"';
    return (uint16_t)strlen(src)+2;
}

void parse_mqtt(char * source, char *topic, char *paylad){
	char *p_t,*p_l;
	p_t = strstr(source,",\"");
	p_t+= 2;
	p_l = strstr(p_t,"\",\"");
	char *p_l_end = strstr(p_l,"\"\r\n");
	*p_l_end = 0;
	char *p_t_end = p_l;
	p_l +=3 ;
	*p_t_end = 0;
	strcpy(topic,p_t);
	strcpy(paylad,p_l);
}
