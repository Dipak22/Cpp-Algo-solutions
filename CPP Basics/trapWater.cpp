#include <iostream>
using namespace std;
int trap(int height[], int heightSize)
{
    int maxHeight = height[0];
    int maxIndex = 0;
    for(int i =1; i<heightSize;i++){
        if(maxHeight<height[i]){
            maxHeight = height[i];
            maxIndex = i;
        }
    }
    int LWater = 0;
    int LMax = height[0];
    for(int i = 1; i<maxIndex;i++){
        if(height[i]<LMax)
            LWater += (LMax - height[i]);
        else
            LMax = height[i];
    }

    int RWater = 0;
    int Rmax = height[heightSize-1];
    for(int i = heightSize -2; i>maxIndex;i--){
        if(height[i]<Rmax)
            RWater += (Rmax - height[i]);
        else
            Rmax = height[i];
    }
    return LWater + RWater;
}
int trapAmount(int height[], int size){
    int maxVolume = 0;
    int li = 0;
    int ri = size-1;
    while(li<ri){
        int l,h;
        if(height[li]<height[ri]){
            l = li; h = ri;
        }else{
            l = ri; h = li;
        }
        int vol = (ri - li)* height[l];
        if(vol>maxVolume){
            maxVolume = vol;
        }
        if(l==ri)
            ri--;
        else
            li++;
    }
    return maxVolume;
}
int main()
{    
    int A[] = {0,1,0,2,1,0,1,3,2,1,0,3,2,1,2};
    int heightSize = 15;
    int unitsA = trap(A,heightSize);
    cout<<unitsA<<" units.\n";

    int height[] = {1,8,6,2,5,4,8,3,7}, size = 9;
    int units = trapAmount(height, size);
    cout << "There are " << units << " units of trapped rainwater.";

    return 0;
}






