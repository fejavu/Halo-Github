  /*This is my notes about LeetCode
  * Every problem I think it is meaningful
  * will be noted here.
  *
  * I SAY WE MAKE IT POP
  */


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
};

/*#Add Binary
* use ASCII code to do the math
*
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

static const auto __=[](){
  ios::sync_with_stdio(false);//speed up to in and out
  cin.tie(nullptr);
  return nullptr;
}

class solution{
public:
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
};

/*217. Contains Duplicate
*Given an array of integers, find if the array contains any duplicates.
*Your function should return true if any value appears at least twice in the array,
*and it should return false if every element is distinct.
*/
static int x=[](){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}

class Solution{
public:
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
};
