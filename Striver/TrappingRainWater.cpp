class Solution {
public:
    int trap(vector<int>& height) {
        int waterCollected = 0;
        int i=0, maxIndex=0, maxVal=height[0], n = height.size();
        for(int i=0; i<n; i++) {
            if(height[i] > maxVal) {
                maxVal = height[i];
                maxIndex = i;
            }
        }
        int currentMax=0;
        for (int i=0; i<maxIndex; i++) {
            if(currentMax < height[i]) {
                currentMax = height[i];
                continue;
            }
            waterCollected += (currentMax-height[i]);
        }
        currentMax=0;
        for(int i=n-1; i>maxIndex; i--) {
            if(currentMax < height[i]) {
                currentMax = height[i];
                continue;
            }
            waterCollected += (currentMax-height[i]);
        }
        return waterCollected;
    }
};
