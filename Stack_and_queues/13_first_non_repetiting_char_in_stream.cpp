	public:
		string FirstNonRepeating(string A){
		    // Code here
		    int n=A.size();
		    string ans="";
		    queue<char>q;//for storing the character that are coming one by one, 
		    //becoz they can be answer for current stream and future stream,
		    
		    map<char,int>m;//for checking the repetiting character
		    for(int i=0;i<n;i++)
		    {
		        m[A[i]]++;
		        q.push(A[i]);
		        
		        //now till we got the non repetiting character
		        while(!q.empty() && m[q.front()]>1){
		            q.pop();
		        }
		        if(q.empty()) ans+='#';
		        else{
		            ans+=q.front();
		        }
		    }
		    return ans;
		}

};