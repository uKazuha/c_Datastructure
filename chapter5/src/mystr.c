#include "mystr.h"



/*
    素模式匹配：暴力破解

    主串：s
    字串：sub

    从主串的第一个位置开始：
        s[i] == sub[j],初始i=0，j=0
        若匹配则i++,j++;直到j == sub_length → 匹配成功！
        若中途失配，则子串向后移动；即从主串的下一个字符开始比较
        



*/
Index locateSubstr(const char *s,const char *sub){

    int s_length = strlen(s);
    int sub_length = strlen(sub);

    int s_idx;
    int sub_idx;
    int i,j;

    for(s_idx = 0; s_idx < s_length; s_idx++){
        //每一次失配，sub_idx回溯到0
        sub_idx = 0;
        //开始比较每一位字符
        for(i=s_idx,j=sub_idx; j < sub_length;){

            if(s[i] == sub[j]){
                i++;
                j++;
            }else{
                //退出本次匹配
                break;
            }

        }
        //如果退出这一轮匹配时，j == sub_length，则说明匹配成功
        if(j == sub_length){
            printf("match success!\n");
            printf("the index is:%d\n",i-j);
            return i - j;
        }
    }

    //匹配失败
    puts("miss match");
    return -1;
}




/*
    KMP算法：
        对于朴素匹配模式，最大的问题就是需要不停的回溯，这导致最差可能需要匹配 n*m 次

        KMP算法使用一个next[i]数组,指导当发生失配时,下一步应该用子串的哪个元素进行下一轮匹配
        next[i]的值的意义：当前位置的前面，最长的相等的前后缀串的长度
        求next数组：前缀是固定的，后缀是相对的

            aabcabcx

        初始状态next[0]=0，next[1]=0;
        next数组不仅在子串和主串的匹配中有作用，同样在计算next数组元素值时有作用。
        计算next数组的值，就是找到最长的相等的前缀和后缀的长度，
        而前缀(子串的子串)是固定的,从0开始,假设要求的是next[2]的值，那么此时就是aa
        令i=0指向前缀，j=1指向后缀。s[i]==s[j],所以next[2]=1,i++,j++
        此时i=1,j=2,s[i]!=s[j],
        
*/

void get_next(const char *T,int len,int *next){

    int i=0;//前缀
    int j=1;//后缀
    next[0]=-1;
    next[1]=0;

    if( i == -1 || T[i] == T[j] ){

        i++;
        j++;
        next[j] = i;

    }else{
        /*
            next[i]的值，记录了最长匹配前后缀的长度。
            当匹配失配，如前缀在i这个位置失配，失配前，前缀长度=后缀长度=匹配的长度为i,next[j] == i
            即T[0]...T[i-1] == T[j-i]...T[j-1]
            朴素算法是将前缀i回溯到零，但我们不这么做
            我们试图在这个长前缀T[0]...T[i-1]中寻找最长的前缀和后缀，而这个长度是记录在next[i]这里的，假设这个长度为k
            即长前缀的前缀T[0]...T[K-1] == 长后缀的后缀T[i-k]...T[i-1],
            重点来了！！！！
            而长前缀的后缀T[i-k]...[i-1] == 长后缀的后缀T[j-k]...T[j-1]，这一点我们是可以确定的
            所以这个长前缀的前缀，一定等于这个长后缀的后缀！！！！！！
            所以我们不需要将前缀的指针从零开始，从k开始即可，即 i = next[i]
        */
        i = next[i];    
    }

}

void get_nextval(const char *T,int len,int *nextval){

    int i=0;//前缀
    int j=1;//后缀
    nextval[0]=-1;  //哨兵
    nextval[1]=0;       

    if( i == -1 || T[i] == T[j] ){

        i++;
        j++;

        /*
            next数组还有改进的地方，假设有下面这一种情况:
            主串S为：aaaabcde
            模式串T为:aaaaax
            next数组为:-1,0,1,2,3,4
            注意到：S[4] != T[4]，此时发生回溯：j = next[j] = next[4] = 3
            所以下一轮匹配是：T[3] 与 S[4]
            而又因为：T[3] == T[4],则T[3]肯定不等于S[4],这样最终经过好几次没必要的回溯到T[0]与S[4]
            那么如果一开始next[4]记录的就是next[0]的值就好了即
            nextval数组为：-1,-1,-1,-1,-1,0
        */

        if(T[j] == T[j-1]){
            //如果当前字符(即下一个对比的后缀)与前一个字符相等，
            nextval[j] = nextval[i];
        }else{
            nextval[j] = i;
        }



    }else{
        i = nextval[i];    
    }

}





int KMP(const char *S,const char *T){

    int *next;
    int i=0;
    int j=0;
    int len_S = strlen(S);
    int len_T = strlen(T);

    get_nextval(T,len_T,next);

    while(i < len_S && j < len_T){

        if(j == -1 || S[i] == T[j]){
            i++;
            j++;
        }else{
            j = next[j];
        }
    }

    if(j == len_T) return i-j;
    else return -1;
}