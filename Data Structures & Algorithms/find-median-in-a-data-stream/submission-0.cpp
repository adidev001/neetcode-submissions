class MedianFinder {
    vector<int> arr;
    int sum =0;
    int count=0;
public:
    MedianFinder() {
        


    }
    
    void addNum(int num) {
        arr.push_back(num);
        sum+=num;
        count++;

    }
    
    double findMedian() {
        return sum/count;
    }
};
