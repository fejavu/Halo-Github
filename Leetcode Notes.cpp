  /*
  ================================================
  = This is my notes about LeetCode              =
  = Every problem I think it is meaningful       =
  = will be noted here.                          =
  = I SAY WE MAKE IT POP                         =
  ================================================
  */

static const auto __=[](){
  ios::sync_with_stdio(false);//speed up to in and out
  cin.tie(nullptr);
  return nullptr;
}();

static int x=[](){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

class solution{
public:
  vector<int> plusoOne(vector<int>& digits){
    int length = digits.size()-1;
    caryOrNot(digits,length);
    return digits;
  }

  void carryOrNot(vector<int>& nums,depth){
    if(nums[depth]==9){
      if(depth==0)
        nums[depth]=0;
      nums.insert(nums.begin(),1);
      else
        nums[depth]=0;
      carryOrNot(nums,depth-1);
    }
    else
      digits[depth]+=1;
  }

  int binarySearch(vector<int>& nums,int target){
    int left = 0;
    int right = nums.size()-1;
    while(left<=right){
      int mid = left + (right-left)/2; //avoid of overflow
    if(nums[mid]<target)
      left = mid+1;
    else
      right = mid-1;  //in case of nums[mid]>=target,when left > right,jump out of this loop and return left(now left=right+1)
  }
    return left;
  }

  /*
  ================================================
  = Add Binary
  = use ASCII code to do the math
  ================================================
  */
  string addBinary(string a, string b) {
    string str = "";
    int carry = 0, ptA = a.size()-1, ptB = b.size()-1;
    while(ptA>=0 || ptB>=0 || carry==1){
      carry += ptA>=0 ? a[ptA--]-'0':0;
      carry += ptB>=0 ? b[ptB--]-'0':0;
      str = char(carry%2 + '0')+str;
      carry /= 2;
    }
    return str;
  }

  /*
  ================================================
  = Add Two Numbers
  = You are given two non-empty linked lists representing two non-negative integers.
  = The digits are stored in reverse order and each of their nodes contain a single digit.
  = Add the two numbers and return it as a linked list.
  = struct ListNode{
  =   int val;
  =   ListNode *next;
  =   ListNode(int x):val(x),next(NULL){}
  = };
  ================================================
  */
    ListNode* addTwoNumbers(ListNode* l1,ListNode* l2) {
      ListNode prevHead(0),*pt = &prevHead;
      int carry = 0;
      while(l1||l2||carry){
       int sum = (l1?l1->val:0)+(l2?l2->val:0) + carry;
       carry = sum/10;
       pt->next = ListNode(sum%10);
       pt = pt->next;
       l1 = l1?l1->next:l1;
       l2 = l2?l2->next:l2;
     }
     return prevHead.next;
   }

  /*
  ================================================
  = 217. Contains Duplicate
  = Given an array of integers, find if the array contains any duplicates.
  = Your function should return true if any value appears at least twice in the array,
  = and it should return false if every element is distinct.
  ================================================
  */

  bool containsDuplicate1(vector<int>& nums){
    return (nums.size() > set<int>(nums.begin(),nums.end()).size());//set method doesn't contain repeat elements
  }

  bool containsDuplicate2(vector<int>& nums){
    sort(nums.begin(),nums.end());
    for(int i = 1;i<nums.size();i++){
      if(nums[i]==nums[i - 1])
        return true;
    }
    return false;
  }

  /*
  ================================================
  = 167.Two Sum II - Input array is sorted
  ================================================
  */
  std::vector<int> twoSum1(std::vector<int>& nums,int target){
    int lo = 0,hi = nums.size()-1;
    while(nums[lo]+nums[hi]!=target){
      if (nums[lo]+nums[hi]<target){
        lo++;
      }else{
        hi--;
      }
    }
    return std::vector<int> {lo+1,hi+1};
  };

  std::vector<int> twoSum2(std::vector<int>& nums,int target ){
    if(nums.empty())
      return {};
    for (int i = 0; i < nums.size()-1;i++){
      int start = i+1,end = nums.size()-1,gap=target-nums[i];
      while(start<=end){
        int m = start+(end-start)/2;
        if(nums[m]==gap) return {i+1,m+1};
        else if(nums[m]>gap){
          end = m-1;
        }else{
          start = m+1;
        }
      }
    }
  };

  /*
  ================================================
  = 349. Intersection of Two Arrays
  ================================================
  */
  vector<int> intersection(vector<int>& nums1,vector<int>& nums2){
    unordered_set<int> m(nums1.begin(),nums1.end());
    vector<int> res;
    for(auto val:nums2){
      if (m.count(val)){
        res.push_back(val);
        m.erase(val);
      }
    }
    return res;
  };

  /*
  ================================================
  = 350.Given two arrays, 
  = write a function to compute their intersection.
  ================================================
  */
  vector<int> intersect2(vector<int>& nums1, vector<int>& nums2) {
   sort(nums1.begin(),nums1.end());
   sort(nums2.begin(),nums2.end());
   vector<int> res;
   int l1=0,l2=0;
   int r1=nums1.size(),r2=nums2.size();
   while(l1<r1 && l2<r2){
     if(nums1[l1]==nums2[l2]){
       res.push_back(nums1[l1]);
       l1++;
       l2++;
     }else if(nums1[l1]>nums2[l2]){
      l2++;
    }else{
      l1++;
    }
  }
  return res;
}

vector<int> intersect2_1(vector<int>& nums1,vector<int>& nums2){
  unordered_map<int,int> tmp;
  std::vector<int> res;
  for (int i = 0; i < nums1.size(); i++){
    tmp[nums1[i]]++;
  }
  for (int i = 0; i < nums2.size(); i++){
    if (tmp[nums2[i]]>0){
      res.push_back(nums2[i]);
      tmp[nums2[i]]--;  // In case of the repeat calls of push_back while the nums1 get only one;
    }
  }
  return res;
}

  /*
  ================================================
  = 387. First Unique Character in a String
  = Given a string, find the first non-repeating 
  = character in it and return it's index. If it doesn't exist, return -1.
  ================================================
  */

  int firstUniqChar(string s){
    unordered_map<char,int> m;
    for (int i = 0; i < size(); i++){
      m[s[i]]++;
    }
    for (int i = 0; i < s.size(); i++){
      if(m[s[j]]==1)  return j;
    }
    return -1;
  }

  int firstUniqChar2(string s){
    std::vector<int> v(26);
    for (int i = 0; i < s.length(); i++){
      v[s[i]-'a']++;
    }
    for (int i = 0; i < s.length(); i++){
      if (v[s[i]-'a']==1){
        return i;
      }
    }
    return -1;
  }

  /*
  ================================================
  = 69. Sqrt(x)
  = 实现 int sqrt(int x) 函数。
  = 计算并返回 x 的平方根，其中 x 是非负整数。
  = 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。 
  = 二分查找；乘法溢出；
  ================================================
  */
  int mySqrt(int x) {
    if(x<2)    
      return x;
    int l=1,r=x;
    while(l<r){
      int mid=l+(r-l)/2;
      if(mid<=(x/mid))
        l=mid+1;
      else if(mid>(x/mid))
        r=mid;
    }
    return  r-1;
  }

  int mySqrt2(int x){
    long r = x;
    long a = x;
    while(r * r > a) {
      r = (r + a / r) / 2;
    }
    return r;    
  }

  /*
  ================================================
  = 367. Valid Perfect Square
  ================================================
  */
    bool isPerfectSquare(int num) {
      if(num<2)    
        return true;
      int l=1,r=num;
      while(l<r){
        int mid=l+(r-l)/2;
        if(mid<=(num/mid))
          l=mid+1;
        else if(mid>(num/mid))
          r=mid;
      }
      return  num==(r-1)*(r-1);
    }
  
  /*
  ================================================
  = #633. Sum of Square Numbers
  ================================================
  */
    bool judgeSquareSum(int c) {
      int b=(int)std::sqrt(c);
      int a=0;
      while(b>=a){
        long num = a*a+b*b; 
        if(num>c)   b--;
        else if (num<c) a++;
        else return true; 
      }
      return false;
    }
  /*
  ================================================
  = #50. Pow(x, n)
  ================================================
  */
    double myPow(double x,int n){
      if(n==0)  return  1;
      double tmp = myPow(x,n/2);
      if(n%2){
        return n<0 ? 1/(x*tmp*tmp):x*tmp*tmp;
      }else
        return tmp*tmp;
    }
  /*
  ================================================
  = #441.Arranging Coins
  ================================================
  */
  int arrangeCoins(int n){
    if(n==0)  return 0;
    int i=0;
    while(n>=i){
      n-=i;
      i++;
    }
    return --i;
  }

  int arrangeCoins2(int n){
        /* 
        (1+k)*k/2 = n
        k+k*k = 2*n
        k*k + k + 0.25 = 2*n + 0.25
        (k + 0.5) ^ 2 = 2*n +0.25
        k + 0.5 = sqrt(2*n + 0.25)
        k = sqrt(2*n + 0.25) - 0.5
        */
    return (int)(math.sqrt(2*(long)n+0.25)-0.5);
  }

  /*
  ================================================
  = #744. Find Smallest Letter Greater Than Target
  ================================================
  */
  char nextGreaterestLetter(std::vector<char>& letters,char target){
    auto i = letters.begin();
    for(;i!=letters.end();i++){
      if(*i>target)
        return *i;
    }
    if(i==letters.end())
      return letters[0];
  }

  char nextGreaterestLetter2(std::vector<char>& letters,char target){
    auto res = upper_bound(letters.begin(),letters.end(),target);
    if(res==letters.end())
    return letters[0];
    return *res;
  }

  /*
  ================================================
  = #744. Find Smallest Letter Greater Than Target
  ================================================
  */
  int romanToInt(string s){
    map<char,int> rToI = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}}; 
    int res = 0;
    for(auto pt = s.begin();pt != s.end();pt++){
        int tmp = rToI[*pt];
        res += ((pt != s.end()-1) && rToI[*pt] < rToI[*(pt+1)]) ? -tmp:tmp;
    }
    return res;
  }

  /*
  ================================================
  = #14. Longest Common Prefix
  ================================================
  */
  string longestCommonPrefix(std::vector<string>& strs){
    string res;
    char ch;
    if(strs.size()<1) return res;
    for(int i = 0;;i++){
      ch = strs[0][i];
      for(auto s:strs)
        if((i+1 > s.size()) || ch != s.[i])
          return res;
        res.push_back(ch);
    }
    return res;
  }

  /*
  ================================================
  = #20. 有效的括号
  ================================================
  */
  bool isValid(string s) {
    std::stack<char> buffer;
    for(char& c : s){
      if(buffer.empty() || c - buffer.top() != 1 && c - buffer.top() != 2)
        buffer.push(c);
      else
        buffer.pop();
    }
    return buffer.empty();
  }
  bool isValid2(string s){
    stack<char> st;
    for(auto& i:s){
      if(!st.empty()){
        if(st.top()=='{' && i == '}')       st.pop();
        else if (st.top()=='[' && i == ']') st.pop();
        else if (st.top()=='(' && i == ')') st.pop();
        else                                st.push(i);
      }
      else                                  st.push(i);
    }
    return st.empty();
}

};
