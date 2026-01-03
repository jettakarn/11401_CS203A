#ifndef COMMON_DEF_H
#define COMMON_DEF_H

#include <cstddef>

template <typename T>
struct ListNode {
    T val;
    ListNode* next;

    ListNode(T x) : val(x), next(nullptr) {}
    ListNode() : val(0), next(nullptr) {}
};

template <typename T>
struct DListNode {
    T val;
    DListNode* prev;
    DListNode* next;

    DListNode(T x) : val(x), prev(nullptr), next(nullptr) {}
    DListNode() : val(0), prev(nullptr), next(nullptr) {}
};

template <typename T>
struct TreeNode {
    T val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};

#endif