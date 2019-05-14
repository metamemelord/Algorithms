/*
Given a BST, find a node which is closest to some given arbitrary value

Optimal complxity:
    Time: O(logN)
    Space: O(1)
*/

#include <bits/stdc++.h>

using namespace std;

struct BST
{
    int value;
    BST *left;
    BST *right;
    void insert(int value);
} *root = NULL;

void BST::insert(int value)
{
    BST *node = root;
    if (node == NULL)
    {
        node = new BST();
        node->value = value;
        node->left = node->right = NULL;
        root = node;
    }
    else
    {
        BST *prev = NULL;
        while (node != NULL)
        {
            prev = node;
            if (node->value < value)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }
        node = new BST();
        node->value = value;
        node->left = node->right = NULL;
        if (prev->value < value)
        {
            prev->right = node;
        }
        else
        {
            prev->left = node;
        }
    }
}

void inOrderPrintBST(BST *root)
{
    if (root == NULL)
        return;
    inOrderPrintBST(root->left);
    cout << root->value << "\n";
    inOrderPrintBST(root->right);
}

/*
Iterative solution:
    Time: O(log(n)) (Worst: O(n))
    Space: O(1) (Worst: O(1))   
*/
int findClosestIterative(BST *root, int target)
{
    BST *iter = root;
    int ans = -1, min_val = INT_MAX;
    while (iter != NULL)
    {
        if (abs(iter->value - target) < min_val)
        {
            min_val = abs(iter->value - target);
            ans = iter->value;
        }
        if (iter->value == target)
        {
            ans = iter->value;
            break;
        }
        else if (iter->value < target)
        {
            iter = iter->right;
        }
        else
        {
            iter = iter->left;
        }
    }
    return ans;
}

/*
Recursive solution:
    Time: O(logN) (Worst: O(n))
    Space: O(log(n)) (Worst: O(n))
*/
int findClosestRecursiveImpl(BST *root, int target, int ans)
{
    if (root == NULL)
    {
        return ans;
    }
    if (abs(target - root->value) < abs(target - ans))
    {
        ans = root->value;
    }
    if (target < root->value)
    {
        return findClosestRecursiveImpl(root->left, target, ans);
    }
    else if (target > root->value)
    {
        return findClosestRecursiveImpl(root->right, target, ans);
    }
    else
    {
        return ans;
    }
}

int findClosestRecursiveWrapper(BST *root, int target)
{
    return findClosestRecursiveImpl(root, target, INT_MAX);
}

int main()
{
    root = NULL;
    root->insert(10);
    root->insert(20);
    root->insert(2);
    root->insert(3);
    root->insert(22);
    root->insert(4);
    root->insert(1);
    root->insert(9);
    root->insert(12);
    root->insert(25);
    root->insert(340);
    root->insert(188);
    root->insert(276);
    root->insert(412);
    root->insert(67);
    root->insert(120);
    root->insert(200);
    root->insert(367);
    root->insert(228);
    root->insert(255);
    root->insert(221);
    root->insert(347);
    root->insert(399);
    root->insert(300);
    root->insert(470);
    root->insert(86);
    root->insert(408);
    root->insert(203);
    root->insert(341);
    root->insert(46);
    root->insert(195);
    root->insert(189);
    root->insert(267);
    root->insert(51);
    root->insert(301);
    root->insert(82);
    root->insert(298);
    root->insert(330);
    root->insert(186);
    root->insert(162);
    root->insert(58);
    root->insert(284);
    root->insert(446);
    root->insert(122);
    root->insert(113);
    root->insert(253);
    root->insert(148);
    root->insert(416);
    root->insert(460);
    root->insert(343);
    root->insert(184);
    root->insert(232);
    root->insert(133);
    root->insert(257);
    root->insert(333);
    root->insert(208);
    root->insert(444);
    root->insert(392);
    root->insert(59);
    root->insert(52);
    root->insert(296);
    root->insert(399);
    root->insert(250);
    root->insert(251);
    root->insert(347);
    root->insert(328);
    root->insert(167);
    root->insert(350);
    root->insert(316);
    root->insert(129);
    root->insert(338);
    root->insert(39);
    root->insert(198);
    root->insert(457);
    root->insert(368);
    root->insert(30);
    root->insert(108);
    root->insert(237);
    root->insert(174);
    root->insert(94);
    root->insert(337);
    root->insert(462);
    root->insert(170);
    root->insert(491);
    root->insert(280);
    root->insert(121);
    root->insert(257);
    root->insert(28);
    root->insert(466);
    root->insert(302);
    root->insert(335);
    root->insert(208);
    root->insert(488);
    root->insert(430);
    root->insert(87);
    root->insert(497);
    root->insert(349);
    root->insert(262);
    root->insert(187);
    root->insert(81);
    root->insert(499);
    root->insert(352);
    root->insert(79);
    root->insert(108);
    root->insert(63);
    root->insert(294);
    root->insert(190);
    root->insert(170);
    root->insert(328);
    int ans;
    cin >> ans;
    cout << findClosestIterative(root, ans);
    cout << "\n"
         << findClosestRecursiveWrapper(root, ans);
}
