// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    int carry = 0;

    ListNode *root = nullptr;
    ListNode *pointer = nullptr;
    ListNode *pointer1 = l1;
    ListNode *pointer2 = l2;

    while (pointer1 || pointer2)
    {
      if (pointer1 && pointer2)
      {
        int sum = pointer1->val + pointer2->val + carry, mod = sum % 10;
        carry = sum >= 10 ? 1 : 0;

        if (pointer == nullptr)
        {
          pointer = new ListNode(mod);
          root = pointer;
        }
        else
        {
          pointer->next = new ListNode(mod);
          pointer = pointer->next;
        }

        pointer1 = pointer1->next;
        pointer2 = pointer2->next;
        continue;
      }

      if (carry == 0)
      {
        if (pointer1)
        {
          pointer->next = pointer1;
        }
        else if (pointer2)
        {
          pointer->next = pointer2;
        }
        break;
      }

      int sum = pointer1 ? pointer1->val + carry : pointer2->val + carry, mod = sum % 10;
      carry = sum >= 10 ? 1 : 0;
      pointer->next = new ListNode(mod);
      pointer = pointer->next;
      if (pointer1)
      {
        pointer1 = pointer1->next;
      }
      else if (pointer2)
      {
        pointer2 = pointer2->next;
      }
    }

    if (carry == 1)
    {
      pointer->next = new ListNode(carry);
    }

    return root;
  }
};
