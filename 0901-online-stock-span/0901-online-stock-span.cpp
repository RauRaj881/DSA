class StockSpanner {
public:
stack<pair<int,int>> st;
int i=0;
    StockSpanner() {
    }
    
    int next(int price){
        while(!st.empty()&&st.top().first<=price){
            st.pop();
        }
        int pse=-1;
        if(!st.empty()){pse=st.top().second;}
        st.push({price,i});
        int x=i;
        i++;        
        return x-pse;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */