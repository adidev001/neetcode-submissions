class MedianFinder {
    vector<int> arr;
    int sum =0;
    int count=0;
public:
    MedianFinder() {
        


    }
    
    void addNum(int num) {
        arr.push_back(num);

    }
    
    double findMedian() {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        if(n%2==0){
            double x=arr[(n+1)/2];
            double y=arr[(n-1)/2];
            return (x+y)/2;

        }else{
            return double(arr[n/2]);
        }
    }
};
