class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;

        Node* prev = root;

        while (prev->left) {
            Node* cur = prev;

            while (cur) {
                cur->left->next = cur->right;

                if (cur->next)
                    cur->right->next = cur->next->left;

                cur = cur->next;
            }

            prev = prev->left;
        }

        return root;
    }
};