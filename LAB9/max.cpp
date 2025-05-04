#include <stdio.h>
#include <vector>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int  n;
        scanf("%d",&n);
        std::vector<int>s(n);
        int max1 = -1,max2=-1;

        for(int i =0;i <n;++i){
            scanf("%d",&s[i]);
            if(s[i]>max1){
                max2=max1;
                max1=s[i];
            }else if(s[i]>max2){
                max2 = s[i];
            }
        }
        for(int i=0;i<n;++i){
            if(s[i]==max1){
                printf("%d ",s[i]-max2);
            }else{
                printf("%d ",s[i]-max1);
            }
        }
        printf("\n");
    }
    return 0;
}