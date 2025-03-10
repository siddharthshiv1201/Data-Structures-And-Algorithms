class Solution {
public:
    bool isvowel(char ch)
    {
        return (ch=='a' || ch=='e' ||ch=='i' ||ch=='o'||ch=='u');
    }
    long long countOfSubstrings(string word, int k) {
        unordered_map<char,int>mpp;
        int n=word.size();
        long long ans=0;
        int cons=0;
        vector<int>nxtc(n);
        int lastc=n;
        for(int i=n-1;i>=0;i--)
        {
            nxtc[i]=lastc;
            if(!isvowel(word[i]))
            {
                lastc=i;
            }
        }
        int i=0,j=0;
        while(j<n)
        {
            char ch=word[j];
            if(isvowel(ch)) mpp[ch]++;
            else cons++;
            while(i<n && cons>k)
            {
                char s=word[i];
                if(isvowel(s))
                {
                    mpp[s]--;
                    if(mpp[s]==0) mpp.erase(s);
                }
                else
                {
                    cons--;
                }
                i++;
            }
            while(i<n && mpp.size()==5 && cons == k)
            {
                int idx=nxtc[j];
                ans+=idx-j;
                if(isvowel(word[i]))
                {
                    mpp[word[i]]--;
                    if(mpp[word[i]]==0) mpp.erase(word[i]);
                }
                else
                cons--;
                i++;
            }
            j++;
        }
        return ans;
    }
};