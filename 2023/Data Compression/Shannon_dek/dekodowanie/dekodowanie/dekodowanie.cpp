#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

string huffman(string input);

class Node
{
public:
    Node* left;
    Node* right;
    pair<char, int> letter;
    string encoded_value;

    Node(pair<char, int> typo) { left = nullptr, right = nullptr, letter = typo; }
    Node(Node* l = nullptr, Node* r = nullptr, pair<char, int> typo = make_pair('-', 0)) { left = l, right = r, letter = typo; }
    //Node (Node* l, Node* r, pair<char,int> typo) { left = l, right = r, letter = typo;}

    ~Node();
};

void sorting(vector<Node*>& node);
void encode(Node* node, string code);
string huffman(string input);

int main()
{
    cout << huffman("aaaabbbbbbccdeeee");
    return 0;
}

void sorting(vector<Node*>& node)
{
    for (int i = 0; i < node.size() - 1; i++)
    {
        for (int j = 0; j < node.size() - 1; j++)
        {
            if (node[j]->letter.second < node[j + 1]->letter.second)
                swap(node[j], node[j + 1]);
        }
    }
}

void encode(Node* node, string code)
{
    if (node == nullptr)
        return;

    if (node->letter.first != '-') {
        node->encoded_value = code;
        return;
    }

    encode(node->left, code + "0");
    encode(node->right, code + "1");
}


string huffman(string input)
{
    vector<Node*> starting_node, final_node;
    string output;
    //creating structure to measure wages
    for (int i = 0; i < 'g' - 'a'; i++)
    {
        Node* temp = new Node(make_pair(char('a' + i), 0));
        starting_node.push_back(temp);
    }

    for (int i = 0; i < input.size(); i++)
    {
        starting_node[input[i] - 'a']->letter.second++;
    }
    sorting(starting_node);

    for (int i = 0; i < starting_node.size(); i++)
    {
        cout << starting_node[i]->letter.first << ':' << starting_node[i]->letter.second << '\n';
    }
    cout << '\n';

    //creating a final node
    while (starting_node.size() != 0)
    {
        for (int i = 0; i < 2; i++)
        {
            final_node.push_back(starting_node[starting_node.size() - 1]);
            starting_node.pop_back();

            if (starting_node.size() == 0)
                break;
        }
        if (starting_node.size() == 0)
            break;
        starting_node.push_back(new Node(final_node[final_node.size() - 2], final_node[final_node.size() - 1], make_pair('-', final_node[final_node.size() - 2]->letter.second + final_node[final_node.size() - 1]->letter.second)));
        sorting(starting_node);
    }

    //adding root
    final_node.push_back(new Node(final_node[final_node.size() - 2], final_node[final_node.size() - 1], make_pair('-', final_node[final_node.size() - 2]->letter.second + final_node[final_node.size() - 1]->letter.second)));

    for (int i = 0; i < final_node.size(); i++)
    {
        if (final_node[i]->left != nullptr)
            final_node[i]->left->encoded_value = '0';

        if (final_node[i]->right != nullptr)
            final_node[i]->right->encoded_value = '1';
    }

    //encoding
    encode(final_node[final_node.size() - 1], "");
    for (int i = 0; i < final_node.size(); i++)
    {
        if (final_node[i]->letter.first != '-')
            cout << final_node[i]->letter.first << ": " << final_node[i]->encoded_value << '\n';
    }


    //final output
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < final_node.size(); j++)
        {
            if (input[i] == final_node[j]->letter.first)
                output += final_node[j]->encoded_value;
        }
    }


    return output;
}
