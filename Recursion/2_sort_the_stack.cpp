void helpSort(stack<int>&s){
   if(s.empty()) return;
   int ele=s.top();
   s.pop();
   helpSort(s);
   stack<int>s2;
   
   //now jb tk ele greter aaye stacked value se jo recursion hokrr shi hokr aayi hai
   //tb tk pop kro and uske liye correct position dekho
   while(!s.empty() && ele<s.top()){
       s2.push(s.top());
       s.pop();
   }
   s.push(ele);//pushing at correct position
   //now inserting remianing elements that were popped
   while(!s2.empty()){
       s.push(s2.top());
       s2.pop();
   }
}
