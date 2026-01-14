function ListNode(val, next = null) {
  this.val = val
  this.next = next
}

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
var rotateRight = function (head, k) {
  if (head == null || head.next == null) return head

  let n = 1
  let end = head
  while (end.next != null) {
    end = end.next
    n++
  }

  k %= n
  if (k === 0) return head

  end.next = head

  let t = head
  for (let i = 0; i < n - k - 1; ++i) t = t.next
  let res = t.next
  t.next = null
  return res
}
