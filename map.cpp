#include <iostream>
#include <map>
#include<string>
#include<iterator>

using namespace std;

int main(){
	map<string, string> my_map;
	my_map["g"] = "grace";
	my_map["g"] = "muze";
	my_map["e"] = "eve";
	my_map["d"] = "duncan";

	for(auto it = my_map.begin(); it != my_map.end(); ++it)
		cout << it ->first << "=" << it->second<<'\n';
	//cout<<my_map["g"]<<endl;

return 0;

}