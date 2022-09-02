Selection sort :-
​
int n = nums.size();
for(int i=0;i<n;i++){
int mi = i;
for(int j=i+1;j<n;j++){
if(nums[j] < nums[mi]){
mi = j;
}
}
swap(nums[mi],nums[i]);
}
​
Bubble sort :-
​
for(int i=0;i<n-1;i++){
for(int j=0;j<n-i-1;j++){
if(nums[j]>nums[j+1]) swap(nums[j],nums[j+1]);
}
}
Insertion sort :-
for(int i=1;i<n;i++){
int j = i;
while(j>0 && nums[j]<nums[j-1]){
swap(nums[j],nums[j-1]);
j--;
}
}
​