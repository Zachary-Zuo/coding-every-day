class LRUCache
{
    unordered_map<int, list<pair<int, int>>::iterator> hash;
    list<pair<int, int>> cache;
    int size;

public:
    LRUCache(int capacity) : size(capacity) {}

    int get(int key)
    {
        auto it = hash.find(key);
        if (it == hash.end())
        {
            return -1;
        }
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }

    void put(int key, int value)
    {
        auto it = hash.find(key);
        if (it != hash.end())
        {
            it->second->second = value;
            return cache.splice(cache.begin(), cache, it->second);
        }
        cache.insert(cache.begin(), make_pair(key, value));
        hash[key] = cache.begin();
        if (cache.size() > size)
        {
            hash.erase(cache.back().first);
            cache.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/*Notes:
list::splice实现list拼接的功能。将源list的内容部分或全部元素删除，拼插入到目的list。

函数有以下三种声明：

一：void splice ( iterator position, list<T,Allocator>& x ); 会在position后把list&x所有的元素到剪接到要操作的list对象

二：void splice ( iterator position, list<T,Allocator>& x, iterator it ); 只会把it的值剪接到要操作的list对象中

三：void splice ( iterator position, list<T,Allocator>& x, iterator first, iterator last ); 把first 到 last 剪接到要操作的list对象中

解释：

position 是要操作的list对象的迭代器

list&x 被剪的对象
*/