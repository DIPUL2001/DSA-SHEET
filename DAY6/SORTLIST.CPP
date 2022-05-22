 ListNode* sortList(ListNode* head){
        bool done = (!head);
    // Keep partitioning our list into bigger sublists length. Starting with a size of 1 and doubling each time
    for (int step = 1; !done; step *= 2) {
      done = true;
      ListNode** next_ptr = &head;
      ListNode* remaining = head;
      ListNode* list[2];
      do {
        // Split off two sublists of size step
        for (auto& sub_head : list) {
          sub_head = remaining;
          ListNode* tail = nullptr;
          for (int i = 0; i < step && remaining; ++i, remaining = remaining->next) {
            tail = remaining;
          }
          // Terminate our sublist
          if (tail) {
            tail->next = nullptr;
          }
        }

        // We're done if these are the first two sublists in this pass and they
        // encompass the entire primary list
        done &= !remaining;

        // If we have two sublists, merge them into one
        if (list[1]) {
          while (list[0] || list[1]) {
            int idx = (!list[1] || list[0] && list[0]->val <= list[1]->val) ? 0 : 1;
            *next_ptr = list[idx];
            list[idx] = list[idx]->next;
            next_ptr = &(**next_ptr).next;
          }

          // Terminate our new sublist
          *next_ptr = nullptr;
        } else {
          // Only a single sublist, no need to merge, just attach to the end
          *next_ptr = list[0];
        }
      } while (remaining);
    }
    return head;
    }