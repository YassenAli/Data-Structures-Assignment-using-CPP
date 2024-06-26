#include "TreeUtils.h"
#include "Item.h"

struct CompareByName
{
    bool operator()(const Item &a, const Item &b) const
    {
        return a.getName() < b.getName();
    }
};

struct CompareByCategory
{
    bool operator()(const Item &a, const Item &b) const
    {
        return a.getCategory() < b.getCategory();
    }
};

struct CompareByPrice
{
    bool operator()(const Item &a, const Item &b) const
    {
        return a.getPrice() < b.getPrice();
    }
};

struct NameComparison
{
    bool operator()(const Item *a, const Item *b) const
    {
        return a->getName() < b->getName();
    }
};

struct CategoryComparison
{
    bool operator()(const Item *a, const Item *b) const
    {
        return a->getCategory() < b->getCategory();
    }
};

struct PriceComparison
{
    bool operator()(const Item *a, const Item *b) const
    {
        return a->getPrice() < b->getPrice();
    }
};

struct ComparByName
{
    bool operator()(const Item &a, const Item &b) const
    {
        return a.getName() < b.getName();
    }
};

struct ComparByCategory
{
    bool operator()(const Item &a, const Item &b) const
    {
        return a.getCategory() < b.getCategory();
    }
};

struct ComparByPrice
{
    bool operator()(const Item &a, const Item &b) const
    {
        return a.getPrice() < b.getPrice();
    }
};

template <typename Comparator>
void readItemsToHeap(const string &filename, Heap<Comparator> &tree)
{
    ifstream inputFile(filename);
    if (!inputFile)
    {
        cerr << "Unable to open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(inputFile, line))
    {

        int quantity;
        istringstream iss(line);
        if (!(iss >> quantity))
        {
            continue;
        }

        for (int i = 0; i < quantity; ++i)
        {
            string name, category;
            int price;

            if (!getline(inputFile, name) || name.empty())
            {
                continue;
            }

            if (!getline(inputFile, category) || category.empty())
            {
                continue;
            }

            if (!(inputFile >> price))
            {
                inputFile.clear();
                inputFile.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            inputFile.ignore(numeric_limits<streamsize>::max(), '\n');

            Item item(name, category, price);
            tree.addItem(item);
        }
    }

    inputFile.close();
}

template <typename Comparator>
void readItemsToBST(const string &filename, BinarySearchTree<Comparator> &tree)
{
    ifstream inputFile(filename);
    if (!inputFile)
    {
        cerr << "Unable to open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(inputFile, line))
    {

        int quantity;
        istringstream iss(line);
        if (!(iss >> quantity))
        {
            continue;
        }

        for (int i = 0; i < quantity; ++i)
        {
            string name, category;
            int price;

            if (!getline(inputFile, name) || name.empty())
            {
                continue;
            }

            if (!getline(inputFile, category) || category.empty())
            {
                continue;
            }

            if (!(inputFile >> price))
            {
                inputFile.clear();
                inputFile.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            inputFile.ignore(numeric_limits<streamsize>::max(), '\n');

            Item *item = new Item(name, category, price);
            tree.insert(item);
        }
    }

    inputFile.close();
}

template <typename Comparator>
void readItemsToAVL(const string &filename, AvlTree<Comparator> &tree)
{
    ifstream inputFile(filename);
    if (!inputFile)
    {
        cerr << "Unable to open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(inputFile, line))
    {
        int quantity;
        istringstream iss(line);
        if (!(iss >> quantity))
        {
            continue;
        }

        for (int i = 0; i < quantity; ++i)
        {
            string name, category;
            int price;

            if (!getline(inputFile, name) || name.empty())
            {
                continue;
            }

            if (!getline(inputFile, category) || category.empty())
            {
                continue;
            }

            if (!(inputFile >> price))
            {
                inputFile.clear();
                inputFile.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            inputFile.ignore(numeric_limits<streamsize>::max(), '\n');

            Item *item = new Item(name, category, price);
            tree.addItem(*item);
        }
    }

    inputFile.close();
}

template void readItemsToHeap(const string &filename, Heap<CompareByName> &tree);
template void readItemsToHeap(const string &filename, Heap<CompareByPrice> &tree);
template void readItemsToHeap(const string &filename, Heap<CompareByCategory> &tree);

template void readItemsToBST(const string &filename, BinarySearchTree<NameComparison> &tree);
template void readItemsToBST(const string &filename, BinarySearchTree<PriceComparison> &tree);
template void readItemsToBST(const string &filename, BinarySearchTree<CategoryComparison> &tree);

template void readItemsToAVL(const string &filename, AvlTree<ComparByName> &tree);
template void readItemsToAVL(const string &filename, AvlTree<ComparByPrice> &tree);
template void readItemsToAVL(const string &filename, AvlTree<ComparByCategory> &tree);