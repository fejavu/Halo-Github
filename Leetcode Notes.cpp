  /*This is my notes about LeetCode
  * Every problem I think it is meaningful
  * will be noted here.
  *
  * I SAY WE MAKE IT POP
  */

static const auto __=[](){
  ios::sync_with_stdio(false);//speed up to in and out
  cin.tie(nullptr);
  return nullptr;
}

static int x=[](){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}

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

  /*#Add Binary
  * use ASCII code to do the math
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

/*#Add Two Numbers
 *You are given two non-empty linked lists representing two non-negative integers.
 *The digits are stored in reverse order and each of their nodes contain a single digit.
 *Add the two numbers and return it as a linked list.
  struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
  };*/
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

  /*217. Contains Duplicate
  *Given an array of integers, find if the array contains any duplicates.
  *Your function should return true if any value appears at least twice in the array,
  *and it should return false if every element is distinct.
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

  /*167.Two Sum II - Input array is sorted
  *
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

  /*349. Intersection of Two Arrays
  *
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

  /*350.Given two arrays, 
  *write a function to compute their intersection.
  *
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


};
