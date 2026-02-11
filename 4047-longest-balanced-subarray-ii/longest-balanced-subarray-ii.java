class segmentTree{
    public int n;
    public int size;
    public int[]sum;
    public int[]mn;
    public int[]mx;
    segmentTree(int n1){
        n=n1;
        size=4*n1;
        sum=new int[size];
        mn=new int[size];
        mx=new int[size];
    }
    void _pull(int node){
        int l=node*2,r=node*2+1;
        sum[node]=sum[l]+sum[r];
    mn[node]=Math.min(mn[l],sum[l]+mn[r]);
 mx[node]=Math.max(mx[l],sum[l]+mx[r]);
     }
    void update(int idx,int val){
    int node=1,l=0,r=n-1;
    int[]path=new int[32];
        int ps=0;
        while(l!=r){
  path[ps++]=node;
    int m=l+(r-l)/2;
    if(idx<=m){
        node=node*2;
        r=m;
    }else{
        node=node*2+1;
        l=m+1;
    }
        }
        sum[node]=val;
        mx[node]=val;
        mn[node]=val;
    while(ps>0){
        _pull(path[--ps]);
    }
    }
    int findRightPre(int target){
    int node=1,l=0,r=n-1,sumBefore=0;
 if(!(mn[node]<=target-sumBefore&&target-sumBefore<=mx[node]))
     return -1;
    while(l!=r){
    int m=l+(r-l)/2;
    int lc=node*2,rc=node*2+1;
    int sumRight=sum[lc]+sumBefore;
    int need=target-sumRight;
    if(mn[rc]<=need&&need<=mx[rc]){
        node=rc;
        l=m+1;
        sumBefore=sumRight;
        }else{
        node=lc;
        r=m;
        }
    }
    return l;
    }
}
class Solution {
    public int longestBalanced(int[] nums) {
  int n=nums.length;
    segmentTree seg=new segmentTree(n);
 Map<Integer,Integer>mpp=new HashMap<>();
    int ans=0;
    for(int l=n-1;l>=0;--l){
        int num=nums[l];
        Integer old=mpp.get(num);
        if(old!=null)
            seg.update(old,0);
    mpp.put(num,l);
    seg.update(l,(num%2==0)?1:-1);
    int r=seg.findRightPre(0);
        if(r>=l)
        ans=Math.max(ans,r-l+1);
            }
        return ans;
     }
}