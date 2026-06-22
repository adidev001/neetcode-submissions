class Solution {
   public:
    int shipWithinDays(vector<int>& weights, int days) {
        int r = accumulate(weights.begin(), weights.end(), 0);
        int l = *max_element(weights.begin(), weights.end());

        int res = r;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (sail(weight, days, mid)) {
                res = min(res, mid);
                r = mid - 1;

            } else {
                l = mid + 1;
            }
        }
        return res;
    }

   private:
    bool sail(const vector<int>& weights, int days, int cap) {
        int ship = 1;
        int curcap = cap;
        for (auto w : weight) {
            if (curcap - w < 0) {
                ship++;
                if (ship < days) return false;

                curcap = cap;
            }
            curcap -= w;
        }return true;

    }
};