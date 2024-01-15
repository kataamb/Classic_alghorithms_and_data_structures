#include <vector>
#include <iostream>

#include <string>
#include <sstream>
#include <iterator>

static constexpr int ELEMENTS = 2;

/*
 * chain method
 */

template <typename T>
class Set {
private:
    std::vector< std::vector<T> > body;
    size_t hash(T& element, size_t N) const;
    bool have_to_rehash();
    void rehash();
    size_t cnt_elems;
public:
    Set();
    Set(const std::vector<T>& v);
    void add(T element);
    bool find(T element) const;
    void remove(T element);

    size_t get_size();

    void output();

    Set<T> intersection(const Set<T>& set2) const;
    Set<T> difference(const Set<T>& set2) const;

};

//----------------------------------------------------------------------------------------------------
// constructors

template <typename T>
Set<T>::Set() {
    body.reserve(ELEMENTS);

    std::vector<T> cur_lst;
    for (size_t i = 0; i < ELEMENTS; ++i)
        body.push_back(cur_lst);
    cnt_elems = 0;

}

template <typename T>
Set<T>::Set(const std::vector<T>& v) {
    body.reserve(ELEMENTS);

    std::vector<T> cur_lst;
    for (size_t i = 0; i < ELEMENTS; ++i)
        body.push_back(cur_lst);
    cnt_elems = 0;

    for (auto &elem: v) {
        add(elem);
    }
}

/*
//same as method below
template <typename T>
Set<T>::Set(const std::vector<T>& v) {
    body.reserve(ELEMENTS);

    std::vector<T> cur_lst;
    for (size_t i = 0; i < ELEMENTS; ++i)
        body.push_back(cur_lst);
    cnt_elems = 0;
    
    for (auto &elem: v) {
        this->add(elem);
    }
}
*/

//----------------------------------------------------------------------------------------------------
// hash for different types

template <typename T>
size_t Set<T>::hash(T& element, size_t N) const {
    return (N > 0) ? (element % N) : (0);
}

template <>
size_t Set<std::string>::hash(std::string &element, size_t N) const {
    size_t value = 0;
    size_t poww = 1;
    for (int i = 0; i < element.size(); ++i)
    {
        value += poww * element[i];
        poww *= 2;
    }
    return (N > 0) ? (value % N) : (0);
}

//----------------------------------------------------------------------------------------------------

template <typename T>
bool Set<T>::have_to_rehash() {
    return cnt_elems > body.size();
}

template <typename T>
void Set<T>::rehash() {
    size_t new_size = body.size() * 2;
    std::vector< std::vector<T> > new_body(new_size);

    for (auto& cur_lst: body) {
        for (auto& elem: cur_lst) {
            new_body[ hash(elem, new_body.size()) ].push_back(elem);
        }
    }
    body = new_body;
}

//----------------------------------------------------------------------------------------------------

template <typename T>
bool Set<T>::find(T element) const
{
    auto& cur_lst = body[hash(element, body.size())]; 
    for (auto& cur_elem: cur_lst) {
        if (cur_elem == element)
            return true;
    }
    return false;
}

template <typename T>
void Set<T>::add(T element) {
    if (find(element))
        return;
    if (have_to_rehash())
        rehash();
    size_t hash_val = hash(element, body.size());
    body[hash_val].push_back(element);
    ++cnt_elems;
}

template <typename T>
void Set<T>::remove(T element)
{
    if (!find(element))
        return;
    auto& cur_lst = body[hash(element, body.size())]; 
    for (size_t i = 0; i < cur_lst.size(); i++) {
        if (cur_lst[i] == element) {
            cur_lst[i] = cur_lst[cur_lst.size() - 1];
            cur_lst.pop_back();
        }      
    }
    --cnt_elems;
}

template <typename T>
size_t Set<T>::get_size() {
    return cnt_elems;
}

template <typename T>
void Set<T>::output()
{
    for (auto& lst: body) {
        std::cout << "list: ";
        for (auto& elem: lst) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

template <typename T>
Set<T> Set<T>::intersection(const Set<T>& set2) const {
    Set<T> new_set;
     for (auto& lst: body) {
        for (auto& elem: lst) {
            if(set2.find(elem)) {
                new_set.add(elem);
            }
        }
    }
    return new_set;
}

template <typename T>
Set<T> Set<T>::difference(const Set<T>& set2) const {
    Set<T> new_set;
     for (auto& lst: body) {
        for (auto& elem: lst) {
            if(!set2.find(elem)) {
                new_set.add(elem);
            }
        }
    }
    return new_set;
}

//----------------------------------------------------------------------------------------------------

std::vector<int> read_int_vector(std::istream& in = std::cin) {
    std::string buffer;
    std::getline(in, buffer);

    std::istringstream str_in(buffer);
    return std::vector<int>(std::istream_iterator<int>(str_in), std::istream_iterator<int>());
}

int main()
{
    std::vector<int> input_array = read_int_vector();
    Set<int> s(input_array);

    s.add(1);
    s.add(10);
    
    s.output();
    s.add(8);
    s.add(144);
    s.add(97);
    s.add(14);
    s.output();
    s.remove(10);
    s.output();
    s.add(1);
    s.output();
    s.add(2);
    s.add(3);
    s.add(4);
    s.add(5);
    s.add(6);
    s.add(7);
    s.output();

    return 0;
}

