int candy(vector<int>& ratings) {
int ans = 0;
int n = ratings.size();
vector<int> c(n);
int idx  = -1;
int p = INT_MAX;
for(int i=0;i<ratings.size();i++){
if(ratings[i]<p){
idx = i;
p = ratings[i];
}
}
int last= 0 ;
c[idx] = 1;
for(int i=1;i<n;i++){
if(ratings[i]>ratings[i-1]){
c[i] = c[i-1] + 1;
last = i;
}
else if(ratings[i] == ratings[i-1]){
if(ratings[i]==ratings[last]) last = i;
c[i] = 1;
}
else if(ratings[i]<ratings[i-1]){
c[i] = 1;
if(c[i-1] == c[i]){
int j=i;
/*while(j>0 && ratings[j-1]>ratings[j]){
if(c[j-1] != c[j]) break;
c[j-1] = c[j-1] + 1;
j--;
}*/
c[i-1] = i-last;
}
}
}
for(int i=idx-1;i>=0;i--){
if(ratings[i]>ratings[i+1]){
c[i] = c[i+1] + 1;
last = i;
}