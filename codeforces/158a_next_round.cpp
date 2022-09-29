    #include <iostream>
     
     
    int main(){
        int n = 0;
        int k = 0;
        
        std::cin >> n >> k;
        
        int ar[n];
        for(int i = 0; i < n; i++)
            std::cin >> ar[i];
        int i = 0;
        int cnt = 0;
        while(ar[i] != 0 && ar[i]>=ar[k-1] && i < n){
            i++;
            cnt++;
        }
        
        std::cout << cnt << "\n";
        
        return 0;
    }
