#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

class Person{
friend ostream &operator<<(ostream &os, const Person &rhs);

private:
    string name;
    int age;

public:
    Person(string name, int age):name{name},age{age}{}
    Person(const Person&p):name{p.name},age{p.age}{}
    ~Person() = default;

    string get_name(){return name;}
    void set_name(string name){this->name = name;};

    int get_age(){return age;}
    void set_age(int age){this->age = age;}

};

void filter_vector(const vector<int> &vec, function<bool(int)> func){
cout<<"[";
for(int i: vec){
    if(func(i))
        cout<<i<<" ";
}
cout<<"]";
}

auto make_lambda(){
return [](){cout<<"this is lambda was made using make lambda"<<endl;};
}


int main(){

    vector<int> nums = {10,20,30,40,50,60,70,80};
    filter_vector(nums,[](int x){return x>50;});

    vector<Person> stooges
    {
   {"Larry",18},{"Moe",20},{"Curly",32}
    };

    sort(begin(stooges),end(stooges),[](Person &p1, Person &p2){return p1.get_name() < p2.get_name();});
    for(auto p: stooges){
        cout<<p.get_name()<<endl;
    }
}
