#include<bits/stdc++.h>

using namespace std;

map<char[],int> g_names_list;

int main()
{
  //Installize and Input
  int n,m;
  scanf("%d", &n);
  pair<char[],bool> t_pair;
  char t_str[100];
  for(int i=1; i<=n; i++) {
    scanf("%s", t_str);
    t_pair.first=t_str;
    t_pair.second+=1;
    names_list.insert(t_pair);
  }
  scanf("%d", &m);
  
  for(int i=1; i<=m; i++) {
    scanf("%s", t_str);
    auto t_item = g_names_list.find(t_str);
    if(t_item == g_names_list.end()) {
      printf("WRONG");
    }else if(t_item->second > 1) {
      printf("REPEAT");
    }else{
      printf("OK");
    }
  }
  return 0;
} 
