#include <bits/stdc++.h>

using namespace std;
class node
{
public:
   int data;
   node *next;
   node *prev;
   node(int val)
   {
      data = val;
      next = NULL;
      prev = NULL;
   }
};
// linked list for slink
class linked_list
{
public:
   node *head;
   node *tail;
   int cnt;
   linked_list()
   {
      head = NULL;
      tail = NULL;
      cnt = 0;
   }
   void push(int x)
   {
      node *n = new node(x);
      if (head == NULL)
      {
         head = n;
         tail = n;
         return;
      }
      tail->next = n;
      n->prev = tail;
      tail = n;
      cnt++;
   }
   void display()
   {
      node *t = head;
      while (t != NULL)
      {
         cout << t->data << " ";
         t = t->next;
      }
      cout << endl;
   }
   void empty()
   {
      head = NULL;
      tail = NULL;
   }
   /* Question no 11 binary search in linked list which is worse than the linear search. But tried to
   implement it in the way of binary search */
   bool binary_search(int x)
   {
      node *h = head;
      node *l = tail;
      int low = 1, high = cnt;
      while (low < high)
      {
         int mid = (low + high) / 2;
         node *temp = h;
         int k = low;
         // cout<<mid<<endl;
         while (k != mid)
         {
            k++;
            temp = temp->next;
         }
         if (temp->data == x)
         {
            return true;
         }
         else if (temp->data < x)
         {
            h = temp->next;
            high = mid - 1;
         }
         else
         {
            l = temp->prev;
            low = mid + 1;
         }
      }
      return false;
   }
};
// Stack for input stack and temp stack implemented using linked list.
class Stack
{
   node *f;
   node *l;
   int n, cnt;

public:
   Stack(int x = INT_MAX)
   {
      n = x;
      cnt = 0;
      f = NULL;
      l = NULL;
   }
   bool empty()
   {
      return (!cnt);
   }
   bool full()
   {
      return (cnt == n);
   }
   void push(int x)
   {
      if (full())
      {
         return;
      }
      cnt++;
      node *n = new node(x);
      if (!f)
      {
         f = n;
         l = n;
         // cnt++;
         return;
      }
      l->next = n;
      n->prev = l;
      l = n;
   }

   void pop()
   {
      if (empty())
      {
         return;
      }
      cnt--;
      node *temp = l;
      l = l->prev;
      if (cnt == 0)
      {
         f = NULL;
         return;
      }
      l->next = NULL;
      free(temp);
   }
   int top()
   {
      if (!empty())
      {
         return l->data;
      }
      return -1;
   }
   int size()
   {
      return cnt;
   }
   void display()
   {
      node *t = l;
      while (t != NULL)
      {
         cout << t->data << " ";
         t = t->prev;
      }
      cout << endl;
   }
};

/*for sorting the stack this method is used this work according to the given algorithm*/
void sortstack(Stack &s1, Stack &s2)
{
   // int cnt=0;

   while (s1.empty() == false)
   {
      if (s2.empty() == true)
      {
         s2.push(s1.top());
         s1.pop();
      }
      else
      {
         int element = s1.top();
         s1.pop();
         Stack s3;
         while (s2.empty() == false and element < s2.top())
         {
            s3.push(s2.top());
            s2.pop();
         }
         s2.push(element);
         while (!s3.empty())
         {
            s2.push(s3.top());
            s3.pop();
         }
      }
      // cnt++;
      // if(cnt==2){
      //    break;
      // }
   }

   // cout << s2.empty() << endl;
   while (!s2.empty())
   {
      s1.push(s2.top());
      s2.pop();
   }
   // s1.display();
}
/* Merge sort function used in the bucket sort */
void merge(int ar[], int l, int r, int p)
{
   int temp[r - l + 1];
   int i = l;
   int j = p + 1;
   int k = 0;
   while (i <= p and j <= r)
   {
      if (ar[i] <= ar[j])
      {
         temp[k] = ar[i];
         i++;
      }
      else
      {
         temp[k] = ar[j];
         j++;
      }
      k++;
   }
   while (i <= p)
   {
      temp[k] = ar[i];
      i++;
      k++;
   }
   while (j <= r)
   {
      temp[k] = ar[j];
      j++;
      k++;
   }
   for (int i = l; i <= r; i++)
   {
      ar[i] = temp[i - l];
   }
}
void merge_sort(int ar[], int l, int r)
{
   if (l < r)
   {
      int p = (l + r) / 2;
      merge_sort(ar, l, p);
      merge_sort(ar, p + 1, r);
      merge(ar, l, r, p);
   }
}
/*bucket sort for sorting the link list. here i used just nodw data instead of array elemrnt and for tracking the number
elements present in the array I took a additional array*/
void bucket_sort(linked_list &l1, int mn, int mx, int n)
{
   int ar[15][n];
   int b[15];
   int range = (mx - mn) / 15;
   memset(b, 0, sizeof b);
   // cout<<1<<endl;

   node *temp = l1.head;
   // cout<<temp->data<<endl;
   while (temp != NULL)
   {
      double z = ((temp->data - mn) / range);
      int x = z;
      double diff = z - x;
      if (temp->data != mn and diff == 0 and x != 0)
      {
         ar[x - 1][b[x - 1]] = temp->data;
         b[x - 1]++;
      }
      else
      {
         ar[x][b[x]] = temp->data;
         b[x]++;
      }
      // cout<<b[x]<<endl;
      // b[x]++;
      // cout<<temp->data<<endl;
      temp = temp->next;
   }
   // cout<<1<<endl;
   temp = l1.head;
   for (int i = 0; i < 15; i++)
   {
      if (b[i] != 0)
      {
         merge_sort(ar[i], 0, b[i] - 1);
         for (int j = 0; j < b[i]; j++)
         {
            temp->data = ar[i][j];
            if (temp->next == NULL)
            {
               break;
            }
            else
            {
               temp = temp->next;
            }
            // cout<<ar[i][j]<<" ";
         }
         // cout<<endl;
      }
   }
}
int main()
{
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   int n;
   cin >> n;
   int ar[n];
   int mx = 0;
   int mn = 1e9;
   Stack inpuststack = Stack(n), tempstack = Stack(n);
   linked_list slink = linked_list();
   for (int i = 0; i < n; i++)
   {
      cin >> ar[i];
      if (ar[i] > mx)
      {
         mx = ar[i];
      }
      if (ar[i] < mn)
      {
         mn = ar[i];
      }
      inpuststack.push(ar[i]);
      // cout << inpuststack.top() << endl;
      slink.push(ar[i]);
   }
   // inpuststack.display();
   sortstack(inpuststack, tempstack);
   inpuststack.display();
   bucket_sort(slink, mn, mx, 150);
   slink.display();
   node *temp = slink.head;
   /* both are the sortings work porporly there is no difference betweeen the stack and the linked list*/
   while (!inpuststack.empty())
   {
      cout << inpuststack.top() << "-" << temp->data << ": " << inpuststack.top() - temp->data << endl;
      inpuststack.pop();
      temp = temp->next;
   }
   cout << slink.binary_search((slink.head->data + slink.tail->data) / 2) << endl;
}
